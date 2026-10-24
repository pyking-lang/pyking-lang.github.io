// Generated from lib_tinyweb_beat.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java PykRuntime.java
//         then run with:            java Program

public final class Program {

    private static String kick;
    private static String hat;
    private static String steps;

    private static void step(final int n, final double time) {
        System.out.println("step" + " " + String.valueOf(n) + " " + "at" + " " + PykRuntime.floatStr(time) + " " + "beat" + " " + PykRuntime.floatStr(Tinyweb.sound__beat()));
        if (n - n / 4 * 4 == 0) {
            Tinyweb.play(kick, time, 1.0, 1.0, 0.0, Tinyweb.play__default__voice());
        }
        Tinyweb.play(hat, time, 0.3, 1.0, 0.0, Tinyweb.play__default__voice());
        if (n == 2) {
            Tinyweb.sound__tempo(90.0);
        }
    }

    private static void listened() {
        System.out.println("level" + " " + PykRuntime.floatStr(Tinyweb.sound__level()) + " " + "bands" + " " + String.valueOf(Tinyweb.sound__bands()) + " " + PykRuntime.floatStr(Tinyweb.sound__band(0)) + " " + PykRuntime.floatStr(Tinyweb.sound__band(7)) + " " + "wave" + " " + PykRuntime.floatStr(Tinyweb.sound__wave(0)) + " " + PykRuntime.floatStr(Tinyweb.sound__wave(3)));
    }

    private static void toggle(final boolean on) {
        if (on) {
            Tinyweb.sound__resume();
        } else {
            Tinyweb.sound__pause();
        }
        System.out.println("playing" + " " + String.valueOf(on));
    }

    private static void song() {
        Tinyweb.play(kick, 0.0, 1.0, 1.0, 0.0, Tinyweb.play__default__voice());
        Tinyweb.play(kick, 0.5, 1.0, 1.0, 0.0, Tinyweb.play__default__voice());
        Tinyweb.sound__tone(220.0, 1.0, 0.25, "sine", 0.5, 0.0, 0);
    }

    private static void done(final double took, final double peak) {
        System.out.println("rendered in" + " " + PykRuntime.floatStr(took) + " " + "seconds, peak" + " " + PykRuntime.floatStr(peak));
    }

    public static void main(String[] args) {
        Math.init();
        Text.init();
        Tinyweb.init();
        Tinyweb.web_init(0);
        kick = TinywebExternal.load_sample("kick1.wav");
        hat = TinywebExternal.load_sample("hihat1.wav");
        Tinyweb.sound__tempo(120.0);
        Tinyweb.sound__swing(0.2);
        Tinyweb.sound__listen(8, 0.5);
        steps = Tinyweb.sound__on_beat((p$1, p$2) -> { step(p$1, p$2); return null; }, 2);
        System.out.println(steps);
        Tinyweb.button("Listen", () -> { listened(); return null; });
        Tinyweb.checkbox("Playing", true, p$1 -> { toggle(p$1); return null; });
        Tinyweb.sound__render_wav(2.0, () -> { song(); return null; }, "song.wav", (p$1, p$2) -> { done(p$1, p$2); return null; });
        Tinyweb.sound__render_wav(1.0, () -> { song(); return null; }, "tinyweb.wav", Tinyweb.sound__render_wav__default__on_rendered());
        System.out.println("latency" + " " + PykRuntime.floatStr(Tinyweb.sound__latency()));
        TinywebExternal.splash();
    }
}
