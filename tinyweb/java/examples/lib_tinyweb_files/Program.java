// Generated from lib_tinyweb_files.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java PykRuntime.java
//         then run with:            java Program

public final class Program {

    private static String c;
    private static String picker;

    private static void loaded(final String name) {
        System.out.println("loaded" + " " + name + " " + "holding" + " " + Tinyweb.net__file_text());
    }

    public static void main(String[] args) {
        Math.init();
        Text.init();
        Tinyweb.init();
        Tinyweb.web_init(0);
        c = TinywebExternal.canvas(100, 100);
        Tinyweb.circle(c, 50, 50, 40, Tinyweb.color__green, Tinyweb.circle__default__stroke(), 1, 1.0, Tinyweb.circle__default__paint(), Tinyweb.circle__default__style());
        Tinyweb.game__cursor(c, "crosshair");
        Tinyweb.game__cursor(c, "none");
        Tinyweb.net__save_canvas(c, "canvas.png");
        Tinyweb.net__save_canvas(c, "circle.png");
        Tinyweb.net__download("notes.txt", "line one\nline \"two\"");
        System.out.println("before:" + " " + ("[" + Tinyweb.net__file_text() + "]"));
        picker = Tinyweb.net__file_button("Open", p$1 -> { loaded(p$1); return null; });
        System.out.println(picker);
    }
}
