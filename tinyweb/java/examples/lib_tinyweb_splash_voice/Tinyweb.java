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

    public static void on_click(final String c, final java.util.function.BiFunction<Integer, Integer, Void> f) {
        TinywebExternal.on_mouse(c, f::apply);
    }

    private static String sound__settings(final double at, final double volume, final double rate, final double pan, final Sound__Voice voice) {
        final double v = volume == 1.0 ? voice.volume() : volume;
        final double r = rate == 1.0 ? voice.rate() : rate;
        final double p = pan == 0.0 ? voice.pan() : pan;
        return floats4(at, v, r, p) + " " + String.valueOf((Object) voice.channel()) + " " + bit(voice.reverse());
    }

    public static Sound__Voice sound__start__default__voice() {
        return new Sound__Voice(1.0, 1.0, 0.0, 0, false, false);
    }

    public static String sound__start(final String sample, final double at, final double volume, final double rate, final double pan, final boolean looping, final Sound__Voice voice) {
        final var id = TinywebExternal.fresh_id("voice");
        final boolean looped = looping ? true : voice.looping();
        TinywebExternal.command("start", id, sample, sound__settings(at, volume, rate, pan, voice) + " " + bit(looped), 2);
        return id;
    }

    public static void sound__tone(final double frequency, final double at, final double duration, final String wave, final double volume, final double pan, final int channel) {
        TinywebExternal.command("tone", "", wave, floats4(frequency, at, duration, volume) + " " + PykRuntime.floatStr(pan) + " " + String.valueOf(channel), 2);
    }

    public static double sound__note(final String name) {
        final var semitones = sound__semitones(name);
        return semitones < -1000 ? 0.0 : 440.0 * Math.pow(2.0, (double) (semitones - 57) / 12.0);
    }

    private static int sound__semitones(final String name) {
        final int base;
        final String s$1 = Text.upper(Text.char_at(name, 0));
        switch (s$1) {
            case String t$2 when "C".equals(t$2) -> {
                base = 0;
            }
            case String t$3 when "D".equals(t$3) -> {
                base = 2;
            }
            case String t$4 when "E".equals(t$4) -> {
                base = 4;
            }
            case String t$5 when "F".equals(t$5) -> {
                base = 5;
            }
            case String t$6 when "G".equals(t$6) -> {
                base = 7;
            }
            case String t$7 when "A".equals(t$7) -> {
                base = 9;
            }
            case String t$8 when "B".equals(t$8) -> {
                base = 11;
            }
            case String t$9 -> {
                base = -10000;
            }
        }
        final int shift;
        final String s$10 = Text.char_at(name, 1);
        switch (s$10) {
            case String t$11 when "#".equals(t$11) -> {
                shift = 1;
            }
            case String t$12 when "b".equals(t$12) -> {
                shift = -1;
            }
            case String t$13 -> {
                shift = 0;
            }
        }
        final var rest = Text.slice(name, shift == 0 ? 1 : 2, Text.length(name));
        final var octave = rest.equals("") ? 4 : PykRuntime.intOfString(rest);
        final var valid = base < 0 ? false : rest.equals("") ? true : String.valueOf(octave).equals(rest);
        return valid ? base + shift + octave * 12 : -10000;
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
