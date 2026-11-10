// Generated from lib_tinyweb_load_bitmap.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java PykRuntime.java
//         then run with:            java Program

public final class Program {

    private static String c;
    private static String made;

    private static String show(final Tinyweb.Color__Color p) {
        return String.valueOf((Object) p.r()) + " " + String.valueOf((Object) p.g()) + " " + String.valueOf((Object) p.b());
    }

    private static void loaded(final String b) {
        final PykRuntime.T2<Integer, Integer> t$1 = Tinyweb.bitmap__size(b);
        final int w = t$1.a0();
        final int h = t$1.a1();
        System.out.println("loaded" + " " + b + " " + "of" + " " + String.valueOf(w) + " " + "by" + " " + String.valueOf(h));
        for (final int y : PykRuntime.range(h)) {
            for (final int x : PykRuntime.range(w)) {
                System.out.println(" " + " " + String.valueOf(x) + " " + String.valueOf(y) + " " + show(Tinyweb.bitmap__get_pixel(b, x, y)) + " " + PykRuntime.floatStr((double) Tinyweb.bitmap__get_pixel(b, x, y).a()));
            }
        }
        Tinyweb.bitmap__set_pixel(b, 1, 1, Tinyweb.color__black);
        Tinyweb.bitmap__show_bitmap(c, b, 0, 0, 10.0);
    }

    private static void broken(final String b) {
        System.out.println("never called for" + " " + b);
    }

    public static void main(String[] args) {
        Math.init();
        Text.init();
        Tinyweb.init();
        Tinyweb.web_init(0);
        c = TinywebExternal.canvas(40, 40);
        made = Tinyweb.bitmap__bitmap(5, 3, Tinyweb.bitmap__bitmap__default__background());
        System.out.println("made:" + " " + PykRuntime.str(Tinyweb.bitmap__size(made)) + " " + "not a bitmap:" + " " + PykRuntime.str(Tinyweb.bitmap__size("nothing")));
        Tinyweb.bitmap__load_bitmap("pic.png", p$1 -> { loaded(p$1); return null; });
        Tinyweb.bitmap__load_bitmap("broken.png", p$1 -> { broken(p$1); return null; });
        System.out.println("asked for both");
    }
}
