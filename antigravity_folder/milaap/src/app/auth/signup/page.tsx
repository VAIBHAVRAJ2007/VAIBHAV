"use client";

import { useState } from "react";
import { createUserWithEmailAndPassword, updateProfile } from "firebase/auth";
import { auth, db } from "@/lib/firebase"; // Assuming db is exported from firebase.ts
import { doc, setDoc } from "firebase/firestore";
import { useRouter } from "next/navigation";
import Link from "next/link";
import { Sparkles, Loader2 } from "lucide-react";
import MotionButton from "@/components/ui/motion-button";

export default function SignupPage() {
    const [formData, setFormData] = useState({
        name: "",
        email: "",
        password: "",
        rollNo: "",
        department: ""
    });
    const [loading, setLoading] = useState(false);
    const [error, setError] = useState("");
    const router = useRouter();

    const handleChange = (e: React.ChangeEvent<HTMLInputElement | HTMLSelectElement>) => {
        setFormData({ ...formData, [e.target.name]: e.target.value });
    };

    const handleSignup = async (e: React.FormEvent) => {
        e.preventDefault();
        setLoading(true);
        setError("");

        try {
            // 1. Create auth user
            // 1. Create auth user
            const userCredential = await createUserWithEmailAndPassword(auth, formData.email, formData.password);

            if (!userCredential || !userCredential.user) {
                throw new Error("Failed to retrieve user data after signup.");
            }

            const user = userCredential.user;

            // 2. Update profile
            try {
                await updateProfile(user, { displayName: formData.name });
            } catch (profileErr) {
                console.warn("Profile update warning:", profileErr);
            }

            // 3. Save extra details to Firestore
            try {
                await setDoc(doc(db, "users", user.uid), {
                    uid: user.uid,
                    name: formData.name,
                    email: formData.email,
                    rollNo: formData.rollNo,
                    department: formData.department,
                    role: "student",
                    createdAt: new Date().toISOString()
                });
            } catch (dbErr: any) {
                console.error("Firestore Error:", dbErr);
                // If this fails, the user is created but profile is missing. 
                // We might want to alert the user but still redirect or ask them to contact support.
                throw new Error(`Database Error: ${dbErr.message} (User created but profile save failed)`);
            }

            router.push("/dashboard");
        } catch (err: any) {
            console.error(err);
            setError(err.message || "Failed to create account.");
        } finally {
            setLoading(false);
        }
    };

    return (
        <div className="flex items-center justify-center min-h-[calc(100vh-6rem)] relative py-10">
            <div className="absolute bottom-[20%] left-[30%] w-[400px] h-[400px] rounded-full bg-pink-500/20 blur-[100px] pointer-events-none"></div>

            <div className="glass-card w-full max-w-lg p-8 z-10 animate-fade-in relative">
                <div className="flex flex-col items-center mb-6">
                    <div className="p-3 bg-white/10 rounded-full mb-3">
                        <Sparkles className="text-white" size={24} />
                    </div>
                    <h2 className="text-2xl font-bold text-white">Create Account</h2>
                    <p className="text-muted-foreground text-sm">Join the network to help find lost items</p>
                </div>

                {error && (
                    <div className="bg-red-500/10 border border-red-500/20 text-red-200 text-sm p-3 rounded mb-4">
                        {error}
                    </div>
                )}

                <form onSubmit={handleSignup} className="grid grid-cols-1 md:grid-cols-2 gap-4">
                    <div className="col-span-2">
                        <label className="text-sm font-medium text-gray-300 mb-1 block">Full Name</label>
                        <input
                            name="name"
                            type="text"
                            required
                            className="input-field"
                            placeholder="John Doe"
                            value={formData.name}
                            onChange={handleChange}
                        />
                    </div>

                    <div className="col-span-2">
                        <label className="text-sm font-medium text-gray-300 mb-1 block">Email Address</label>
                        <input
                            name="email"
                            type="email"
                            required
                            className="input-field"
                            placeholder="you@college.edu"
                            value={formData.email}
                            onChange={handleChange}
                        />
                    </div>

                    <div>
                        <label className="text-sm font-medium text-gray-300 mb-1 block">Roll Number</label>
                        <input
                            name="rollNo"
                            type="text"
                            required
                            className="input-field"
                            placeholder="2024CS101"
                            value={formData.rollNo}
                            onChange={handleChange}
                        />
                    </div>

                    <div>
                        <label className="text-sm font-medium text-gray-300 mb-1 block">Department</label>
                        <select
                            name="department"
                            required
                            className="input-field"
                            value={formData.department}
                            onChange={handleChange}
                            style={{ backgroundColor: '#1f2937' }} // Fix for option visibility in dark mode
                        >
                            <option value="">Select Dept</option>
                            <option value="CSE">CSE</option>
                            <option value="ECE">ECE</option>
                            <option value="MECH">MECH</option>
                            <option value="CIVIL">CIVIL</option>
                            <option value="OTHER">Other</option>
                        </select>
                    </div>

                    <div className="col-span-2">
                        <label className="text-sm font-medium text-gray-300 mb-1 block">Password</label>
                        <input
                            name="password"
                            type="password"
                            required
                            className="input-field"
                            placeholder="••••••••"
                            value={formData.password}
                            onChange={handleChange}
                        />
                    </div>

                    import MotionButton from "@/components/ui/motion-button";

                    // ... inside component ...

                    <MotionButton
                        type="submit"
                        disabled={loading}
                        className="w-full mt-4 col-span-2"
                        variant="primary"
                        glow
                    >
                        {loading ? <Loader2 className="animate-spin mr-2" size={18} /> : null}
                        {loading ? "Creating account..." : "Sign Up"}
                    </MotionButton>
                </form>

                <div className="mt-6 text-center text-sm text-gray-400">
                    Already have an account? <Link href="/auth/login" className="text-indigo-400 hover:text-indigo-300">Log in</Link>
                </div>
            </div>
        </div>
    );
}
