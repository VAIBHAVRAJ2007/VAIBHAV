import { NextRequest, NextResponse } from "next/server";
import { db } from "@/lib/firebase";
import { collection, query, where, getDocs, doc, getDoc } from "firebase/firestore";

export async function POST(req: NextRequest) {
    try {
        const { itemId, type } = await req.json();

        if (!itemId || !type) {
            return NextResponse.json({ error: "Missing itemId or type" }, { status: 400 });
        }

        // 1. Get the source item to find matches FOR
        const itemRef = doc(db, "items", itemId);
        const itemSnap = await getDoc(itemRef);

        if (!itemSnap.exists()) {
            return NextResponse.json({ error: "Item not found" }, { status: 404 });
        }

        const sourceItem = itemSnap.data();
        const targetType = type === 'lost' ? 'found' : 'lost';

        // 2. Query potential matches (same category, opposite type)
        // Basic filtering first
        const q = query(
            collection(db, "items"),
            where("type", "==", targetType),
            where("aiCategory", "==", sourceItem.aiCategory || sourceItem.userCategory)
            // Fallback to user category if AI didn't run or failed
        );

        const querySnapshot = await getDocs(q);
        const candidates = querySnapshot.docs.map(doc => ({ id: doc.id, ...doc.data() }));

        // 3. Rank by Tag Overlap (Simple "AI" Matching)
        const sourceTags = new Set([
            ...(sourceItem.aiTags || []).map((t: string) => t.toLowerCase()),
            ...(sourceItem.aiColors || []).map((c: string) => c.toLowerCase()),
            sourceItem.userTitle.toLowerCase()
        ]);

        const scoredMatches = candidates.map((candidate: any) => {
            const candidateTags = [
                ...(candidate.aiTags || []).map((t: string) => t.toLowerCase()),
                ...(candidate.aiColors || []).map((c: string) => c.toLowerCase()),
                candidate.userTitle.toLowerCase()
            ];

            // Count overlaps
            let score = 0;
            candidateTags.forEach(tag => {
                if (sourceTags.has(tag)) score += 10;
                // Partial match?
                sourceTags.forEach(sTag => {
                    if (tag.includes(sTag) || sTag.includes(tag)) score += 2;
                });
            });

            return { ...candidate, matchScore: score };
        });

        // Filter and Sort
        const finalMatches = scoredMatches
            .filter(m => m.matchScore > 2) // Minimum threshold
            .sort((a, b) => b.matchScore - a.matchScore)
            .slice(0, 5); // Top 5

        return NextResponse.json({ matches: finalMatches });

    } catch (error: any) {
        console.error("Match API Error:", error);
        return NextResponse.json({ error: error.message }, { status: 500 });
    }
}
