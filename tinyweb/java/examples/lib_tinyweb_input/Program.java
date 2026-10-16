// Generated from lib_tinyweb_input.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java
//         then run with:            java Program

public final class Program {

    // What the top level binds, where every method can read it; the
    // top level in `main` below is what fills each of them in.
    private static int c;
    private static int status;

    private static void clicked(final int x, final int y) {
        TinywebExternal.set_label(status, "clicked at " + String.valueOf(x) + ", " + String.valueOf(y));
        Tinyweb.circle(c, x, y, 5, "blue");
    }

    private static void pressed(final String key) {
        System.out.println("key [" + key + "]");
        if (key.equals("Enter")) {
            Tinyweb.play_file("snare1.wav");
        }
    }

    private static void moved(final int value) {
        TinywebExternal.set_label(status, "slider at " + String.valueOf(value));
    }

    public static void main(String[] args) {
        // Every module of the program, in the order they must run.
        Tinyweb.init();

        TinywebExternal.web_init(0);
        c = TinywebExternal.canvas(300, 200);
        Tinyweb.rect(c, 0, 0, 300, 200, "#eeeeee");
        Tinyweb.line(c, 0, 0, 300, 200, Tinyweb.line__default__color(), Tinyweb.line__default__width());
        Tinyweb.line(c, 0, 200, 300, 0, "red", 3);
        Tinyweb.text(c, 10, 10, "click \"me\"", Tinyweb.text__default__color(), 20);
        status = TinywebExternal.label("nothing yet");
        TinywebExternal.on_mouse(c, (p$1, p$2) -> clicked(p$1, p$2));
        TinywebExternal.on_key((p$1) -> pressed(p$1));
        Tinyweb.slider(0, 10, 5, (p$1) -> moved(p$1));
        Tinyweb.slider(1, 3, 2, Tinyweb.slider__default__on_change());
    }
}
