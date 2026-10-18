// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// Target: java21. The module 'tinyweb' of the program; compile it with the others.

public final class Tinyweb {

    public static void web_init(final int port) {
        TinywebExternal.web_start(port);
    }

    public static void scale(final String c, final double sx, final double sy) {
        TinywebExternal.set_state(c, "scale", "", PykRuntime.floatStr(sx) + " " + PykRuntime.floatStr(sy));
    }

    public static int show_bitmap__default__x() {
        return 0;
    }

    public static int show_bitmap__default__y() {
        return 0;
    }

    public static double show_bitmap__default__scale() {
        return 1.0;
    }

    public static void show_bitmap(final String c, final String b, final int x, final int y, final double scale) {
        TinywebExternal.draw_bitmap(c, b, x, y, scale);
    }

    private static int channel_of(final int n) {
        return n < 0 ? 0 : n > 255 ? 255 : n;
    }

    public static int pixel_color(final int r, final int g, final int b) {
        return channel_of(r) * 65536 + channel_of(g) * 256 + channel_of(b);
    }

    public static int red(final int color) {
        return color / 65536 - color / 16777216 * 256;
    }

    public static int green(final int color) {
        return color / 256 - color / 65536 * 256;
    }

    public static int blue(final int color) {
        return color - color / 256 * 256;
    }

    public static void init() {
    }
}
