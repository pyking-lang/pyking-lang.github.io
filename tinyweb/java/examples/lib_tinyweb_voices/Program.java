// Generated from lib_tinyweb_voices.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java PykRuntime.java
//         then run with:            java Program

public final class Program {

    private static String kick;
    private static String piano;
    private static Tinyweb.Sound__Voice soft;
    private static String hum;
    private static String other;

    private static void quieter() {
        Tinyweb.sound__fade(hum, 0.0, 2.0);
        System.out.println("fading");
    }

    private static void stop() {
        Tinyweb.sound__stop(other, 0.0);
        Tinyweb.sound__stop(hum, 3.0);
        System.out.println("stopped");
    }

    private static void silence() {
        Tinyweb.sound__stop_all();
        System.out.println("silence");
    }

    public static void main(String[] args) {
        Math.init();
        Text.init();
        Tinyweb.init();
        Tinyweb.web_init(0);
        kick = TinywebExternal.load_sample("kick1.wav");
        piano = TinywebExternal.load_sample("piano_c1.wav");
        Tinyweb.sound__master_volume(0.8);
        Tinyweb.sound__channel_style(1, 0.7, -0.5, 0.4, 0.25, 0.5, 0.0, 0.0);
        Tinyweb.sound__channel_style(2, 1.0, 0.0, 0.0, 0.3, 0.35, 0.6, 1200.0);
        Tinyweb.sound__channel_style(1, 0.9, 0.0, 0.0, 0.3, 0.35, 0.0, 0.0);
        Tinyweb.play(kick, 0.0, 1.0, 1.0, 0.0, Tinyweb.play__default__voice());
        Tinyweb.play(kick, 0.5, 0.5, 2.0, 1.0, Tinyweb.play__default__voice());
        soft = new Tinyweb.Sound__Voice(0.25, 1.0, 0.0, 1, false, false);
        Tinyweb.play(kick, 0.0, 1.0, 1.0, 0.0, soft);
        Tinyweb.play(kick, 0.0, 0.75, 1.0, 0.0, soft);
        Tinyweb.play(piano, 0.0, 1.0, 1.0, 0.0, new Tinyweb.Sound__Voice(1.0, 1.0, 0.0, 2, false, true));
        hum = Tinyweb.sound__start(piano, 0.0, 0.3, 1.0, 0.0, true, Tinyweb.sound__start__default__voice());
        other = Tinyweb.sound__start(piano, 1.0, 1.0, 1.0, 0.0, false, new Tinyweb.Sound__Voice(1.0, 0.5, 0.0, 2, true, false));
        System.out.println(hum + " " + other);
        Tinyweb.sound__tone(440.0, 0.0, 0.5, "sine", 0.5, 0.0, 0);
        Tinyweb.sound__tone(Tinyweb.sound__note("C5"), 0.25, 0.125, "square", 0.2, 0.5, 1);
        System.out.println(PykRuntime.floatStr(Tinyweb.sound__note("A4")) + " " + PykRuntime.floatStr(Tinyweb.sound__note("C4")) + " " + PykRuntime.floatStr(Tinyweb.sound__note("C#4")) + " " + PykRuntime.floatStr(Tinyweb.sound__note("Db4")) + " " + PykRuntime.floatStr(Tinyweb.sound__note("H2")) + " " + PykRuntime.floatStr(Tinyweb.sound__note("C")));
        System.out.println(PykRuntime.floatStr(Tinyweb.sound__rate_of("C5", "C4")) + " " + PykRuntime.floatStr(Tinyweb.sound__rate_of("C3", "C4")) + " " + PykRuntime.floatStr(Tinyweb.sound__rate_of("G4", "G3")) + " " + PykRuntime.floatStr(Tinyweb.sound__rate_of("nothing", "C4")));
        Tinyweb.button("Quieter", () -> { quieter(); return null; });
        Tinyweb.button("Stop", () -> { stop(); return null; });
        Tinyweb.button("Silence", () -> { silence(); return null; });
        TinywebExternal.splash();
    }
}
