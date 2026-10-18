// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// Target: java21. The module 'tinyweb' of the program; compile it with the others.

public final class Tinyweb {

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

    public static double line__default__alpha() {
        return 1.0;
    }

    public static void line(final String c, final int x1, final int y1, final int x2, final int y2, final String color, final int width, final double alpha) {
        TinywebExternal.draw_shape(c, "line", numbers4(x1, y1, x2, y2), "", color, (double) width, alpha);
    }

    public static void on_press(final String c, final java.util.function.BiFunction<Integer, Integer, Void> f) {
        TinywebExternal.watch_pointer(c, "press", f::apply);
    }

    public static void on_release(final String c, final java.util.function.BiFunction<Integer, Integer, Void> f) {
        TinywebExternal.watch_pointer(c, "release", f::apply);
    }

    public static void on_move(final String c, final java.util.function.BiFunction<Integer, Integer, Void> f) {
        TinywebExternal.watch_pointer(c, "move", f::apply);
    }

    public static void on_drag(final String c, final java.util.function.BiFunction<Integer, Integer, Void> f) {
        TinywebExternal.watch_pointer(c, "drag", f::apply);
    }

    public static int mouse_x(final String c) {
        return TinywebExternal.pointer(c, "x");
    }

    public static int mouse_y(final String c) {
        return TinywebExternal.pointer(c, "y");
    }

    public static boolean mouse_down(final String c) {
        return TinywebExternal.pointer(c, "down") == 1;
    }

    public static void ignore2(final int x, final int y) {

    }

    public static void init() {
    }
}
