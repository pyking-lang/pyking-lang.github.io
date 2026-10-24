// Generated from lib_tinyweb_shapes.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java PykRuntime.java
//         then run with:            java Program

public final class Program {

    private static String c;
    private static Tinyweb.Color__Color gold;

    private static String show(final Tinyweb.Color__Color c2) {
        return String.valueOf((Object) c2.r()) + " " + String.valueOf((Object) c2.g()) + " " + String.valueOf((Object) c2.b()) + " " + PykRuntime.floatStr((double) c2.a());
    }

    public static void main(String[] args) {
        Math.init();
        Text.init();
        Tinyweb.init();
        Tinyweb.web_init(0);
        c = TinywebExternal.canvas(300, 200);
        Tinyweb.clear(c, Tinyweb.color__rgb(17, 17, 17));
        gold = Tinyweb.color__hex(16766720);
        Tinyweb.circle(c, 50, 50, 30, gold, Tinyweb.color__white, 3, 1.0, Tinyweb.circle__default__paint(), Tinyweb.circle__default__style());
        Tinyweb.circle(c, 80, 50, 30, Tinyweb.color__rgba(0, 128, 255, 0.5), Tinyweb.circle__default__stroke(), 1, 1.0, Tinyweb.circle__default__paint(), Tinyweb.circle__default__style());
        Tinyweb.rect(c, 120, 20, 60, 40, Tinyweb.color__none, Tinyweb.color__hsl(120.0, 100.0, 50.0), 1, 1.0, Tinyweb.rect__default__paint(), Tinyweb.rect__default__style(), 8);
        Tinyweb.ellipse(c, 220, 40, 50, 20, Tinyweb.color__hex(14315734), Tinyweb.ellipse__default__stroke(), 1, 0.75, Tinyweb.ellipse__default__paint(), Tinyweb.ellipse__default__style());
        Tinyweb.arc(c, 50, 140, 40, Math.pi / 6.0, 11.0 * Math.pi / 6.0, Tinyweb.color__yellow, Tinyweb.arc__default__stroke(), 1, 1.0, Tinyweb.arc__default__paint(), Tinyweb.arc__default__style());
        Tinyweb.arc(c, 150, 140, 40, Math.pi, 2.0 * Math.pi, Tinyweb.color__none, Tinyweb.color__red, 4, 1.0, Tinyweb.arc__default__paint(), Tinyweb.arc__default__style());
        Tinyweb.line(c, 200, 100, 290, 190, Tinyweb.color__cyan, 2, 1.0, Tinyweb.line__default__style());
        Tinyweb.curve(c, 200, 190, 245, 60, 290, 190, Tinyweb.color__white, 2, 0.5, Tinyweb.curve__default__style());
        Tinyweb.text(c, 150, 180, "Step 1", Tinyweb.color__white, 18, "serif", "center", true, 1.0, "top", Tinyweb.text__default__stroke(), 1, Tinyweb.text__default__paint(), Tinyweb.text__default__style());
        System.out.println(show(Tinyweb.color__rgb(255, 136, 0)));
        System.out.println(show(Tinyweb.color__rgb(-5, 300, 16)));
        System.out.println(show(Tinyweb.color__hsl(200.0, 50.0, 25.0)));
        System.out.println(String.valueOf(Tinyweb.color__to_hex(Tinyweb.color__hex(16746496))) + " " + String.valueOf(Tinyweb.color__to_hex(Tinyweb.color__rgb(1, 2, 3))));
        System.out.println(String.valueOf(Tinyweb.color__same(Tinyweb.color__hex(65535), Tinyweb.color__cyan)) + " " + String.valueOf(Tinyweb.color__same(Tinyweb.color__red, Tinyweb.color__blue)));
        System.out.println(show(Tinyweb.color__mix(Tinyweb.color__black, Tinyweb.color__white, 0.5)));
        System.out.println(show(Tinyweb.color__with_alpha(Tinyweb.color__red, 0.25)));
        System.out.println(show(Tinyweb.color__rgba(10, 20, 30, 0.5)) + " " + show(Tinyweb.color__none));
    }
}
