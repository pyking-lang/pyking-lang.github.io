// Generated from lib_tinyweb_bitmap.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java PykRuntime.java
//         then run with:            java Program

public final class Program {

    private static String c;
    private static String b;
    private static int orange;
    private static String small;

    private static void frame(final double t) {
        TinywebExternal.set_pixel(small, 1, 1, Tinyweb.pixel_color(PykRuntime.truncate(t * 100.0), 0, 0));
        Tinyweb.show_bitmap(c, small, 120, 60, 2.0);
    }

    public static void main(String[] args) {
        Tinyweb.init();
        Tinyweb.web_init(0);
        c = TinywebExternal.canvas(160, 100);
        b = TinywebExternal.bitmap(16, 10);
        System.out.println("a new bitmap is black:" + " " + String.valueOf(TinywebExternal.get_pixel(b, 3, 3)));
        for (final int y : PykRuntime.range(10)) {
            for (final int x : PykRuntime.range(16)) {
                TinywebExternal.set_pixel(b, x, y, Tinyweb.pixel_color(x * 16, y * 25, 128));
            }
        }
        Tinyweb.show_bitmap(c, b, Tinyweb.show_bitmap__default__x(), Tinyweb.show_bitmap__default__y(), 10.0);
        orange = Tinyweb.pixel_color(255, 136, 0);
        System.out.println("orange is" + " " + String.valueOf(orange) + " " + String.valueOf(Tinyweb.red(orange)) + " " + String.valueOf(Tinyweb.green(orange)) + " " + String.valueOf(Tinyweb.blue(orange)));
        System.out.println("clamped:" + " " + String.valueOf(Tinyweb.pixel_color(300, -5, 70)));
        TinywebExternal.set_pixel(b, 4, 2, orange);
        TinywebExternal.set_pixel(b, 7, 5, orange);
        TinywebExternal.set_pixel(b, 40, 2, orange);
        System.out.println("pixel (4, 2):" + " " + String.valueOf(TinywebExternal.get_pixel(b, 4, 2)) + " " + "outside:" + " " + String.valueOf(TinywebExternal.get_pixel(b, -1, 0)));
        Tinyweb.show_bitmap(c, b, 0, 0, 10.0);
        Tinyweb.show_bitmap(c, b, 5, 5, Tinyweb.show_bitmap__default__scale());
        small = TinywebExternal.bitmap(4, 4);
        TinywebExternal.fill_bitmap(small, Tinyweb.pixel_color(0, 0, 255));
        System.out.println("filled:" + " " + String.valueOf(Tinyweb.blue(TinywebExternal.get_pixel(small, 3, 3))));
        Tinyweb.show_bitmap(c, small, 120, 60, 0.5);
        TinywebExternal.on_frame(c$1 -> frame(c$1));
    }
}
