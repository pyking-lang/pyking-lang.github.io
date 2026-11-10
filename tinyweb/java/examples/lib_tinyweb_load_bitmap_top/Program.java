// Generated from lib_tinyweb_load_bitmap_top.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java PykRuntime.java
//         then run with:            java Program

public final class Program {

    private static String c;

    private static void loaded(final String b) {
        final PykRuntime.T2<Integer, Integer> t$1 = Tinyweb.bitmap__size(b);
        final int w = t$1.a0();
        final int h = t$1.a1();
        System.out.println("ball.png is" + " " + String.valueOf(w) + " " + "by" + " " + String.valueOf(h));
        final var p = Tinyweb.bitmap__get_pixel(b, w / 2, h / 2);
        System.out.println("its middle:" + " " + String.valueOf((Object) p.r()) + " " + String.valueOf((Object) p.g()) + " " + String.valueOf((Object) p.b()));
        Tinyweb.bitmap__show_bitmap(c, b, 10, 10, 1.0);
    }

    public static void main(String[] args) {
        Math.init();
        Text.init();
        Tinyweb.init();
        Tinyweb.web_init(0);
        c = TinywebExternal.canvas(100, 100);
        Tinyweb.bitmap__load_bitmap("ball.png", p$1 -> { loaded(p$1); return null; });
        Tinyweb.bitmap__load_bitmap("no_such_picture.png", p$1 -> { loaded(p$1); return null; });
        System.out.println("asked for two pictures");
    }
}
