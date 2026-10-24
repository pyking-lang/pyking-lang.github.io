// Generated from lib_tinyweb_timers.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java PykRuntime.java
//         then run with:            java Program

public final class Program {

    private static int ticks;
    private static String repeating;
    private static String later;

    private static void tick() {
        ticks = ticks + 1;
        System.out.println("tick" + " " + String.valueOf(ticks) + " " + PykRuntime.floatStr(TinywebExternal.time()));
        if (ticks == 3) {
            Tinyweb.cancel(repeating);
        }
    }

    private static void once() {
        System.out.println("once at" + " " + PykRuntime.floatStr(TinywebExternal.time()) + " " + "beat" + " " + PykRuntime.floatStr(Tinyweb.sound__beat()) + " " + "latency" + " " + PykRuntime.floatStr(Tinyweb.sound__latency()) + " " + "level" + " " + PykRuntime.floatStr(Tinyweb.sound__level()));
        System.out.println("bands" + " " + String.valueOf(Tinyweb.sound__bands()) + " " + PykRuntime.floatStr(Tinyweb.sound__band(0)) + " " + PykRuntime.floatStr(Tinyweb.sound__band(1)) + " " + PykRuntime.floatStr(Tinyweb.sound__band(9)));
        System.out.println("typed" + " " + Tinyweb.value_of("name"));
    }

    public static void main(String[] args) {
        Math.init();
        Text.init();
        Tinyweb.init();
        Tinyweb.web_init(0);
        ticks = 0;
        repeating = "";
        repeating = Tinyweb.every(0.5, () -> { tick(); return null; });
        later = Tinyweb.after(2.0, () -> { once(); return null; });
        System.out.println(repeating + " " + later);
    }
}
