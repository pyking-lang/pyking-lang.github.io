// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// Target: java21. The module 'tinyweb' of the program; compile it with the others.

public final class Tinyweb {

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

    public static boolean checkbox__default__checked() {
        return false;
    }

    public static java.util.function.Function<Boolean, Void> checkbox__default__on_change() {
        return p$1 -> { ignore_bool(p$1); return null; };
    }

    public static String checkbox(final String title, final boolean checked, final java.util.function.Function<Boolean, Void> on_change) {
        return TinywebExternal.make_checkbox(title, checked, on_change::apply);
    }

    public static boolean radio__default__chosen() {
        return false;
    }

    public static java.util.function.Function<String, Void> radio__default__on_pick() {
        return p$1 -> { ignore_text(p$1); return null; };
    }

    public static String radio(final String group, final String title, final boolean chosen, final java.util.function.Function<String, Void> on_pick) {
        return TinywebExternal.make_radio(group, title, chosen, on_pick::apply);
    }

    public static String text_input__default__placeholder() {
        return "";
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

    public static void init() {
    }
}
