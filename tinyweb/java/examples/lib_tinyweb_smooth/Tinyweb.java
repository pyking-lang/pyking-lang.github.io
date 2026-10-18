// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// Target: java21. The module 'tinyweb' of the program; compile it with the others.

public final class Tinyweb {

    private static String numbers2(final int a, final int b) {
        return String.valueOf(a) + " " + String.valueOf(b);
    }

    private static String numbers4(final int a, final int b, final int c, final int d) {
        return numbers2(a, b) + " " + numbers2(c, d);
    }

    private static String joined_by(final java.util.List<String> words, final String between) {
        String whole = "";
        String chunk = "";
        int count = 0;
        int chunks = 0;
        for (final String word : words) {
            chunk = count == 0 ? word : chunk + between + word;
            count = count + 1;
            if (count == 128) {
                whole = chunks == 0 ? chunk : whole + between + chunk;
                chunks = chunks + 1;
                chunk = "";
                count = 0;
            }
        }
        return count == 0 ? whole : chunks == 0 ? chunk : whole + between + chunk;
    }

    private static String joined(final java.util.List<String> words) {
        return joined_by(words, " ");
    }

    private static String points_text(final java.util.List<PykRuntime.T2<Integer, Integer>> points) {
        return joined(PykRuntime.flatMap(points, i$2 -> { final int x = i$2.a0(); final int y = i$2.a1(); return PykRuntime.single(numbers2(x, y)); }));
    }

    private static String segments_text(final java.util.List<PykRuntime.T4<Integer, Integer, Integer, Integer>> segments) {
        return joined(PykRuntime.flatMap(segments, i$3 -> { final int x1 = i$3.a0(); final int y1 = i$3.a1(); final int x2 = i$3.a2(); final int y2 = i$3.a3(); return PykRuntime.single(numbers4(x1, y1, x2, y2)); }));
    }

    private static String floats2(final double a, final double b) {
        return PykRuntime.floatStr(a) + " " + PykRuntime.floatStr(b);
    }

    private static String float_points_text(final java.util.List<PykRuntime.T2<Double, Double>> points) {
        return joined(PykRuntime.flatMap(points, i$4 -> { final double x = i$4.a0(); final double y = i$4.a1(); return PykRuntime.single(floats2(x, y)); }));
    }

    public static void web_init(final int port) {
        TinywebExternal.web_start(port);
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

    public static int lines__default__width() {
        return 1;
    }

    public static double lines__default__alpha() {
        return 1.0;
    }

    public static void lines(final String c, final java.util.List<PykRuntime.T4<Integer, Integer, Integer, Integer>> segments, final String color, final int width, final double alpha) {
        TinywebExternal.draw_shape(c, "lines", segments_text(segments), "", color, (double) width, alpha);
    }

    public static void clip_polygon(final String c, final java.util.List<PykRuntime.T2<Integer, Integer>> points) {
        TinywebExternal.set_state(c, "clip", "polygon", points_text(points));
    }

    public static void push(final String c) {
        TinywebExternal.set_state(c, "push", "", "");
    }

    public static void pop(final String c) {
        TinywebExternal.set_state(c, "pop", "", "");
    }

    public static double smooth__polygon__default__alpha() {
        return 1.0;
    }

    public static void smooth__polygon(final String c, final java.util.List<PykRuntime.T2<Double, Double>> points, final String color, final String outline, final double outline_width, final double alpha) {
        TinywebExternal.draw_pairs(c, "polygon", points, color, outline, outline_width, alpha);
    }

    public static void smooth__lines(final String c, final java.util.List<PykRuntime.T4<Double, Double, Double, Double>> segments, final String color, final double width, final double alpha) {
        TinywebExternal.draw_quads(c, "lines", segments, "", color, width, alpha);
    }

    public static double smooth__path__default__alpha() {
        return 1.0;
    }

    public static void smooth__path(final String c, final java.util.List<PykRuntime.T2<Double, Double>> points, final String color, final double width, final double alpha) {
        TinywebExternal.draw_pairs(c, "path", points, "", color, width, alpha);
    }

    public static void smooth__clip_polygon(final String c, final java.util.List<PykRuntime.T2<Double, Double>> points) {
        TinywebExternal.set_state(c, "clip", "polygon", float_points_text(points));
    }

    public static void init() {
    }
}
