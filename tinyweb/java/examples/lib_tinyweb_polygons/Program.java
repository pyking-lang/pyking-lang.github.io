// Generated from lib_tinyweb_polygons.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java PykRuntime.java
//         then run with:            java Program

public final class Program {

    private static String c;
    private static java.util.List<String> ocean;

    public static void main(String[] args) {
        Tinyweb.init();
        Tinyweb.web_init(0);
        c = TinywebExternal.canvas(200, 200);
        ocean = Tinyweb.colors__palette("ocean");
        System.out.println(String.valueOf(ocean.size()));
        Tinyweb.polygon(c, java.util.Arrays.asList(new PykRuntime.T2<>(100, 10), new PykRuntime.T2<>(130, 90), new PykRuntime.T2<>(70, 90)), "orange", "black", Tinyweb.polygon__default__outline_width(), Tinyweb.polygon__default__alpha());
        Tinyweb.path(c, java.util.Arrays.asList(new PykRuntime.T2<>(10, 190), new PykRuntime.T2<>(60, 120), new PykRuntime.T2<>(110, 170), new PykRuntime.T2<>(190, 110)), "teal", 3, Tinyweb.path__default__alpha());
        Tinyweb.polygon(c, java.util.Collections.emptyList(), "red", Tinyweb.polygon__default__outline(), Tinyweb.polygon__default__outline_width(), Tinyweb.polygon__default__alpha());
        System.out.println(PykRuntime.str(Tinyweb.colors__palette("nothing")));
    }
}
