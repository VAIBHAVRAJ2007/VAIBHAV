export default function Footer() {
    return (
        <footer className="glass" style={{ borderTop: '1px solid var(--card-border)', padding: '2rem 0', marginTop: 'auto' }}>
            <div className="container">
                <div className="flex flex-col md:flex-row justify-between items-center gap-4">
                    <div className="flex items-center gap-2">
                        <span className="font-bold text-lg">Milaap</span>
                        <span className="text-muted-foreground text-sm">© 2024 Milaap Inc.</span>
                    </div>

                    <div className="flex items-center gap-6 text-sm text-muted-foreground">
                        <a href="#" className="hover:text-white transition-colors">Privacy Policy</a>
                        <a href="#" className="hover:text-white transition-colors">Terms of Service</a>
                        <a href="#" className="hover:text-white transition-colors">Contact Support</a>
                    </div>
                </div>
            </div>
        </footer>
    );
}
