// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// Target: java21. The module 'tinyweb' of the program; compile it with the others.

public final class Tinyweb {

    private static void nothing() {

    }

    private static String numbers2(final int a, final int b) {
        return String.valueOf(a) + " " + String.valueOf(b);
    }

    private static String numbers3(final int a, final int b, final int c) {
        return numbers2(a, b) + " " + String.valueOf(c);
    }

    public static void web_init(final int port) {
        TinywebExternal.web_start(port);
    }

    public static String circle__default__color() {
        return "#000000";
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

    public static java.util.function.Supplier<Void> button__default__on_click() {
        return () -> { nothing(); return null; };
    }

    public static String button(final String title, final java.util.function.Supplier<Void> on_click) {
        return TinywebExternal.make_button(title, on_click::get);
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

    public static void init() {
    }
}
