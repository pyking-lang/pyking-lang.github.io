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

    private static String floats2(final double a, final double b) {
        return PykRuntime.floatStr(a) + " " + PykRuntime.floatStr(b);
    }

    private static String floats3(final double a, final double b, final double c) {
        return floats2(a, b) + " " + PykRuntime.floatStr(c);
    }

    private static String floats4(final double a, final double b, final double c, final double d) {
        return floats2(a, b) + " " + floats2(c, d);
    }

    private static String bit(final boolean on) {
        return on ? "1" : "0";
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
        final Integer s$1 = d;
        switch (s$1) {
            case Integer t$2 when PykRuntime.truth((int) t$2 == 0) -> {
                return "0";
            }
            case Integer t$3 when PykRuntime.truth((int) t$3 == 1) -> {
                return "1";
            }
            case Integer t$4 when PykRuntime.truth((int) t$4 == 2) -> {
                return "2";
            }
            case Integer t$5 when PykRuntime.truth((int) t$5 == 3) -> {
                return "3";
            }
            case Integer t$6 when PykRuntime.truth((int) t$6 == 4) -> {
                return "4";
            }
            case Integer t$7 when PykRuntime.truth((int) t$7 == 5) -> {
                return "5";
            }
            case Integer t$8 when PykRuntime.truth((int) t$8 == 6) -> {
                return "6";
            }
            case Integer t$9 when PykRuntime.truth((int) t$9 == 7) -> {
                return "7";
            }
            case Integer t$10 when PykRuntime.truth((int) t$10 == 8) -> {
                return "8";
            }
            case Integer t$11 when PykRuntime.truth((int) t$11 == 9) -> {
                return "9";
            }
            case Integer t$12 when PykRuntime.truth((int) t$12 == 10) -> {
                return "a";
            }
            case Integer t$13 when PykRuntime.truth((int) t$13 == 11) -> {
                return "b";
            }
            case Integer t$14 when PykRuntime.truth((int) t$14 == 12) -> {
                return "c";
            }
            case Integer t$15 when PykRuntime.truth((int) t$15 == 13) -> {
                return "d";
            }
            case Integer t$16 when PykRuntime.truth((int) t$16 == 14) -> {
                return "e";
            }
            case Integer t$17 -> {
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
        final Color__Paint s$18 = p;
        switch (s$18) {
            case Color__Plain(var t$19) -> {
                final var c = t$19;
                return color__drawn(c);
            }
            case Color__Linear(var t$20, var t$21, var t$22, var t$23, var t$24, var t$25, var t$26) -> {
                final double x1 = t$20;
                final double y1 = t$21;
                final double x2 = t$22;
                final double y2 = t$23;
                final var start = t$24;
                final var end = t$25;
                final var stops = t$26;
                return "linear-gradient(" + floats4(x1, y1, x2, y2) + "); 0.0 " + color__css(start) + "; 1.0 " + color__css(end) + stops;
            }
            case Color__Radial(var t$27, var t$28, var t$29, var t$30, var t$31, var t$32, var t$33, var t$34, var t$35) -> {
                final double x12 = t$27;
                final double y12 = t$28;
                final double r1 = t$29;
                final double x22 = t$30;
                final double y22 = t$31;
                final double r2 = t$32;
                final var start2 = t$33;
                final var end2 = t$34;
                final var stops2 = t$35;
                return "radial-gradient(" + floats3(x12, y12, r1) + " " + floats3(x22, y22, r2) + "); 0.0 " + color__css(start2) + "; 1.0 " + color__css(end2) + stops2;
            }
            case Color__Conic(var t$36, var t$37, var t$38, var t$39, var t$40, var t$41) -> {
                final double x = t$36;
                final double y = t$37;
                final double angle = t$38;
                final var start3 = t$39;
                final var end3 = t$40;
                final var stops3 = t$41;
                return "conic-gradient(" + floats3(x, y, angle) + "); 0.0 " + color__css(start3) + "; 1.0 " + color__css(end3) + stops3;
            }
            default -> {
                throw new IllegalStateException();
            }
        }
    }

    private static boolean color__painted(final Color__Paint p) {
        final Color__Paint s$42 = p;
        switch (s$42) {
            case Color__Plain(var t$43) -> {
                final var c = t$43;
                return c.a() > 0.0;
            }
            case Color__Paint t$44 -> {
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

    public static Color__Color line__default__stroke() {
        return color__black;
    }

    public static Style line__default__style() {
        return new Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint());
    }

    public static void line(final String c, final int x1, final int y1, final int x2, final int y2, final Color__Color stroke, final int width, final double alpha, final Style style) {
        stroked(c, "line", numbers4(x1, y1, x2, y2), stroke, width, alpha, style);
    }

    public static Color__Color text__default__fill() {
        return color__black;
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

    public static java.util.function.Function<Integer, Void> slider__default__on_change() {
        return p$1 -> { ignore(p$1); return null; };
    }

    public static String slider(final int low, final int high, final int value, final java.util.function.Function<Integer, Void> on_change) {
        return TinywebExternal.make_slider(low, high, value, on_change::apply);
    }

    public static void set_text(final String id, final String words) {
        TinywebExternal.command("set_text", id, words, "", 1);
    }

    public static void on_click(final String c, final java.util.function.BiFunction<Integer, Integer, Void> f) {
        TinywebExternal.on_mouse(c, f::apply);
    }

    private static String sound__settings(final double at, final double volume, final double rate, final double pan, final Sound__Voice voice) {
        final double v = volume == 1.0 ? voice.volume() : volume;
        final double r = rate == 1.0 ? voice.rate() : rate;
        final double p = pan == 0.0 ? voice.pan() : pan;
        return floats4(at, v, r, p) + " " + String.valueOf((Object) voice.channel()) + " " + bit(voice.reverse());
    }

    public static Sound__Voice play__default__voice() {
        return new Sound__Voice(1.0, 1.0, 0.0, 0, false, false);
    }

    public static void play(final String sample, final double at, final double volume, final double rate, final double pan, final Sound__Voice voice) {
        TinywebExternal.command("play", sample, "", sound__settings(at, volume, rate, pan, voice), 2);
    }

    public static void play_file(final String name) {
        play(TinywebExternal.load_sample(name), 0.0, 1.0, 1.0, 0.0, play__default__voice());
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
