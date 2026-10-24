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
    private static String notes;

    private static void clicked() {
        System.out.println("clicked");
    }

    private static void edited(final String words) {
        System.out.println("notes:" + " " + words);
    }

    public static void main(String[] args) {
        Math.init();
        Text.init();
        Tinyweb.init();
        Tinyweb.web_init(0);
        Tinyweb.page_style(Tinyweb.page_style__default__background(), Tinyweb.page_style__default__foreground(), "", -1, -1, -1, "center");
        title = TinywebExternal.label("Layout");
        Tinyweb.set_style(title, Tinyweb.set_style__default__background(), Tinyweb.set_style__default__foreground(), Tinyweb.set_style__default__border(), -1, -1, "", 28, -1, Tinyweb.set_style__default__accent(), -1, 700, -1);
        buttons = Tinyweb.layout__row();
        Tinyweb.layout__inside(buttons);
        Tinyweb.button("one", () -> { clicked(); return null; });
        Tinyweb.button("two", Tinyweb.button__default__on_click());
        Tinyweb.layout__outside();
        TinywebExternal.canvas(100, 40);
        controls = Tinyweb.layout__row();
        Tinyweb.layout__inside(controls);
        TinywebExternal.label("speed");
        Tinyweb.slider(0, 10, 5, Tinyweb.slider__default__on_change());
        Tinyweb.layout__inside(buttons);
        Tinyweb.button("three", Tinyweb.button__default__on_click());
        Tinyweb.layout__outside();
        figures = Tinyweb.layout__row();
        Tinyweb.layout__inside(figures);
        left = Tinyweb.layout__column();
        Tinyweb.layout__inside(left);
        small = TinywebExternal.canvas(50, 20);
        Tinyweb.set_style(small, Tinyweb.set_style__default__background(), Tinyweb.set_style__default__foreground(), Tinyweb.set_style__default__border(), -1, -1, "", -1, -1, Tinyweb.set_style__default__accent(), 100, -1, 40);
        TinywebExternal.label("stretched");
        Tinyweb.layout__inside(figures);
        right = Tinyweb.layout__column();
        Tinyweb.layout__inside(right);
        TinywebExternal.canvas(100, 40);
        TinywebExternal.label("as it is");
        Tinyweb.layout__outside();
        notes = Tinyweb.layout__text_area("first line\nsecond \"line\"", 3, 30, p$1 -> { edited(p$1); return null; });
        Tinyweb.layout__text_area("", 4, 40, Tinyweb.layout__text_area__default__on_change());
        TinywebExternal.label("the end");
        System.out.println(notes + " " + Tinyweb.value_of(notes));
    }
}
