// Generated from lib_tinyweb_splash.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java PykRuntime.java
//         then run with:            java Program

public final class Program {

    private static String c;
    private static String kick;

    private static void again() {
        Tinyweb.play(kick, Tinyweb.play__default__at(), Tinyweb.play__default__volume(), Tinyweb.play__default__rate());
        System.out.println("kick again");
    }

    public static void main(String[] args) {
        Tinyweb.init();
        Tinyweb.web_init(0);
        TinywebExternal.set_splash("Click for drums");
        c = TinywebExternal.canvas(200, 100);
        Tinyweb.clear(c, "#202020");
        kick = TinywebExternal.load_sample("kick1.wav");
        Tinyweb.play(kick, 0.25, Tinyweb.play__default__volume(), Tinyweb.play__default__rate());
        Tinyweb.circle(c, 100, 50, 30, "#ffcc00", Tinyweb.circle__default__outline(), Tinyweb.circle__default__outline_width(), Tinyweb.circle__default__alpha());
        Tinyweb.button("Again", () -> { again(); return null; });
        System.out.println("built the page");
        TinywebExternal.splash();
    }
}
