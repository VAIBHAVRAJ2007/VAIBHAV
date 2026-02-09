'use client';

import { useState, useEffect } from "react";
import { Search, MapPin, Calendar, Tag, Filter, ImageIcon } from "lucide-react";
import { cn } from "@/lib/utils";

interface Item {
    id: string;
    type: 'lost' | 'found';
    userTitle?: string;
    userCategory?: string;
    imageUrl?: string;
    location?: string;
    date?: string;
    aiTitle?: string;
    aiTags?: string[];
    status: string;
}

export default function BrowsePage() {
    const [items, setItems] = useState<Item[]>([]);
    const [loading, setLoading] = useState(true);
    const [search, setSearch] = useState("");
    const [filterType, setFilterType] = useState<'all' | 'lost' | 'found'>("all");

    const fetchItems = async () => {
        setLoading(true);
        try {
            const params = new URLSearchParams();
            if (filterType !== 'all') params.append("type", filterType);
            if (search) params.append("search", search);

            const res = await fetch(`/api/items?${params.toString()}`);
            const data = await res.json();

            if (data.items) {
                setItems(data.items);
            }
        } catch (error) {
            console.error("Failed to fetch items:", error);
        } finally {
            setLoading(false);
        }
    };

    // Debounce search
    useEffect(() => {
        const timer = setTimeout(() => {
            fetchItems();
        }, 500);
        return () => clearTimeout(timer);
    }, [search, filterType]);

    return (
        <div className="min-h-screen flex flex-col">
            <div className="container mx-auto px-4 py-8 flex-grow page-container">
                <div className="text-center mb-10">
                    <h1 className="text-3xl md:text-5xl font-bold mb-4">
                        Browse <span className="text-gradient">Items</span>
                    </h1>
                    <p className="text-muted-foreground text-lg max-w-2xl mx-auto">
                        Search through lost and found items using our AI-powered matching system.
                    </p>
                </div>

                {/* Search & Filter Controls */}
                <div className="glass-card mb-10 p-4 md:p-6 sticky top-[calc(var(--header-height)+1rem)] z-40 shadow-xl backdrop-blur-xl border-white/10">
                    <div className="flex flex-col md:flex-row gap-4 items-center justify-between">
                        {/* Search Input */}
                        <div className="w-full md:flex-1 relative">
                            <input
                                type="text"
                                placeholder="Search by name, color, location..."
                                value={search}
                                onChange={(e) => setSearch(e.target.value)}
                                className="input-field w-full pl-10 bg-black/20 focus:bg-black/40 border-white/10 text-white placeholder:text-gray-400"
                            />
                            <Search className="absolute left-3 top-1/2 -translate-y-1/2 text-gray-400 w-5 h-5" />
                        </div>

                        {/* Filter Tabs */}
                        <div className="flex gap-1 p-1 bg-black/20 rounded-lg border border-white/5 w-full md:w-auto overflow-x-auto">
                            {(['all', 'lost', 'found'] as const).map((type) => (
                                <button
                                    key={type}
                                    onClick={() => setFilterType(type)}
                                    className={cn(
                                        "px-6 py-2 rounded-md text-sm font-medium transition-all whitespace-nowrap flex-1 md:flex-none",
                                        filterType === type
                                            ? "bg-primary text-white shadow-lg"
                                            : "text-gray-400 hover:text-white hover:bg-white/5"
                                    )}
                                >
                                    {type.charAt(0).toUpperCase() + type.slice(1)}
                                </button>
                            ))}
                        </div>
                    </div>
                </div>

                {/* Results Grid */}
                {loading ? (
                    <div className="flex flex-col items-center justify-center py-20 gap-4">
                        <div className="w-12 h-12 border-4 border-primary border-t-transparent rounded-full animate-spin" />
                        <p className="text-muted-foreground animate-pulse">Searching...</p>
                    </div>
                ) : items.length === 0 ? (
                    <div className="text-center py-20 glass-card border-dashed border-2 border-white/10 rounded-xl">
                        <div className="w-16 h-16 bg-white/5 rounded-full flex items-center justify-center mx-auto mb-4">
                            <Search className="w-8 h-8 text-muted-foreground" />
                        </div>
                        <h3 className="text-xl font-semibold text-white mb-2">No items found</h3>
                        <p className="text-gray-400">Try adjusting your search terms or filters.</p>
                    </div>
                ) : (
                    <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-3 gap-6">
                        {items.map((item) => (
                            <div key={item.id} className="glass-card group hover:-translate-y-1 transition-all duration-300 hover:shadow-2xl hover:shadow-primary/10 hover:border-primary/30 flex flex-col h-full">
                                {/* Image Container */}
                                <div className="relative aspect-video rounded-t-lg overflow-hidden bg-black/40 border-b border-white/5">
                                    <div className={cn(
                                        "absolute top-3 right-3 px-3 py-1 rounded-full text-xs font-bold uppercase tracking-wide shadow-lg z-10 backdrop-blur-md",
                                        item.type === 'lost' ? 'bg-red-500/90 text-white' : 'bg-emerald-500/90 text-white'
                                    )}>
                                        {item.type}
                                    </div>

                                    {item.imageUrl ? (
                                        <img
                                            src={item.imageUrl}
                                            alt={item.userTitle || "Item"}
                                            className="w-full h-full object-cover group-hover:scale-105 transition-transform duration-700"
                                        />
                                    ) : (
                                        <div className="w-full h-full flex flex-col items-center justify-center text-gray-500 bg-white/5">
                                            <ImageIcon className="w-10 h-10 mb-2 opacity-50" />
                                            <span className="text-xs uppercase tracking-widest opacity-50">No Image</span>
                                        </div>
                                    )}
                                </div>

                                {/* Content */}
                                <div className="p-5 flex flex-col flex-grow">
                                    <div className="flex justify-between items-start mb-3">
                                        <h3 className="font-bold text-lg leading-tight line-clamp-1 text-white group-hover:text-primary transition-colors" title={item.userTitle}>
                                            {item.userTitle || item.aiTitle || "Untitled Item"}
                                        </h3>
                                    </div>

                                    <div className="space-y-2 mb-4 flex-grow">
                                        <p className="text-sm text-gray-400 flex items-center gap-2">
                                            <MapPin className="w-4 h-4 text-primary shrink-0" />
                                            <span className="truncate">{item.location || "Location unknown"}</span>
                                        </p>
                                        <p className="text-sm text-gray-400 flex items-center gap-2">
                                            <Calendar className="w-4 h-4 text-primary shrink-0" />
                                            <span>{item.date ? new Date(item.date).toLocaleDateString(undefined, { month: 'short', day: 'numeric', year: 'numeric' }) : 'Date unknown'}</span>
                                        </p>
                                    </div>

                                    <div className="flex flex-wrap gap-2 mb-4">
                                        {item.aiTags?.slice(0, 3).map((tag, i) => (
                                            <span key={i} className="text-xs px-2.5 py-1 rounded-full bg-white/5 border border-white/10 text-gray-300 flex items-center gap-1 group-hover:border-primary/20 transition-colors">
                                                <Tag size={10} className="opacity-50" />
                                                #{tag}
                                            </span>
                                        ))}
                                    </div>

                                    <button className="w-full py-2.5 rounded-lg border border-white/10 bg-white/5 hover:bg-primary hover:border-primary text-white transition-all text-sm font-medium mt-auto group-hover:shadow-lg group-hover:shadow-primary/20">
                                        View Details
                                    </button>
                                </div>
                            </div>
                        ))}
                    </div>
                )}
            </div>
        </div>
    );
}
