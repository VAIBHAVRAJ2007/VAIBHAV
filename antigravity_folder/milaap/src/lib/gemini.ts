import { GoogleGenerativeAI } from "@google/generative-ai";

const genAI = new GoogleGenerativeAI(process.env.GEMINI_API_KEY || "");

export async function analyzeImage(imageBase64: string, mimeType: string) {
    try {
        const model = genAI.getGenerativeModel({ model: "gemini-1.5-flash" });

        const prompt = `
      Analyze this image of a lost/found item. 
      Return a JSON object with the following fields:
      - "item": Short name of the item (e.g. "Black Leather Wallet")
      - "category": Best fitting category (Electronics, Clothing, Accessories, ID Cards, Keys, Other)
      - "colors": Array of dominant colors
      - "description": specific visual details (brand, scratches, unique features)
      - "tags": Array of 10 search keywords
      
      Output ONLY raw JSON. Do not use markdown backticks.
    `;

        const imagePart = {
            inlineData: {
                data: imageBase64,
                mimeType: mimeType,
            },
        };

        const result = await model.generateContent([prompt, imagePart]);
        const response = await result.response;
        const text = response.text();

        // Clean up markdown if present (just in case)
        const jsonStr = text.replace(/```json/g, "").replace(/```/g, "").trim();

        return JSON.parse(jsonStr);
    } catch (error) {
        console.error("Gemini Analysis Error:", error);
        return null; // Fallback or throw
    }
}
