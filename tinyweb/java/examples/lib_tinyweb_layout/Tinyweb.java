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

    private static void nothing() {

    }

    private static void ignore(final int value) {

    }

    private static void ignore_text(final String value) {

    }

    private static String numbers2(final int a, final int b) {
        return String.valueOf(a) + " " + String.valueOf(b);
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

    private static boolean color__is_theme(final Color__Color c) {
        return c.a() < 0.0;
    }

    public static void web_init(final int port) {
        TinywebExternal.web_start(port);
    }

    public static java.util.function.Supplier<Void> button__default__on_click() {
        return () -> { nothing(); return null; };
    }

    public static String button(final String title, final java.util.function.Supplier<Void> on_click) {
        return TinywebExternal.make_button(title, on_click::get);
    }

    public static java.util.function.Function<Integer, Void> slider__default__on_change() {
        return p$1 -> { ignore(p$1); return null; };
    }

    public static String slider(final int low, final int high, final int value, final java.util.function.Function<Integer, Void> on_change) {
        return TinywebExternal.make_slider(low, high, value, on_change::apply);
    }

    public static String value_of(final String id) {
        return TinywebExternal.report_text("value." + id);
    }

    private static void style_text(final String id, final String kind, final String property, final String value) {
        if (value.equals("")) {

        } else {
            TinywebExternal.apply_style(id, kind, property, value);
        }
    }

    private static void style_color(final String id, final String kind, final String property, final Color__Color c) {
        if (color__is_theme(c)) {

        } else {
            TinywebExternal.apply_style(id, kind, property, color__css(c));
        }
    }

    private static void style_border(final String id, final String kind, final Color__Color border, final int width) {
        if (color__is_theme(border)) {
            if (width >= 0) {
                TinywebExternal.apply_style(id, kind, "border", String.valueOf(width) + "px solid currentColor");
            }
        } else if (border.a() <= 0.0) {
            TinywebExternal.apply_style(id, kind, "border", "none");
        } else {
            TinywebExternal.apply_style(id, kind, "border", String.valueOf(width >= 0 ? width : 1) + "px solid " + color__css(border));
        }
    }

    private static void style_pixels(final String id, final String kind, final String property, final int value) {
        if (value < 0) {

        } else {
            TinywebExternal.apply_style(id, kind, property, String.valueOf(value) + "px");
        }
    }

    public static Color__Color page_style__default__background() {
        return color__theme;
    }

    public static Color__Color page_style__default__foreground() {
        return color__theme;
    }

    public static void page_style(final Color__Color background, final Color__Color foreground, final String font, final int size, final int padding, final int gap, final String align) {
        style_color("", "page", "background", background);
        style_color("", "page", "color", foreground);
        style_text("", "page", "font", font);
        style_pixels("", "page", "size", size);
        style_pixels("", "page", "padding", padding);
        style_pixels("", "page", "gap", gap);
        style_text("", "page", "align", align);
    }

    public static Color__Color set_style__default__background() {
        return color__theme;
    }

    public static Color__Color set_style__default__foreground() {
        return color__theme;
    }

    public static Color__Color set_style__default__border() {
        return color__theme;
    }

    public static Color__Color set_style__default__accent() {
        return color__theme;
    }

    public static void set_style(final String id, final Color__Color background, final Color__Color foreground, final Color__Color border, final int border_width, final int radius, final String font, final int size, final int padding, final Color__Color accent, final int width, final int weight, final int height) {
        style_color(id, "element", "background", background);
        style_color(id, "element", "color", foreground);
        style_border(id, "element", border, border_width);
        style_pixels(id, "element", "radius", radius);
        style_text(id, "element", "font", font);
        style_pixels(id, "element", "size", size);
        style_pixels(id, "element", "padding", padding);
        style_color(id, "element", "accent", accent);
        style_pixels(id, "element", "width", width);
        if (weight >= 0) {
            style_text(id, "element", "weight", String.valueOf(weight));
        }
        style_pixels(id, "element", "height", height);
    }

    public static void on_click(final String c, final java.util.function.BiFunction<Integer, Integer, Void> f) {
        TinywebExternal.on_mouse(c, f::apply);
    }

    public static String layout__row() {
        return TinywebExternal.row();
    }

    public static String layout__column() {
        return TinywebExternal.column();
    }

    public static void layout__inside(final String id) {
        TinywebExternal.inside(id);
    }

    public static void layout__outside() {
        TinywebExternal.outside();
    }

    public static java.util.function.Function<String, Void> layout__text_area__default__on_change() {
        return p$1 -> { ignore_text(p$1); return null; };
    }

    public static String layout__text_area(final String words, final int rows, final int columns, final java.util.function.Function<String, Void> on_change) {
        final var id = TinywebExternal.fresh_id("text");
        TinywebExternal.watch_text(id, "change", "value." + id, on_change::apply);
        TinywebExternal.command("text_area", id, words, numbers2(rows, columns), 0);
        return id;
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
