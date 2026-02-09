"use client";

import { useEffect, useState } from "react";
import { useRouter } from "next/navigation";
import { auth, db } from "@/lib/firebase";
import { onAuthStateChanged, signOut } from "firebase/auth";
import { collection, query, getDocs, deleteDoc, doc, updateDoc, orderBy } from "firebase/firestore";
import { Shield, LogOut, CheckCircle, Trash2, Search, Filter } from "lucide-react";
import MotionButton from "@/components/ui/motion-button";
import { motion, AnimatePresence } from "framer-motion";

export default function AdminDashboard() {
    const [user, setUser] = useState<any>(null);
    const [loading, setLoading] = useState(true);
    const [items, setItems] = useState<any[]>([]);
    const [search, setSearch] = useState("");
    const router = useRouter();

    useEffect(() => {
        const unsubscribe = onAuthStateChanged(auth, (currentUser) => {
            if (!currentUser || !currentUser.email?.includes("admin")) {
                // Basic protection
                router.push("/admin/login");
                return;
            }
            setUser(currentUser);
            fetchItems();
        });
        return () => unsubscribe();
    }, [router]);

    const fetchItems = async () => {
        try {
            const q = query(collection(db, "items"), orderBy("createdAt", "desc"));
            const snapshot = await getDocs(q);
            const data = snapshot.docs.map(doc => ({ id: doc.id, ...doc.data() } as any));
            setItems(data);
        } catch (error) {
            console.error("Error fetching items:", error);
        } finally {
            setLoading(false);
        }
    };

    const handleDelete = async (id: string) => {
        if (!confirm("Are you sure you want to delete this item?")) return;
        try {
            await deleteDoc(doc(db, "items", id));
            setItems(prev => prev.filter(item => item.id !== id));
        } catch (error) {
            console.error("Error deleting:", error);
        }
    };

    const handleResolve = async (id: string) => {
        try {
            await updateDoc(doc(db, "items", id), { status: "resolved" });
            setItems(prev => prev.map(item => item.id === id ? { ...item, status: "resolved" } : item));
        } catch (error) {
            console.error("Error updating:", error);
        }
    };

    const handleLogout = async () => {
        await signOut(auth);
        router.push("/admin/login");
    };

    const filteredItems = items.filter(item =>
        item.title?.toLowerCase().includes(search.toLowerCase()) ||
        item.location?.toLowerCase().includes(search.toLowerCase()) ||
        item.userTitle?.toLowerCase().includes(search.toLowerCase())
    );

    if (loading) return <div className="min-h-screen bg-black flex items-center justify-center text-white">Loading Admin Panel...</div>;

    return (
        <div className="min-h-screen bg-black text-white p-6">
            <div className="max-w-7xl mx-auto">
                {/* Header */}
                <div className="flex flex-col md:flex-row items-center justify-between mb-8 gap-4 bg-white/5 p-6 rounded-2xl border border-white/10">
                    <div className="flex items-center gap-4">
                        <div className="w-12 h-12 bg-indigo-600 rounded-xl flex items-center justify-center shadow-lg shadow-indigo-500/20">
                            <Shield className="text-white w-6 h-6" />
                        </div>
                        <div>
                            <h1 className="text-2xl font-bold">Admin Controls</h1>
                            <p className="text-gray-400 text-sm">Supervise and manage all reported items</p>
                        </div>
                    </div>

                    <div className="flex gap-4">
                        <MotionButton onClick={fetchItems} variant="ghost" size="sm">Refresh</MotionButton>
                        <MotionButton onClick={handleLogout} variant="danger" size="sm" className="bg-red-500/20 text-red-300 hover:bg-red-500/30 border-red-500/20">
                            <LogOut size={16} /> Logout
                        </MotionButton>
                    </div>
                </div>

                {/* Filters */}
                <div className="flex flex-col md:flex-row gap-4 mb-6">
                    <div className="relative flex-1">
                        <Search className="absolute left-3 top-1/2 -translate-y-1/2 text-gray-400 w-4 h-4" />
                        <input
                            type="text"
                            placeholder="Search items..."
                            value={search}
                            onChange={(e) => setSearch(e.target.value)}
                            className="w-full bg-white/5 border border-white/10 rounded-xl py-2 pl-10 pr-4 focus:border-indigo-500 focus:outline-none transition-colors"
                        />
                    </div>
                    <div className="flex items-center gap-2 bg-white/5 px-4 rounded-xl border border-white/10">
                        <Filter className="text-gray-400 w-4 h-4" />
                        <span className="text-sm font-medium">{filteredItems.length} Items</span>
                    </div>
                </div>

                {/* Table / List */}
                <div className="grid grid-cols-1 gap-4">
                    <AnimatePresence>
                        {filteredItems.map(item => (
                            <motion.div
                                key={item.id}
                                layout
                                initial={{ opacity: 0, y: 10 }}
                                animate={{ opacity: 1, y: 0 }}
                                exit={{ opacity: 0, scale: 0.95 }}
                                className="bg-white/5 hover:bg-white/10 border border-white/10 rounded-xl p-4 flex flex-col md:flex-row items-center gap-4 group transition-colors"
                            >
                                <img
                                    src={item.imageUrl}
                                    className="w-16 h-16 rounded-lg object-cover bg-black/30"
                                    alt="Item"
                                />

                                <div className="flex-1 text-center md:text-left">
                                    <div className="flex items-center justify-center md:justify-start gap-2 mb-1">
                                        <h3 className="font-semibold text-lg">{item.userTitle || item.title || "Untitled"}</h3>
                                        <span className={`text-[10px] px-2 py-0.5 rounded-full uppercase font-bold tracking-wide ${item.type === 'lost' ? 'bg-red-500/20 text-red-400' : 'bg-green-500/20 text-green-400'}`}>
                                            {item.type}
                                        </span>
                                        {item.status === 'resolved' && (
                                            <span className="text-[10px] bg-blue-500/20 text-blue-400 px-2 py-0.5 rounded-full border border-blue-500/20">Resolved</span>
                                        )}
                                    </div>
                                    <p className="text-sm text-gray-400">{item.location} • {item.date}</p>
                                    <p className="text-xs text-gray-500 mt-1 truncate max-w-md">{item.aiDescription || "No description"}</p>
                                </div>

                                <div className="flex items-center gap-3">
                                    <div className="text-right mr-4 hidden md:block">
                                        <p className="text-xs text-gray-500">Reported by</p>
                                        <p className="text-xs font-medium text-gray-300">{item.contactName || "User"}</p>
                                    </div>

                                    {item.status !== 'resolved' && (
                                        <button
                                            onClick={() => handleResolve(item.id)}
                                            className="p-2 rounded-full bg-green-500/10 text-green-400 hover:bg-green-500/20 border border-green-500/20 transition-colors"
                                            title="Mark as Resolved"
                                        >
                                            <CheckCircle size={18} />
                                        </button>
                                    )}

                                    <button
                                        onClick={() => handleDelete(item.id)}
                                        className="p-2 rounded-full bg-red-500/10 text-red-400 hover:bg-red-500/20 border border-red-500/20 transition-colors"
                                        title="Delete Item"
                                    >
                                        <Trash2 size={18} />
                                    </button>
                                </div>
                            </motion.div>
                        ))}
                    </AnimatePresence>

                    {filteredItems.length === 0 && (
                        <div className="text-center py-20 text-gray-500">
                            No items found matching your filter.
                        </div>
                    )}
                </div>
            </div>
        </div>
    );
}
