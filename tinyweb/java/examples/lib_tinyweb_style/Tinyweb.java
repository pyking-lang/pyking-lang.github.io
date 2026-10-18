// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// Target: java21. The module 'tinyweb' of the program; compile it with the others.

public final class Tinyweb {

    private static void ignore(final int value) {

    }

    public static void web_init(final int port) {
        TinywebExternal.web_start(port);
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

    private static boolean known_theme(final String name) {
        final String s$1 = name;
        switch (s$1) {
            case String t$2 when "light".equals(t$2) -> {
                return true;
            }
            case String t$3 when "dark".equals(t$3) -> {
                return true;
            }
            case String t$4 when "plain".equals(t$4) -> {
                return true;
            }
            case String t$5 when "paper".equals(t$5) -> {
                return true;
            }
            case String t$6 when "retro".equals(t$6) -> {
                return true;
            }
            case String t$7 -> {
                return false;
            }
        }
    }

    private static void style_text(final String id, final String kind, final String property, final String value) {
        if (value.equals("")) {

        } else {
            TinywebExternal.apply_style(id, kind, property, value);
        }
    }

    private static void style_pixels(final String id, final String kind, final String property, final int value) {
        if (value < 0) {

        } else {
            TinywebExternal.apply_style(id, kind, property, String.valueOf(value) + "px");
        }
    }

    public static void theme(final String name) {
        if (known_theme(name)) {
            TinywebExternal.apply_style("", "theme", "name", name);
        } else {
            System.err.println("tinyweb: there is no theme called \"" + name + "\"; the themes are light, dark, plain, paper and retro");
        }
    }

    public static String page_style__default__align() {
        return "";
    }

    public static void page_style(final String background, final String color, final String font, final int size, final int padding, final int gap, final String align) {
        style_text("", "page", "background", background);
        style_text("", "page", "color", color);
        style_text("", "page", "font", font);
        style_pixels("", "page", "size", size);
        style_pixels("", "page", "padding", padding);
        style_pixels("", "page", "gap", gap);
        style_text("", "page", "align", align);
    }

    public static void button_style(final String background, final String color, final String border, final int radius, final String font, final int size, final int padding) {
        style_text("", "button", "background", background);
        style_text("", "button", "color", color);
        style_text("", "button", "border", border);
        style_pixels("", "button", "radius", radius);
        style_text("", "button", "font", font);
        style_pixels("", "button", "size", size);
        style_pixels("", "button", "padding", padding);
    }

    public static void label_style(final String background, final String color, final String border, final int radius, final String font, final int size, final int padding) {
        style_text("", "label", "background", background);
        style_text("", "label", "color", color);
        style_text("", "label", "border", border);
        style_pixels("", "label", "radius", radius);
        style_text("", "label", "font", font);
        style_pixels("", "label", "size", size);
        style_pixels("", "label", "padding", padding);
    }

    public static void slider_style(final String accent, final int width, final String color, final String font, final int size) {
        style_text("", "slider", "accent", accent);
        style_pixels("", "slider", "width", width);
        style_text("", "slider", "color", color);
        style_text("", "slider", "font", font);
        style_pixels("", "slider", "size", size);
    }

    public static void canvas_style(final String border, final int radius) {
        style_text("", "canvas", "border", border);
        style_pixels("", "canvas", "radius", radius);
    }

    public static String set_colors__default__color() {
        return "";
    }

    public static String set_colors__default__background() {
        return "";
    }

    public static void set_colors(final String id, final String color, final String background) {
        style_text(id, "element", "color", color);
        style_text(id, "element", "accent", color);
        style_text(id, "element", "background", background);
    }

    public static String set_style__default__background() {
        return "";
    }

    public static String set_style__default__color() {
        return "";
    }

    public static int set_style__default__radius() {
        return -1;
    }

    public static String set_style__default__font() {
        return "";
    }

    public static int set_style__default__size() {
        return -1;
    }

    public static int set_style__default__padding() {
        return -1;
    }

    public static String set_style__default__accent() {
        return "";
    }

    public static int set_style__default__width() {
        return -1;
    }

    public static int set_style__default__weight() {
        return -1;
    }

    public static int set_style__default__height() {
        return -1;
    }

    public static void set_style(final String id, final String background, final String color, final String border, final int radius, final String font, final int size, final int padding, final String accent, final int width, final int weight, final int height) {
        style_text(id, "element", "background", background);
        style_text(id, "element", "color", color);
        style_text(id, "element", "border", border);
        style_pixels(id, "element", "radius", radius);
        style_text(id, "element", "font", font);
        style_pixels(id, "element", "size", size);
        style_pixels(id, "element", "padding", padding);
        style_text(id, "element", "accent", accent);
        style_pixels(id, "element", "width", width);
        if (weight >= 0) {
            style_text(id, "element", "weight", String.valueOf(weight));
        }
        style_pixels(id, "element", "height", height);
    }

    public static void init() {
    }
}
