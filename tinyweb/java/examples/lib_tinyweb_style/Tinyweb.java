// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// Target: java21. The module 'tinyweb' of the program; compile it with the others.

public final class Tinyweb {

    private static void ignore(final int value) {

    }

    public static int button(final String title, final Runnable on_click) {
        return TinywebExternal.make_button(title, on_click);
    }

    public static java.util.function.Consumer<Integer> slider__default__on_change() {
        return (p$1) -> ignore(p$1);
    }

    public static int slider(final int low, final int high, final int value, final java.util.function.Consumer<Integer> on_change) {
        return TinywebExternal.make_slider(low, high, value, on_change);
    }

    private static boolean known_theme(final String name) {
        var __subject = name;
        if (__subject.equals("light")) {
            return true;
        } else if (__subject.equals("dark")) {
            return true;
        } else if (__subject.equals("plain")) {
            return true;
        } else if (__subject.equals("paper")) {
            return true;
        } else if (__subject.equals("retro")) {
            return true;
        } else {
            return false;
        }
    }

    private static void style_text(final int id, final String kind, final String property, final String value) {
        if (value.equals("")) {

        } else {
            TinywebExternal.apply_style(id, kind, property, value);
        }
    }

    private static void style_pixels(final int id, final String kind, final String property, final int value) {
        if (value < 0) {

        } else {
            TinywebExternal.apply_style(id, kind, property, String.valueOf(value) + "px");
        }
    }

    public static void theme(final String name) {
        if (known_theme(name)) {
            TinywebExternal.apply_style(0, "theme", "name", name);
        } else {
            System.err.println("tinyweb: there is no theme called \"" + name + "\"; the themes are light, dark, plain, paper and retro");
        }
    }

    public static void page_style(final String background, final String color, final String font, final int size, final int padding, final int gap) {
        style_text(0, "page", "background", background);
        style_text(0, "page", "color", color);
        style_text(0, "page", "font", font);
        style_pixels(0, "page", "size", size);
        style_pixels(0, "page", "padding", padding);
        style_pixels(0, "page", "gap", gap);
    }

    public static void button_style(final String background, final String color, final String border, final int radius, final String font, final int size, final int padding) {
        style_text(0, "button", "background", background);
        style_text(0, "button", "color", color);
        style_text(0, "button", "border", border);
        style_pixels(0, "button", "radius", radius);
        style_text(0, "button", "font", font);
        style_pixels(0, "button", "size", size);
        style_pixels(0, "button", "padding", padding);
    }

    public static void label_style(final String background, final String color, final String border, final int radius, final String font, final int size, final int padding) {
        style_text(0, "label", "background", background);
        style_text(0, "label", "color", color);
        style_text(0, "label", "border", border);
        style_pixels(0, "label", "radius", radius);
        style_text(0, "label", "font", font);
        style_pixels(0, "label", "size", size);
        style_pixels(0, "label", "padding", padding);
    }

    public static void slider_style(final String accent, final int width, final String color, final String font, final int size) {
        style_text(0, "slider", "accent", accent);
        style_pixels(0, "slider", "width", width);
        style_text(0, "slider", "color", color);
        style_text(0, "slider", "font", font);
        style_pixels(0, "slider", "size", size);
    }

    public static void canvas_style(final String border, final int radius) {
        style_text(0, "canvas", "border", border);
        style_pixels(0, "canvas", "radius", radius);
    }

    public static String set_colors__default__color() {
        return "";
    }

    public static String set_colors__default__background() {
        return "";
    }

    public static void set_colors(final int id, final String color, final String background) {
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

    public static void set_style(final int id, final String background, final String color, final String border, final int radius, final String font, final int size, final int padding, final String accent, final int width) {
        style_text(id, "element", "background", background);
        style_text(id, "element", "color", color);
        style_text(id, "element", "border", border);
        style_pixels(id, "element", "radius", radius);
        style_text(id, "element", "font", font);
        style_pixels(id, "element", "size", size);
        style_pixels(id, "element", "padding", padding);
        style_text(id, "element", "accent", accent);
        style_pixels(id, "element", "width", width);
    }

    public static void init() {

    }
}
