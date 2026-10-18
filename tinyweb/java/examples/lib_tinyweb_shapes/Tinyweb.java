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

    public static int rect__default__outline_width() {
        return 1;
    }

    public static double rect__default__alpha() {
        return 1.0;
    }

    public static void rect(final String c, final int x, final int y, final int width, final int height, final String color, final String outline, final int outline_width, final double alpha, final int radius) {
        TinywebExternal.draw_shape(c, "rect", numbers4(x, y, width, height) + " " + String.valueOf(radius), color, outline, (double) outline_width, alpha);
    }

    public static String ellipse__default__outline() {
        return "";
    }

    public static int ellipse__default__outline_width() {
        return 1;
    }

    public static void ellipse(final String c, final int x, final int y, final int rx, final int ry, final String color, final String outline, final int outline_width, final double alpha) {
        TinywebExternal.draw_shape(c, "ellipse", numbers4(x, y, rx, ry), color, outline, (double) outline_width, alpha);
    }

    public static String arc__default__outline() {
        return "";
    }

    public static int arc__default__outline_width() {
        return 1;
    }

    public static double arc__default__alpha() {
        return 1.0;
    }

    public static void arc(final String c, final int x, final int y, final int radius, final double start, final double end, final String color, final String outline, final int outline_width, final double alpha) {
        TinywebExternal.draw_shape(c, "arc", numbers3(x, y, radius) + " " + PykRuntime.floatStr(start) + " " + PykRuntime.floatStr(end), color, outline, (double) outline_width, alpha);
    }

    public static double line__default__alpha() {
        return 1.0;
    }

    public static void line(final String c, final int x1, final int y1, final int x2, final int y2, final String color, final int width, final double alpha) {
        TinywebExternal.draw_shape(c, "line", numbers4(x1, y1, x2, y2), "", color, (double) width, alpha);
    }

    public static void curve(final String c, final int x1, final int y1, final int cx, final int cy, final int x2, final int y2, final String color, final int width, final double alpha) {
        TinywebExternal.draw_shape(c, "curve", numbers2(x1, y1) + " " + numbers4(cx, cy, x2, y2), "", color, (double) width, alpha);
    }

    public static double text__default__alpha() {
        return 1.0;
    }

    public static String text__default__baseline() {
        return "top";
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

    private static String colors__hex2(final int n) {
        final var clamped = n < 0 ? 0 : n > 255 ? 255 : n;
        return colors__hex_digit(clamped / 16) + colors__hex_digit(clamped - clamped / 16 * 16);
    }

    private static String colors__hex_digit(final int d) {
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

    public static String colors__rgb(final int r, final int g, final int b) {
        return "#" + colors__hex2(r) + colors__hex2(g) + colors__hex2(b);
    }

    public static String colors__rgba(final int r, final int g, final int b, final double a) {
        return "rgba(" + String.valueOf(r) + ", " + String.valueOf(g) + ", " + String.valueOf(b) + ", " + PykRuntime.floatStr(a) + ")";
    }

    public static String colors__hsl(final int h, final int s, final int l) {
        return "hsl(" + String.valueOf(h) + ", " + String.valueOf(s) + "%, " + String.valueOf(l) + "%)";
    }

    public static void init() {
    }
}
