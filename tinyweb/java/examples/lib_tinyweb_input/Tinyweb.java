// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// Target: java21. The module 'tinyweb' of the program; compile it with the others.

public final class Tinyweb {

    private static void ignore(final int value) {

    }

    public static void circle(final int c, final int x, final int y, final int radius, final String color) {
        TinywebExternal.draw_circle(c, x, y, radius, color);
    }

    public static void rect(final int c, final int x, final int y, final int width, final int height, final String color) {
        TinywebExternal.draw_rect(c, x, y, width, height, color);
    }

    public static String line__default__color() {
        return "#000000";
    }

    public static int line__default__width() {
        return 1;
    }

    public static void line(final int c, final int x1, final int y1, final int x2, final int y2, final String color, final int width) {
        TinywebExternal.draw_line(c, x1, y1, x2, y2, color, width);
    }

    public static String text__default__color() {
        return "#000000";
    }

    public static void text(final int c, final int x, final int y, final String words, final String color, final int size) {
        TinywebExternal.draw_text(c, x, y, words, color, size);
    }

    public static java.util.function.Consumer<Integer> slider__default__on_change() {
        return (p$1) -> ignore(p$1);
    }

    public static int slider(final int low, final int high, final int value, final java.util.function.Consumer<Integer> on_change) {
        return TinywebExternal.make_slider(low, high, value, on_change);
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

    public static void play_file(final String name) {
        play(TinywebExternal.load_sample(name), play__default__at(), play__default__volume(), play__default__rate());
    }

    public static void init() {

    }
}
