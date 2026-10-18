// Generated from lib_tinyweb_shapes.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java PykRuntime.java
//         then run with:            java Program

public final class Program {

    private static String c;

    public static void main(String[] args) {
        Tinyweb.init();
        Tinyweb.web_init(0);
        c = TinywebExternal.canvas(300, 200);
        Tinyweb.clear(c, Tinyweb.colors__rgb(17, 17, 17));
        Tinyweb.circle(c, 50, 50, 30, "gold", "white", 3, Tinyweb.circle__default__alpha());
        Tinyweb.circle(c, 80, 50, 30, Tinyweb.colors__rgba(0, 128, 255, 0.5), Tinyweb.circle__default__outline(), Tinyweb.circle__default__outline_width(), Tinyweb.circle__default__alpha());
        Tinyweb.rect(c, 120, 20, 60, 40, "", Tinyweb.colors__hsl(120, 100, 50), Tinyweb.rect__default__outline_width(), Tinyweb.rect__default__alpha(), 8);
        Tinyweb.ellipse(c, 220, 40, 50, 20, "orchid", Tinyweb.ellipse__default__outline(), Tinyweb.ellipse__default__outline_width(), 0.75);
        Tinyweb.arc(c, 50, 140, 40, 30.0, 330.0, "yellow", Tinyweb.arc__default__outline(), Tinyweb.arc__default__outline_width(), Tinyweb.arc__default__alpha());
        Tinyweb.arc(c, 150, 140, 40, 180.0, 360.0, "", "red", 4, Tinyweb.arc__default__alpha());
        Tinyweb.line(c, 200, 100, 290, 190, "cyan", 2, Tinyweb.line__default__alpha());
        Tinyweb.curve(c, 200, 190, 245, 60, 290, 190, "white", 2, 0.5);
        Tinyweb.text(c, 150, 180, "Step 1", "white", 18, "serif", "center", true, Tinyweb.text__default__alpha(), Tinyweb.text__default__baseline(), Tinyweb.text__default__outline(), Tinyweb.text__default__outline_width());
        System.out.println(Tinyweb.colors__rgb(255, 136, 0));
        System.out.println(Tinyweb.colors__rgb(-5, 300, 16));
        System.out.println(Tinyweb.colors__hsl(200, 50, 25));
    }
}
