// Generated from lib_tinyweb_splash_off.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java PykRuntime.java
//         then run with:            java Program

public final class Program {

    private static String snare;

    private static void hit() {
        Tinyweb.play(snare, Tinyweb.play__default__at(), 0.5, Tinyweb.play__default__rate());
        System.out.println("hit");
    }

    public static void main(String[] args) {
        Tinyweb.init();
        Tinyweb.web_init(0);
        TinywebExternal.set_splash("");
        snare = TinywebExternal.load_sample("snare1.wav");
        Tinyweb.button("Hit", () -> { hit(); return null; });
        TinywebExternal.splash();
    }
}
