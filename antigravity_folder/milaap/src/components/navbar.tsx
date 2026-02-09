"use client";

import { useState, useEffect } from "react";
import Link from "next/link";
import { usePathname } from "next/navigation";
import { cn } from "@/lib/utils";
import { Sparkles } from "lucide-react";
import { auth } from "@/lib/firebase";
import { onAuthStateChanged, signOut } from "firebase/auth";

export default function Navbar() {
    const pathname = usePathname();
    const [user, setUser] = useState<any>(null);
    const [loading, setLoading] = useState(true);

    useEffect(() => {
        const unsubscribe = onAuthStateChanged(auth, (currentUser) => {
            setUser(currentUser);
            setLoading(false);
        });
        return () => unsubscribe();
    }, []);

    const handleLogout = async () => {
        await signOut(auth);
        window.location.href = "/";
    };

    return (
        <nav className="navbar glass">
            <div className="container flex items-center justify-between h-full">
                {/* Logo */}
                <Link href="/" className="flex items-center gap-2">
                    <div className="flex items-center justify-center w-8 h-8 rounded-full bg-gradient-to-tr from-indigo-500 to-purple-500" style={{ background: 'linear-gradient(135deg, var(--primary), var(--secondary))' }}>
                        <Sparkles size={16} className="text-white" />
                    </div>
                    <span className="font-bold text-xl tracking-tight">Milaap</span>
                </Link>

                {/* Navigation Links */}
                <div className="flex items-center gap-6">
                    <Link href="/browse" className={cn("text-sm hover:text-white transition-colors", pathname === "/browse" ? "text-white" : "text-muted-foreground")}>
                        Browse Items
                    </Link>
                    <Link href="/report/lost" className={cn("text-sm hover:text-white transition-colors", pathname?.startsWith("/report") ? "text-white" : "text-muted-foreground")}>
                        Report
                    </Link>
                    {user && (
                        <Link href="/dashboard" className={cn("text-sm hover:text-white transition-colors", pathname === "/dashboard" ? "text-white" : "text-muted-foreground")}>
                            Dashboard
                        </Link>
                    )}
                </div>

                {/* Auth Buttons */}
                <div className="flex items-center gap-4">
                    {loading ? (
                        <div className="w-8 h-8 rounded-full bg-white/10 animate-pulse" />
                    ) : user ? (
                        <div className="flex items-center gap-4">
                            <span className="text-sm text-muted-foreground hidden md:block">Hi, {user.displayName?.split(' ')[0]}</span>
                            <div className="flex items-center gap-3">
                                <Link href="/dashboard">
                                    <div className="w-9 h-9 rounded-full bg-gradient-to-tr from-indigo-500 to-purple-500 p-[1px] cursor-pointer hover:scale-105 transition-transform">
                                        <div className="w-full h-full rounded-full bg-black flex items-center justify-center text-white font-bold text-xs">
                                            {user.displayName?.[0]?.toUpperCase() || "U"}
                                        </div>
                                    </div>
                                </Link>
                                <button
                                    onClick={() => auth.signOut()}
                                    className="text-xs bg-red-500/10 hover:bg-red-500/20 text-red-400 border border-red-500/20 px-3 py-1.5 rounded-full transition-colors font-medium"
                                >
                                    Log Out
                                </button>
                            </div>
                        </div>
                    ) : (
                        <div className="flex items-center gap-3">
                            <Link href="/auth/login" className="text-sm font-medium hover:text-white text-muted-foreground transition-colors px-2">
                                Login
                            </Link>
                            <Link href="/auth/signup">
                                <span className="bg-white text-black px-4 py-2 rounded-full text-sm font-bold hover:bg-gray-200 transition-colors">
                                    Get Started
                                </span>
                            </Link>
                        </div>
                    )}
                </div>
            </div>
        </nav>
    );
}
