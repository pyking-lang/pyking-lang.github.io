// Generated from lib_tinyweb_splash_voice.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java PykRuntime.java
//         then run with:            java Program

public final class Program {

    private static void hum() {
        System.out.println(PykRuntime.<String, String>let(TinywebExternal.load_sample("piano_c1.wav"), sample__arg -> PykRuntime.<Tinyweb.Sound__Voice, String>let(Tinyweb.sound__start__default__voice(), voice__arg -> Tinyweb.sound__start(sample__arg, 0.0, 0.3, 1.0, 0.0, true, voice__arg))));
    }

    public static void main(String[] args) {
        Math.init();
        Text.init();
        Tinyweb.init();
        Tinyweb.web_init(0);
        Tinyweb.sound__tone(Tinyweb.sound__note("A4"), 0.0, 0.25, "sine", 0.5, 0.0, 0);
        Tinyweb.button("Hum", () -> { hum(); return null; });
        TinywebExternal.splash();
    }
}
