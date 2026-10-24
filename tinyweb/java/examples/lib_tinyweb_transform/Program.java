// Generated from lib_tinyweb_transform.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java PykRuntime.java
//         then run with:            java Program

public final class Program {

    private static String c;

    private static void draw(final double t) {
        Tinyweb.clear(c, Tinyweb.color__black);
        Tinyweb.push(c);
        Tinyweb.translate(c, 100.0, 100.0);
        Tinyweb.rotate(c, t * Math.pi / 2.0);
        Tinyweb.rect(c, -20, -20, 40, 40, Tinyweb.color__hex(14423100), Tinyweb.rect__default__stroke(), 1, 1.0, Tinyweb.rect__default__paint(), Tinyweb.rect__default__style(), 0);
        Tinyweb.push(c);
        Tinyweb.scale(c, 0.5, 2.0);
        Tinyweb.circle(c, 60, 0, 10, Tinyweb.color__white, Tinyweb.circle__default__stroke(), 1, 1.0, Tinyweb.circle__default__paint(), Tinyweb.circle__default__style());
        Tinyweb.pop(c);
        Tinyweb.pop(c);
        Tinyweb.shadow(c, Tinyweb.color__white, 12, 0, 0);
        Tinyweb.circle(c, 30, 30, 10, Tinyweb.color__hex(16766720), Tinyweb.circle__default__stroke(), 1, 1.0, Tinyweb.circle__default__paint(), Tinyweb.circle__default__style());
        Tinyweb.shadow(c, Tinyweb.color__none, 10, 0, 0);
        Tinyweb.blend(c, "add");
        Tinyweb.circle(c, 160, 160, 20, Tinyweb.color__hex(8388608), Tinyweb.circle__default__stroke(), 1, 1.0, Tinyweb.circle__default__paint(), Tinyweb.circle__default__style());
        Tinyweb.circle(c, 175, 160, 20, Tinyweb.color__hex(128), Tinyweb.circle__default__stroke(), 1, 1.0, Tinyweb.circle__default__paint(), Tinyweb.circle__default__style());
        Tinyweb.blend(c, "normal");
        Tinyweb.blend(c, "multiply");
        Tinyweb.reset(c);
    }

    public static void main(String[] args) {
        Math.init();
        Text.init();
        Tinyweb.init();
        Tinyweb.web_init(0);
        c = TinywebExternal.canvas(200, 200);
        TinywebExternal.on_frame(c$1 -> draw(c$1));
    }
}
