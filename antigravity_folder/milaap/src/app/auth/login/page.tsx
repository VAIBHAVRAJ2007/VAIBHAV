"use client";

import { useState } from "react";
import { signInWithEmailAndPassword } from "firebase/auth";
import { auth } from "@/lib/firebase";
import { useRouter } from "next/navigation";
import Link from "next/link";
import { Sparkles, Loader2 } from "lucide-react";
import MotionButton from "@/components/ui/motion-button";

export default function LoginPage() {
    const [email, setEmail] = useState("");
    const [password, setPassword] = useState("");
    const [loading, setLoading] = useState(false);
    const [error, setError] = useState("");
    const router = useRouter();

    const handleLogin = async (e: React.FormEvent) => {
        e.preventDefault();
        setLoading(true);
        setError("");

        try {
            await signInWithEmailAndPassword(auth, email, password);
            router.push("/dashboard");
        } catch (err: any) {
            setError("Invalid email or password. Please try again.");
        } finally {
            setLoading(false);
        }
    };

    return (
        <div className="flex items-center justify-center min-h-[calc(100vh-6rem)] relative">
            <div className="absolute top-[20%] right-[30%] w-[300px] h-[300px] rounded-full bg-indigo-500/20 blur-[100px] pointer-events-none"></div>

            <div className="glass-card w-full max-w-md p-8 z-10 animate-fade-in relative">
                <div className="flex flex-col items-center mb-6">
                    <div className="p-3 bg-white/10 rounded-full mb-3">
                        <Sparkles className="text-white" size={24} />
                    </div>
                    <h2 className="text-2xl font-bold text-white">Welcome Back</h2>
                    <p className="text-muted-foreground text-sm">Sign in to continue to Milaap</p>
                </div>

                {error && (
                    <div className="bg-red-500/10 border border-red-500/20 text-red-200 text-sm p-3 rounded mb-4">
                        {error}
                    </div>
                )}

                <form onSubmit={handleLogin} className="flex flex-col gap-4">
                    <div>
                        <label className="text-sm font-medium text-gray-300 mb-1 block">Email Address</label>
                        <input
                            type="email"
                            required
                            className="input-field"
                            placeholder="you@college.edu"
                            value={email}
                            onChange={(e) => setEmail(e.target.value)}
                        />
                    </div>

                    <div>
                        <label className="text-sm font-medium text-gray-300 mb-1 block">Password</label>
                        <input
                            type="password"
                            required
                            className="input-field"
                            placeholder="••••••••"
                            value={password}
                            onChange={(e) => setPassword(e.target.value)}
                        />
                    </div>

                    import MotionButton from "@/components/ui/motion-button";

                    // ... inside component ...

                    <MotionButton
                        type="submit"
                        disabled={loading}
                        className="w-full mt-4"
                        variant="primary"
                        glow
                    >
                        {loading ? <Loader2 className="animate-spin mr-2" size={18} /> : null}
                        {loading ? "Signing in..." : "Sign In"}
                    </MotionButton>
                </form>

                <div className="mt-6 text-center text-sm text-gray-400">
                    Don&apos;t have an account? <Link href="/auth/signup" className="text-indigo-400 hover:text-indigo-300">Sign up</Link>
                </div>
            </div>
        </div>
    );
}
