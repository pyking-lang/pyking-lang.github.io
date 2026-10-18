// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// Target: java21. The module 'tinyweb' of the program; compile it with the others.

public final class Tinyweb {

    public static void web_init(final int port) {
        TinywebExternal.web_start(port);
    }

    public static String button(final String title, final java.util.function.Supplier<Void> on_click) {
        return TinywebExternal.make_button(title, on_click::get);
    }

    public static double play__default__at() {
        return 0.0;
    }

    public static double play__default__rate() {
        return 1.0;
    }

    public static void play(final String sample, final double at, final double volume, final double rate) {
        TinywebExternal.play_sample(sample, at, volume, rate);
    }

    public static void init() {
    }
}
