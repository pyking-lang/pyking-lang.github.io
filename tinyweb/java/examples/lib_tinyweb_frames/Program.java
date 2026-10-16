// Generated from lib_tinyweb_frames.pyk by the Pyking compiler. Do not edit.
// Target: java21. Compile with:  javac --release 21 Program.java
//         then run with:            java Program

public final class Program {

    // A Float written the way Pyking writes one, which is not the way
    // Java writes a double.
    private static String pykFloatStr(double x) {
        if (Double.isNaN(x)) return "nan";
        if (x == Double.POSITIVE_INFINITY) return "inf";
        if (x == Double.NEGATIVE_INFINITY) return "-inf";
        String sign = (x < 0.0 || (x == 0.0 && 1.0 / x < 0.0)) ? "-" : "";
        double a = Math.abs(x);
        if (a == 0.0) return sign + "0.0";
        String s = "";
        for (int p = 0; p <= 16; p++) {
            s = String.format(java.util.Locale.ROOT, "%." + p + "e", a);
            if (Double.parseDouble(s) == a) break;
        }
        int at = s.indexOf('e');
        String digits = s.substring(0, at).replace(".", "");
        int decpt = Integer.parseInt(s.substring(at + 1)) + 1;
        int n = digits.length();
        while (n > 1 && digits.charAt(n - 1) == '0') n--;
        digits = digits.substring(0, n);
        if (decpt <= -4 || decpt > 16) {
            String mantissa =
                n == 1 ? digits : digits.charAt(0) + "." + digits.substring(1);
            return sign + mantissa + "e" + (decpt - 1);
        }
        StringBuilder out = new StringBuilder(sign);
        if (decpt <= 0) {
            out.append("0.");
            for (int i = 0; i < -decpt; i++) out.append('0');
            return out.append(digits).toString();
        }
        if (decpt >= n) {
            out.append(digits);
            for (int i = 0; i < decpt - n; i++) out.append('0');
            return out.append(".0").toString();
        }
        return out.append(digits, 0, decpt).append('.')
            .append(digits.substring(decpt)).toString();
    }

    private static int pykTruncate(double x) {
        if (Double.isNaN(x) || x <= -2147483649.0 || x >= 2147483648.0) {
            return 0;
        }
        return (int) x;
    }

    // What the top level binds, where every method can read it; the
    // top level in `main` below is what fills each of them in.
    private static int c;
    private static int kick;
    private static double beat;
    private static double next_beat;

    private static void draw(final double t) {
        Tinyweb.clear(c, "#111111");
        Tinyweb.circle(c, pykTruncate(t * 100.0), 50, 10, "#ffcc00");
        if (t >= next_beat) {
            System.out.println("beat scheduled at " + pykFloatStr(next_beat + beat) + ", drawn at " + pykFloatStr(t));
            Tinyweb.play(kick, next_beat + beat, Tinyweb.play__default__volume(), Tinyweb.play__default__rate());
            next_beat = next_beat + beat;
        }
    }

    public static void main(String[] args) {
        // Every module of the program, in the order they must run.
        Tinyweb.init();

        TinywebExternal.web_init(0);
        c = TinywebExternal.canvas(200, 100);
        kick = TinywebExternal.load_sample("kick1.wav");
        beat = 0.5;
        next_beat = 0.0;
        TinywebExternal.on_frame((p$1) -> draw(p$1));
        System.out.println(pykFloatStr(TinywebExternal.time()));
    }
}
