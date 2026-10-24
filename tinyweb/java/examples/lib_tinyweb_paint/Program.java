// Generated from lib_tinyweb_paint.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java PykRuntime.java
//         then run with:            java Program

public final class Program {

    private static String c;
    private static Tinyweb.Color__Paint sky;
    private static Tinyweb.Color__Paint ball;
    private static Tinyweb.Color__Paint wheel;
    private static Tinyweb.Style outlined;

    private static void underline(final double width) {
        Tinyweb.line(c, 10, 60, 10 + PykRuntime.truncate(width), 60, Tinyweb.color__white, 2, 1.0, Tinyweb.line__default__style());
    }

    public static void main(String[] args) {
        Math.init();
        Text.init();
        Tinyweb.init();
        Tinyweb.web_init(0);
        c = TinywebExternal.canvas(300, 200);
        sky = Tinyweb.Color__Linear(0.0, 0.0, 0.0, 200.0, Tinyweb.color__hex(1713022), Tinyweb.color__hex(16758605), "");
        Tinyweb.rect(c, 0, 0, 300, 200, Tinyweb.rect__default__fill(), Tinyweb.rect__default__stroke(), 1, 1.0, Tinyweb.color__stop(sky, 0.6, Tinyweb.color__hex(15277667)), Tinyweb.rect__default__style(), 0);
        ball = Tinyweb.Color__Radial(40.0, 40.0, 4.0, 50.0, 50.0, 30.0, Tinyweb.color__white, Tinyweb.color__hex(14423100), "");
        Tinyweb.circle(c, 50, 50, 30, Tinyweb.circle__default__fill(), Tinyweb.circle__default__stroke(), 1, 1.0, ball, Tinyweb.circle__default__style());
        wheel = Tinyweb.color__stop(Tinyweb.color__stop(Tinyweb.Color__Conic(150.0, 50.0, Math.pi / 2.0, Tinyweb.color__red, Tinyweb.color__red, ""), 0.33, Tinyweb.color__hex(65280)), 0.67, Tinyweb.color__blue);
        PykRuntime.ignore(PykRuntime.<Tinyweb.Color__Color, Void>let(Tinyweb.circle__default__fill(), fill__arg -> PykRuntime.<Tinyweb.Style, Void>let(Tinyweb.circle__default__style(), style__arg -> PykRuntime.unit(() -> Tinyweb.circle(c, 150, 50, 30, fill__arg, Tinyweb.color__white, 2, 1.0, wheel, style__arg)))));
        Tinyweb.push(c);
        Tinyweb.line_style(c, "butt", "bevel", 8.0, 4.0, 2.0, 0.0, 0.0);
        Tinyweb.rect(c, 200, 20, 80, 60, Tinyweb.color__none, Tinyweb.color__white, 3, 1.0, Tinyweb.rect__default__paint(), Tinyweb.rect__default__style(), 0);
        Tinyweb.line_style(c, "round", "round", 3.0, 0.0, 0.0, 0.0, 0.0);
        Tinyweb.line(c, 200, 90, 280, 90, Tinyweb.color__yellow, 2, 1.0, Tinyweb.line__default__style());
        Tinyweb.pop(c);
        Tinyweb.push(c);
        Tinyweb.clip_rect(c, 10, 100, 60, 40);
        Tinyweb.circle(c, 40, 120, 35, Tinyweb.color__orange, Tinyweb.circle__default__stroke(), 1, 1.0, Tinyweb.circle__default__paint(), Tinyweb.circle__default__style());
        Tinyweb.pop(c);
        Tinyweb.push(c);
        Tinyweb.clip_circle(c, 120, 130, 25);
        Tinyweb.rect(c, 90, 100, 60, 60, Tinyweb.color__teal, Tinyweb.rect__default__stroke(), 1, 1.0, Tinyweb.rect__default__paint(), Tinyweb.rect__default__style(), 0);
        Tinyweb.pop(c);
        Tinyweb.bezier(c, 160, 160, 190, 100, 230, 200, 260, 120, Tinyweb.color__black, 3, 1.0, Tinyweb.bezier__default__style());
        Tinyweb.erase(c, 270, 150, 20, 20);
        Tinyweb.text(c, 10, 190, "bottom", Tinyweb.color__white, 14, "", "left", false, 1.0, "bottom", Tinyweb.color__black, 3, Tinyweb.text__default__paint(), Tinyweb.text__default__style());
        Tinyweb.text(c, 80, 185, "middle", Tinyweb.color__white, 14, "", "left", false, 1.0, "middle", Tinyweb.text__default__stroke(), 1, Tinyweb.text__default__paint(), Tinyweb.text__default__style());
        Tinyweb.text(c, 150, 185, "alphabetic", Tinyweb.color__none, 14, "", "left", false, 1.0, "alphabetic", Tinyweb.color__white, 1, Tinyweb.text__default__paint(), Tinyweb.text__default__style());
        Tinyweb.smooth__circle(c, 250.5, 130.25, 6.5, Tinyweb.color__hex(16766720), Tinyweb.color__black, 0.5, 1.0, Tinyweb.smooth__circle__default__paint(), Tinyweb.smooth__circle__default__style());
        Tinyweb.smooth__rect(c, 200.5, 100.5, 30.0, 15.0, Tinyweb.color__none, Tinyweb.color__white, 1.0, 1.0, Tinyweb.smooth__rect__default__paint(), Tinyweb.smooth__rect__default__style(), 4.0);
        Tinyweb.smooth__ellipse(c, 100.0, 180.0, 12.5, 6.25, Tinyweb.color__hex(14524637), Tinyweb.smooth__ellipse__default__stroke(), 1.0, 1.0, Tinyweb.smooth__ellipse__default__paint(), Tinyweb.smooth__ellipse__default__style());
        Tinyweb.smooth__arc(c, 30.0, 170.0, 10.0, 0.0, 1.5 * Math.pi, Tinyweb.color__none, Tinyweb.color__cyan, 2.5, 1.0, Tinyweb.smooth__arc__default__paint(), Tinyweb.smooth__arc__default__style());
        Tinyweb.smooth__line(c, 0.0, 199.5, 300.0, 198.5, Tinyweb.color__white, 0.8, 1.0, Tinyweb.smooth__line__default__style());
        Tinyweb.smooth__curve(c, 5.0, 5.0, 50.0, 0.5, 95.0, 5.0, Tinyweb.color__white, 1.5, 1.0, Tinyweb.smooth__curve__default__style());
        Tinyweb.smooth__bezier(c, 5.0, 95.0, 30.0, 70.0, 70.0, 120.0, 95.0, 95.0, Tinyweb.color__white, 1.5, 0.5, Tinyweb.smooth__bezier__default__style());
        Tinyweb.smooth__text(c, 150.5, 100.25, "smooth", Tinyweb.color__white, 12, "", "center", false, 1.0, "middle", Tinyweb.smooth__text__default__stroke(), 1.0, Tinyweb.smooth__text__default__paint(), Tinyweb.smooth__text__default__style());
        Tinyweb.push(c);
        Tinyweb.smooth__clip_circle(c, 50.5, 50.5, 20.0);
        Tinyweb.rect(c, 30, 30, 20, 40, Tinyweb.color__black, Tinyweb.rect__default__stroke(), 1, 0.3, Tinyweb.rect__default__paint(), Tinyweb.rect__default__style(), 0);
        Tinyweb.pop(c);
        outlined = new Tinyweb.Style(Tinyweb.color__navy, Tinyweb.color__yellow, 2, 0.8, Tinyweb.field__default__Style__paint());
        Tinyweb.circle(c, 20, 20, 8, Tinyweb.circle__default__fill(), Tinyweb.circle__default__stroke(), 1, 1.0, Tinyweb.circle__default__paint(), outlined);
        Tinyweb.rect(c, 40, 10, 20, 20, Tinyweb.color__red, Tinyweb.rect__default__stroke(), 1, 1.0, Tinyweb.rect__default__paint(), outlined, 0);
        Tinyweb.line(c, 0, 0, 30, 30, Tinyweb.line__default__stroke(), 1, 1.0, outlined);
        Tinyweb.circle(c, 70, 20, 8, Tinyweb.circle__default__fill(), Tinyweb.circle__default__stroke(), 1, 1.0, Tinyweb.circle__default__paint(), new Tinyweb.Style(Tinyweb.field__default__Style__fill(), Tinyweb.field__default__Style__stroke(), 1, 1.0, ball));
        Tinyweb.smooth__circle(c, 90.0, 20.0, 8.0, Tinyweb.smooth__circle__default__fill(), Tinyweb.smooth__circle__default__stroke(), 1.0, 1.0, Tinyweb.smooth__circle__default__paint(), outlined);
        Tinyweb.measure_text("Hello, canvas!", p$1 -> { underline(p$1); return null; }, 20, "", true);
    }
}
