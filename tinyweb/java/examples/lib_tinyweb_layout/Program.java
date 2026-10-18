// Generated from lib_tinyweb_layout.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java PykRuntime.java
//         then run with:            java Program

public final class Program {

    private static String title;
    private static String buttons;
    private static String controls;
    private static String figures;
    private static String left;
    private static String small;
    private static String right;

    private static void clicked() {
        System.out.println("clicked");
    }

    public static void main(String[] args) {
        Tinyweb.init();
        Tinyweb.web_init(Tinyweb.web_init__default__port());
        Tinyweb.page_style(Tinyweb.page_style__default__background(), Tinyweb.page_style__default__color(), Tinyweb.page_style__default__font(), Tinyweb.page_style__default__size(), Tinyweb.page_style__default__padding(), Tinyweb.page_style__default__gap(), "center");
        title = TinywebExternal.label("Layout");
        Tinyweb.set_style(title, Tinyweb.set_style__default__background(), Tinyweb.set_style__default__color(), Tinyweb.set_style__default__border(), Tinyweb.set_style__default__radius(), Tinyweb.set_style__default__font(), 28, Tinyweb.set_style__default__padding(), Tinyweb.set_style__default__accent(), Tinyweb.set_style__default__width(), 700, Tinyweb.set_style__default__height());
        buttons = TinywebExternal.row();
        TinywebExternal.inside(buttons);
        Tinyweb.button("one", () -> { clicked(); return null; });
        Tinyweb.button("two", Tinyweb.button__default__on_click());
        TinywebExternal.outside();
        TinywebExternal.canvas(100, 40);
        controls = TinywebExternal.row();
        TinywebExternal.inside(controls);
        TinywebExternal.label("speed");
        Tinyweb.slider(0, 10, 5, Tinyweb.slider__default__on_change());
        TinywebExternal.inside(buttons);
        Tinyweb.button("three", Tinyweb.button__default__on_click());
        TinywebExternal.outside();
        figures = TinywebExternal.row();
        TinywebExternal.inside(figures);
        left = TinywebExternal.column();
        TinywebExternal.inside(left);
        small = TinywebExternal.canvas(50, 20);
        Tinyweb.set_style(small, Tinyweb.set_style__default__background(), Tinyweb.set_style__default__color(), Tinyweb.set_style__default__border(), Tinyweb.set_style__default__radius(), Tinyweb.set_style__default__font(), Tinyweb.set_style__default__size(), Tinyweb.set_style__default__padding(), Tinyweb.set_style__default__accent(), 100, Tinyweb.set_style__default__weight(), 40);
        TinywebExternal.label("stretched");
        TinywebExternal.inside(figures);
        right = TinywebExternal.column();
        TinywebExternal.inside(right);
        TinywebExternal.canvas(100, 40);
        TinywebExternal.label("as it is");
        TinywebExternal.outside();
        TinywebExternal.label("the end");
    }
}
