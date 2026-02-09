"use client";

import { motion } from "framer-motion";
import { cn } from "@/lib/utils";
import React from "react";

interface MotionButtonProps {
    variant?: "primary" | "secondary" | "outline" | "ghost" | "glass" | "danger";
    size?: "sm" | "md" | "lg";
    className?: string;
    children: React.ReactNode;
    onClick?: () => void;
    disabled?: boolean;
    href?: string;
    type?: "button" | "submit" | "reset";
    glow?: boolean; // Kept for compatibility but disabled internally or simplified
}

export default function MotionButton({
    variant = "primary",
    size = "md",
    className,
    children,
    disabled,
    onClick,
    type = "button",
    // eslint-disable-next-line @typescript-eslint/no-unused-vars
    glow = false
}: MotionButtonProps) {

    // Cleaned up base styles - removed potential conflicts
    const baseStyles = "inline-flex items-center justify-center rounded-full font-semibold transition-colors focus:outline-none focus:ring-2 focus:ring-offset-2 disabled:opacity-50 disabled:pointer-events-none select-none cursor-pointer relative overflow-hidden";

    // Simplified, Professional Variants matching globals.css theme
    const variants = {
        // Solid Indigo to Violet gradient - consistent with theme, less "rainbow"
        primary: "bg-indigo-600 hover:bg-indigo-700 text-white shadow-md hover:shadow-lg border border-transparent",

        // Clean White
        secondary: "bg-white text-indigo-900 border border-gray-200 hover:bg-gray-50 shadow-sm",

        // Transparent with white border
        outline: "bg-transparent border border-white/30 text-white hover:bg-white/10",

        // Simple Ghost
        ghost: "bg-transparent text-white hover:bg-white/10",

        // Glassmorphism - simplified
        glass: "bg-white/10 backdrop-blur-md border border-white/10 text-white hover:bg-white/20",

        // Danger
        danger: "bg-red-500/10 border border-red-500/50 text-red-500 hover:bg-red-500/20",
    };

    const sizes = {
        sm: "text-xs px-4 py-2",
        md: "text-sm px-6 py-2.5",
        lg: "text-base px-8 py-3",
    };

    return (
        <motion.button
            whileHover={{ scale: 1.02 }} // Reduced scale effect
            whileTap={{ scale: 0.98 }}
            className={cn(baseStyles, variants[variant], sizes[size], className)}
            onClick={onClick}
            disabled={disabled}
            type={type}
        >
            <span className="relative z-10 flex items-center gap-2">{children}</span>
        </motion.button>
    );
}
