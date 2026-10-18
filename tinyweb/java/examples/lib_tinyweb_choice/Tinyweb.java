// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// Target: java21. The module 'tinyweb' of the program; compile it with the others.

public final class Tinyweb {

    private static void ignore(final int value) {

    }

    public static void web_init(final int port) {
        TinywebExternal.web_start(port);
    }

    private static String lines_of(final java.util.List<String> options) {
        final java.util.List<String> s$1 = options;
        switch (s$1) {
            case java.util.List<String> t$2 when t$2.size() == 0 -> {
                return "";
            }
            case java.util.List<String> t$3 when t$3.size() == 1 -> {
                final var only = t$3.get(0);
                return only;
            }
            case java.util.List<String> t$4 when t$4.size() >= 1 -> {
                final var first = t$4.get(0);
                final java.util.List<String> rest = t$4.subList(1, t$4.size() - 0);
                return first + "\n" + lines_of(rest);
            }
            default -> {
                throw new IllegalStateException();
            }
        }
    }

    public static int choice__default__chosen() {
        return 0;
    }

    public static java.util.function.Function<Integer, Void> choice__default__on_change() {
        return p$1 -> { ignore(p$1); return null; };
    }

    public static String choice(final java.util.List<String> options, final int chosen, final java.util.function.Function<Integer, Void> on_change) {
        return TinywebExternal.make_choice(lines_of(options), chosen, on_change::apply);
    }

    public static void init() {
    }
}
