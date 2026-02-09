"use client";

import { useState } from "react";
import { useRouter } from "next/navigation";
import { storage, auth } from "@/lib/firebase";
import { ref, uploadBytes, getDownloadURL } from "firebase/storage";
import { Loader2, Upload, MapPin, Calendar, Type } from "lucide-react";
import { onAuthStateChanged } from "firebase/auth";

export default function ReportFoundPage() {
    const [file, setFile] = useState<File | null>(null);
    const [preview, setPreview] = useState<string | null>(null);
    const [loading, setLoading] = useState(false);
    const router = useRouter();

    // Form State
    const [title, setTitle] = useState("");
    const [foundLocation, setFoundLocation] = useState("");
    const [date, setDate] = useState("");
    const [category, setCategory] = useState("Electronics");

    // Auth check
    useState(() => {
        onAuthStateChanged(auth, (user) => {
            if (!user) router.push("/auth/login");
        });
    });

    const handleFileChange = (e: React.ChangeEvent<HTMLInputElement>) => {
        if (e.target.files && e.target.files[0]) {
            const selected = e.target.files[0];
            setFile(selected);
            setPreview(URL.createObjectURL(selected));
        }
    };

    const handleSubmit = async (e: React.FormEvent) => {
        e.preventDefault();
        if (!file) return alert("Please upload an image of the found item");

        setLoading(true);

        try {
            const storageRef = ref(storage, `items/${Date.now()}_${file.name}`);
            await uploadBytes(storageRef, file);
            const url = await getDownloadURL(storageRef);

            const res = await fetch("/api/items", {
                method: "POST",
                headers: { "Content-Type": "application/json" },
                body: JSON.stringify({
                    type: "found", // Explicitly set to 'found'
                    title,
                    category,
                    location: foundLocation,
                    date,
                    imageUrl: url,
                    uid: auth.currentUser?.uid
                })
            });

            if (res.ok) {
                router.push("/dashboard");
            } else {
                alert("Failed to report item");
            }

        } catch (error) {
            console.error(error);
            alert("Error submitting report");
        } finally {
            setLoading(false);
        }
    };

    return (
        <div className="container pt-24 pb-12 max-w-2xl relative min-h-screen">
            {/* Background Ambience */}
            <div className="absolute top-0 left-0 w-[400px] h-[400px] bg-pink-600/10 rounded-full blur-[100px] -z-10 pointer-events-none" />
            <div className="absolute bottom-0 right-0 w-[300px] h-[300px] bg-indigo-600/10 rounded-full blur-[100px] -z-10 pointer-events-none" />

            <div className="space-y-2 mb-8 text-center sm:text-left">
                <h1 className="text-4xl font-extrabold tracking-tight text-gradient mb-2">Report Found Item</h1>
                <p className="text-muted-foreground text-lg">Good Samaritan! Please provide details of the item you found.</p>
            </div>

            <form onSubmit={handleSubmit} className="glass-card flex flex-col gap-6 p-6 animate-fade-in">

                {/* Image Upload */}
                <div className="flex flex-col items-center justify-center border-2 border-dashed border-white/20 rounded-xl p-8 transition-colors hover:border-pink-500/50 hover:bg-white/5 cursor-pointer relative group">
                    <input
                        type="file"
                        accept="image/*"
                        onChange={handleFileChange}
                        className="absolute inset-0 w-full h-full opacity-0 cursor-pointer"
                    />
                    {preview ? (
                        <img src={preview} alt="Preview" className="max-h-64 rounded-lg shadow-lg" />
                    ) : (
                        <div className="flex flex-col items-center text-muted-foreground group-hover:text-white transition-colors">
                            <Upload size={40} className="mb-4" />
                            <p className="font-medium">Upload Image of Found Item</p>
                            <p className="text-xs">JPG, PNG (Max 5MB)</p>
                        </div>
                    )}
                </div>

                {/* Fields */}
                <div className="grid grid-cols-1 md:grid-cols-2 gap-4">
                    <div>
                        <label className="text-sm font-medium mb-1 block flex items-center gap-2">
                            <Type size={14} /> Description / Title
                        </label>
                        <input
                            required
                            value={title}
                            onChange={(e) => setTitle(e.target.value)}
                            placeholder="e.g. Blue Umbrella"
                            className="input-field focus:border-pink-500"
                        />
                    </div>

                    <div>
                        <label className="text-sm font-medium mb-1 block">Category</label>
                        <select
                            value={category}
                            onChange={(e) => setCategory(e.target.value)}
                            className="input-field focus:border-pink-500"
                            style={{ backgroundColor: '#1f2937' }}
                        >
                            <option>Electronics</option>
                            <option>Clothing & Accessories</option>
                            <option>ID Cards / Wallets</option>
                            <option>Keys</option>
                            <option>Books / Stationery</option>
                            <option>Other</option>
                        </select>
                    </div>

                    <div>
                        <label className="text-sm font-medium mb-1 block flex items-center gap-2">
                            <MapPin size={14} /> Found Location
                        </label>
                        <input
                            required
                            value={foundLocation}
                            onChange={(e) => setFoundLocation(e.target.value)}
                            placeholder="e.g. Canteen Table 4"
                            className="input-field focus:border-pink-500"
                        />
                    </div>

                    <div>
                        <label className="text-sm font-medium mb-1 block flex items-center gap-2">
                            <Calendar size={14} /> Date Found
                        </label>
                        <input
                            type="date"
                            required
                            value={date}
                            onChange={(e) => setDate(e.target.value)}
                            className="input-field focus:border-pink-500"
                        />
                    </div>
                </div>

                <button
                    type="submit"
                    disabled={loading}
                    className="btn btn-secondary w-full mt-4 py-4 text-lg"
                >
                    {loading ? <span className="flex items-center gap-2"><Loader2 className="animate-spin" /> Submitting...</span> : "Submit Report"}
                </button>

            </form>
        </div>
    );
}
