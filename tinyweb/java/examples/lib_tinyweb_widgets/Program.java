// Generated from lib_tinyweb_widgets.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java PykRuntime.java
//         then run with:            java Program

public final class Program {

    private static String shown;
    private static String box;
    private static String frame_based;
    private static String count;
    private static String speed;

    private static void trails(final boolean on) {
        TinywebExternal.set_label(shown, on ? "trails on" : "trails off");
    }

    private static void mode(final String title) {
        TinywebExternal.set_label(shown, "mode: " + title);
    }

    private static void entered(final String name) {
        TinywebExternal.set_label(shown, "hello, " + name);
    }

    private static void balls(final int n) {
        TinywebExternal.set_label(shown, String.valueOf(n) + " balls");
    }

    public static void main(String[] args) {
        Tinyweb.init();
        Tinyweb.web_init(0);
        shown = TinywebExternal.label("nothing yet");
        box = Tinyweb.checkbox("Trails", Tinyweb.checkbox__default__checked(), p$1 -> { trails(p$1); return null; });
        Tinyweb.checkbox("Slow frames", true, Tinyweb.checkbox__default__on_change());
        Tinyweb.radio("mode", "time-based", Tinyweb.radio__default__chosen(), p$1 -> { mode(p$1); return null; });
        frame_based = Tinyweb.radio("mode", "frame-based", Tinyweb.radio__default__chosen(), p$1 -> { mode(p$1); return null; });
        Tinyweb.radio("speed", "slow", Tinyweb.radio__default__chosen(), Tinyweb.radio__default__on_pick());
        Tinyweb.radio("speed", "fast", true, Tinyweb.radio__default__on_pick());
        Tinyweb.text_input("your name", p$1 -> { entered(p$1); return null; });
        Tinyweb.text_input(Tinyweb.text_input__default__placeholder(), Tinyweb.text_input__default__on_enter());
        count = Tinyweb.number_input(1, 20, 3, p$1 -> { balls(p$1); return null; });
        speed = Tinyweb.slider(0, 10, 5, Tinyweb.slider__default__on_change());
        TinywebExternal.set_checked(box, true);
        TinywebExternal.set_checked(frame_based, true);
        TinywebExternal.set_value(count, 5);
        TinywebExternal.set_value(speed, 8);
        System.out.println(frame_based);
    }
}
