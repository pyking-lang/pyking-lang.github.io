// Generated from lib_tinyweb_bitmap.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java PykRuntime.java
//         then run with:            java Program

public final class Program {

    private static String c;
    private static String b;
    private static Tinyweb.Color__Color orange;
    private static String small;

    private static String show(final Tinyweb.Color__Color p) {
        return String.valueOf((Object) p.r()) + " " + String.valueOf((Object) p.g()) + " " + String.valueOf((Object) p.b());
    }

    private static void frame(final double t) {
        Tinyweb.bitmap__set_pixel(small, 1, 1, Tinyweb.color__rgb(PykRuntime.truncate(t * 100.0), 0, 0));
        Tinyweb.bitmap__show_bitmap(c, small, 120, 60, 2.0);
    }

    public static void main(String[] args) {
        Math.init();
        Text.init();
        Tinyweb.init();
        Tinyweb.web_init(0);
        c = TinywebExternal.canvas(160, 100);
        b = Tinyweb.bitmap__bitmap(16, 10, Tinyweb.bitmap__bitmap__default__background());
        System.out.println("a new bitmap is white:" + " " + show(Tinyweb.bitmap__get_pixel(b, 3, 3)));
        System.out.println("or its background:" + " " + show(Tinyweb.bitmap__get_pixel(Tinyweb.bitmap__bitmap(2, 2, Tinyweb.color__green), 1, 1)));
        for (final int y : PykRuntime.range(10)) {
            for (final int x : PykRuntime.range(16)) {
                Tinyweb.bitmap__set_pixel(b, x, y, Tinyweb.color__rgb(x * 16, y * 25, 128));
            }
        }
        Tinyweb.bitmap__show_bitmap(c, b, 0, 0, 10.0);
        orange = Tinyweb.color__rgb(255, 136, 0);
        Tinyweb.bitmap__set_pixel(b, 4, 2, orange);
        Tinyweb.bitmap__set_pixel(b, 7, 5, orange);
        Tinyweb.bitmap__set_pixel(b, 40, 2, orange);
        System.out.println("pixel (4, 2):" + " " + show(Tinyweb.bitmap__get_pixel(b, 4, 2)) + " " + "outside:" + " " + show(Tinyweb.bitmap__get_pixel(b, -1, 0)) + " " + PykRuntime.floatStr((double) Tinyweb.bitmap__get_pixel(b, -1, 0).a()));
        Tinyweb.bitmap__show_bitmap(c, b, 0, 0, 10.0);
        Tinyweb.bitmap__show_bitmap(c, b, 5, 5, 1.0);
        small = Tinyweb.bitmap__bitmap(4, 4, Tinyweb.bitmap__bitmap__default__background());
        Tinyweb.bitmap__fill_bitmap(small, Tinyweb.color__blue);
        System.out.println("filled:" + " " + String.valueOf((Object) Tinyweb.bitmap__get_pixel(small, 3, 3).b()));
        Tinyweb.bitmap__show_bitmap(c, small, 120, 60, 0.5);
        TinywebExternal.on_frame(c$1 -> frame(c$1));
    }
}
