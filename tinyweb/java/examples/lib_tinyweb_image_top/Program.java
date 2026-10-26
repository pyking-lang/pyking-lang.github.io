// Generated from lib_tinyweb_image_top.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java PykRuntime.java
//         then run with:            java Program

public final class Program {

    private static String c;
    private static String tile;
    private static String star;
    private static String missing;

    public static void main(String[] args) {
        Math.init();
        Text.init();
        Tinyweb.init();
        Tinyweb.web_init(0);
        c = TinywebExternal.canvas(200, 100);
        tile = TinywebExternal.load_image("tile.png");
        star = TinywebExternal.load_image("star.png");
        missing = TinywebExternal.load_image("no_such_picture.png");
        Tinyweb.image(c, tile, 0, 0, 200, 100, 1.0);
        Tinyweb.rect(c, 20, 20, 60, 30, Tinyweb.color__hex(2113664), Tinyweb.rect__default__stroke(), 1, 1.0, Tinyweb.rect__default__paint(), Tinyweb.rect__default__style(), 0);
        Tinyweb.image(c, star, 100, 10, 50, 50, 0.5);
        Tinyweb.image(c, missing, 10, 60, 30, 30, 1.0);
        Tinyweb.circle(c, 170, 70, 15, Tinyweb.color__hex(12595248), Tinyweb.circle__default__stroke(), 1, 1.0, Tinyweb.circle__default__paint(), Tinyweb.circle__default__style());
        System.out.println("drawn");
    }
}
