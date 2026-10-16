// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// Target: java21. The module 'tinyweb' of the program; compile it with the others.

public final class Tinyweb {

    private static void nothing() {

    }

    public static String circle__default__color() {
        return "#000000";
    }

    public static void circle(final int c, final int x, final int y, final int radius, final String color) {
        TinywebExternal.draw_circle(c, x, y, radius, color);
    }

    public static Runnable button__default__on_click() {
        return () -> nothing();
    }

    public static int button(final String title, final Runnable on_click) {
        return TinywebExternal.make_button(title, on_click);
    }

    public static double play__default__at() {
        return 0.0;
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
