// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// Target: java21. The module 'tinyweb' of the program; compile it with the others.

public final class Tinyweb {

    private static void nothing() {

    }

    private static void ignore(final int value) {

    }

    public static int web_init__default__port() {
        return 0;
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

    public static String page_style__default__background() {
        return "";
    }

    public static String page_style__default__color() {
        return "";
    }

    public static String page_style__default__font() {
        return "";
    }

    public static int page_style__default__size() {
        return -1;
    }

    public static int page_style__default__padding() {
        return -1;
    }

    public static int page_style__default__gap() {
        return -1;
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

    public static String set_style__default__background() {
        return "";
    }

    public static String set_style__default__color() {
        return "";
    }

    public static String set_style__default__border() {
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
