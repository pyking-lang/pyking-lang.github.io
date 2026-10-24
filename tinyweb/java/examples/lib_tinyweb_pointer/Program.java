// Generated from lib_tinyweb_pointer.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java PykRuntime.java
//         then run with:            java Program

public final class Program {

    private static String c;
    private static String other;
    private static Tinyweb.Pointer start;

    private static void pressed(final int x, final int y) {
        System.out.println("press at" + " " + String.valueOf(x) + " " + String.valueOf(y) + " " + "down" + " " + String.valueOf((Object) Tinyweb.mouse(c).down()));
        Tinyweb.circle(c, x, y, 4, Tinyweb.color__hex(14423100), Tinyweb.circle__default__stroke(), 1, 1.0, Tinyweb.circle__default__paint(), Tinyweb.circle__default__style());
    }

    private static void dragged(final int x, final int y) {
        System.out.println("drag to" + " " + String.valueOf(x) + " " + String.valueOf(y) + " " + "down" + " " + String.valueOf((Object) Tinyweb.mouse(c).down()));
        Tinyweb.line(c, 0, 0, x, y, Tinyweb.color__black, 2, 1.0, Tinyweb.line__default__style());
    }

    private static void moved(final int x, final int y) {
        System.out.println("move to" + " " + String.valueOf(x) + " " + String.valueOf(y) + " " + "down" + " " + String.valueOf((Object) Tinyweb.mouse(c).down()));
    }

    private static void released(final int x, final int y) {
        System.out.println("release at" + " " + String.valueOf(x) + " " + String.valueOf(y) + " " + "down" + " " + String.valueOf((Object) Tinyweb.mouse(c).down()));
    }

    private static void nothing(final int x, final int y) {

    }

    private static void let_go(final String key) {
        System.out.println("let go of" + " " + key + " " + "still held:" + " " + String.valueOf(TinywebExternal.key_down(key)));
    }

    private static void frame(final double t) {
        final var left = TinywebExternal.key_down("ArrowLeft");
        final var right = TinywebExternal.key_down("ArrowRight");
        System.out.println("frame" + " " + PykRuntime.floatStr(t) + " " + "left" + " " + String.valueOf(left) + " " + "right" + " " + String.valueOf(right));
    }

    public static void main(String[] args) {
        Math.init();
        Text.init();
        Tinyweb.init();
        Tinyweb.web_init(0);
        c = TinywebExternal.canvas(200, 100);
        other = TinywebExternal.canvas(50, 50);
        Tinyweb.track_mouse(c);
        Tinyweb.on_press(c, (p$1, p$2) -> { pressed(p$1, p$2); return null; });
        Tinyweb.on_drag(c, (p$1, p$2) -> { dragged(p$1, p$2); return null; });
        Tinyweb.on_move(c, (p$1, p$2) -> { moved(p$1, p$2); return null; });
        Tinyweb.on_release(c, (p$1, p$2) -> { released(p$1, p$2); return null; });
        Tinyweb.on_move(other, (p$1, p$2) -> { nothing(p$1, p$2); return null; });
        start = Tinyweb.mouse(c);
        System.out.println("before any event" + " " + String.valueOf((Object) start.x()) + " " + String.valueOf((Object) start.y()) + " " + String.valueOf((Object) start.down()));
        TinywebExternal.on_key_up(c$1 -> let_go(c$1));
        TinywebExternal.on_frame(c$1 -> frame(c$1));
    }
}
