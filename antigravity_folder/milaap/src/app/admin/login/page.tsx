"use client";

import { useState } from "react";
import { useRouter } from "next/navigation";
import { signInWithEmailAndPassword } from "firebase/auth";
import { auth } from "@/lib/firebase";
import { Shield, Lock, AlertCircle } from "lucide-react";
import { motion } from "framer-motion";
import MotionButton from "@/components/ui/motion-button";

export default function AdminLogin() {
    const [email, setEmail] = useState("");
    const [password, setPassword] = useState("");
    const [error, setError] = useState("");
    const [loading, setLoading] = useState(false);
    const router = useRouter();

    const handleAdminLogin = async (e: React.FormEvent) => {
        e.preventDefault();
        setLoading(true);
        setError("");

        // Simple Admin Check logic
        // In a real app, this should be done via Custom Claims or a protected collection
        // For this prototype, we'll enforce a specific email domain or specific email.

        if (!email.includes("admin")) {
            setError("Access Denied: Not an admin account.");
            setLoading(false);
            return;
        }

        try {
            await signInWithEmailAndPassword(auth, email, password);
            router.push("/admin");
        } catch (err: any) {
            console.error(err);
            setError("Invalid admin credentials.");
        } finally {
            setLoading(false);
        }
    };

    return (
        <div className="min-h-screen flex items-center justify-center relative overflow-hidden bg-black">
            {/* Background Effects */}
            <div className="absolute inset-0 bg-[radial-gradient(circle_at_50%_120%,rgba(120,50,255,0.1),rgba(0,0,0,0))]" />
            <div className="absolute top-0 left-1/2 -translate-x-1/2 w-[600px] h-[300px] bg-indigo-500/10 rounded-full blur-[100px] pointer-events-none" />

            <motion.div
                initial={{ opacity: 0, scale: 0.95 }}
                animate={{ opacity: 1, scale: 1 }}
                className="w-full max-w-md p-8 glass-card border-indigo-500/20 shadow-2xl shadow-indigo-500/10 relative z-10"
            >
                <div className="flex flex-col items-center mb-8">
                    <div className="w-16 h-16 rounded-2xl bg-gradient-to-tr from-indigo-500 to-purple-600 flex items-center justify-center mb-4 shadow-lg shadow-indigo-500/25">
                        <Shield className="text-white w-8 h-8" />
                    </div>
                    <h1 className="text-2xl font-bold text-white tracking-tight">Admin Portal</h1>
                    <p className="text-gray-400 text-sm">Secure access for staff only</p>
                </div>

                {error && (
                    <motion.div initial={{ opacity: 0, y: -10 }} animate={{ opacity: 1, y: 0 }} className="mb-6 p-3 bg-red-500/10 border border-red-500/20 rounded-lg flex items-center gap-2 text-red-400 text-sm">
                        <AlertCircle size={16} />
                        {error}
                    </motion.div>
                )}

                <form onSubmit={handleAdminLogin} className="space-y-4">
                    <div className="space-y-2">
                        <label className="text-xs font-semibold text-gray-400 uppercase tracking-wider ml-1">Email ID</label>
                        <div className="relative">
                            <input
                                type="email"
                                required
                                value={email}
                                onChange={(e) => setEmail(e.target.value)}
                                className="w-full bg-black/40 border border-white/10 rounded-xl px-4 py-3 pl-10 text-white focus:border-indigo-500 focus:ring-1 focus:ring-indigo-500 transition-all outline-none"
                                placeholder="admin@milaap.edu"
                            />
                            <Shield className="absolute left-3 top-3.5 text-gray-500 w-4 h-4" />
                        </div>
                    </div>

                    <div className="space-y-2">
                        <label className="text-xs font-semibold text-gray-400 uppercase tracking-wider ml-1">Password</label>
                        <div className="relative">
                            <input
                                type="password"
                                required
                                value={password}
                                onChange={(e) => setPassword(e.target.value)}
                                className="w-full bg-black/40 border border-white/10 rounded-xl px-4 py-3 pl-10 text-white focus:border-indigo-500 focus:ring-1 focus:ring-indigo-500 transition-all outline-none"
                                placeholder="••••••••"
                            />
                            <Lock className="absolute left-3 top-3.5 text-gray-500 w-4 h-4" />
                        </div>
                    </div>

                    <div className="pt-4">
                        <MotionButton
                            type="submit"
                            variant="primary"
                            glow
                            className="w-full justify-center"
                            disabled={loading}
                        >
                            {loading ? "Verifying..." : "Access Dashboard"}
                        </MotionButton>
                    </div>
                </form>

                <div className="mt-6 text-center">
                    <a href="/" className="text-xs text-gray-500 hover:text-white transition-colors">Return to Home</a>
                </div>
            </motion.div>
        </div>
    );
}
