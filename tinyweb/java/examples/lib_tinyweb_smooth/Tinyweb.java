// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// Target: java21. The module 'tinyweb' of the program; compile it with the others.

public final class Tinyweb {

    public record Color__Color(int r, int g, int b, double a) implements PykRuntime.Data {
        public String pykTag() { return "Color__Color"; }
        public Object[] pykFields() { return new Object[] { r, g, b, a }; }
    }

    public sealed interface Color__Paint extends PykRuntime.Data permits Color__Plain, Color__Linear, Color__Radial, Color__Conic {
    }

    public static Color__Paint Color__Plain(final Color__Color f$0) {
        return new Color__Plain(f$0);
    }

    public record Color__Plain(Color__Color f$0) implements Color__Paint {
        public String pykTag() { return "Color__Plain"; }
        public Object[] pykFields() { return new Object[] { f$0 }; }
    }

    public static Color__Paint Color__Linear(final double x1, final double y1, final double x2, final double y2, final Color__Color start, final Color__Color end, final String stops) {
        return new Color__Linear(x1, y1, x2, y2, start, end, stops);
    }

    public record Color__Linear(double x1, double y1, double x2, double y2, Color__Color start, Color__Color end, String stops) implements Color__Paint {
        public String pykTag() { return "Color__Linear"; }
        public Object[] pykFields() { return new Object[] { x1, y1, x2, y2, start, end, stops }; }
    }

    public static Color__Paint Color__Radial(final double x1, final double y1, final double r1, final double x2, final double y2, final double r2, final Color__Color start, final Color__Color end, final String stops) {
        return new Color__Radial(x1, y1, r1, x2, y2, r2, start, end, stops);
    }

    public record Color__Radial(double x1, double y1, double r1, double x2, double y2, double r2, Color__Color start, Color__Color end, String stops) implements Color__Paint {
        public String pykTag() { return "Color__Radial"; }
        public Object[] pykFields() { return new Object[] { x1, y1, r1, x2, y2, r2, start, end, stops }; }
    }

    public static Color__Paint Color__Conic(final double x, final double y, final double angle, final Color__Color start, final Color__Color end, final String stops) {
        return new Color__Conic(x, y, angle, start, end, stops);
    }

    public record Color__Conic(double x, double y, double angle, Color__Color start, Color__Color end, String stops) implements Color__Paint {
        public String pykTag() { return "Color__Conic"; }
        public Object[] pykFields() { return new Object[] { x, y, angle, start, end, stops }; }
    }

    public record Point(int x, int y) implements PykRuntime.Data {
        public String pykTag() { return "Point"; }
        public Object[] pykFields() { return new Object[] { x, y }; }
    }

    public record Style(Color__Color fill, Color__Color stroke, int width, double alpha, Color__Paint paint) implements PykRuntime.Data {
        public String pykTag() { return "Style"; }
        public Object[] pykFields() { return new Object[] { fill, stroke, width, alpha, paint }; }
    }

    public record Pointer(int x, int y, boolean down) implements PykRuntime.Data {
        public String pykTag() { return "Pointer"; }
        public Object[] pykFields() { return new Object[] { x, y, down }; }
    }

    public record Sound__Voice(double volume, double rate, double pan, int channel, boolean looping, boolean reverse) implements PykRuntime.Data {
        public String pykTag() { return "Sound__Voice"; }
        public Object[] pykFields() { return new Object[] { volume, rate, pan, channel, looping, reverse }; }
    }

    public record Smooth__Point(double x, double y) implements PykRuntime.Data {
        public String pykTag() { return "Smooth__Point"; }
        public Object[] pykFields() { return new Object[] { x, y }; }
    }

    public static Color__Color color__black;
    public static Color__Color color__white;
    public static Color__Color color__gray;
    public static Color__Color color__red;
    public static Color__Color color__green;
    public static Color__Color color__blue;
    public static Color__Color color__yellow;
    public static Color__Color color__orange;
    public static Color__Color color__purple;
    public static Color__Color color__pink;
    public static Color__Color color__navy;
    public static Color__Color color__teal;
    public static Color__Color color__brown;
    public static Color__Color color__cyan;
    public static Color__Color color__magenta;
    public static Color__Color color__none;
    public static Color__Color color__theme;

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

    private static String points_text(final java.util.List<Point> points) {
        return joined(PykRuntime.flatMap(points, i$2 -> { final var p = i$2; return PykRuntime.single(numbers2(p.x(), p.y())); }));
    }

    private static String segments_text(final java.util.List<PykRuntime.T2<Point, Point>> segments) {
        return joined(PykRuntime.flatMap(segments, i$3 -> { final var a = i$3.a0(); final var b = i$3.a1(); return PykRuntime.single(numbers4(a.x(), a.y(), b.x(), b.y())); }));
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

    private static String float_points_text(final java.util.List<Smooth__Point> points) {
        return joined(PykRuntime.flatMap(points, i$4 -> { final var p = i$4; return PykRuntime.single(floats2(p.x(), p.y())); }));
    }

    private static int color__part(final int n) {
        return n < 0 ? 0 : n > 255 ? 255 : n;
    }

    private static double color__unit(final double x) {
        return x < 0.0 ? 0.0 : x > 1.0 ? 1.0 : x;
    }

    private static String color__hex2(final int n) {
        final var clamped = color__part(n);
        return color__hex_digit(clamped / 16) + color__hex_digit(clamped - clamped / 16 * 16);
    }

    private static String color__hex_digit(final int d) {
        final Integer s$5 = d;
        switch (s$5) {
            case Integer t$6 when PykRuntime.truth((int) t$6 == 0) -> {
                return "0";
            }
            case Integer t$7 when PykRuntime.truth((int) t$7 == 1) -> {
                return "1";
            }
            case Integer t$8 when PykRuntime.truth((int) t$8 == 2) -> {
                return "2";
            }
            case Integer t$9 when PykRuntime.truth((int) t$9 == 3) -> {
                return "3";
            }
            case Integer t$10 when PykRuntime.truth((int) t$10 == 4) -> {
                return "4";
            }
            case Integer t$11 when PykRuntime.truth((int) t$11 == 5) -> {
                return "5";
            }
            case Integer t$12 when PykRuntime.truth((int) t$12 == 6) -> {
                return "6";
            }
            case Integer t$13 when PykRuntime.truth((int) t$13 == 7) -> {
                return "7";
            }
            case Integer t$14 when PykRuntime.truth((int) t$14 == 8) -> {
                return "8";
            }
            case Integer t$15 when PykRuntime.truth((int) t$15 == 9) -> {
                return "9";
            }
            case Integer t$16 when PykRuntime.truth((int) t$16 == 10) -> {
                return "a";
            }
            case Integer t$17 when PykRuntime.truth((int) t$17 == 11) -> {
                return "b";
            }
            case Integer t$18 when PykRuntime.truth((int) t$18 == 12) -> {
                return "c";
            }
            case Integer t$19 when PykRuntime.truth((int) t$19 == 13) -> {
                return "d";
            }
            case Integer t$20 when PykRuntime.truth((int) t$20 == 14) -> {
                return "e";
            }
            case Integer t$21 -> {
                return "f";
            }
        }
    }

    private static String color__css(final Color__Color c) {
        if (c.a() >= 1.0) {
            return "#" + color__hex2(c.r()) + color__hex2(c.g()) + color__hex2(c.b());
        } else {
            return "rgba(" + String.valueOf(color__part(c.r())) + ", " + String.valueOf(color__part(c.g())) + ", " + String.valueOf(color__part(c.b())) + ", " + PykRuntime.floatStr(color__unit(c.a())) + ")";
        }
    }

    private static String color__drawn(final Color__Color c) {
        return c.a() <= 0.0 ? "" : color__css(c);
    }

    private static String color__paint_text(final Color__Paint p) {
        final Color__Paint s$22 = p;
        switch (s$22) {
            case Color__Plain(var t$23) -> {
                final var c = t$23;
                return color__drawn(c);
            }
            case Color__Linear(var t$24, var t$25, var t$26, var t$27, var t$28, var t$29, var t$30) -> {
                final double x1 = t$24;
                final double y1 = t$25;
                final double x2 = t$26;
                final double y2 = t$27;
                final var start = t$28;
                final var end = t$29;
                final var stops = t$30;
                return "linear-gradient(" + floats4(x1, y1, x2, y2) + "); 0.0 " + color__css(start) + "; 1.0 " + color__css(end) + stops;
            }
            case Color__Radial(var t$31, var t$32, var t$33, var t$34, var t$35, var t$36, var t$37, var t$38, var t$39) -> {
                final double x12 = t$31;
                final double y12 = t$32;
                final double r1 = t$33;
                final double x22 = t$34;
                final double y22 = t$35;
                final double r2 = t$36;
                final var start2 = t$37;
                final var end2 = t$38;
                final var stops2 = t$39;
                return "radial-gradient(" + floats3(x12, y12, r1) + " " + floats3(x22, y22, r2) + "); 0.0 " + color__css(start2) + "; 1.0 " + color__css(end2) + stops2;
            }
            case Color__Conic(var t$40, var t$41, var t$42, var t$43, var t$44, var t$45) -> {
                final double x = t$40;
                final double y = t$41;
                final double angle = t$42;
                final var start3 = t$43;
                final var end3 = t$44;
                final var stops3 = t$45;
                return "conic-gradient(" + floats3(x, y, angle) + "); 0.0 " + color__css(start3) + "; 1.0 " + color__css(end3) + stops3;
            }
            default -> {
                throw new IllegalStateException();
            }
        }
    }

    private static boolean color__painted(final Color__Paint p) {
        final Color__Paint s$46 = p;
        switch (s$46) {
            case Color__Plain(var t$47) -> {
                final var c = t$47;
                return c.a() > 0.0;
            }
            case Color__Paint t$48 -> {
                return true;
            }
        }
    }

    public static Color__Color color__hex(final int n) {
        return new Color__Color(color__part(n / 65536), color__part(n / 256 - n / 65536 * 256), color__part(n - n / 256 * 256), 1.0);
    }

    public static boolean color__same(final Color__Color a, final Color__Color b) {
        return (int) a.r() == (int) b.r() ? (int) a.g() == (int) b.g() ? (int) a.b() == (int) b.b() ? (double) a.a() == (double) b.a() : false : false : false;
    }

    public static void web_init(final int port) {
        TinywebExternal.web_start(port);
    }

    public static Color__Color field__default__Style__fill() {
        return color__black;
    }

    public static Color__Color field__default__Style__stroke() {
        return color__none;
    }

    public static Color__Paint field__default__Style__paint() {
        return Color__Plain(color__none);
    }

    private static String fill_of(final Color__Color fill, final Color__Paint paint, final Style style) {
        if (color__painted(paint)) {
            return color__paint_text(paint);
        } else if (not_default_fill(fill)) {
            return color__drawn(fill);
        } else if (color__painted(style.paint())) {
            return color__paint_text(style.paint());
        } else {
            return color__drawn(style.fill());
        }
    }

    private static boolean not_default_fill(final Color__Color fill) {
        return color__same(fill, color__black) ? false : true;
    }

    private static String stroke_of(final Color__Color stroke, final Style style) {
        return color__drawn(color__same(stroke, color__none) ? style.stroke() : stroke);
    }

    private static String line_of(final Color__Color stroke, final Style style) {
        if (not_default_fill(stroke)) {
            return color__drawn(stroke);
        } else if (color__same(style.stroke(), color__none)) {
            return color__drawn(style.fill());
        } else {
            return color__drawn(style.stroke());
        }
    }

    private static double width_of(final int width, final Style style) {
        return (double) (int) (width == 1 ? style.width() : width);
    }

    private static double alpha_of(final double alpha, final Style style) {
        return alpha == 1.0 ? style.alpha() : alpha;
    }

    private static void shape(final String c, final String kind, final String numbers, final Color__Color fill, final Color__Color stroke, final int width, final double alpha, final Color__Paint paint, final Style style) {
        TinywebExternal.draw_shape(c, kind, numbers, fill_of(fill, paint, style), stroke_of(stroke, style), width_of(width, style), alpha_of(alpha, style));
    }

    private static void stroked(final String c, final String kind, final String numbers, final Color__Color stroke, final int width, final double alpha, final Style style) {
        TinywebExternal.draw_shape(c, kind, numbers, "", line_of(stroke, style), width_of(width, style), alpha_of(alpha, style));
    }

    public static Color__Color rect__default__stroke() {
        return color__none;
    }

    public static Color__Paint rect__default__paint() {
        return Color__Plain(color__none);
    }

    public static Style rect__default__style() {
        return new Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint());
    }

    public static void rect(final String c, final int x, final int y, final int w, final int h, final Color__Color fill, final Color__Color stroke, final int width, final double alpha, final Color__Paint paint, final Style style, final int radius) {
        shape(c, "rect", numbers4(x, y, w, h) + " " + String.valueOf(radius), fill, stroke, width, alpha, paint, style);
    }

    public static Style lines__default__style() {
        return new Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint());
    }

    public static void lines(final String c, final java.util.List<PykRuntime.T2<Point, Point>> segments, final Color__Color stroke, final int width, final double alpha, final Style style) {
        stroked(c, "lines", segments_text(segments), stroke, width, alpha, style);
    }

    public static void clip_polygon(final String c, final java.util.List<Point> points) {
        TinywebExternal.set_state(c, "clip", "polygon", points_text(points));
    }

    public static void push(final String c) {
        TinywebExternal.set_state(c, "push", "", "");
    }

    public static void pop(final String c) {
        TinywebExternal.set_state(c, "pop", "", "");
    }

    private static double smooth__width_of(final double width, final Style style) {
        return width == 1.0 ? (double) (int) style.width() : width;
    }

    private static java.util.List<PykRuntime.T2<Double, Double>> smooth__pairs(final java.util.List<Smooth__Point> points) {
        return PykRuntime.flatMap(points, i$49 -> { final var p = i$49; return PykRuntime.single(new PykRuntime.T2<>(p.x(), p.y())); });
    }

    public static Color__Color smooth__circles__default__stroke() {
        return color__none;
    }

    public static Style smooth__circles__default__style() {
        return new Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint());
    }

    public static void smooth__circles(final String c, final java.util.List<PykRuntime.T3<Double, Double, Double>> circles, final Color__Color fill, final Color__Color stroke, final double width, final double alpha, final Style style) {
        TinywebExternal.draw_triples(c, "circles", circles, fill_of(fill, Color__Plain(color__none), style), stroke_of(stroke, style), smooth__width_of(width, style), alpha_of(alpha, style));
    }

    public static Style smooth__polygon__default__style() {
        return new Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint());
    }

    public static void smooth__polygon(final String c, final java.util.List<Smooth__Point> points, final Color__Color fill, final Color__Color stroke, final double width, final double alpha, final Style style) {
        TinywebExternal.draw_pairs(c, "polygon", smooth__pairs(points), fill_of(fill, Color__Plain(color__none), style), stroke_of(stroke, style), smooth__width_of(width, style), alpha_of(alpha, style));
    }

    public static Style smooth__lines__default__style() {
        return new Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint());
    }

    public static void smooth__lines(final String c, final java.util.List<PykRuntime.T2<Smooth__Point, Smooth__Point>> segments, final Color__Color stroke, final double width, final double alpha, final Style style) {
        TinywebExternal.draw_quads(c, "lines", PykRuntime.flatMap(segments, i$50 -> { final var a = i$50.a0(); final var b = i$50.a1(); return PykRuntime.single(new PykRuntime.T4<>(a.x(), a.y(), b.x(), b.y())); }), "", line_of(stroke, style), smooth__width_of(width, style), alpha_of(alpha, style));
    }

    public static Style smooth__path__default__style() {
        return new Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint());
    }

    public static void smooth__path(final String c, final java.util.List<Smooth__Point> points, final Color__Color stroke, final double width, final double alpha, final Style style) {
        TinywebExternal.draw_pairs(c, "path", smooth__pairs(points), "", line_of(stroke, style), smooth__width_of(width, style), alpha_of(alpha, style));
    }

    public static void smooth__clip_polygon(final String c, final java.util.List<Smooth__Point> points) {
        TinywebExternal.set_state(c, "clip", "polygon", float_points_text(points));
    }

    public static void init() {
        color__black = new Color__Color(0, 0, 0, 1.0);
        color__white = new Color__Color(255, 255, 255, 1.0);
        color__gray = new Color__Color(128, 128, 128, 1.0);
        color__red = new Color__Color(255, 0, 0, 1.0);
        color__green = new Color__Color(0, 128, 0, 1.0);
        color__blue = new Color__Color(0, 0, 255, 1.0);
        color__yellow = new Color__Color(255, 255, 0, 1.0);
        color__orange = new Color__Color(255, 165, 0, 1.0);
        color__purple = new Color__Color(128, 0, 128, 1.0);
        color__pink = new Color__Color(255, 192, 203, 1.0);
        color__navy = new Color__Color(0, 0, 128, 1.0);
        color__teal = new Color__Color(0, 128, 128, 1.0);
        color__brown = new Color__Color(139, 69, 19, 1.0);
        color__cyan = new Color__Color(0, 255, 255, 1.0);
        color__magenta = new Color__Color(255, 0, 255, 1.0);
        color__none = new Color__Color(0, 0, 0, 0.0);
        color__theme = new Color__Color(-1, -1, -1, -1.0);
    }
}
