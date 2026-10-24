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

    private static void ignore_bool(final boolean value) {

    }

    private static void ignore_text(final String value) {

    }

    public static void web_init(final int port) {
        TinywebExternal.web_start(port);
    }

    public static java.util.function.Function<Integer, Void> slider__default__on_change() {
        return p$1 -> { ignore(p$1); return null; };
    }

    public static String slider(final int low, final int high, final int value, final java.util.function.Function<Integer, Void> on_change) {
        return TinywebExternal.make_slider(low, high, value, on_change::apply);
    }

    public static java.util.function.Function<Boolean, Void> checkbox__default__on_change() {
        return p$1 -> { ignore_bool(p$1); return null; };
    }

    public static String checkbox(final String title, final boolean checked, final java.util.function.Function<Boolean, Void> on_change) {
        return TinywebExternal.make_checkbox(title, checked, on_change::apply);
    }

    public static java.util.function.Function<String, Void> radio__default__on_pick() {
        return p$1 -> { ignore_text(p$1); return null; };
    }

    public static String radio(final String group, final String title, final boolean chosen, final java.util.function.Function<String, Void> on_pick) {
        return TinywebExternal.make_radio(group, title, chosen, on_pick::apply);
    }

    public static java.util.function.Function<String, Void> text_input__default__on_enter() {
        return p$1 -> { ignore_text(p$1); return null; };
    }

    public static String text_input(final String placeholder, final java.util.function.Function<String, Void> on_enter) {
        return TinywebExternal.make_text_input(placeholder, on_enter::apply);
    }

    public static String number_input(final int low, final int high, final int value, final java.util.function.Function<Integer, Void> on_change) {
        return TinywebExternal.make_number_input(low, high, value, on_change::apply);
    }

    public static void set_text(final String id, final String words) {
        TinywebExternal.command("set_text", id, words, "", 1);
    }

    public static void show(final String id) {
        TinywebExternal.command("visible", id, "", "1", 1);
    }

    public static void hide(final String id) {
        TinywebExternal.command("visible", id, "", "0", 1);
    }

    public static void enable(final String id) {
        TinywebExternal.command("enabled", id, "", "1", 1);
    }

    public static void disable(final String id) {
        TinywebExternal.command("enabled", id, "", "0", 1);
    }

    public static void remove(final String id) {
        TinywebExternal.command("remove", id, "", "", 0);
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
