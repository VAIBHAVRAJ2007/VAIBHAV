"use client";

import { useState, useEffect } from "react";
import { useRouter } from "next/navigation";
import { auth, db } from "@/lib/firebase";
import { collection, query, where, getDocs, orderBy } from "firebase/firestore";
import { onAuthStateChanged } from "firebase/auth";
import { Loader2, Sparkles, Plus, SearchCheck, MapPin, Calendar } from "lucide-react";
import Link from "next/link";
import { motion, AnimatePresence } from "framer-motion";
import MotionButton from "@/components/ui/motion-button";

function MatchFinder({ itemId, type }: { itemId: string, type: string }) {
    const [matches, setMatches] = useState<any[]>([]);
    const [loading, setLoading] = useState(false);
    const [show, setShow] = useState(false);

    const findMatches = async () => {
        setLoading(true);
        setShow(true);
        try {
            const res = await fetch("/api/matches", {
                method: "POST",
                body: JSON.stringify({ itemId, type })
            });
            const data = await res.json();
            setMatches(data.matches || []);
        } catch (e) {
            console.error(e);
        } finally {
            setLoading(false);
        }
    };

    if (!show) {
        return (
            <MotionButton
                onClick={findMatches}
                variant="primary"
                size="sm"
                className="text-xs !py-1 !px-3 bg-indigo-500/20 hover:bg-indigo-500/40 border-indigo-500/30"
            >
                <Sparkles size={12} className="mr-1" /> AI Match
            </MotionButton>
        );
    }

    return (
        <motion.div
            initial={{ opacity: 0, height: 0 }}
            animate={{ opacity: 1, height: "auto" }}
            exit={{ opacity: 0, height: 0 }}
            className="mt-3 bg-black/40 rounded-xl p-4 text-sm border border-white/10 backdrop-blur-md"
        >
            <h4 className="font-medium text-xs text-indigo-300 mb-3 flex items-center justify-between uppercase tracking-wider">
                <span className="flex items-center gap-2"><Sparkles size={12} /> AI Suggestions</span>
                <button onClick={() => setShow(false)} className="text-gray-500 hover:text-white transition-colors">Close</button>
            </h4>
            {loading ? <div className="flex justify-center py-4"><Loader2 className="animate-spin text-indigo-400" size={20} /></div> : (
                <div className="space-y-2">
                    {matches.length === 0 ? <p className="text-gray-500 text-xs text-center py-2">No matches found yet.</p> : null}
                    {matches.map(m => (
                        <div key={m.id} className="flex gap-3 items-center bg-white/5 p-2 rounded-lg hover:bg-white/10 cursor-pointer transition-colors border border-transparent hover:border-white/10">
                            <img src={m.imageUrl} className="w-10 h-10 rounded-md object-cover bg-black/20" />
                            <div className="overflow-hidden flex-1">
                                <p className="truncate font-medium text-white text-sm">{m.userTitle}</p>
                                <div className="flex justify-between items-center mt-0.5">
                                    <span className="text-[10px] text-gray-400 truncate max-w-[100px]">{m.location}</span>
                                    <span className="text-[10px] bg-green-500/20 text-green-400 px-1.5 py-0.5 rounded-full border border-green-500/20">{(m.matchScore * 10).toFixed(0)}% Match</span>
                                </div>
                            </div>
                        </div>
                    ))}
                </div>
            )}
        </motion.div>
    );
}

const containerVariants = {
    hidden: { opacity: 0 },
    visible: {
        opacity: 1,
        transition: { staggerChildren: 0.1 }
    }
};

const itemVariants = {
    hidden: { y: 20, opacity: 0 },
    visible: { y: 0, opacity: 1 }
};

export default function Dashboard() {
    const [user, setUser] = useState<any>(null);
    const [loading, setLoading] = useState(true);
    const [lostItems, setLostItems] = useState<any[]>([]);
    const [foundItems, setFoundItems] = useState<any[]>([]);
    const router = useRouter();

    useEffect(() => {
        const unsubscribe = onAuthStateChanged(auth, async (currentUser) => {
            if (!currentUser) {
                router.push("/auth/login");
                return;
            }
            setUser(currentUser);

            try {
                // Fetch My Lost Items
                const lostq = query(collection(db, "items"), where("uid", "==", currentUser.uid), where("type", "==", "lost"));
                const lostSnap = await getDocs(lostq);
                const lostDocs = lostSnap.docs.map(doc => ({ id: doc.id, ...doc.data() } as any));
                setLostItems(lostDocs.sort((a, b) => new Date(b.createdAt).getTime() - new Date(a.createdAt).getTime()));

                // Fetch My Found Items
                const foundq = query(collection(db, "items"), where("uid", "==", currentUser.uid), where("type", "==", "found"));
                const foundSnap = await getDocs(foundq);
                const foundDocs = foundSnap.docs.map(doc => ({ id: doc.id, ...doc.data() } as any));
                setFoundItems(foundDocs.sort((a, b) => new Date(b.createdAt).getTime() - new Date(a.createdAt).getTime()));

            } catch (err) {
                console.error("Error fetching items:", err);
            } finally {
                setLoading(false);
            }
        });

        return () => unsubscribe();
    }, [router]);

    if (loading) return <div className="flex items-center justify-center h-screen"><Loader2 className="animate-spin text-primary" size={40} /></div>;

    return (
        <div className="container min-h-screen relative pb-20">
            {/* Background Ambience */}
            <div className="fixed top-20 left-1/2 -translate-x-1/2 w-[800px] h-[500px] bg-indigo-900/20 rounded-full blur-[120px] -z-10 pointer-events-none" />

            <div className="flex flex-col md:flex-row items-end justify-between mb-12 gap-6">
                <div>
                    <h1 className="text-4xl font-bold bg-clip-text text-transparent bg-gradient-to-r from-white to-gray-400 mb-2">
                        Dashboard
                    </h1>
                    <p className="text-muted-foreground">Welcome back, {user?.displayName || "User"}</p>
                </div>

                <div className="flex gap-4">
                    <Link href="/report/lost">
                        <MotionButton variant="primary" glow>
                            <Plus size={18} /> Report Lost
                        </MotionButton>
                    </Link>
                    <Link href="/report/found">
                        <MotionButton variant="secondary">
                            <SearchCheck size={18} /> Report Found
                        </MotionButton>
                    </Link>
                </div>
            </div>

            {/* Stats Overview */}
            <div className="grid grid-cols-2 md:grid-cols-4 gap-4 mb-12">
                <motion.div initial={{ opacity: 0, y: 20 }} animate={{ opacity: 1, y: 0 }} transition={{ delay: 0.1 }} className="glass-card p-6 flex flex-col items-center justify-center text-center">
                    <span className="text-3xl font-bold text-white mb-1">{lostItems.length}</span>
                    <span className="text-xs text-gray-400 uppercase tracking-wider">Lost Items</span>
                </motion.div>
                <motion.div initial={{ opacity: 0, y: 20 }} animate={{ opacity: 1, y: 0 }} transition={{ delay: 0.2 }} className="glass-card p-6 flex flex-col items-center justify-center text-center">
                    <span className="text-3xl font-bold text-white mb-1">{foundItems.length}</span>
                    <span className="text-xs text-gray-400 uppercase tracking-wider">Found Items</span>
                </motion.div>
                <motion.div initial={{ opacity: 0, y: 20 }} animate={{ opacity: 1, y: 0 }} transition={{ delay: 0.3 }} className="glass-card p-6 flex flex-col items-center justify-center text-center col-span-2 md:col-span-2 bg-gradient-to-r from-indigo-900/20 to-purple-900/20 border-indigo-500/20">
                    <span className="text-lg font-medium text-indigo-300 mb-2">Active Matches</span>
                    <div className="flex -space-x-2">
                        {[1, 2, 3].map(i => <div key={i} className="w-8 h-8 rounded-full bg-indigo-500/50 border border-white/20" />)}
                        <div className="w-8 h-8 rounded-full bg-black/50 border border-white/20 flex items-center justify-center text-xs">+2</div>
                    </div>
                </motion.div>
            </div>

            <div className="grid grid-cols-1 lg:grid-cols-2 gap-8">
                {/* My Lost Reports */}
                <section>
                    <div className="flex items-center justify-between mb-6">
                        <h2 className="text-xl font-semibold text-white flex items-center gap-2">
                            <span className="w-2 h-8 bg-red-500 rounded-full inline-block"></span>
                            My Lost Items
                        </h2>
                    </div>

                    <motion.div variants={containerVariants} initial="hidden" animate="visible" className="space-y-4">
                        <AnimatePresence>
                            {lostItems.map(item => (
                                <motion.div variants={itemVariants} key={item.id} layout className="glass-card p-4 group hover:border-red-500/30 transition-colors">
                                    <div className="flex gap-4">
                                        <div className="w-24 h-24 rounded-lg overflow-hidden bg-black/40 flex-shrink-0 relative">
                                            <img src={item.imageUrl} alt={item.title} className="w-full h-full object-cover group-hover:scale-110 transition-transform duration-500" />
                                            {item.status === 'resolved' && <div className="absolute inset-0 bg-black/60 flex items-center justify-center text-green-400 font-bold text-xs uppercase">Resolved</div>}
                                        </div>
                                        <div className="flex-1 min-w-0">
                                            <div className="flex justify-between items-start">
                                                <h3 className="font-semibold text-lg text-white truncate pr-4">{item.title}</h3>
                                                <span className="text-[10px] bg-red-500/10 text-red-400 px-2 py-0.5 rounded border border-red-500/20 capitalize">{item.status || "Open"}</span>
                                            </div>

                                            <div className="flex items-center gap-4 text-xs text-gray-400 mt-2 mb-3">
                                                <span className="flex items-center gap-1"><MapPin size={12} /> {item.location}</span>
                                                <span className="flex items-center gap-1"><Calendar size={12} /> {item.date}</span>
                                            </div>

                                            <div className="flex gap-2 mb-3">
                                                {item.aiTags?.slice(0, 3).map((tag: string) => (
                                                    <span key={tag} className="text-[10px] bg-white/5 px-2 py-0.5 rounded text-gray-400 border border-white/5">#{tag}</span>
                                                ))}
                                            </div>

                                            <div className="flex items-center gap-2">
                                                <MatchFinder itemId={item.id} type={item.type} />
                                                {/* Future: Add Edit/Delete buttons here */}
                                            </div>
                                        </div>
                                    </div>
                                </motion.div>
                            ))}
                        </AnimatePresence>
                        {lostItems.length === 0 && (
                            <div className="glass-card text-center p-12 border-dashed border-2 border-white/10">
                                <p className="text-gray-500 mb-4">No lost items reported.</p>
                                <Link href="/report/lost">
                                    <MotionButton variant="outline" size="sm" className="text-indigo-300 hover:text-white border-indigo-500/30">Report an Item</MotionButton>
                                </Link>
                            </div>
                        )}
                    </motion.div>
                </section>

                {/* My Found Reports */}
                <section>
                    <div className="flex items-center justify-between mb-6">
                        <h2 className="text-xl font-semibold text-white flex items-center gap-2">
                            <span className="w-2 h-8 bg-emerald-500 rounded-full inline-block"></span>
                            Items I Found
                        </h2>
                    </div>

                    <motion.div variants={containerVariants} initial="hidden" animate="visible" className="space-y-4">
                        <AnimatePresence>
                            {foundItems.map(item => (
                                <motion.div variants={itemVariants} key={item.id} layout className="glass-card p-4 group hover:border-emerald-500/30 transition-colors">
                                    <div className="flex gap-4">
                                        <div className="w-24 h-24 rounded-lg overflow-hidden bg-black/40 flex-shrink-0 relative">
                                            <img src={item.imageUrl} alt={item.title} className="w-full h-full object-cover group-hover:scale-110 transition-transform duration-500" />
                                        </div>
                                        <div className="flex-1 min-w-0">
                                            <div className="flex justify-between items-start">
                                                <h3 className="font-semibold text-lg text-white truncate pr-4">{item.title}</h3>
                                                <span className="text-[10px] bg-emerald-500/10 text-emerald-400 px-2 py-0.5 rounded border border-emerald-500/20 capitalize">{item.status || "Open"}</span>
                                            </div>

                                            <div className="flex items-center gap-4 text-xs text-gray-400 mt-2 mb-3">
                                                <span className="flex items-center gap-1"><MapPin size={12} /> {item.location}</span>
                                                <span className="flex items-center gap-1"><Calendar size={12} /> {item.date}</span>
                                            </div>

                                            <div className="flex gap-2 mb-3">
                                                {item.aiTags?.slice(0, 3).map((tag: string) => (
                                                    <span key={tag} className="text-[10px] bg-white/5 px-2 py-0.5 rounded text-gray-400 border border-white/5">#{tag}</span>
                                                ))}
                                            </div>
                                        </div>
                                    </div>
                                </motion.div>
                            ))}
                        </AnimatePresence>
                        {foundItems.length === 0 && (
                            <div className="glass-card text-center p-12 border-dashed border-2 border-white/10">
                                <p className="text-gray-500 mb-4">You haven&apos;t reported finding any items.</p>
                                <Link href="/report/found">
                                    <MotionButton variant="outline" size="sm" className="text-emerald-300 hover:text-white border-emerald-500/30">Report Found Item</MotionButton>
                                </Link>
                            </div>
                        )}
                    </motion.div>
                </section>
            </div>
        </div>
    );
}

