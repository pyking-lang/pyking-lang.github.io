// Generated from lib_tinyweb_polygons.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java PykRuntime.java
//         then run with:            java Program

public final class Program {

    private static String c;
    private static java.util.List<Tinyweb.Color__Color> ocean;

    public static void main(String[] args) {
        Math.init();
        Text.init();
        Tinyweb.init();
        Tinyweb.web_init(0);
        c = TinywebExternal.canvas(200, 200);
        ocean = Tinyweb.color__palette("ocean");
        System.out.println(String.valueOf(ocean.size()));
        Tinyweb.polygon(c, java.util.Arrays.asList(new Tinyweb.Point(100, 10), new Tinyweb.Point(130, 90), new Tinyweb.Point(70, 90)), Tinyweb.color__orange, Tinyweb.color__black, 1, 1.0, Tinyweb.polygon__default__paint(), Tinyweb.polygon__default__style());
        Tinyweb.path(c, java.util.Arrays.asList(new Tinyweb.Point(10, 190), new Tinyweb.Point(60, 120), new Tinyweb.Point(110, 170), new Tinyweb.Point(190, 110)), Tinyweb.color__teal, 3, 1.0, Tinyweb.path__default__style());
        Tinyweb.polygon(c, java.util.Collections.emptyList(), Tinyweb.color__red, Tinyweb.polygon__default__stroke(), 1, 1.0, Tinyweb.polygon__default__paint(), Tinyweb.polygon__default__style());
        Tinyweb.lines(c, java.util.Arrays.asList(new PykRuntime.T2<>(new Tinyweb.Point(0, 0), new Tinyweb.Point(20, 20)), new PykRuntime.T2<>(new Tinyweb.Point(20, 0), new Tinyweb.Point(0, 20))), Tinyweb.color__navy, 1, 1.0, Tinyweb.lines__default__style());
        System.out.println(String.valueOf(Tinyweb.color__palette("nothing").size()));
    }
}
