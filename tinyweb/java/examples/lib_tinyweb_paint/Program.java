// Generated from lib_tinyweb_paint.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java PykRuntime.java
//         then run with:            java Program

public final class Program {

    private static String c;
    private static String sky;
    private static String sky2;
    private static String ball;
    private static String wheel;

    private static void underline(final double width) {
        Tinyweb.line(c, 10, 60, 10 + PykRuntime.truncate(width), 60, "white", 2, Tinyweb.line__default__alpha());
    }

    public static void main(String[] args) {
        Tinyweb.init();
        Tinyweb.web_init(0);
        c = TinywebExternal.canvas(300, 200);
        sky = Tinyweb.colors__linear_gradient(0.0, 0.0, 0.0, 200.0, "#1a237e", "#ffb74d");
        sky2 = Tinyweb.colors__stop(sky, 0.6, "#e91e63");
        Tinyweb.clear(c, sky2);
        ball = Tinyweb.colors__radial_gradient(40.0, 40.0, 4.0, 50.0, 50.0, 30.0, "white", "crimson");
        Tinyweb.circle(c, 50, 50, 30, ball, Tinyweb.circle__default__outline(), Tinyweb.circle__default__outline_width(), Tinyweb.circle__default__alpha());
        wheel = Tinyweb.colors__stop(Tinyweb.colors__stop(Tinyweb.colors__conic_gradient(150.0, 50.0, 90.0, "red", "red"), 0.33, "lime"), 0.67, "blue");
        Tinyweb.circle(c, 150, 50, 30, wheel, "white", 2, Tinyweb.circle__default__alpha());
        Tinyweb.push(c);
        Tinyweb.line_style(c, "butt", "bevel", 8.0, 4.0, 2.0, Tinyweb.line_style__default__dash2(), Tinyweb.line_style__default__gap2());
        Tinyweb.rect(c, 200, 20, 80, 60, "", "white", 3, Tinyweb.rect__default__alpha(), Tinyweb.rect__default__radius());
        Tinyweb.line_style(c, Tinyweb.line_style__default__cap(), Tinyweb.line_style__default__join(), 3.0, Tinyweb.line_style__default__gap(), Tinyweb.line_style__default__offset(), Tinyweb.line_style__default__dash2(), Tinyweb.line_style__default__gap2());
        Tinyweb.line(c, 200, 90, 280, 90, "yellow", 2, Tinyweb.line__default__alpha());
        Tinyweb.pop(c);
        Tinyweb.push(c);
        Tinyweb.clip_rect(c, 10, 100, 60, 40);
        Tinyweb.circle(c, 40, 120, 35, "orange", Tinyweb.circle__default__outline(), Tinyweb.circle__default__outline_width(), Tinyweb.circle__default__alpha());
        Tinyweb.pop(c);
        Tinyweb.push(c);
        Tinyweb.clip_circle(c, 120, 130, 25);
        Tinyweb.rect(c, 90, 100, 60, 60, "teal", Tinyweb.rect__default__outline(), Tinyweb.rect__default__outline_width(), Tinyweb.rect__default__alpha(), Tinyweb.rect__default__radius());
        Tinyweb.pop(c);
        Tinyweb.bezier(c, 160, 160, 190, 100, 230, 200, 260, 120, "black", 3, Tinyweb.bezier__default__alpha());
        Tinyweb.erase(c, 270, 150, 20, 20);
        Tinyweb.text(c, 10, 190, "bottom", "white", 14, Tinyweb.text__default__font(), Tinyweb.text__default__align(), Tinyweb.text__default__bold(), Tinyweb.text__default__alpha(), "bottom", "black", 3);
        Tinyweb.text(c, 80, 185, "middle", "white", 14, Tinyweb.text__default__font(), Tinyweb.text__default__align(), Tinyweb.text__default__bold(), Tinyweb.text__default__alpha(), "middle", Tinyweb.text__default__outline(), Tinyweb.text__default__outline_width());
        Tinyweb.text(c, 150, 185, "alphabetic", "", 14, Tinyweb.text__default__font(), Tinyweb.text__default__align(), Tinyweb.text__default__bold(), Tinyweb.text__default__alpha(), "alphabetic", "white", Tinyweb.text__default__outline_width());
        Tinyweb.smooth__circle(c, 250.5, 130.25, 6.5, "gold", "black", 0.5, Tinyweb.smooth__circle__default__alpha());
        Tinyweb.smooth__rect(c, 200.5, 100.5, 30.0, 15.0, "", "white", Tinyweb.smooth__rect__default__outline_width(), Tinyweb.smooth__rect__default__alpha(), 4.0);
        Tinyweb.smooth__ellipse(c, 100.0, 180.0, 12.5, 6.25, "plum", Tinyweb.smooth__ellipse__default__outline(), Tinyweb.smooth__ellipse__default__outline_width(), Tinyweb.smooth__ellipse__default__alpha());
        Tinyweb.smooth__arc(c, 30.0, 170.0, 10.0, 0.0, 270.0, "", "cyan", 2.5, Tinyweb.smooth__arc__default__alpha());
        Tinyweb.smooth__line(c, 0.0, 199.5, 300.0, 198.5, "white", 0.8, Tinyweb.smooth__line__default__alpha());
        Tinyweb.smooth__curve(c, 5.0, 5.0, 50.0, 0.5, 95.0, 5.0, "white", 1.5, Tinyweb.smooth__curve__default__alpha());
        Tinyweb.smooth__bezier(c, 5.0, 95.0, 30.0, 70.0, 70.0, 120.0, 95.0, 95.0, "white", 1.5, 0.5);
        Tinyweb.smooth__text(c, 150.5, 100.25, "smooth", "white", 12, Tinyweb.smooth__text__default__font(), "center", Tinyweb.smooth__text__default__bold(), Tinyweb.smooth__text__default__alpha(), "middle", Tinyweb.smooth__text__default__outline(), Tinyweb.smooth__text__default__outline_width());
        Tinyweb.push(c);
        Tinyweb.smooth__clip_circle(c, 50.5, 50.5, 20.0);
        Tinyweb.rect(c, 30, 30, 20, 40, "black", Tinyweb.rect__default__outline(), Tinyweb.rect__default__outline_width(), 0.3, Tinyweb.rect__default__radius());
        Tinyweb.pop(c);
        Tinyweb.measure_text("Hello, canvas!", p$1 -> { underline(p$1); return null; }, 20, Tinyweb.measure_text__default__font(), true);
    }
}
