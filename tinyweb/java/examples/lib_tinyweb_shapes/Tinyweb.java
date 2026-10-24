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

    private static PykRuntime.T3<Double, Double, Double> color__sector(final int sector, final double chroma, final double x) {
        final Integer s$1 = sector;
        switch (s$1) {
            case Integer t$2 when PykRuntime.truth((int) t$2 == 0) -> {
                return new PykRuntime.T3<>(chroma, x, 0.0);
            }
            case Integer t$3 when PykRuntime.truth((int) t$3 == 1) -> {
                return new PykRuntime.T3<>(x, chroma, 0.0);
            }
            case Integer t$4 when PykRuntime.truth((int) t$4 == 2) -> {
                return new PykRuntime.T3<>(0.0, chroma, x);
            }
            case Integer t$5 when PykRuntime.truth((int) t$5 == 3) -> {
                return new PykRuntime.T3<>(0.0, x, chroma);
            }
            case Integer t$6 when PykRuntime.truth((int) t$6 == 4) -> {
                return new PykRuntime.T3<>(x, 0.0, chroma);
            }
            case Integer t$7 -> {
                return new PykRuntime.T3<>(chroma, 0.0, x);
            }
        }
    }

    private static int color__part(final int n) {
        return n < 0 ? 0 : n > 255 ? 255 : n;
    }

    private static double color__unit(final double x) {
        return x < 0.0 ? 0.0 : x > 1.0 ? 1.0 : x;
    }

    private static int color__byte(final double x) {
        return color__part(PykRuntime.truncate(color__unit(x) * 255.0 + 0.5));
    }

    private static double color__absolute(final double x) {
        return x < 0.0 ? -x : x;
    }

    private static double color__wrap(final double x, final double m) {
        final var r = x - (double) PykRuntime.truncate(x / m) * m;
        return r < 0.0 ? r + m : r;
    }

    private static double color__between(final int a, final int b, final double t) {
        return (double) a + (double) (b - a) * t;
    }

    private static String color__hex2(final int n) {
        final var clamped = color__part(n);
        return color__hex_digit(clamped / 16) + color__hex_digit(clamped - clamped / 16 * 16);
    }

    private static String color__hex_digit(final int d) {
        final Integer s$8 = d;
        switch (s$8) {
            case Integer t$9 when PykRuntime.truth((int) t$9 == 0) -> {
                return "0";
            }
            case Integer t$10 when PykRuntime.truth((int) t$10 == 1) -> {
                return "1";
            }
            case Integer t$11 when PykRuntime.truth((int) t$11 == 2) -> {
                return "2";
            }
            case Integer t$12 when PykRuntime.truth((int) t$12 == 3) -> {
                return "3";
            }
            case Integer t$13 when PykRuntime.truth((int) t$13 == 4) -> {
                return "4";
            }
            case Integer t$14 when PykRuntime.truth((int) t$14 == 5) -> {
                return "5";
            }
            case Integer t$15 when PykRuntime.truth((int) t$15 == 6) -> {
                return "6";
            }
            case Integer t$16 when PykRuntime.truth((int) t$16 == 7) -> {
                return "7";
            }
            case Integer t$17 when PykRuntime.truth((int) t$17 == 8) -> {
                return "8";
            }
            case Integer t$18 when PykRuntime.truth((int) t$18 == 9) -> {
                return "9";
            }
            case Integer t$19 when PykRuntime.truth((int) t$19 == 10) -> {
                return "a";
            }
            case Integer t$20 when PykRuntime.truth((int) t$20 == 11) -> {
                return "b";
            }
            case Integer t$21 when PykRuntime.truth((int) t$21 == 12) -> {
                return "c";
            }
            case Integer t$22 when PykRuntime.truth((int) t$22 == 13) -> {
                return "d";
            }
            case Integer t$23 when PykRuntime.truth((int) t$23 == 14) -> {
                return "e";
            }
            case Integer t$24 -> {
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
        final Color__Paint s$25 = p;
        switch (s$25) {
            case Color__Plain(var t$26) -> {
                final var c = t$26;
                return color__drawn(c);
            }
            case Color__Linear(var t$27, var t$28, var t$29, var t$30, var t$31, var t$32, var t$33) -> {
                final double x1 = t$27;
                final double y1 = t$28;
                final double x2 = t$29;
                final double y2 = t$30;
                final var start = t$31;
                final var end = t$32;
                final var stops = t$33;
                return "linear-gradient(" + floats4(x1, y1, x2, y2) + "); 0.0 " + color__css(start) + "; 1.0 " + color__css(end) + stops;
            }
            case Color__Radial(var t$34, var t$35, var t$36, var t$37, var t$38, var t$39, var t$40, var t$41, var t$42) -> {
                final double x12 = t$34;
                final double y12 = t$35;
                final double r1 = t$36;
                final double x22 = t$37;
                final double y22 = t$38;
                final double r2 = t$39;
                final var start2 = t$40;
                final var end2 = t$41;
                final var stops2 = t$42;
                return "radial-gradient(" + floats3(x12, y12, r1) + " " + floats3(x22, y22, r2) + "); 0.0 " + color__css(start2) + "; 1.0 " + color__css(end2) + stops2;
            }
            case Color__Conic(var t$43, var t$44, var t$45, var t$46, var t$47, var t$48) -> {
                final double x = t$43;
                final double y = t$44;
                final double angle = t$45;
                final var start3 = t$46;
                final var end3 = t$47;
                final var stops3 = t$48;
                return "conic-gradient(" + floats3(x, y, angle) + "); 0.0 " + color__css(start3) + "; 1.0 " + color__css(end3) + stops3;
            }
            default -> {
                throw new IllegalStateException();
            }
        }
    }

    private static boolean color__painted(final Color__Paint p) {
        final Color__Paint s$49 = p;
        switch (s$49) {
            case Color__Plain(var t$50) -> {
                final var c = t$50;
                return c.a() > 0.0;
            }
            case Color__Paint t$51 -> {
                return true;
            }
        }
    }

    public static Color__Color color__rgb(final int r, final int g, final int b) {
        return new Color__Color(color__part(r), color__part(g), color__part(b), 1.0);
    }

    public static Color__Color color__rgba(final int r, final int g, final int b, final double a) {
        return new Color__Color(color__part(r), color__part(g), color__part(b), a < 0.0 ? 0.0 : a > 1.0 ? 1.0 : a);
    }

    public static Color__Color color__hsl(final double h, final double s, final double l) {
        final var hue = color__wrap(h, 360.0) / 60.0;
        final var sat = color__unit(s / 100.0);
        final var light = color__unit(l / 100.0);
        final var chroma = (1.0 - color__absolute(2.0 * light - 1.0)) * sat;
        final var x = chroma * (1.0 - color__absolute(color__wrap(hue, 2.0) - 1.0));
        final var m = light - chroma / 2.0;
        final PykRuntime.T3<Double, Double, Double> t$52 = color__sector(PykRuntime.truncate(hue), chroma, x);
        final double r = t$52.a0();
        final double g = t$52.a1();
        final double b = t$52.a2();
        return new Color__Color(color__byte(r + m), color__byte(g + m), color__byte(b + m), 1.0);
    }

    public static Color__Color color__hex(final int n) {
        return new Color__Color(color__part(n / 65536), color__part(n / 256 - n / 65536 * 256), color__part(n - n / 256 * 256), 1.0);
    }

    public static int color__to_hex(final Color__Color c) {
        return color__part(c.r()) * 65536 + color__part(c.g()) * 256 + color__part(c.b());
    }

    public static Color__Color color__with_alpha(final Color__Color c, final double a) {
        return new Color__Color(c.r(), c.g(), c.b(), color__unit(a));
    }

    public static Color__Color color__mix(final Color__Color a, final Color__Color b, final double t) {
        final var k = color__unit(t);
        return new Color__Color(color__byte(color__between(a.r(), b.r(), k) / 255.0), color__byte(color__between(a.g(), b.g(), k) / 255.0), color__byte(color__between(a.b(), b.b(), k) / 255.0), a.a() + (b.a() - a.a()) * k);
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

    public static void clear(final String c, final Color__Color fill) {
        TinywebExternal.fill_canvas(c, color__css(fill));
    }

    public static Color__Color circle__default__stroke() {
        return color__none;
    }

    public static Color__Paint circle__default__paint() {
        return Color__Plain(color__none);
    }

    public static Style circle__default__style() {
        return new Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint());
    }

    public static void circle(final String c, final int x, final int y, final int radius, final Color__Color fill, final Color__Color stroke, final int width, final double alpha, final Color__Paint paint, final Style style) {
        shape(c, "circle", numbers3(x, y, radius), fill, stroke, width, alpha, paint, style);
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

    public static Color__Color ellipse__default__stroke() {
        return color__none;
    }

    public static Color__Paint ellipse__default__paint() {
        return Color__Plain(color__none);
    }

    public static Style ellipse__default__style() {
        return new Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint());
    }

    public static void ellipse(final String c, final int x, final int y, final int rx, final int ry, final Color__Color fill, final Color__Color stroke, final int width, final double alpha, final Color__Paint paint, final Style style) {
        shape(c, "ellipse", numbers4(x, y, rx, ry), fill, stroke, width, alpha, paint, style);
    }

    public static Color__Color arc__default__stroke() {
        return color__none;
    }

    public static Color__Paint arc__default__paint() {
        return Color__Plain(color__none);
    }

    public static Style arc__default__style() {
        return new Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint());
    }

    public static void arc(final String c, final int x, final int y, final int radius, final double start, final double end, final Color__Color fill, final Color__Color stroke, final int width, final double alpha, final Color__Paint paint, final Style style) {
        shape(c, "arc", numbers3(x, y, radius) + " " + floats2(start, end), fill, stroke, width, alpha, paint, style);
    }

    public static Style line__default__style() {
        return new Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint());
    }

    public static void line(final String c, final int x1, final int y1, final int x2, final int y2, final Color__Color stroke, final int width, final double alpha, final Style style) {
        stroked(c, "line", numbers4(x1, y1, x2, y2), stroke, width, alpha, style);
    }

    public static Style curve__default__style() {
        return new Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint());
    }

    public static void curve(final String c, final int x1, final int y1, final int cx, final int cy, final int x2, final int y2, final Color__Color stroke, final int width, final double alpha, final Style style) {
        stroked(c, "curve", numbers2(x1, y1) + " " + numbers4(cx, cy, x2, y2), stroke, width, alpha, style);
    }

    public static Color__Color text__default__stroke() {
        return color__none;
    }

    public static Color__Paint text__default__paint() {
        return Color__Plain(color__none);
    }

    public static Style text__default__style() {
        return new Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint());
    }

    public static void text(final String c, final int x, final int y, final String words, final Color__Color fill, final int size, final String font, final String align, final boolean bold, final double alpha, final String baseline, final Color__Color stroke, final int width, final Color__Paint paint, final Style style) {
        TinywebExternal.draw_text(c, (double) x, (double) y, words, fill_of(fill, paint, style), size, font, align, baseline, bold, stroke_of(stroke, style), width_of(width, style), alpha_of(alpha, style));
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
