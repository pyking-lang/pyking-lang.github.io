// Generated from lib_tinyweb_style.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java PykRuntime.java
//         then run with:            java Program

public final class Program {

    private static String title;
    private static String level;
    private static String c;
    private static String ok;

    private static void pressed() {
        Tinyweb.theme("retro");
        Tinyweb.set_style(title, Tinyweb.color__black, Tinyweb.set_style__default__foreground(), Tinyweb.set_style__default__border(), -1, -1, "", -1, -1, Tinyweb.set_style__default__accent(), -1, -1, -1);
        System.out.println("now retro");
    }

    public static void main(String[] args) {
        Math.init();
        Text.init();
        Tinyweb.init();
        Tinyweb.web_init(0);
        Tinyweb.theme("paper");
        Tinyweb.theme("no such theme");
        Tinyweb.page_style(Tinyweb.color__hex(16643811), Tinyweb.color__hex(5795445), "serif", 18, 12, 16, "");
        Tinyweb.button_style(Tinyweb.color__hex(2526162), Tinyweb.color__white, Tinyweb.color__none, -1, 14, "monospace", 16, 8);
        Tinyweb.label_style(Tinyweb.color__hex(16777184), Tinyweb.color__hex(3355443), Tinyweb.color__hex(16766720), 1, 4, "sans-serif", 14, 6);
        Tinyweb.slider_style(Tinyweb.color__hex(14423100), 240, Tinyweb.color__hex(14423100), "monospace", 20);
        Tinyweb.canvas_style(Tinyweb.color__teal, 3, 10);
        title = TinywebExternal.label("Styled");
        Tinyweb.set_style(title, Tinyweb.color__navy, Tinyweb.color__white, Tinyweb.color__orange, 2, 0, "Georgia", 28, 10, Tinyweb.set_style__default__accent(), 300, -1, -1);
        level = Tinyweb.slider(0, 10, 4, Tinyweb.slider__default__on_change());
        Tinyweb.set_style(level, Tinyweb.set_style__default__background(), Tinyweb.color__hex(3050327), Tinyweb.set_style__default__border(), -1, -1, "", -1, -1, Tinyweb.set_style__default__accent(), -1, -1, -1);
        c = TinywebExternal.canvas(120, 60);
        Tinyweb.set_style(c, Tinyweb.set_style__default__background(), Tinyweb.set_style__default__foreground(), Tinyweb.color__black, 1, -1, "", -1, -1, Tinyweb.set_style__default__accent(), -1, -1, -1);
        ok = Tinyweb.button("Retro", () -> { pressed(); return null; });
        PykRuntime.ignore(PykRuntime.<Tinyweb.Color__Color, Void>let(Tinyweb.color__rgba(255, 215, 0, 0.5), background__arg -> PykRuntime.<Tinyweb.Color__Color, Void>let(Tinyweb.set_style__default__border(), border__arg -> PykRuntime.<Tinyweb.Color__Color, Void>let(Tinyweb.set_style__default__accent(), accent__arg -> PykRuntime.unit(() -> Tinyweb.set_style(ok, background__arg, Tinyweb.color__black, border__arg, -1, -1, "", -1, -1, accent__arg, -1, -1, -1))))));
    }
}
