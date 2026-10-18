// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// Target: java21. The module 'tinyweb' of the program; compile it with the others.

public final class Tinyweb {

    private static String numbers2(final int a, final int b) {
        return String.valueOf(a) + " " + String.valueOf(b);
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

    public static void web_init(final int port) {
        TinywebExternal.web_start(port);
    }

    public static String polygon__default__outline() {
        return "";
    }

    public static int polygon__default__outline_width() {
        return 1;
    }

    public static double polygon__default__alpha() {
        return 1.0;
    }

    public static void polygon(final String c, final java.util.List<PykRuntime.T2<Integer, Integer>> points, final String color, final String outline, final int outline_width, final double alpha) {
        TinywebExternal.draw_shape(c, "polygon", points_text(points), color, outline, (double) outline_width, alpha);
    }

    public static double path__default__alpha() {
        return 1.0;
    }

    public static void path(final String c, final java.util.List<PykRuntime.T2<Integer, Integer>> points, final String color, final int width, final double alpha) {
        TinywebExternal.draw_shape(c, "path", points_text(points), "", color, (double) width, alpha);
    }

    public static java.util.List<String> colors__palette(final String name) {
        final String s$3 = name;
        switch (s$3) {
            case String t$4 when "ocean".equals(t$4) -> {
                return java.util.Arrays.asList("#03045e", "#0077b6", "#00b4d8", "#90e0ef", "#caf0f8");
            }
            case String t$5 when "candy".equals(t$5) -> {
                return java.util.Arrays.asList("#ff70a6", "#ff9770", "#ffd670", "#e9ff70", "#70d6ff");
            }
            case String t$6 when "forest".equals(t$6) -> {
                return java.util.Arrays.asList("#2d6a4f", "#40916c", "#52b788", "#95d5b2", "#d8f3dc");
            }
            case String t$7 when "sunset".equals(t$7) -> {
                return java.util.Arrays.asList("#f94144", "#f3722c", "#f8961e", "#f9c74f", "#90be6d");
            }
            case String t$8 when "neon".equals(t$8) -> {
                return java.util.Arrays.asList("#ff00ff", "#00ffff", "#39ff14", "#ffff00", "#ff3131");
            }
            case String t$9 -> {
                System.err.println("tinyweb: there is no palette called \"" + name + "\"; the palettes are ocean, candy, forest, sunset and neon");
                return java.util.Collections.emptyList();
            }
        }
    }

    public static void init() {
    }
}
