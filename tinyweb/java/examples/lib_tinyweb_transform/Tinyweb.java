// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// Target: java21. The module 'tinyweb' of the program; compile it with the others.

public final class Tinyweb {

    public static void clear(final String c, final String color) {
        TinywebExternal.fill_canvas(c, color);
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

    public static void translate(final String c, final double x, final double y) {
        TinywebExternal.set_state(c, "translate", "", PykRuntime.floatStr(x) + " " + PykRuntime.floatStr(y));
    }

    public static void rotate(final String c, final double degrees) {
        TinywebExternal.set_state(c, "rotate", "", PykRuntime.floatStr(degrees));
    }

    public static void scale(final String c, final double sx, final double sy) {
        TinywebExternal.set_state(c, "scale", "", PykRuntime.floatStr(sx) + " " + PykRuntime.floatStr(sy));
    }

    public static void push(final String c) {
        TinywebExternal.set_state(c, "push", "", "");
    }

    public static void pop(final String c) {
        TinywebExternal.set_state(c, "pop", "", "");
    }

    public static void reset(final String c) {
        TinywebExternal.set_state(c, "reset", "", "");
    }

    public static int shadow__default__blur() {
        return 10;
    }

    public static int shadow__default__dx() {
        return 0;
    }

    public static int shadow__default__dy() {
        return 0;
    }

    public static void shadow(final String c, final String color, final int blur, final int dx, final int dy) {
        TinywebExternal.set_state(c, "shadow", color, numbers3(blur, dx, dy));
    }

    public static void blend(final String c, final String mode) {
        final String s$1 = mode;
        switch (s$1) {
            case String t$2 when "normal".equals(t$2) || "add".equals(t$2) -> {
                TinywebExternal.set_state(c, "blend", mode, "");
            }
            case String t$3 -> {
                System.err.println("tinyweb: there is no blending called \"" + mode + "\"; the modes are normal and add");
            }
        }
    }

    public static void init() {
    }
}
