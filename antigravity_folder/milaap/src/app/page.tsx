import Link from 'next/link';
import { Search, MapPin, ShieldCheck, Sparkles, ArrowRight, LayoutGrid } from 'lucide-react';
import MotionButton from '@/components/ui/motion-button';

export default function Home() {
  return (
    <div className="flex flex-col items-center justify-center min-h-[85vh] relative overflow-hidden">
      {/* Background Ambience */}
      <div className="absolute top-[-10%] left-1/2 -translate-x-1/2 w-[1000px] h-[500px] bg-indigo-600/20 rounded-full blur-[120px] -z-10 pointer-events-none" />
      <div className="absolute bottom-[-10%] right-[-10%] w-[800px] h-[600px] bg-pink-600/10 rounded-full blur-[120px] -z-10 pointer-events-none" />

      <div className="container flex flex-col items-center text-center gap-8 px-4 relative z-10 pt-10">

        {/* Badge */}
        <div className="inline-flex items-center gap-2 px-4 py-1.5 rounded-full bg-white/5 border border-white/10 backdrop-blur-md mb-2 animate-pulse hover:bg-white/10 transition-colors cursor-default">
          <Sparkles size={14} className="text-indigo-400" />
          <span className="text-xs font-semibold uppercase tracking-wider text-indigo-200">AI-Powered Recovery</span>
        </div>

        <h1 className="max-w-4xl mx-auto leading-tight">
          <span className="block text-white mb-2 font-bold tracking-tight text-4xl md:text-6xl">Reconnect with your</span>
          <span className="text-gradient font-extrabold block text-5xl md:text-7xl">lost belongings.</span>
        </h1>

        <p className="max-w-2xl mx-auto text-lg text-white/60 leading-relaxed">
          Milaap leverages advanced Gemini AI to instantly match lost items with found reports on campus.
          Simple, fast, and reliable.
        </p>

        <div className="flex flex-col sm:flex-row items-center gap-4 mt-4 w-full justify-center">
          <Link href="/report/lost">
            <MotionButton variant="primary" size="lg" glow>
              I Lost Something <ArrowRight size={18} />
            </MotionButton>
          </Link>
          <Link href="/browse">
            <MotionButton variant="outline" size="lg">
              <LayoutGrid size={18} /> Browse Found Items
            </MotionButton>
          </Link>
        </div>

        {/* Stats Grid */}
        <div className="grid grid-cols-1 md:grid-cols-3 gap-4 mt-20 w-full max-w-4xl">
          <div className="glass-card p-6 flex flex-col items-center text-center hover:bg-white/5 transition-colors group">
            <div className="w-12 h-12 rounded-xl bg-indigo-500/20 flex items-center justify-center mb-4 text-indigo-400 group-hover:scale-110 transition-transform">
              <Search size={24} />
            </div>
            <h3 className="text-3xl font-bold text-white mb-1">98%</h3>
            <p className="text-sm text-white/50">Match Accuracy</p>
          </div>

          <div className="glass-card p-6 flex flex-col items-center text-center hover:bg-white/5 transition-colors group">
            <div className="w-12 h-12 rounded-xl bg-pink-500/20 flex items-center justify-center mb-4 text-pink-400 group-hover:scale-110 transition-transform">
              <ShieldCheck size={24} />
            </div>
            <h3 className="text-3xl font-bold text-white mb-1">Secure</h3>
            <p className="text-sm text-white/50">Campus Verified</p>
          </div>

          <div className="glass-card p-6 flex flex-col items-center text-center hover:bg-white/5 transition-colors group">
            <div className="w-12 h-12 rounded-xl bg-violet-500/20 flex items-center justify-center mb-4 text-violet-400 group-hover:scale-110 transition-transform">
              <MapPin size={24} />
            </div>
            <h3 className="text-3xl font-bold text-white mb-1">Local</h3>
            <p className="text-sm text-white/50">Campus Wide Coverage</p>
          </div>
        </div>
      </div>
    </div>
  );
}
