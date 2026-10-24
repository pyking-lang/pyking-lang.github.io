// Generated from text.pyk by the Pyking compiler. Do not edit.
// Target: java21. The module 'text' of the program; compile it with the others.

public final class Text {

    private static int within(final int k, final int top) {
        if (k < 0) {
            return 0;
        } else if (k > top) {
            return top;
        } else {
            return k;
        }
    }

    public static int length(final String s) {
        return TextExternal.host_length(s);
    }

    public static String slice(final String s, final int start, final int stop) {
        final var n = TextExternal.host_length(s);
        final var a = within(start, n);
        final var b = within(stop, n);
        return b <= a ? "" : TextExternal.host_slice(s, a, b);
    }

    public static String char_at(final String s, final int k) {
        if (k < 0) {
            return "";
        } else if (k < TextExternal.host_length(s)) {
            return TextExternal.host_slice(s, k, k + 1);
        } else {
            return "";
        }
    }

    public static String upper(final String s) {
        return TextExternal.host_upper(s);
    }

    public static void init() {
    }
}
