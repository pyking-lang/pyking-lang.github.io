// Generated from lib_tinyweb_input.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java PykRuntime.java
//         then run with:            java Program

public final class Program {

    private static String c;
    private static String status;

    private static void clicked(final int x, final int y) {
        Tinyweb.set_text(status, "clicked at " + String.valueOf(x) + ", " + String.valueOf(y));
        Tinyweb.circle(c, x, y, 5, Tinyweb.color__blue, Tinyweb.circle__default__stroke(), 1, 1.0, Tinyweb.circle__default__paint(), Tinyweb.circle__default__style());
    }

    private static void pressed(final String key) {
        System.out.println("key [" + key + "]");
        if (key.equals("Enter")) {
            Tinyweb.play_file("snare1.wav");
        }
    }

    private static void moved(final int value) {
        Tinyweb.set_text(status, "slider at " + String.valueOf(value));
    }

    public static void main(String[] args) {
        Math.init();
        Text.init();
        Tinyweb.init();
        Tinyweb.web_init(0);
        c = TinywebExternal.canvas(300, 200);
        Tinyweb.rect(c, 0, 0, 300, 200, Tinyweb.color__hex(15658734), Tinyweb.rect__default__stroke(), 1, 1.0, Tinyweb.rect__default__paint(), Tinyweb.rect__default__style(), 0);
        Tinyweb.line(c, 0, 0, 300, 200, Tinyweb.line__default__stroke(), 1, 1.0, Tinyweb.line__default__style());
        Tinyweb.line(c, 0, 200, 300, 0, Tinyweb.color__red, 3, 1.0, Tinyweb.line__default__style());
        Tinyweb.text(c, 10, 10, "click \"me\"", Tinyweb.text__default__fill(), 20, "", "left", false, 1.0, "top", Tinyweb.text__default__stroke(), 1, Tinyweb.text__default__paint(), Tinyweb.text__default__style());
        status = TinywebExternal.label("nothing yet");
        Tinyweb.on_click(c, (p$1, p$2) -> { clicked(p$1, p$2); return null; });
        TinywebExternal.on_key(c$1 -> pressed(c$1));
        Tinyweb.slider(0, 10, 5, p$1 -> { moved(p$1); return null; });
        Tinyweb.slider(1, 3, 2, Tinyweb.slider__default__on_change());
        TinywebExternal.splash();
    }
}
