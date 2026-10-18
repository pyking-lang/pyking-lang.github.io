// Generated from lib_tinyweb_frames.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java PykRuntime.java
//         then run with:            java Program

public final class Program {

    private static String c;
    private static String kick;
    private static double beat;
    private static double next_beat;

    private static void draw(final double t) {
        Tinyweb.clear(c, "#111111");
        Tinyweb.circle(c, PykRuntime.truncate(t * 100.0), 50, 10, "#ffcc00", Tinyweb.circle__default__outline(), Tinyweb.circle__default__outline_width(), Tinyweb.circle__default__alpha());
        if (t >= next_beat) {
            System.out.println("beat scheduled at " + PykRuntime.floatStr(next_beat + beat) + ", drawn at " + PykRuntime.floatStr(t));
            Tinyweb.play(kick, next_beat + beat, Tinyweb.play__default__volume(), Tinyweb.play__default__rate());
            next_beat = next_beat + beat;
        }
    }

    public static void main(String[] args) {
        Tinyweb.init();
        Tinyweb.web_init(0);
        c = TinywebExternal.canvas(200, 100);
        kick = TinywebExternal.load_sample("kick1.wav");
        beat = 0.5;
        next_beat = 0.0;
        TinywebExternal.on_frame(c$1 -> draw(c$1));
        System.out.println(PykRuntime.floatStr(TinywebExternal.time()));
        TinywebExternal.splash();
    }
}
