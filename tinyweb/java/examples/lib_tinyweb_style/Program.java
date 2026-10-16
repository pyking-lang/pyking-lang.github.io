// Generated from lib_tinyweb_style.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java
//         then run with:            java Program

public final class Program {

    // What the top level binds, where every method can read it; the
    // top level in `main` below is what fills each of them in.
    private static int title;
    private static int level;
    private static int c;
    private static int ok;

    private static void pressed() {
        Tinyweb.theme("retro");
        Tinyweb.set_colors(title, Tinyweb.set_colors__default__color(), "black");
        System.out.println("now retro");
    }

    public static void main(String[] args) {
        // Every module of the program, in the order they must run.
        Tinyweb.init();

        TinywebExternal.web_init(0);
        Tinyweb.theme("paper");
        Tinyweb.theme("no such theme");
        Tinyweb.page_style("#fdf6e3", "#586e75", "serif", 18, 12, 16);
        Tinyweb.button_style("#268bd2", "white", "none", 14, "monospace", 16, 8);
        Tinyweb.label_style("lightyellow", "#333333", "1px solid gold", 4, "sans-serif", 14, 6);
        Tinyweb.slider_style("crimson", 240, "crimson", "monospace", 20);
        Tinyweb.canvas_style("3px solid teal", 10);
        title = TinywebExternal.label("Styled");
        Tinyweb.set_style(title, "navy", "white", "2px dashed orange", 0, "Georgia", 28, 10, Tinyweb.set_style__default__accent(), 300);
        level = Tinyweb.slider(0, 10, 4, Tinyweb.slider__default__on_change());
        Tinyweb.set_colors(level, "seagreen", Tinyweb.set_colors__default__background());
        c = TinywebExternal.canvas(120, 60);
        Tinyweb.set_style(c, Tinyweb.set_style__default__background(), Tinyweb.set_style__default__color(), "1px solid black", Tinyweb.set_style__default__radius(), Tinyweb.set_style__default__font(), Tinyweb.set_style__default__size(), Tinyweb.set_style__default__padding(), Tinyweb.set_style__default__accent(), Tinyweb.set_style__default__width());
        ok = Tinyweb.button("Retro", () -> pressed());
        Tinyweb.set_colors(ok, "black", "gold");
    }
}
