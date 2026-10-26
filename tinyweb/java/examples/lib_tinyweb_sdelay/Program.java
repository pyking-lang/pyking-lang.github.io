// Generated from lib_tinyweb_sdelay.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java PykRuntime.java
//         then run with:            java Program

public final class Program {

    private static String c;
    private static String piano;
    private static int round;

    public static void main(String[] args) {
        Math.init();
        Text.init();
        Tinyweb.init();
        Tinyweb.web_init(0);
        c = TinywebExternal.canvas(200, 40);
        piano = TinywebExternal.load_sample("piano_c1.wav");
        round = 0;
        while (true) {
            Tinyweb.play(piano, 0.0, 1.0, 1.0, 0.0, Tinyweb.play__default__voice());
            System.out.println("round" + " " + String.valueOf(round) + " " + "at" + " " + PykRuntime.floatStr(TinywebExternal.time()));
            Tinyweb.circle(c, 10 + 20 * round, 20, 8, Tinyweb.color__orange, Tinyweb.circle__default__stroke(), 1, 1.0, Tinyweb.circle__default__paint(), Tinyweb.circle__default__style());
            round = round + 1;
            if (round == 8) {
                break;
            }
            TinywebExternal.sdelay(round == 4 ? 0.5 : 0.25);
        }
        TinywebExternal.splash();
    }
}
