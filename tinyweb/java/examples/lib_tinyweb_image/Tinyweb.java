// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// Target: java21. The module 'tinyweb' of the program; compile it with the others.

public final class Tinyweb {

    public static void clear(final String c, final String color) {
        TinywebExternal.fill_canvas(c, color);
    }

    public static void web_init(final int port) {
        TinywebExternal.web_start(port);
    }

    public static double image__default__alpha() {
        return 1.0;
    }

    public static void image(final String c, final String picture, final int x, final int y, final int width, final int height, final double alpha) {
        TinywebExternal.draw_image(c, picture, x, y, width, height, alpha);
    }

    public static void init() {
    }
}
