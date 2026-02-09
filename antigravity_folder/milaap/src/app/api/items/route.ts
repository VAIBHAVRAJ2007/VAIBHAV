import { NextRequest, NextResponse } from "next/server";
import { db } from "@/lib/firebase"; // This imports the client SDK - this works in Next.js API routes but effectively runs as client for auth? 
// Ideally we use firebase-admin for server-side, but client SDK is easier for hackathons if we don't care about rigorous backend auth checks (using client uid passed in body is insecure in production but okay here).
// Wait, the `lib/firebase.ts` exports `getFirestore(app)` which is client SDk. 
// For API routes, it's better to use `firebase-admin` or just use the client SDK if triggered from server (Node.js env). standard firebase SDK works in Node.js too.

import { collection, addDoc, getDocs, QueryDocumentSnapshot } from "firebase/firestore";
import { analyzeImage } from "@/lib/gemini";

// Helper to fetch image and convert to base64
async function fetchImageBase64(url: string) {
    const response = await fetch(url);
    const arrayBuffer = await response.arrayBuffer();
    return Buffer.from(arrayBuffer).toString('base64');
}

export async function POST(req: NextRequest) {
    try {
        const body = await req.json();
        const { type, title, category, location, date, imageUrl, uid } = body;

        if (!imageUrl) {
            return NextResponse.json({ error: "Image URL required" }, { status: 400 });
        }

        // 1. Analyze with Gemini
        // We need to fetch the image from the URL to send to Gemini
        console.log("Fetching image for analysis...");
        const base64Image = await fetchImageBase64(imageUrl);
        console.log("Image fetched. analyzing...");

        const aiAnalysis = await analyzeImage(base64Image, "image/jpeg"); // Assuming jpeg/png

        const itemData = {
            type,
            userTitle: title,
            userCategory: category,
            location,
            date,
            imageUrl,
            uid,
            status: "open",
            createdAt: new Date().toISOString(),
            // AI Data
            aiTitle: aiAnalysis?.item || title,
            aiCategory: aiAnalysis?.category || category,
            aiTags: aiAnalysis?.tags || [],
            aiColors: aiAnalysis?.colors || [],
            aiDescription: aiAnalysis?.description || "",
            // Use AI data as primary for search if available
            searchKeywords: [
                title,
                category,
                location,
                ...(aiAnalysis?.tags || []),
                ...(aiAnalysis?.colors || [])
            ].map(s => s.toLowerCase())
        };

        // 2. Save to Firestore
        const docRef = await addDoc(collection(db, "items"), itemData);

        return NextResponse.json({ success: true, id: docRef.id, analysis: aiAnalysis });

    } catch (error: any) {
        console.error("API Error:", error);
        return NextResponse.json({ error: error.message }, { status: 500 });
    }
}

export async function GET(req: NextRequest) {
    try {
        const { searchParams } = new URL(req.url);
        const type = searchParams.get("type"); // 'lost' or 'found'
        const search = searchParams.get("search")?.toLowerCase();

        let q = collection(db, "items");
        // We will filter in memory for search/type to avoid complex index requirements for now, 
        // or just simple type filtering.
        // Firestore requires composite indexes for multiple fields. 
        // To keep it simple and robust for the hackathon: Fetch all (or limit 50) and filter in JS if needed, 
        // OR use basic single-field indexes.

        // Let's just fetch by collection content. 
        // Ideally: where("status", "==", "open")

        const querySnapshot = await getDocs(q);
        let items = querySnapshot.docs.map(doc => ({ id: doc.id, ...doc.data() } as any));

        // 1. Filter by Status
        items = items.filter(item => item.status !== "solved");

        // 2. Filter by Type
        if (type && type !== "all") {
            items = items.filter(item => item.type === type);
        }

        // 3. Filter by Search (Client-side fuzzy match)
        if (search) {
            items = items.filter(item =>
                item.userTitle?.toLowerCase().includes(search) ||
                item.userCategory?.toLowerCase().includes(search) ||
                item.location?.toLowerCase().includes(search) ||
                item.aiTags?.some((tag: string) => tag.toLowerCase().includes(search))
            );
        }

        // Sort by Date (newest first)
        items.sort((a, b) => new Date(b.createdAt).getTime() - new Date(a.createdAt).getTime());

        return NextResponse.json({ items });
    } catch (error: any) {
        console.error("Fetch Error:", error);
        return NextResponse.json({ error: error.message }, { status: 500 });
    }
}
