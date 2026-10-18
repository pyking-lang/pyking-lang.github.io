// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// Target: java21. The module 'tinyweb' of the program; compile it with the others.

public final class Tinyweb {

    private static void ignore(final int value) {

    }

    private static String numbers2(final int a, final int b) {
        return String.valueOf(a) + " " + String.valueOf(b);
    }

    private static String numbers3(final int a, final int b, final int c) {
        return numbers2(a, b) + " " + String.valueOf(c);
    }

    private static String numbers4(final int a, final int b, final int c, final int d) {
        return numbers2(a, b) + " " + numbers2(c, d);
    }

    public static void web_init(final int port) {
        TinywebExternal.web_start(port);
    }

    public static String circle__default__outline() {
        return "";
    }

    public static int circle__default__outline_width() {
        return 1;
    }

    public static double circle__default__alpha() {
        return 1.0;
    }

    public static void circle(final String c, final int x, final int y, final int radius, final String color, final String outline, final int outline_width, final double alpha) {
        TinywebExternal.draw_shape(c, "circle", numbers3(x, y, radius), color, outline, (double) outline_width, alpha);
    }

    public static String rect__default__outline() {
        return "";
    }

    public static int rect__default__outline_width() {
        return 1;
    }

    public static double rect__default__alpha() {
        return 1.0;
    }

    public static int rect__default__radius() {
        return 0;
    }

    public static void rect(final String c, final int x, final int y, final int width, final int height, final String color, final String outline, final int outline_width, final double alpha, final int radius) {
        TinywebExternal.draw_shape(c, "rect", numbers4(x, y, width, height) + " " + String.valueOf(radius), color, outline, (double) outline_width, alpha);
    }

    public static String line__default__color() {
        return "#000000";
    }

    public static int line__default__width() {
        return 1;
    }

    public static double line__default__alpha() {
        return 1.0;
    }

    public static void line(final String c, final int x1, final int y1, final int x2, final int y2, final String color, final int width, final double alpha) {
        TinywebExternal.draw_shape(c, "line", numbers4(x1, y1, x2, y2), "", color, (double) width, alpha);
    }

    public static String text__default__color() {
        return "#000000";
    }

    public static String text__default__font() {
        return "";
    }

    public static String text__default__align() {
        return "left";
    }

    public static boolean text__default__bold() {
        return false;
    }

    public static double text__default__alpha() {
        return 1.0;
    }

    public static String text__default__baseline() {
        return "top";
    }

    public static String text__default__outline() {
        return "";
    }

    public static int text__default__outline_width() {
        return 1;
    }

    public static void text(final String c, final int x, final int y, final String words, final String color, final int size, final String font, final String align, final boolean bold, final double alpha, final String baseline, final String outline, final int outline_width) {
        TinywebExternal.draw_text(c, (double) x, (double) y, words, color, size, font, align, baseline, bold, outline, (double) outline_width, alpha);
    }

    public static java.util.function.Function<Integer, Void> slider__default__on_change() {
        return p$1 -> { ignore(p$1); return null; };
    }

    public static String slider(final int low, final int high, final int value, final java.util.function.Function<Integer, Void> on_change) {
        return TinywebExternal.make_slider(low, high, value, on_change::apply);
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

    public static void play(final String sample, final double at, final double volume, final double rate) {
        TinywebExternal.play_sample(sample, at, volume, rate);
    }

    public static void play_file(final String name) {
        play(TinywebExternal.load_sample(name), play__default__at(), play__default__volume(), play__default__rate());
    }

    public static void init() {
    }
}
