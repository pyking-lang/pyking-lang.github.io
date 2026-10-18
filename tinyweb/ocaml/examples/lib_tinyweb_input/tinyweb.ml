(* Generated from tinyweb.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml5.5. The module 'tinyweb' of the program; compile it
   before the ones that import it. *)

let pyk_float_str x =
  if x <> x then "nan"
  else if x = infinity then "inf"
  else if x = neg_infinity then "-inf"
  else
    let negative = x < 0.0 || (x = 0.0 && 1.0 /. x < 0.0) in
    let sign = if negative then "-" else "" in
    let a = abs_float x in
    if a = 0.0 then sign ^ "0.0"
    else
      let rec shortest p =
        let s = Printf.sprintf "%.*e" p a in
        if p >= 16 || float_of_string s = a then s else shortest (p + 1)
      in
      let s = shortest 0 in
      let at = String.index s 'e' in
      let digits =
        String.concat "" (String.split_on_char '.' (String.sub s 0 at))
      in
      let rec trim n =
        if n > 1 && digits.[n - 1] = '0' then trim (n - 1) else n
      in
      let digits = String.sub digits 0 (trim (String.length digits)) in
      let len = String.length digits in
      let decpt =
        int_of_string (String.sub s (at + 1) (String.length s - at - 1))
        + 1
      in
      let zeros n = String.make (max 0 n) '0' in
      if decpt <= -4 || decpt > 16 then
        let mantissa =
          if len = 1 then digits
          else String.sub digits 0 1 ^ "." ^ String.sub digits 1 (len - 1)
        in
        sign ^ mantissa ^ "e" ^ string_of_int (decpt - 1)
      else if decpt <= 0 then sign ^ "0." ^ zeros (-decpt) ^ digits
      else if decpt >= len then sign ^ digits ^ zeros (decpt - len) ^ ".0"
      else
        sign ^ String.sub digits 0 decpt ^ "."
        ^ String.sub digits decpt (len - decpt)

let nothing () = ()

let ignore _value = ()

let ignore_bool _value = ()

let ignore_text _value = ()

let clear__default__color () = "#ffffff"

let clear c color = Tinyweb_external.fill_canvas c color

let numbers2 a b = string_of_int a ^ " " ^ string_of_int b

let numbers3 a b c = numbers2 a b ^ " " ^ string_of_int c

let numbers4 a b c d = numbers2 a b ^ " " ^ numbers2 c d

let joined_by words between =
  let whole = ref "" in
  let chunk = ref "" in
  let count = ref 0 in
  let chunks = ref 0 in
  let rec tmp1 _tmp2 tmp4 =
    match tmp4 with
        | [] -> ()
        | word :: tmp3 -> (chunk := if !count = 0 then word else !chunk ^ between ^ word;
    count := !count + 1;
    if !count = 128 then
      (whole := if !chunks = 0 then !chunk else !whole ^ between ^ !chunk;
      chunks := !chunks + 1; chunk := ""; count := 0);
    tmp1 () tmp3) in
  tmp1 () words;
  if !count = 0 then !whole
  else if !chunks = 0 then !chunk
  else !whole ^ between ^ !chunk

let joined words = joined_by words " "

let points_text points =
  joined (List.concat_map (function | (x, y) -> [numbers2 x y]) points)

let segments_text segments =
  joined (List.concat_map (function | (x1, y1, x2, y2) -> [numbers4 x1 y1 x2 y2]) segments)

let floats2 a b = pyk_float_str a ^ " " ^ pyk_float_str b

let floats3 a b c = floats2 a b ^ " " ^ pyk_float_str c

let floats4 a b c d = floats2 a b ^ " " ^ floats2 c d

let float_points_text points =
  joined (List.concat_map (function | (x, y) -> [floats2 x y]) points)

let web_init__default__port () = 0

let web_init port = Tinyweb_external.web_start port

let circle__default__color () = "#000000"

let circle__default__outline () = ""

let circle__default__outline_width () = 1

let circle__default__alpha () = 1.0

let circle c x y radius color outline outline_width alpha =
  Tinyweb_external.draw_shape c "circle" (numbers3 x y radius) color outline (float_of_int outline_width) alpha

let rect__default__color () = "#000000"

let rect__default__outline () = ""

let rect__default__outline_width () = 1

let rect__default__alpha () = 1.0

let rect__default__radius () = 0

let rect c x y width height color outline outline_width alpha radius =
  Tinyweb_external.draw_shape c "rect" (numbers4 x y width height ^ " " ^ string_of_int radius) color outline (float_of_int outline_width) alpha

let ellipse__default__color () = "#000000"

let ellipse__default__outline () = ""

let ellipse__default__outline_width () = 1

let ellipse__default__alpha () = 1.0

let ellipse c x y rx ry color outline outline_width alpha =
  Tinyweb_external.draw_shape c "ellipse" (numbers4 x y rx ry) color outline (float_of_int outline_width) alpha

let arc__default__color () = "#000000"

let arc__default__outline () = ""

let arc__default__outline_width () = 1

let arc__default__alpha () = 1.0

let arc c x y radius start end_ color outline outline_width alpha =
  Tinyweb_external.draw_shape c "arc" (numbers3 x y radius ^ " " ^ pyk_float_str start ^ " " ^ pyk_float_str end_) color outline (float_of_int outline_width) alpha

let polygon__default__color () = "#000000"

let polygon__default__outline () = ""

let polygon__default__outline_width () = 1

let polygon__default__alpha () = 1.0

let polygon c points color outline outline_width alpha =
  Tinyweb_external.draw_shape c "polygon" (points_text points) color outline (float_of_int outline_width) alpha

let line__default__color () = "#000000"

let line__default__width () = 1

let line__default__alpha () = 1.0

let line c x1 y1 x2 y2 color width alpha =
  Tinyweb_external.draw_shape c "line" (numbers4 x1 y1 x2 y2) "" color (float_of_int width) alpha

let path__default__color () = "#000000"

let path__default__width () = 1

let path__default__alpha () = 1.0

let path c points color width alpha =
  Tinyweb_external.draw_shape c "path" (points_text points) "" color (float_of_int width) alpha

let curve__default__color () = "#000000"

let curve__default__width () = 1

let curve__default__alpha () = 1.0

let curve c x1 y1 cx cy x2 y2 color width alpha =
  Tinyweb_external.draw_shape c "curve" (numbers2 x1 y1 ^ " " ^ numbers4 cx cy x2 y2) "" color (float_of_int width) alpha

let lines__default__color () = "#000000"

let lines__default__width () = 1

let lines__default__alpha () = 1.0

let lines c segments color width alpha =
  Tinyweb_external.draw_shape c "lines" (segments_text segments) "" color (float_of_int width) alpha

let bezier__default__color () = "#000000"

let bezier__default__width () = 1

let bezier__default__alpha () = 1.0

let bezier c x1 y1 ax ay bx by x2 y2 color width alpha =
  Tinyweb_external.draw_shape c "bezier" (numbers4 x1 y1 ax ay ^ " " ^ numbers4 bx by x2 y2) "" color (float_of_int width) alpha

let erase c x y width height =
  Tinyweb_external.draw_shape c "erase" (numbers4 x y width height) "" "" 0.0 1.0

let line_style__default__cap () = "round"

let line_style__default__join () = "round"

let line_style__default__dash () = 0.0

let line_style__default__gap () = 0.0

let line_style__default__offset () = 0.0

let line_style__default__dash2 () = 0.0

let line_style__default__gap2 () = 0.0

let line_style c cap join dash gap offset dash2 gap2 =
  let first =
    if dash <= 0.0 then ""
    else if gap <= 0.0 then " " ^ floats2 dash dash
    else " " ^ floats2 dash gap in
  let second =
    if dash <= 0.0 then ""
    else if dash2 <= 0.0 then ""
    else if gap2 <= 0.0 then " " ^ floats2 dash2 dash2
    else " " ^ floats2 dash2 gap2 in
  Tinyweb_external.set_state c "line_style" (cap ^ " " ^ join) (pyk_float_str offset ^ first ^ second)

let clip_rect c x y width height =
  Tinyweb_external.set_state c "clip" "rect" (numbers4 x y width height ^ " 0")

let clip_circle c x y radius =
  Tinyweb_external.set_state c "clip" "circle" (numbers3 x y radius)

let clip_polygon c points =
  Tinyweb_external.set_state c "clip" "polygon" (points_text points)

let text__default__color () = "#000000"

let text__default__size () = 16

let text__default__font () = ""

let text__default__align () = "left"

let text__default__bold () = false

let text__default__alpha () = 1.0

let text__default__baseline () = "top"

let text__default__outline () = ""

let text__default__outline_width () = 1

let text c x y words color size font align bold alpha baseline outline outline_width =
  Tinyweb_external.draw_text c (float_of_int x) (float_of_int y) words color size font align baseline bold outline (float_of_int outline_width) alpha

let measure_text__default__size () = 16

let measure_text__default__font () = ""

let measure_text__default__bold () = false

let measure_text words answer size font bold =
  Tinyweb_external.measure words size font bold answer

let translate c x y =
  Tinyweb_external.set_state c "translate" "" (pyk_float_str x ^ " " ^ pyk_float_str y)

let rotate c degrees =
  Tinyweb_external.set_state c "rotate" "" (pyk_float_str degrees)

let scale c sx sy =
  Tinyweb_external.set_state c "scale" "" (pyk_float_str sx ^ " " ^ pyk_float_str sy)

let push c = Tinyweb_external.set_state c "push" "" ""

let pop c = Tinyweb_external.set_state c "pop" "" ""

let reset c = Tinyweb_external.set_state c "reset" "" ""

let shadow__default__blur () = 10

let shadow__default__dx () = 0

let shadow__default__dy () = 0

let shadow c color blur dx dy =
  Tinyweb_external.set_state c "shadow" color (numbers3 blur dx dy)

let blend c mode =
  match mode with
      | ("normal" | "add") -> Tinyweb_external.set_state c "blend" mode ""
      | _ -> prerr_endline ("tinyweb: there is no blending called \"" ^ mode ^ "\"; the modes are normal and add")

let image__default__alpha () = 1.0

let image c picture x y width height alpha =
  Tinyweb_external.draw_image c picture x y width height alpha

let rec colors__hex2 n =
  let clamped = if n < 0 then 0 else if n > 255 then 255 else n in
  colors__hex_digit (clamped / 16) ^ colors__hex_digit (clamped - clamped / 16 * 16)
and colors__hex_digit d =
  match d with
      | 0 -> "0"
      | 1 -> "1"
      | 2 -> "2"
      | 3 -> "3"
      | 4 -> "4"
      | 5 -> "5"
      | 6 -> "6"
      | 7 -> "7"
      | 8 -> "8"
      | 9 -> "9"
      | 10 -> "a"
      | 11 -> "b"
      | 12 -> "c"
      | 13 -> "d"
      | 14 -> "e"
      | _ -> "f"

let colors__rgb r g b =
  "#" ^ colors__hex2 r ^ colors__hex2 g ^ colors__hex2 b

let colors__rgba r g b a =
  "rgba(" ^ string_of_int r ^ ", " ^ string_of_int g ^ ", " ^ string_of_int b ^ ", " ^ pyk_float_str a ^ ")"

let colors__hsl h s l =
  "hsl(" ^ string_of_int h ^ ", " ^ string_of_int s ^ "%, " ^ string_of_int l ^ "%)"

let colors__palette name =
  match name with
      | "ocean" -> ["#03045e"; "#0077b6"; "#00b4d8"; "#90e0ef"; "#caf0f8"]
      | "candy" -> ["#ff70a6"; "#ff9770"; "#ffd670"; "#e9ff70"; "#70d6ff"]
      | "forest" -> ["#2d6a4f"; "#40916c"; "#52b788"; "#95d5b2"; "#d8f3dc"]
      | "sunset" -> ["#f94144"; "#f3722c"; "#f8961e"; "#f9c74f"; "#90be6d"]
      | "neon" -> ["#ff00ff"; "#00ffff"; "#39ff14"; "#ffff00"; "#ff3131"]
      | _ -> (prerr_endline ("tinyweb: there is no palette called \"" ^ name ^ "\"; the palettes are ocean, candy, forest, sunset and neon");
  [])

let colors__linear_gradient x1 y1 x2 y2 start end_ =
  "linear-gradient(" ^ floats4 x1 y1 x2 y2 ^ "); 0.0 " ^ start ^ "; 1.0 " ^ end_

let colors__radial_gradient x1 y1 r1 x2 y2 r2 start end_ =
  "radial-gradient(" ^ floats3 x1 y1 r1 ^ " " ^ floats3 x2 y2 r2 ^ "); 0.0 " ^ start ^ "; 1.0 " ^ end_

let colors__conic_gradient x y angle start end_ =
  "conic-gradient(" ^ floats3 x y angle ^ "); 0.0 " ^ start ^ "; 1.0 " ^ end_

let colors__stop gradient at color =
  gradient ^ "; " ^ pyk_float_str at ^ " " ^ color

let button__default__on_click () = nothing

let button title on_click = Tinyweb_external.make_button title on_click

let slider__default__on_change () = ignore

let slider low high value on_change =
  Tinyweb_external.make_slider low high value on_change

let checkbox__default__checked () = false

let checkbox__default__on_change () = ignore_bool

let checkbox title checked on_change =
  Tinyweb_external.make_checkbox title checked on_change

let radio__default__chosen () = false

let radio__default__on_pick () = ignore_text

let radio group title chosen on_pick =
  Tinyweb_external.make_radio group title chosen on_pick

let rec lines_of options =
  match options with
      | [] -> ""
      | [only] -> only
      | (first :: rest) -> first ^ "\n" ^ lines_of rest

let choice__default__chosen () = 0

let choice__default__on_change () = ignore

let choice options chosen on_change =
  Tinyweb_external.make_choice (lines_of options) chosen on_change

let text_input__default__placeholder () = ""

let text_input__default__on_enter () = ignore_text

let text_input placeholder on_enter =
  Tinyweb_external.make_text_input placeholder on_enter

let number_input__default__on_change () = ignore

let number_input low high value on_change =
  Tinyweb_external.make_number_input low high value on_change

let known_theme name =
  match name with
      | "light" -> true
      | "dark" -> true
      | "plain" -> true
      | "paper" -> true
      | "retro" -> true
      | _ -> false

let style_text id kind property value =
  if value = "" then ()
  else Tinyweb_external.apply_style id kind property value

let style_pixels id kind property value =
  if value < 0 then ()
  else
    Tinyweb_external.apply_style id kind property (string_of_int value ^ "px")

let theme name =
  if known_theme name then
    Tinyweb_external.apply_style "" "theme" "name" name
  else
    prerr_endline ("tinyweb: there is no theme called \"" ^ name ^ "\"; the themes are light, dark, plain, paper and retro")

let page_style__default__background () = ""

let page_style__default__color () = ""

let page_style__default__font () = ""

let page_style__default__size () = -1

let page_style__default__padding () = -1

let page_style__default__gap () = -1

let page_style__default__align () = ""

let page_style background color font size padding gap align =
  style_text "" "page" "background" background;
  style_text "" "page" "color" color;
  style_text "" "page" "font" font;
  style_pixels "" "page" "size" size;
  style_pixels "" "page" "padding" padding;
  style_pixels "" "page" "gap" gap;
  style_text "" "page" "align" align

let button_style__default__background () = ""

let button_style__default__color () = ""

let button_style__default__border () = ""

let button_style__default__radius () = -1

let button_style__default__font () = ""

let button_style__default__size () = -1

let button_style__default__padding () = -1

let button_style background color border radius font size padding =
  style_text "" "button" "background" background;
  style_text "" "button" "color" color;
  style_text "" "button" "border" border;
  style_pixels "" "button" "radius" radius;
  style_text "" "button" "font" font;
  style_pixels "" "button" "size" size;
  style_pixels "" "button" "padding" padding

let label_style__default__background () = ""

let label_style__default__color () = ""

let label_style__default__border () = ""

let label_style__default__radius () = -1

let label_style__default__font () = ""

let label_style__default__size () = -1

let label_style__default__padding () = -1

let label_style background color border radius font size padding =
  style_text "" "label" "background" background;
  style_text "" "label" "color" color;
  style_text "" "label" "border" border;
  style_pixels "" "label" "radius" radius;
  style_text "" "label" "font" font;
  style_pixels "" "label" "size" size;
  style_pixels "" "label" "padding" padding

let slider_style__default__accent () = ""

let slider_style__default__width () = -1

let slider_style__default__color () = ""

let slider_style__default__font () = ""

let slider_style__default__size () = -1

let slider_style accent width color font size =
  style_text "" "slider" "accent" accent;
  style_pixels "" "slider" "width" width;
  style_text "" "slider" "color" color;
  style_text "" "slider" "font" font;
  style_pixels "" "slider" "size" size

let canvas_style__default__border () = ""

let canvas_style__default__radius () = -1

let canvas_style border radius =
  style_text "" "canvas" "border" border;
  style_pixels "" "canvas" "radius" radius

let set_colors__default__color () = ""

let set_colors__default__background () = ""

let set_colors id color background =
  style_text id "element" "color" color;
  style_text id "element" "accent" color;
  style_text id "element" "background" background

let set_style__default__background () = ""

let set_style__default__color () = ""

let set_style__default__border () = ""

let set_style__default__radius () = -1

let set_style__default__font () = ""

let set_style__default__size () = -1

let set_style__default__padding () = -1

let set_style__default__accent () = ""

let set_style__default__width () = -1

let set_style__default__weight () = -1

let set_style__default__height () = -1

let set_style id background color border radius font size padding accent width weight height =
  style_text id "element" "background" background;
  style_text id "element" "color" color;
  style_text id "element" "border" border;
  style_pixels id "element" "radius" radius;
  style_text id "element" "font" font;
  style_pixels id "element" "size" size;
  style_pixels id "element" "padding" padding;
  style_text id "element" "accent" accent;
  style_pixels id "element" "width" width;
  if weight >= 0 then
    style_text id "element" "weight" (string_of_int weight);
  style_pixels id "element" "height" height

let play__default__at () = 0.0

let play__default__volume () = 1.0

let play__default__rate () = 1.0

let play sample at volume rate =
  Tinyweb_external.play_sample sample at volume rate

let play_file name =
  play (Tinyweb_external.load_sample name) (play__default__at ()) (play__default__volume ()) (play__default__rate ())

let on_press c f = Tinyweb_external.watch_pointer c "press" f

let on_release c f = Tinyweb_external.watch_pointer c "release" f

let on_move c f = Tinyweb_external.watch_pointer c "move" f

let on_drag c f = Tinyweb_external.watch_pointer c "drag" f

let mouse_x c = Tinyweb_external.pointer c "x"

let mouse_y c = Tinyweb_external.pointer c "y"

let mouse_down c = Tinyweb_external.pointer c "down" = 1

let ignore2 _x _y = ()

let show_bitmap__default__x () = 0

let show_bitmap__default__y () = 0

let show_bitmap__default__scale () = 1.0

let show_bitmap c b x y scale =
  Tinyweb_external.draw_bitmap c b x y scale

let channel_of n = if n < 0 then 0 else if n > 255 then 255 else n

let pixel_color r g b =
  channel_of r * 65536 + channel_of g * 256 + channel_of b

let red color = color / 65536 - color / 16777216 * 256

let green color = color / 256 - color / 65536 * 256

let blue color = color - color / 256 * 256

let smooth__circle__default__color () = "#000000"

let smooth__circle__default__outline () = ""

let smooth__circle__default__outline_width () = 1.0

let smooth__circle__default__alpha () = 1.0

let smooth__circle c x y radius color outline outline_width alpha =
  Tinyweb_external.draw_shape c "circle" (floats3 x y radius) color outline outline_width alpha

let smooth__circles__default__color () = "#000000"

let smooth__circles__default__outline () = ""

let smooth__circles__default__outline_width () = 1.0

let smooth__circles__default__alpha () = 1.0

let smooth__circles c circles color outline outline_width alpha =
  Tinyweb_external.draw_triples c "circles" circles color outline outline_width alpha

let smooth__rect__default__color () = "#000000"

let smooth__rect__default__outline () = ""

let smooth__rect__default__outline_width () = 1.0

let smooth__rect__default__alpha () = 1.0

let smooth__rect__default__radius () = 0.0

let smooth__rect c x y width height color outline outline_width alpha radius =
  Tinyweb_external.draw_shape c "rect" (floats4 x y width height ^ " " ^ pyk_float_str radius) color outline outline_width alpha

let smooth__ellipse__default__color () = "#000000"

let smooth__ellipse__default__outline () = ""

let smooth__ellipse__default__outline_width () = 1.0

let smooth__ellipse__default__alpha () = 1.0

let smooth__ellipse c x y rx ry color outline outline_width alpha =
  Tinyweb_external.draw_shape c "ellipse" (floats4 x y rx ry) color outline outline_width alpha

let smooth__arc__default__color () = "#000000"

let smooth__arc__default__outline () = ""

let smooth__arc__default__outline_width () = 1.0

let smooth__arc__default__alpha () = 1.0

let smooth__arc c x y radius start end_ color outline outline_width alpha =
  Tinyweb_external.draw_shape c "arc" (floats3 x y radius ^ " " ^ floats2 start end_) color outline outline_width alpha

let smooth__polygon__default__color () = "#000000"

let smooth__polygon__default__outline () = ""

let smooth__polygon__default__outline_width () = 1.0

let smooth__polygon__default__alpha () = 1.0

let smooth__polygon c points color outline outline_width alpha =
  Tinyweb_external.draw_pairs c "polygon" points color outline outline_width alpha

let smooth__line__default__color () = "#000000"

let smooth__line__default__width () = 1.0

let smooth__line__default__alpha () = 1.0

let smooth__line c x1 y1 x2 y2 color width alpha =
  Tinyweb_external.draw_shape c "line" (floats4 x1 y1 x2 y2) "" color width alpha

let smooth__lines__default__color () = "#000000"

let smooth__lines__default__width () = 1.0

let smooth__lines__default__alpha () = 1.0

let smooth__lines c segments color width alpha =
  Tinyweb_external.draw_quads c "lines" segments "" color width alpha

let smooth__path__default__color () = "#000000"

let smooth__path__default__width () = 1.0

let smooth__path__default__alpha () = 1.0

let smooth__path c points color width alpha =
  Tinyweb_external.draw_pairs c "path" points "" color width alpha

let smooth__curve__default__color () = "#000000"

let smooth__curve__default__width () = 1.0

let smooth__curve__default__alpha () = 1.0

let smooth__curve c x1 y1 cx cy x2 y2 color width alpha =
  Tinyweb_external.draw_shape c "curve" (floats2 x1 y1 ^ " " ^ floats4 cx cy x2 y2) "" color width alpha

let smooth__bezier__default__color () = "#000000"

let smooth__bezier__default__width () = 1.0

let smooth__bezier__default__alpha () = 1.0

let smooth__bezier c x1 y1 ax ay bx by x2 y2 color width alpha =
  Tinyweb_external.draw_shape c "bezier" (floats4 x1 y1 ax ay ^ " " ^ floats4 bx by x2 y2) "" color width alpha

let smooth__text__default__color () = "#000000"

let smooth__text__default__size () = 16

let smooth__text__default__font () = ""

let smooth__text__default__align () = "left"

let smooth__text__default__bold () = false

let smooth__text__default__alpha () = 1.0

let smooth__text__default__baseline () = "top"

let smooth__text__default__outline () = ""

let smooth__text__default__outline_width () = 1.0

let smooth__text c x y words color size font align bold alpha baseline outline outline_width =
  Tinyweb_external.draw_text c x y words color size font align baseline bold outline outline_width alpha

let smooth__clip_circle c x y radius =
  Tinyweb_external.set_state c "clip" "circle" (floats3 x y radius)

let smooth__clip_polygon c points =
  Tinyweb_external.set_state c "clip" "polygon" (float_points_text points)
