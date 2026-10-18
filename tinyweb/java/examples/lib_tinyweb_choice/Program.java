// Generated from lib_tinyweb_choice.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java PykRuntime.java
//         then run with:            java Program

public final class Program {

    private static java.util.List<String> names;
    private static String shown;
    private static String menu;

    private static void changed(final int position) {
        TinywebExternal.set_label(shown, "chose " + String.valueOf(position));
    }

    public static void main(String[] args) {
        Tinyweb.init();
        Tinyweb.web_init(0);
        names = java.util.Arrays.asList("ocean", "candy", "forest");
        shown = TinywebExternal.label("ocean");
        menu = Tinyweb.choice(names, Tinyweb.choice__default__chosen(), p$1 -> { changed(p$1); return null; });
        Tinyweb.choice(java.util.Arrays.asList("one"), 0, Tinyweb.choice__default__on_change());
        TinywebExternal.set_value(menu, 2);
    }
}
