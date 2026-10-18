// Generated from lib_tinyweb_smooth.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java PykRuntime.java
//         then run with:            java Program

public final class Program {

    private static String c;
    private static java.util.List<PykRuntime.T4<Double, Double, Double, Double>> rays;
    private static java.util.List<PykRuntime.T4<Double, Double, Double, Double>> many;

    public static void main(String[] args) {
        Tinyweb.init();
        Tinyweb.web_init(0);
        c = TinywebExternal.canvas(200, 120);
        Tinyweb.smooth__polygon(c, java.util.Arrays.asList(new PykRuntime.T2<>(100.0, 10.5), new PykRuntime.T2<>(180.5, 90.5), new PykRuntime.T2<>(19.5, 90.5)), "orange", "black", 0.5, Tinyweb.smooth__polygon__default__alpha());
        Tinyweb.smooth__path(c, java.util.Arrays.asList(new PykRuntime.T2<>(10.0, 110.0), new PykRuntime.T2<>(60.5, 20.5), new PykRuntime.T2<>(110.25, 70.0), new PykRuntime.T2<>(190.0, 10.0)), "teal", 2.5, Tinyweb.smooth__path__default__alpha());
        rays = PykRuntime.flatMap(PykRuntime.range(8), i$1 -> { final int i = i$1; return PykRuntime.single(new PykRuntime.T4<>(100.0, 60.0, 100.0 + 45.0 * (double) (i - i / 3 * 3), 5.0 * (double) i)); });
        Tinyweb.smooth__lines(c, rays, "crimson", 0.8, 0.5);
        Tinyweb.lines(c, PykRuntime.flatMap(PykRuntime.range(0, 200, 40), i$2 -> { final int x = i$2; return PykRuntime.single(new PykRuntime.T4<>(x, 0, x, 120)); }), "#cccccc", Tinyweb.lines__default__width(), Tinyweb.lines__default__alpha());
        Tinyweb.push(c);
        Tinyweb.smooth__clip_polygon(c, java.util.Arrays.asList(new PykRuntime.T2<>(100.0, 5.5), new PykRuntime.T2<>(190.5, 115.0), new PykRuntime.T2<>(9.5, 115.0)));
        Tinyweb.rect(c, 0, 60, 200, 60, "gold", Tinyweb.rect__default__outline(), Tinyweb.rect__default__outline_width(), 0.4, Tinyweb.rect__default__radius());
        Tinyweb.pop(c);
        Tinyweb.push(c);
        Tinyweb.clip_polygon(c, java.util.Arrays.asList(new PykRuntime.T2<>(0, 0), new PykRuntime.T2<>(60, 0), new PykRuntime.T2<>(0, 60)));
        Tinyweb.rect(c, 0, 0, 60, 60, "navy", Tinyweb.rect__default__outline(), Tinyweb.rect__default__outline_width(), Tinyweb.rect__default__alpha(), Tinyweb.rect__default__radius());
        Tinyweb.pop(c);
        many = PykRuntime.flatMap(PykRuntime.range(300), i$3 -> { final int i2 = i$3; return PykRuntime.single(new PykRuntime.T4<>((double) i2, 0.0, (double) i2 + 0.5, 120.0)); });
        Tinyweb.smooth__lines(c, many, "black", 0.25, 0.1);
        System.out.println("drew" + " " + String.valueOf(many.size()) + " " + "lines in one go");
    }
}
