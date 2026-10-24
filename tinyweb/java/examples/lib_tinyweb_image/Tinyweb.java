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

    public static Color__Color color__hex(final int n) {
        return new Color__Color(color__part(n / 65536), color__part(n / 256 - n / 65536 * 256), color__part(n - n / 256 * 256), 1.0);
    }

    public static void web_init(final int port) {
        TinywebExternal.web_start(port);
    }

    public static void clear(final String c, final Color__Color fill) {
        TinywebExternal.fill_canvas(c, color__css(fill));
    }

    public static void image(final String c, final String picture, final int x, final int y, final int w, final int h, final double alpha) {
        TinywebExternal.draw_image(c, picture, x, y, w, h, alpha);
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
