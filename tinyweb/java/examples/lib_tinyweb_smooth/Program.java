// Generated from lib_tinyweb_smooth.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java PykRuntime.java
//         then run with:            java Program

public final class Program {

    private static String c;
    private static java.util.List<PykRuntime.T2<Tinyweb.Smooth__Point, Tinyweb.Smooth__Point>> rays;
    private static java.util.List<PykRuntime.T2<Tinyweb.Smooth__Point, Tinyweb.Smooth__Point>> many;

    public static void main(String[] args) {
        Math.init();
        Text.init();
        Tinyweb.init();
        Tinyweb.web_init(0);
        c = TinywebExternal.canvas(200, 120);
        Tinyweb.smooth__polygon(c, java.util.Arrays.asList(new Tinyweb.Smooth__Point(100.0, 10.5), new Tinyweb.Smooth__Point(180.5, 90.5), new Tinyweb.Smooth__Point(19.5, 90.5)), Tinyweb.color__orange, Tinyweb.color__black, 0.5, 1.0, Tinyweb.smooth__polygon__default__style());
        Tinyweb.smooth__path(c, java.util.Arrays.asList(new Tinyweb.Smooth__Point(10.0, 110.0), new Tinyweb.Smooth__Point(60.5, 20.5), new Tinyweb.Smooth__Point(110.25, 70.0), new Tinyweb.Smooth__Point(190.0, 10.0)), Tinyweb.color__teal, 2.5, 1.0, Tinyweb.smooth__path__default__style());
        rays = PykRuntime.flatMap(PykRuntime.range(8), i$1 -> { final int i = i$1; return PykRuntime.single(new PykRuntime.T2<>(new Tinyweb.Smooth__Point(100.0, 60.0), new Tinyweb.Smooth__Point(100.0 + 45.0 * (double) (i - i / 3 * 3), 5.0 * (double) i))); });
        Tinyweb.smooth__lines(c, rays, Tinyweb.color__hex(14423100), 0.8, 0.5, Tinyweb.smooth__lines__default__style());
        Tinyweb.lines(c, PykRuntime.flatMap(PykRuntime.range(0, 200, 40), i$2 -> { final int x = i$2; return PykRuntime.single(new PykRuntime.T2<>(new Tinyweb.Point(x, 0), new Tinyweb.Point(x, 120))); }), Tinyweb.color__hex(13421772), 1, 1.0, Tinyweb.lines__default__style());
        Tinyweb.smooth__circles(c, java.util.Arrays.asList(new PykRuntime.T3<>(10.5, 10.5, 3.0), new PykRuntime.T3<>(20.0, 10.0, 2.5)), Tinyweb.color__navy, Tinyweb.smooth__circles__default__stroke(), 1.0, 1.0, Tinyweb.smooth__circles__default__style());
        Tinyweb.push(c);
        Tinyweb.smooth__clip_polygon(c, java.util.Arrays.asList(new Tinyweb.Smooth__Point(100.0, 5.5), new Tinyweb.Smooth__Point(190.5, 115.0), new Tinyweb.Smooth__Point(9.5, 115.0)));
        Tinyweb.rect(c, 0, 60, 200, 60, Tinyweb.color__hex(16766720), Tinyweb.rect__default__stroke(), 1, 0.4, Tinyweb.rect__default__paint(), Tinyweb.rect__default__style(), 0);
        Tinyweb.pop(c);
        Tinyweb.push(c);
        Tinyweb.clip_polygon(c, java.util.Arrays.asList(new Tinyweb.Point(0, 0), new Tinyweb.Point(60, 0), new Tinyweb.Point(0, 60)));
        Tinyweb.rect(c, 0, 0, 60, 60, Tinyweb.color__navy, Tinyweb.rect__default__stroke(), 1, 1.0, Tinyweb.rect__default__paint(), Tinyweb.rect__default__style(), 0);
        Tinyweb.pop(c);
        many = PykRuntime.flatMap(PykRuntime.range(300), i$3 -> { final int i2 = i$3; return PykRuntime.single(new PykRuntime.T2<>(new Tinyweb.Smooth__Point((double) i2, 0.0), new Tinyweb.Smooth__Point((double) i2 + 0.5, 120.0))); });
        Tinyweb.smooth__lines(c, many, Tinyweb.color__black, 0.25, 0.1, Tinyweb.smooth__lines__default__style());
        System.out.println("drew" + " " + String.valueOf(many.size()) + " " + "lines in one go");
    }
}
