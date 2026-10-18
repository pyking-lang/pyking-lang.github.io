// Generated from lib_tinyweb_pointer.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java PykRuntime.java
//         then run with:            java Program

public final class Program {

    private static String c;
    private static String other;

    private static void pressed(final int x, final int y) {
        System.out.println("press at" + " " + String.valueOf(x) + " " + String.valueOf(y) + " " + "down" + " " + String.valueOf(Tinyweb.mouse_down(c)));
        Tinyweb.circle(c, x, y, 4, "crimson", Tinyweb.circle__default__outline(), Tinyweb.circle__default__outline_width(), Tinyweb.circle__default__alpha());
    }

    private static void dragged(final int x, final int y) {
        System.out.println("drag to" + " " + String.valueOf(x) + " " + String.valueOf(y));
        Tinyweb.line(c, Tinyweb.mouse_x(c), Tinyweb.mouse_y(c), x, y, "black", 2, Tinyweb.line__default__alpha());
    }

    private static void moved(final int x, final int y) {
        System.out.println("move to" + " " + String.valueOf(x) + " " + String.valueOf(y) + " " + "down" + " " + String.valueOf(Tinyweb.mouse_down(c)));
    }

    private static void released(final int x, final int y) {
        System.out.println("release at" + " " + String.valueOf(x) + " " + String.valueOf(y) + " " + "down" + " " + String.valueOf(Tinyweb.mouse_down(c)));
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
        Tinyweb.init();
        Tinyweb.web_init(0);
        c = TinywebExternal.canvas(200, 100);
        other = TinywebExternal.canvas(50, 50);
        Tinyweb.on_press(c, (p$1, p$2) -> { pressed(p$1, p$2); return null; });
        Tinyweb.on_drag(c, (p$1, p$2) -> { dragged(p$1, p$2); return null; });
        Tinyweb.on_move(c, (p$1, p$2) -> { moved(p$1, p$2); return null; });
        Tinyweb.on_release(c, (p$1, p$2) -> { released(p$1, p$2); return null; });
        Tinyweb.on_move(other, (p$1, p$2) -> { Tinyweb.ignore2(p$1, p$2); return null; });
        System.out.println("before any event" + " " + String.valueOf(Tinyweb.mouse_x(c)) + " " + String.valueOf(Tinyweb.mouse_y(c)) + " " + String.valueOf(Tinyweb.mouse_down(c)));
        TinywebExternal.on_key_up(c$1 -> let_go(c$1));
        TinywebExternal.on_frame(c$1 -> frame(c$1));
    }
}
