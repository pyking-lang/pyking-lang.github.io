// Generated from lib_tinyweb_image.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java PykRuntime.java
//         then run with:            java Program

public final class Program {

    private static String c;
    private static String ball;
    private static String star;
    private static String again;

    private static void draw(final double t) {
        Tinyweb.clear(c, Tinyweb.color__hex(2105408));
        Tinyweb.image(c, ball, PykRuntime.truncate(t * 100.0), 20, 40, 40, 1.0);
        Tinyweb.image(c, star, 140, 20, 50, 50, 0.5);
    }

    public static void main(String[] args) {
        Math.init();
        Text.init();
        Tinyweb.init();
        Tinyweb.web_init(0);
        c = TinywebExternal.canvas(200, 100);
        ball = TinywebExternal.load_image("ball.png");
        star = TinywebExternal.load_image("star.png");
        again = TinywebExternal.load_image("ball.png");
        System.out.println(again);
        TinywebExternal.on_frame(c$1 -> draw(c$1));
    }
}
