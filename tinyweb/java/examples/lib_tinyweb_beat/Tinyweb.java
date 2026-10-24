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

    private static String floats2(final double a, final double b) {
        return PykRuntime.floatStr(a) + " " + PykRuntime.floatStr(b);
    }

    private static String floats4(final double a, final double b, final double c, final double d) {
        return floats2(a, b) + " " + floats2(c, d);
    }

    private static String bit(final boolean on) {
        return on ? "1" : "0";
    }

    public static void web_init(final int port) {
        TinywebExternal.web_start(port);
    }

    public static String button(final String title, final java.util.function.Supplier<Void> on_click) {
        return TinywebExternal.make_button(title, on_click::get);
    }

    public static String checkbox(final String title, final boolean checked, final java.util.function.Function<Boolean, Void> on_change) {
        return TinywebExternal.make_checkbox(title, checked, on_change::apply);
    }

    public static void on_click(final String c, final java.util.function.BiFunction<Integer, Integer, Void> f) {
        TinywebExternal.on_mouse(c, f::apply);
    }

    private static String sound__settings(final double at, final double volume, final double rate, final double pan, final Sound__Voice voice) {
        final double v = volume == 1.0 ? voice.volume() : volume;
        final double r = rate == 1.0 ? voice.rate() : rate;
        final double p = pan == 0.0 ? voice.pan() : pan;
        return floats4(at, v, r, p) + " " + String.valueOf((Object) voice.channel()) + " " + bit(voice.reverse());
    }

    public static Sound__Voice play__default__voice() {
        return new Sound__Voice(1.0, 1.0, 0.0, 0, false, false);
    }

    public static void play(final String sample, final double at, final double volume, final double rate, final double pan, final Sound__Voice voice) {
        TinywebExternal.command("play", sample, "", sound__settings(at, volume, rate, pan, voice), 2);
    }

    public static void sound__tone(final double frequency, final double at, final double duration, final String wave, final double volume, final double pan, final int channel) {
        TinywebExternal.command("tone", "", wave, floats4(frequency, at, duration, volume) + " " + PykRuntime.floatStr(pan) + " " + String.valueOf(channel), 2);
    }

    public static void sound__tempo(final double bpm) {
        TinywebExternal.command("tempo", "", "", PykRuntime.floatStr(bpm), 1);
    }

    public static void sound__swing(final double amount) {
        TinywebExternal.command("swing", "", "", PykRuntime.floatStr(amount), 1);
    }

    public static String sound__on_beat(final java.util.function.BiFunction<Integer, Double, Void> f, final int steps) {
        final var id = TinywebExternal.fresh_id("beat");
        TinywebExternal.watch_step(id, "beat", f::apply);
        TinywebExternal.command("beat", id, "", String.valueOf(steps), 0);
        return id;
    }

    public static double sound__beat() {
        return TinywebExternal.report_number("clock", 0);
    }

    public static double sound__latency() {
        return TinywebExternal.report_number("clock", 1);
    }

    public static void sound__pause() {
        TinywebExternal.command("audio", "", "pause", "", 2);
    }

    public static void sound__resume() {
        TinywebExternal.command("audio", "", "resume", "", 2);
    }

    public static void sound__listen(final int bins, final double smoothing) {
        TinywebExternal.command("listen", "", "", String.valueOf(bins) + " " + PykRuntime.floatStr(smoothing), 1);
    }

    public static double sound__level() {
        return TinywebExternal.report_number("level", 0);
    }

    public static double sound__band(final int k) {
        return TinywebExternal.report_number("band", k);
    }

    public static int sound__bands() {
        return TinywebExternal.report_count("band");
    }

    public static double sound__wave(final int k) {
        return TinywebExternal.report_number("wave", k);
    }

    public static java.util.function.BiFunction<Double, Double, Void> sound__render_wav__default__on_rendered() {
        return (p$1, p$2) -> { sound__ignore_rendered(p$1, p$2); return null; };
    }

    public static void sound__render_wav(final double seconds, final java.util.function.Supplier<Void> f, final String name, final java.util.function.BiFunction<Double, Double, Void> on_rendered) {
        final var id = TinywebExternal.fresh_id("render");
        TinywebExternal.watch_pair(id, "rendered", on_rendered::apply);
        TinywebExternal.command("render", id, name, PykRuntime.floatStr(seconds), 2);
        f.get();
        TinywebExternal.command("render_end", id, "", "", 2);
    }

    private static void sound__ignore_rendered(final double took, final double peak) {

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
