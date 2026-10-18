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

    private static String floats2(final double a, final double b) {
        return PykRuntime.floatStr(a) + " " + PykRuntime.floatStr(b);
    }

    private static String floats3(final double a, final double b, final double c) {
        return floats2(a, b) + " " + PykRuntime.floatStr(c);
    }

    private static String floats4(final double a, final double b, final double c, final double d) {
        return floats2(a, b) + " " + floats2(c, d);
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

    public static double line__default__alpha() {
        return 1.0;
    }

    public static void line(final String c, final int x1, final int y1, final int x2, final int y2, final String color, final int width, final double alpha) {
        TinywebExternal.draw_shape(c, "line", numbers4(x1, y1, x2, y2), "", color, (double) width, alpha);
    }

    public static double bezier__default__alpha() {
        return 1.0;
    }

    public static void bezier(final String c, final int x1, final int y1, final int ax, final int ay, final int bx, final int by, final int x2, final int y2, final String color, final int width, final double alpha) {
        TinywebExternal.draw_shape(c, "bezier", numbers4(x1, y1, ax, ay) + " " + numbers4(bx, by, x2, y2), "", color, (double) width, alpha);
    }

    public static void erase(final String c, final int x, final int y, final int width, final int height) {
        TinywebExternal.draw_shape(c, "erase", numbers4(x, y, width, height), "", "", 0.0, 1.0);
    }

    public static String line_style__default__cap() {
        return "round";
    }

    public static String line_style__default__join() {
        return "round";
    }

    public static double line_style__default__gap() {
        return 0.0;
    }

    public static double line_style__default__offset() {
        return 0.0;
    }

    public static double line_style__default__dash2() {
        return 0.0;
    }

    public static double line_style__default__gap2() {
        return 0.0;
    }

    public static void line_style(final String c, final String cap, final String join, final double dash, final double gap, final double offset, final double dash2, final double gap2) {
        final var first = dash <= 0.0 ? "" : gap <= 0.0 ? " " + floats2(dash, dash) : " " + floats2(dash, gap);
        final var second = dash <= 0.0 ? "" : dash2 <= 0.0 ? "" : gap2 <= 0.0 ? " " + floats2(dash2, dash2) : " " + floats2(dash2, gap2);
        TinywebExternal.set_state(c, "line_style", cap + " " + join, PykRuntime.floatStr(offset) + first + second);
    }

    public static void clip_rect(final String c, final int x, final int y, final int width, final int height) {
        TinywebExternal.set_state(c, "clip", "rect", numbers4(x, y, width, height) + " 0");
    }

    public static void clip_circle(final String c, final int x, final int y, final int radius) {
        TinywebExternal.set_state(c, "clip", "circle", numbers3(x, y, radius));
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

    public static String text__default__outline() {
        return "";
    }

    public static int text__default__outline_width() {
        return 1;
    }

    public static void text(final String c, final int x, final int y, final String words, final String color, final int size, final String font, final String align, final boolean bold, final double alpha, final String baseline, final String outline, final int outline_width) {
        TinywebExternal.draw_text(c, (double) x, (double) y, words, color, size, font, align, baseline, bold, outline, (double) outline_width, alpha);
    }

    public static String measure_text__default__font() {
        return "";
    }

    public static void measure_text(final String words, final java.util.function.Function<Double, Void> answer, final int size, final String font, final boolean bold) {
        TinywebExternal.measure(words, size, font, bold, answer::apply);
    }

    public static void push(final String c) {
        TinywebExternal.set_state(c, "push", "", "");
    }

    public static void pop(final String c) {
        TinywebExternal.set_state(c, "pop", "", "");
    }

    public static String colors__linear_gradient(final double x1, final double y1, final double x2, final double y2, final String start, final String end) {
        return "linear-gradient(" + floats4(x1, y1, x2, y2) + "); 0.0 " + start + "; 1.0 " + end;
    }

    public static String colors__radial_gradient(final double x1, final double y1, final double r1, final double x2, final double y2, final double r2, final String start, final String end) {
        return "radial-gradient(" + floats3(x1, y1, r1) + " " + floats3(x2, y2, r2) + "); 0.0 " + start + "; 1.0 " + end;
    }

    public static String colors__conic_gradient(final double x, final double y, final double angle, final String start, final String end) {
        return "conic-gradient(" + floats3(x, y, angle) + "); 0.0 " + start + "; 1.0 " + end;
    }

    public static String colors__stop(final String gradient, final double at, final String color) {
        return gradient + "; " + PykRuntime.floatStr(at) + " " + color;
    }

    public static double smooth__circle__default__alpha() {
        return 1.0;
    }

    public static void smooth__circle(final String c, final double x, final double y, final double radius, final String color, final String outline, final double outline_width, final double alpha) {
        TinywebExternal.draw_shape(c, "circle", floats3(x, y, radius), color, outline, outline_width, alpha);
    }

    public static double smooth__rect__default__outline_width() {
        return 1.0;
    }

    public static double smooth__rect__default__alpha() {
        return 1.0;
    }

    public static void smooth__rect(final String c, final double x, final double y, final double width, final double height, final String color, final String outline, final double outline_width, final double alpha, final double radius) {
        TinywebExternal.draw_shape(c, "rect", floats4(x, y, width, height) + " " + PykRuntime.floatStr(radius), color, outline, outline_width, alpha);
    }

    public static String smooth__ellipse__default__outline() {
        return "";
    }

    public static double smooth__ellipse__default__outline_width() {
        return 1.0;
    }

    public static double smooth__ellipse__default__alpha() {
        return 1.0;
    }

    public static void smooth__ellipse(final String c, final double x, final double y, final double rx, final double ry, final String color, final String outline, final double outline_width, final double alpha) {
        TinywebExternal.draw_shape(c, "ellipse", floats4(x, y, rx, ry), color, outline, outline_width, alpha);
    }

    public static double smooth__arc__default__alpha() {
        return 1.0;
    }

    public static void smooth__arc(final String c, final double x, final double y, final double radius, final double start, final double end, final String color, final String outline, final double outline_width, final double alpha) {
        TinywebExternal.draw_shape(c, "arc", floats3(x, y, radius) + " " + floats2(start, end), color, outline, outline_width, alpha);
    }

    public static double smooth__line__default__alpha() {
        return 1.0;
    }

    public static void smooth__line(final String c, final double x1, final double y1, final double x2, final double y2, final String color, final double width, final double alpha) {
        TinywebExternal.draw_shape(c, "line", floats4(x1, y1, x2, y2), "", color, width, alpha);
    }

    public static double smooth__curve__default__alpha() {
        return 1.0;
    }

    public static void smooth__curve(final String c, final double x1, final double y1, final double cx, final double cy, final double x2, final double y2, final String color, final double width, final double alpha) {
        TinywebExternal.draw_shape(c, "curve", floats2(x1, y1) + " " + floats4(cx, cy, x2, y2), "", color, width, alpha);
    }

    public static void smooth__bezier(final String c, final double x1, final double y1, final double ax, final double ay, final double bx, final double by, final double x2, final double y2, final String color, final double width, final double alpha) {
        TinywebExternal.draw_shape(c, "bezier", floats4(x1, y1, ax, ay) + " " + floats4(bx, by, x2, y2), "", color, width, alpha);
    }

    public static String smooth__text__default__font() {
        return "";
    }

    public static boolean smooth__text__default__bold() {
        return false;
    }

    public static double smooth__text__default__alpha() {
        return 1.0;
    }

    public static String smooth__text__default__outline() {
        return "";
    }

    public static double smooth__text__default__outline_width() {
        return 1.0;
    }

    public static void smooth__text(final String c, final double x, final double y, final String words, final String color, final int size, final String font, final String align, final boolean bold, final double alpha, final String baseline, final String outline, final double outline_width) {
        TinywebExternal.draw_text(c, x, y, words, color, size, font, align, baseline, bold, outline, outline_width, alpha);
    }

    public static void smooth__clip_circle(final String c, final double x, final double y, final double radius) {
        TinywebExternal.set_state(c, "clip", "circle", floats3(x, y, radius));
    }

    public static void init() {
    }
}
