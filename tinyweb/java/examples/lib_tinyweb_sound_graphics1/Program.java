// Generated from lib_tinyweb_sound_graphics1.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java
//         then run with:            java Program

public final class Program {

    // What the top level binds, where every method can read it; the
    // top level in `main` below is what fills each of them in.
    private static int kick;
    private static int snare;
    private static int canvas;
    private static int presses;

    private static void play_kick() {
        Tinyweb.play(kick, Tinyweb.play__default__at(), Tinyweb.play__default__volume(), Tinyweb.play__default__rate());
    }

    private static void play_sound() {
        presses = presses + 1;
        System.out.println("snare, press " + String.valueOf(presses));
        Tinyweb.play(snare, Tinyweb.play__default__at(), 0.5, Tinyweb.play__default__rate());
    }

    public static void main(String[] args) {
        // Every module of the program, in the order they must run.
        Tinyweb.init();

        TinywebExternal.web_init(0);
        kick = TinywebExternal.load_sample("kick1.wav");
        snare = TinywebExternal.load_sample("snare1.wav");
        canvas = TinywebExternal.canvas(400, 200);
        Tinyweb.circle(canvas, 100, 50, 30, "#ff0000");
        Tinyweb.circle(canvas, 100, 50, 20, Tinyweb.circle__default__color());
        presses = 0;
        Tinyweb.button("Play kick", () -> play_kick());
        Tinyweb.button("Play snare", () -> play_sound());
        Tinyweb.button("Does nothing", Tinyweb.button__default__on_click());
        System.out.println("built the page");
    }
}
