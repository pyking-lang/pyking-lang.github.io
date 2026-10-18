// Generated from lib_tinyweb_transform.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java PykRuntime.java
//         then run with:            java Program

public final class Program {

    private static String c;

    private static void draw(final double t) {
        Tinyweb.clear(c, "black");
        Tinyweb.push(c);
        Tinyweb.translate(c, 100.0, 100.0);
        Tinyweb.rotate(c, t * 90.0);
        Tinyweb.rect(c, -20, -20, 40, 40, "crimson", Tinyweb.rect__default__outline(), Tinyweb.rect__default__outline_width(), Tinyweb.rect__default__alpha(), Tinyweb.rect__default__radius());
        Tinyweb.push(c);
        Tinyweb.scale(c, 0.5, 2.0);
        Tinyweb.circle(c, 60, 0, 10, "white", Tinyweb.circle__default__outline(), Tinyweb.circle__default__outline_width(), Tinyweb.circle__default__alpha());
        Tinyweb.pop(c);
        Tinyweb.pop(c);
        Tinyweb.shadow(c, "white", 12, Tinyweb.shadow__default__dx(), Tinyweb.shadow__default__dy());
        Tinyweb.circle(c, 30, 30, 10, "gold", Tinyweb.circle__default__outline(), Tinyweb.circle__default__outline_width(), Tinyweb.circle__default__alpha());
        Tinyweb.shadow(c, "", Tinyweb.shadow__default__blur(), Tinyweb.shadow__default__dx(), Tinyweb.shadow__default__dy());
        Tinyweb.blend(c, "add");
        Tinyweb.circle(c, 160, 160, 20, "#800000", Tinyweb.circle__default__outline(), Tinyweb.circle__default__outline_width(), Tinyweb.circle__default__alpha());
        Tinyweb.circle(c, 175, 160, 20, "#000080", Tinyweb.circle__default__outline(), Tinyweb.circle__default__outline_width(), Tinyweb.circle__default__alpha());
        Tinyweb.blend(c, "normal");
        Tinyweb.blend(c, "multiply");
        Tinyweb.reset(c);
    }

    public static void main(String[] args) {
        Tinyweb.init();
        Tinyweb.web_init(0);
        c = TinywebExternal.canvas(200, 200);
        TinywebExternal.on_frame(c$1 -> draw(c$1));
    }
}
