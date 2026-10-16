// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// Target: java21. The module 'tinyweb' of the program; compile it with the others.

public final class Tinyweb {

    public static void clear(final int c, final String color) {
        TinywebExternal.fill_canvas(c, color);
    }

    public static void circle(final int c, final int x, final int y, final int radius, final String color) {
        TinywebExternal.draw_circle(c, x, y, radius, color);
    }

    public static double play__default__volume() {
        return 1.0;
    }

    public static double play__default__rate() {
        return 1.0;
    }

    public static void play(final int sample, final double at, final double volume, final double rate) {
        TinywebExternal.play_sample(sample, at, volume, rate);
    }

    public static void init() {

    }
}
