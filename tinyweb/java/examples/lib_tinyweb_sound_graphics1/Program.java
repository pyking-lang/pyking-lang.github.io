// Generated from lib_tinyweb_sound_graphics1.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java PykRuntime.java
//         then run with:            java Program

public final class Program {

    private static String kick;
    private static String snare;
    private static String canvas;
    private static int presses;

    private static void play_kick() {
        Tinyweb.play(kick, 0.0, 1.0, 1.0, 0.0, Tinyweb.play__default__voice());
    }

    private static void play_sound() {
        presses = presses + 1;
        System.out.println("snare, press " + String.valueOf(presses));
        Tinyweb.play(snare, 0.0, 0.5, 1.0, 0.0, Tinyweb.play__default__voice());
    }

    public static void main(String[] args) {
        Math.init();
        Text.init();
        Tinyweb.init();
        Tinyweb.web_init(0);
        kick = TinywebExternal.load_sample("kick1.wav");
        snare = TinywebExternal.load_sample("snare1.wav");
        canvas = TinywebExternal.canvas(400, 200);
        Tinyweb.circle(canvas, 100, 50, 30, Tinyweb.color__red, Tinyweb.circle__default__stroke(), 1, 1.0, Tinyweb.circle__default__paint(), Tinyweb.circle__default__style());
        Tinyweb.circle(canvas, 100, 50, 20, Tinyweb.circle__default__fill(), Tinyweb.circle__default__stroke(), 1, 1.0, Tinyweb.circle__default__paint(), Tinyweb.circle__default__style());
        presses = 0;
        Tinyweb.button("Play kick", () -> { play_kick(); return null; });
        Tinyweb.button("Play snare", () -> { play_sound(); return null; });
        Tinyweb.button("Does nothing", Tinyweb.button__default__on_click());
        System.out.println("built the page");
        TinywebExternal.splash();
    }
}
