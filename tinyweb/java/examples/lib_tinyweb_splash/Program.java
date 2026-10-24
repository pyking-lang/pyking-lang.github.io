// Generated from lib_tinyweb_splash.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java PykRuntime.java
//         then run with:            java Program

public final class Program {

    private static String c;
    private static String kick;

    private static void again() {
        Tinyweb.play(kick, 0.0, 1.0, 1.0, 0.0, Tinyweb.play__default__voice());
        System.out.println("kick again");
    }

    public static void main(String[] args) {
        Math.init();
        Text.init();
        Tinyweb.init();
        Tinyweb.web_init(0);
        TinywebExternal.set_splash("Click for drums");
        c = TinywebExternal.canvas(200, 100);
        Tinyweb.clear(c, Tinyweb.color__hex(2105376));
        kick = TinywebExternal.load_sample("kick1.wav");
        Tinyweb.play(kick, 0.25, 1.0, 1.0, 0.0, Tinyweb.play__default__voice());
        Tinyweb.circle(c, 100, 50, 30, Tinyweb.color__hex(16763904), Tinyweb.circle__default__stroke(), 1, 1.0, Tinyweb.circle__default__paint(), Tinyweb.circle__default__style());
        Tinyweb.button("Again", () -> { again(); return null; });
        System.out.println("built the page");
        TinywebExternal.splash();
    }
}
