(* Generated from tinyweb.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml4.14. The module 'tinyweb' of the program; compile it
   before the ones that import it. *)

[@@@warning "-fragile-match"]

let pyk_quote text =
  let out = Buffer.create (String.length text + 2) in
  Buffer.add_char out '"';
  String.iter
    (fun c ->
      match c with
      | '\\' -> Buffer.add_string out "\\\\"
      | '"' -> Buffer.add_string out "\\\""
      | '\n' -> Buffer.add_string out "\\n"
      | '\t' -> Buffer.add_string out "\\t"
      | '\r' -> Buffer.add_string out "\\r"
      | '\000' -> Buffer.add_string out "\\0"
      | c -> Buffer.add_char out c)
    text;
  Buffer.add_char out '"';
  Buffer.contents out

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

let pyk_truncate x =
  if Float.is_nan x then 0
  else
    let t = Float.trunc x in
    if t < -2147483648.0 || t > 2147483647.0 then 0 else int_of_float t

let pyk_int_of_string s =
  let n = String.length s in
  let start = if n > 0 && (s.[0] = '-' || s.[0] = '+') then 1 else 0 in
  let rec digits i = i = n || (s.[i] >= '0' && s.[i] <= '9' && digits (i + 1)) in
  if start = n || not (digits start) then 0
  else
    match int_of_string_opt s with
    | Some v when v >= -2147483648 && v <= 2147483647 -> v
    | Some _ | None -> 0

type color__Color =
  | Color__Color of int * int * int * float
and color__Paint =
  | Color__Plain of color__Color
  | Color__Linear of float * float * float * float * color__Color * color__Color * string
  | Color__Radial of float * float * float * float * float * float * color__Color * color__Color * string
  | Color__Conic of float * float * float * color__Color * color__Color * string
and point =
  | Point of int * int
and style =
  | Style of color__Color * color__Color * int * float * color__Paint
and pointer =
  | Pointer of int * int * bool
and sound__Voice =
  | Sound__Voice of float * float * float * int * bool * bool
and smooth__Point =
  | Smooth__Point of float * float

let rec pyk_show_color__Color value =
  let Color__Color (f0, f1, f2, f3) = value in "Color__Color(" ^ string_of_int f0 ^ ", " ^ string_of_int f1 ^ ", " ^ string_of_int f2 ^ ", " ^ pyk_float_str f3 ^ ")"
and pyk_show_color__Paint value =
  match value with
      | Color__Plain f0 -> "Color__Plain(" ^ pyk_show_color__Color f0 ^ ")"
      | Color__Linear (f0, f1, f2, f3, f4, f5, f6) -> "Color__Linear(" ^ pyk_float_str f0 ^ ", " ^ pyk_float_str f1 ^ ", " ^ pyk_float_str f2 ^ ", " ^ pyk_float_str f3 ^ ", " ^ pyk_show_color__Color f4 ^ ", " ^ pyk_show_color__Color f5 ^ ", " ^ pyk_quote f6 ^ ")"
      | Color__Radial (f0, f1, f2, f3, f4, f5, f6, f7, f8) -> "Color__Radial(" ^ pyk_float_str f0 ^ ", " ^ pyk_float_str f1 ^ ", " ^ pyk_float_str f2 ^ ", " ^ pyk_float_str f3 ^ ", " ^ pyk_float_str f4 ^ ", " ^ pyk_float_str f5 ^ ", " ^ pyk_show_color__Color f6 ^ ", " ^ pyk_show_color__Color f7 ^ ", " ^ pyk_quote f8 ^ ")"
      | Color__Conic (f0, f1, f2, f3, f4, f5) -> "Color__Conic(" ^ pyk_float_str f0 ^ ", " ^ pyk_float_str f1 ^ ", " ^ pyk_float_str f2 ^ ", " ^ pyk_show_color__Color f3 ^ ", " ^ pyk_show_color__Color f4 ^ ", " ^ pyk_quote f5 ^ ")"
and pyk_show_point value =
  let Point (f0, f1) = value in "Point(" ^ string_of_int f0 ^ ", " ^ string_of_int f1 ^ ")"
and pyk_show_style value =
  let Style (f0, f1, f2, f3, f4) = value in "Style(" ^ pyk_show_color__Color f0 ^ ", " ^ pyk_show_color__Color f1 ^ ", " ^ string_of_int f2 ^ ", " ^ pyk_float_str f3 ^ ", " ^ pyk_show_color__Paint f4 ^ ")"
and pyk_show_pointer value =
  let Pointer (f0, f1, f2) = value in "Pointer(" ^ string_of_int f0 ^ ", " ^ string_of_int f1 ^ ", " ^ string_of_bool f2 ^ ")"
and pyk_show_sound__Voice value =
  let Sound__Voice (f0, f1, f2, f3, f4, f5) = value in "Sound__Voice(" ^ pyk_float_str f0 ^ ", " ^ pyk_float_str f1 ^ ", " ^ pyk_float_str f2 ^ ", " ^ string_of_int f3 ^ ", " ^ string_of_bool f4 ^ ", " ^ string_of_bool f5 ^ ")"
and pyk_show_smooth__Point value =
  let Smooth__Point (f0, f1) = value in "Smooth__Point(" ^ pyk_float_str f0 ^ ", " ^ pyk_float_str f1 ^ ")"

let nothing () = ()

let ignore _value = ()

let ignore_bool _value = ()

let ignore_text _value = ()

let _ignore_float _value = ()

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
  joined (List.concat_map (function | p -> [numbers2 (let Point (tmp5, _) = p in tmp5) (let Point (_, tmp6) = p in tmp6)]) points)

let segments_text segments =
  joined (List.concat_map (function | (a, b) -> [numbers4 (let Point (tmp7, _) = a in tmp7) (let Point (_, tmp8) = a in tmp8) (let Point (tmp9, _) = b in tmp9) (let Point (_, tmp10) = b in tmp10)]) segments)

let floats2 a b = pyk_float_str a ^ " " ^ pyk_float_str b

let floats3 a b c = floats2 a b ^ " " ^ pyk_float_str c

let floats4 a b c d = floats2 a b ^ " " ^ floats2 c d

let float_points_text points =
  joined (List.concat_map (function | p -> [floats2 (let Smooth__Point (tmp11, _) = p in tmp11) (let Smooth__Point (_, tmp12) = p in tmp12)]) points)

let bit on = if on then "1" else "0"

let color__black = Color__Color (0, 0, 0, 1.0)

let color__white = Color__Color (255, 255, 255, 1.0)

let color__gray = Color__Color (128, 128, 128, 1.0)

let color__red = Color__Color (255, 0, 0, 1.0)

let color__green = Color__Color (0, 128, 0, 1.0)

let color__blue = Color__Color (0, 0, 255, 1.0)

let color__yellow = Color__Color (255, 255, 0, 1.0)

let color__orange = Color__Color (255, 165, 0, 1.0)

let color__purple = Color__Color (128, 0, 128, 1.0)

let color__pink = Color__Color (255, 192, 203, 1.0)

let color__navy = Color__Color (0, 0, 128, 1.0)

let color__teal = Color__Color (0, 128, 128, 1.0)

let color__brown = Color__Color (139, 69, 19, 1.0)

let color__cyan = Color__Color (0, 255, 255, 1.0)

let color__magenta = Color__Color (255, 0, 255, 1.0)

let color__none = Color__Color (0, 0, 0, 0.0)

let color__theme = Color__Color (-1, -1, -1, -.1.0)

let color__sector sector chroma x =
  match sector with
      | 0 -> (chroma, x, 0.0)
      | 1 -> (x, chroma, 0.0)
      | 2 -> (0.0, chroma, x)
      | 3 -> (0.0, x, chroma)
      | 4 -> (x, 0.0, chroma)
      | _ -> (chroma, 0.0, x)

let color__part n = if n < 0 then 0 else if n > 255 then 255 else n

let color__unit x = if x < 0.0 then 0.0 else if x > 1.0 then 1.0 else x

let color__byte x =
  color__part (pyk_truncate (color__unit x *. 255.0 +. 0.5))

let color__absolute x = if x < 0.0 then -.x else x

let color__wrap x m =
  let r = x -. float_of_int (pyk_truncate (x /. m)) *. m in
  if r < 0.0 then r +. m else r

let color__between a b t = float_of_int a +. float_of_int (b - a) *. t

let rec color__hex2 n =
  let clamped = color__part n in
  color__hex_digit (clamped / 16) ^ color__hex_digit (clamped - clamped / 16 * 16)
and color__hex_digit d =
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

let color__css c =
  if (let Color__Color (_, _, _, tmp13) = c in tmp13) >= 1.0 then
    "#" ^ color__hex2 (let Color__Color (tmp14, _, _, _) = c in tmp14) ^ color__hex2 (let Color__Color (_, tmp15, _, _) = c in tmp15) ^ color__hex2 (let Color__Color (_, _, tmp16, _) = c in tmp16)
  else
    "rgba(" ^ string_of_int (color__part (let Color__Color (tmp17, _, _, _) = c in tmp17)) ^ ", " ^ string_of_int (color__part (let Color__Color (_, tmp18, _, _) = c in tmp18)) ^ ", " ^ string_of_int (color__part (let Color__Color (_, _, tmp19, _) = c in tmp19)) ^ ", " ^ pyk_float_str (color__unit (let Color__Color (_, _, _, tmp20) = c in tmp20)) ^ ")"

let color__drawn c =
  if (let Color__Color (_, _, _, tmp21) = c in tmp21) <= 0.0 then ""
  else color__css c

let color__paint_text p =
  match p with
      | Color__Plain (c) -> color__drawn c
      | Color__Linear (x1, y1, x2, y2, start, end_, stops) -> "linear-gradient(" ^ floats4 x1 y1 x2 y2 ^ "); 0.0 " ^ color__css start ^ "; 1.0 " ^ color__css end_ ^ stops
      | Color__Radial (x1, y1, r1, x2, y2, r2, start, end_, stops) -> "radial-gradient(" ^ floats3 x1 y1 r1 ^ " " ^ floats3 x2 y2 r2 ^ "); 0.0 " ^ color__css start ^ "; 1.0 " ^ color__css end_ ^ stops
      | Color__Conic (x, y, angle, start, end_, stops) -> "conic-gradient(" ^ floats3 x y angle ^ "); 0.0 " ^ color__css start ^ "; 1.0 " ^ color__css end_ ^ stops

let color__painted p =
  match p with
      | Color__Plain (c) -> (let Color__Color (_, _, _, tmp22) = c in tmp22) > 0.0
      | _ -> true

let color__is_theme c =
  (let Color__Color (_, _, _, tmp23) = c in tmp23) < 0.0

let color__rgb r g b =
  Color__Color (color__part r, color__part g, color__part b, 1.0)

let color__rgba r g b a =
  Color__Color (color__part r, color__part g, color__part b, (if a < 0.0 then 0.0 else if a > 1.0 then 1.0 else a))

let color__hsl h s l =
  let hue = color__wrap h 360.0 /. 60.0 in
  let sat = color__unit (s /. 100.0) in
  let light = color__unit (l /. 100.0) in
  let chroma = (1.0 -. color__absolute (2.0 *. light -. 1.0)) *. sat in
  let x = chroma *. (1.0 -. color__absolute (color__wrap hue 2.0 -. 1.0)) in
  let m = light -. chroma /. 2.0 in
  let (r, g, b) = color__sector (pyk_truncate hue) chroma x in
  Color__Color (color__byte (r +. m), color__byte (g +. m), color__byte (b +. m), 1.0)

let color__hex n =
  Color__Color (color__part (n / 65536), color__part (n / 256 - n / 65536 * 256), color__part (n - n / 256 * 256), 1.0)

let color__to_hex c =
  color__part (let Color__Color (tmp24, _, _, _) = c in tmp24) * 65536 + color__part (let Color__Color (_, tmp25, _, _) = c in tmp25) * 256 + color__part (let Color__Color (_, _, tmp26, _) = c in tmp26)

let color__with_alpha c a =
  Color__Color ((let Color__Color (tmp27, _, _, _) = c in tmp27), (let Color__Color (_, tmp28, _, _) = c in tmp28), (let Color__Color (_, _, tmp29, _) = c in tmp29), color__unit a)

let color__mix a b t =
  let k = color__unit t in
  Color__Color (color__byte (color__between (let Color__Color (tmp30, _, _, _) = a in tmp30) (let Color__Color (tmp31, _, _, _) = b in tmp31) k /. 255.0), color__byte (color__between (let Color__Color (_, tmp32, _, _) = a in tmp32) (let Color__Color (_, tmp33, _, _) = b in tmp33) k /. 255.0), color__byte (color__between (let Color__Color (_, _, tmp34, _) = a in tmp34) (let Color__Color (_, _, tmp35, _) = b in tmp35) k /. 255.0), (let Color__Color (_, _, _, tmp36) = a in tmp36) +. ((let Color__Color (_, _, _, tmp37) = b in tmp37) -. (let Color__Color (_, _, _, tmp38) = a in tmp38)) *. k)

let color__same a b =
  if (let Color__Color (tmp39, _, _, _) = a in tmp39) = (let Color__Color (tmp40, _, _, _) = b in tmp40) then
    (if (let Color__Color (_, tmp41, _, _) = a in tmp41) = (let Color__Color (_, tmp42, _, _) = b in tmp42) then
      (if (let Color__Color (_, _, tmp43, _) = a in tmp43) = (let Color__Color (_, _, tmp44, _) = b in tmp44) then
        (let Color__Color (_, _, _, tmp45) = a in tmp45) = (let Color__Color (_, _, _, tmp46) = b in tmp46)
      else false)
    else false)
  else false

let color__palette name =
  match name with
      | "ocean" -> [color__hex 197726; color__hex 30646; color__hex 46296; color__hex 9494767; color__hex 13299960]
      | "candy" -> [color__hex 16740518; color__hex 16750448; color__hex 16766576; color__hex 15335280; color__hex 7395071]
      | "forest" -> [color__hex 2976335; color__hex 4231532; color__hex 5420936; color__hex 9819570; color__hex 14218204]
      | "sunset" -> [color__hex 16335172; color__hex 15954476; color__hex 16291358; color__hex 16369487; color__hex 9485933]
      | "neon" -> [color__hex 16711935; color__hex 65535; color__hex 3800852; color__hex 16776960; color__hex 16724273]
      | _ -> (prerr_endline ("tinyweb: there is no palette called \"" ^ name ^ "\"; the palettes are ocean, candy, forest, sunset and neon");
  [])

let color__stop paint at c =
  let more = "; " ^ pyk_float_str at ^ " " ^ color__css c in
  match paint with
      | Color__Plain (_) -> paint
      | Color__Linear (x1, y1, x2, y2, start, end_, stops) -> Color__Linear (x1, y1, x2, y2, start, end_, stops ^ more)
      | Color__Radial (x1, y1, r1, x2, y2, r2, start, end_, stops) -> Color__Radial (x1, y1, r1, x2, y2, r2, start, end_, stops ^ more)
      | Color__Conic (x, y, angle, start, end_, stops) -> Color__Conic (x, y, angle, start, end_, stops ^ more)

let web_init port = Tinyweb_external.web_start port

let field__default__Style__fill () = color__black

let field__default__Style__stroke () = color__none

let field__default__Style__paint () = Color__Plain color__none

let rec fill_of fill paint style =
  if color__painted paint then color__paint_text paint
  else if not_default_fill fill then color__drawn fill
  else if color__painted (let Style (_, _, _, _, tmp47) = style in tmp47) then
    color__paint_text (let Style (_, _, _, _, tmp48) = style in tmp48)
  else color__drawn (let Style (tmp49, _, _, _, _) = style in tmp49)
and not_default_fill fill =
  if color__same fill color__black then false else true

let stroke_of stroke style =
  color__drawn (if color__same stroke color__none then
    (let Style (_, tmp50, _, _, _) = style in tmp50)
  else stroke)

let line_of stroke style =
  if not_default_fill stroke then color__drawn stroke
  else if color__same (let Style (_, tmp51, _, _, _) = style in tmp51) color__none then
    color__drawn (let Style (tmp52, _, _, _, _) = style in tmp52)
  else color__drawn (let Style (_, tmp53, _, _, _) = style in tmp53)

let width_of width style =
  float_of_int (if width = 1 then (let Style (_, _, tmp54, _, _) = style in tmp54)
  else width)

let alpha_of alpha style =
  if alpha = 1.0 then (let Style (_, _, _, tmp55, _) = style in tmp55)
  else alpha

let shape c kind numbers fill stroke width alpha paint style =
  Tinyweb_external.draw_shape c kind numbers (fill_of fill paint style) (stroke_of stroke style) (width_of width style) (alpha_of alpha style)

let stroked c kind numbers stroke width alpha style =
  Tinyweb_external.draw_shape c kind numbers "" (line_of stroke style) (width_of width style) (alpha_of alpha style)

let clear__default__fill () = color__white

let clear c fill = Tinyweb_external.fill_canvas c (color__css fill)

let circle__default__fill () = color__black

let circle__default__stroke () = color__none

let circle__default__paint () = Color__Plain color__none

let circle__default__style () =
  Style (field__default__Style__fill (), field__default__Style__stroke (), 1, 1.0, field__default__Style__paint ())

let circle c x y radius fill stroke width alpha paint style =
  shape c "circle" (numbers3 x y radius) fill stroke width alpha paint style

let rect__default__fill () = color__black

let rect__default__stroke () = color__none

let rect__default__paint () = Color__Plain color__none

let rect__default__style () =
  Style (field__default__Style__fill (), field__default__Style__stroke (), 1, 1.0, field__default__Style__paint ())

let rect c x y w h fill stroke width alpha paint style radius =
  shape c "rect" (numbers4 x y w h ^ " " ^ string_of_int radius) fill stroke width alpha paint style

let ellipse__default__fill () = color__black

let ellipse__default__stroke () = color__none

let ellipse__default__paint () = Color__Plain color__none

let ellipse__default__style () =
  Style (field__default__Style__fill (), field__default__Style__stroke (), 1, 1.0, field__default__Style__paint ())

let ellipse c x y rx ry fill stroke width alpha paint style =
  shape c "ellipse" (numbers4 x y rx ry) fill stroke width alpha paint style

let arc__default__fill () = color__black

let arc__default__stroke () = color__none

let arc__default__paint () = Color__Plain color__none

let arc__default__style () =
  Style (field__default__Style__fill (), field__default__Style__stroke (), 1, 1.0, field__default__Style__paint ())

let arc c x y radius start end_ fill stroke width alpha paint style =
  shape c "arc" (numbers3 x y radius ^ " " ^ floats2 start end_) fill stroke width alpha paint style

let polygon__default__fill () = color__black

let polygon__default__stroke () = color__none

let polygon__default__paint () = Color__Plain color__none

let polygon__default__style () =
  Style (field__default__Style__fill (), field__default__Style__stroke (), 1, 1.0, field__default__Style__paint ())

let polygon c points fill stroke width alpha paint style =
  shape c "polygon" (points_text points) fill stroke width alpha paint style

let line__default__stroke () = color__black

let line__default__style () =
  Style (field__default__Style__fill (), field__default__Style__stroke (), 1, 1.0, field__default__Style__paint ())

let line c x1 y1 x2 y2 stroke width alpha style =
  stroked c "line" (numbers4 x1 y1 x2 y2) stroke width alpha style

let path__default__stroke () = color__black

let path__default__style () =
  Style (field__default__Style__fill (), field__default__Style__stroke (), 1, 1.0, field__default__Style__paint ())

let path c points stroke width alpha style =
  stroked c "path" (points_text points) stroke width alpha style

let curve__default__stroke () = color__black

let curve__default__style () =
  Style (field__default__Style__fill (), field__default__Style__stroke (), 1, 1.0, field__default__Style__paint ())

let curve c x1 y1 cx cy x2 y2 stroke width alpha style =
  stroked c "curve" (numbers2 x1 y1 ^ " " ^ numbers4 cx cy x2 y2) stroke width alpha style

let lines__default__stroke () = color__black

let lines__default__style () =
  Style (field__default__Style__fill (), field__default__Style__stroke (), 1, 1.0, field__default__Style__paint ())

let lines c segments stroke width alpha style =
  stroked c "lines" (segments_text segments) stroke width alpha style

let bezier__default__stroke () = color__black

let bezier__default__style () =
  Style (field__default__Style__fill (), field__default__Style__stroke (), 1, 1.0, field__default__Style__paint ())

let bezier c x1 y1 ax ay bx by x2 y2 stroke width alpha style =
  stroked c "bezier" (numbers4 x1 y1 ax ay ^ " " ^ numbers4 bx by x2 y2) stroke width alpha style

let erase c x y w h =
  Tinyweb_external.draw_shape c "erase" (numbers4 x y w h) "" "" 0.0 1.0

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

let clip_rect c x y w h =
  Tinyweb_external.set_state c "clip" "rect" (numbers4 x y w h ^ " 0")

let clip_circle c x y radius =
  Tinyweb_external.set_state c "clip" "circle" (numbers3 x y radius)

let clip_polygon c points =
  Tinyweb_external.set_state c "clip" "polygon" (points_text points)

let text__default__fill () = color__black

let text__default__stroke () = color__none

let text__default__paint () = Color__Plain color__none

let text__default__style () =
  Style (field__default__Style__fill (), field__default__Style__stroke (), 1, 1.0, field__default__Style__paint ())

let text c x y words fill size font align bold alpha baseline stroke width paint style =
  Tinyweb_external.draw_text c (float_of_int x) (float_of_int y) words (fill_of fill paint style) size font align baseline bold (stroke_of stroke style) (width_of width style) (alpha_of alpha style)

let measure_text words answer size font bold =
  Tinyweb_external.measure words size font bold answer

let translate c x y =
  Tinyweb_external.set_state c "translate" "" (floats2 x y)

let rotate c angle =
  Tinyweb_external.set_state c "rotate" "" (pyk_float_str angle)

let scale c sx sy =
  Tinyweb_external.set_state c "scale" "" (floats2 sx sy)

let push c = Tinyweb_external.set_state c "push" "" ""

let pop c = Tinyweb_external.set_state c "pop" "" ""

let reset c = Tinyweb_external.set_state c "reset" "" ""

let shadow c shade blur dx dy =
  Tinyweb_external.set_state c "shadow" (color__drawn shade) (numbers3 blur dx dy)

let blend c mode =
  match mode with
      | ("normal" | "add") -> Tinyweb_external.set_state c "blend" mode ""
      | _ -> prerr_endline ("tinyweb: there is no blending called \"" ^ mode ^ "\"; the modes are normal and add")

let image c picture x y w h alpha =
  Tinyweb_external.draw_image c picture x y w h alpha

let button__default__on_click () = nothing

let slider__default__on_change () = ignore

let slider low high value on_change =
  Tinyweb_external.make_slider low high value on_change

let checkbox__default__on_change () = ignore_bool

let checkbox title checked on_change =
  Tinyweb_external.make_checkbox title checked on_change

let radio__default__on_pick () = ignore_text

let radio group title chosen on_pick =
  Tinyweb_external.make_radio group title chosen on_pick

let lines_of options = joined_by options "\n"

let choice__default__on_change () = ignore

let choice options chosen on_change =
  Tinyweb_external.make_choice (lines_of options) chosen on_change

let text_input__default__on_enter () = ignore_text

let text_input placeholder on_enter =
  Tinyweb_external.make_text_input placeholder on_enter

let number_input__default__on_change () = ignore

let number_input low high value on_change =
  Tinyweb_external.make_number_input low high value on_change

let set_text id words =
  Tinyweb_external.command "set_text" id words "" 1

let show id = Tinyweb_external.command "visible" id "" "1" 1

let hide id = Tinyweb_external.command "visible" id "" "0" 1

let enable id = Tinyweb_external.command "enabled" id "" "1" 1

let disable id = Tinyweb_external.command "enabled" id "" "0" 1

let remove id = Tinyweb_external.command "remove" id "" "" 0

let value_of id = Tinyweb_external.report_text ("value." ^ id)

let known_theme name =
  match name with
      | ("light" | "dark" | "plain" | "paper" | "retro") -> true
      | _ -> false

let style_text id kind property value =
  if value = "" then ()
  else Tinyweb_external.apply_style id kind property value

let style_color id kind property c =
  if color__is_theme c then ()
  else Tinyweb_external.apply_style id kind property (color__css c)

let style_border id kind border width =
  if color__is_theme border then
    (if width >= 0 then
      Tinyweb_external.apply_style id kind "border" (string_of_int width ^ "px solid currentColor")
    else ())
  else if (let Color__Color (_, _, _, tmp56) = border in tmp56) <= 0.0 then
    Tinyweb_external.apply_style id kind "border" "none"
  else
    Tinyweb_external.apply_style id kind "border" (string_of_int (if width >= 0 then width else 1) ^ "px solid " ^ color__css border)

let style_pixels id kind property value =
  if value < 0 then ()
  else
    Tinyweb_external.apply_style id kind property (string_of_int value ^ "px")

let theme name =
  if known_theme name then
    Tinyweb_external.apply_style "" "theme" "name" name
  else
    prerr_endline ("tinyweb: there is no theme called \"" ^ name ^ "\"; the themes are light, dark, plain, paper and retro")

let page_style__default__background () = color__theme

let page_style__default__foreground () = color__theme

let page_style background foreground font size padding gap align =
  style_color "" "page" "background" background;
  style_color "" "page" "color" foreground;
  style_text "" "page" "font" font;
  style_pixels "" "page" "size" size;
  style_pixels "" "page" "padding" padding;
  style_pixels "" "page" "gap" gap;
  style_text "" "page" "align" align

let button_style__default__background () = color__theme

let button_style__default__foreground () = color__theme

let button_style__default__border () = color__theme

let button_style background foreground border border_width radius font size padding =
  style_color "" "button" "background" background;
  style_color "" "button" "color" foreground;
  style_border "" "button" border border_width;
  style_pixels "" "button" "radius" radius;
  style_text "" "button" "font" font;
  style_pixels "" "button" "size" size;
  style_pixels "" "button" "padding" padding

let label_style__default__background () = color__theme

let label_style__default__foreground () = color__theme

let label_style__default__border () = color__theme

let label_style background foreground border border_width radius font size padding =
  style_color "" "label" "background" background;
  style_color "" "label" "color" foreground;
  style_border "" "label" border border_width;
  style_pixels "" "label" "radius" radius;
  style_text "" "label" "font" font;
  style_pixels "" "label" "size" size;
  style_pixels "" "label" "padding" padding

let slider_style__default__accent () = color__theme

let slider_style__default__foreground () = color__theme

let slider_style accent width foreground font size =
  style_color "" "slider" "accent" accent;
  style_pixels "" "slider" "width" width;
  style_color "" "slider" "color" foreground;
  style_text "" "slider" "font" font;
  style_pixels "" "slider" "size" size

let canvas_style__default__border () = color__theme

let canvas_style border border_width radius =
  style_border "" "canvas" border border_width;
  style_pixels "" "canvas" "radius" radius

let set_style__default__background () = color__theme

let set_style__default__foreground () = color__theme

let set_style__default__border () = color__theme

let set_style__default__accent () = color__theme

let set_style id background foreground border border_width radius font size padding accent width weight height =
  style_color id "element" "background" background;
  style_color id "element" "color" foreground;
  style_border id "element" border border_width;
  style_pixels id "element" "radius" radius;
  style_text id "element" "font" font;
  style_pixels id "element" "size" size;
  style_pixels id "element" "padding" padding;
  style_color id "element" "accent" accent;
  style_pixels id "element" "width" width;
  if weight >= 0 then
    style_text id "element" "weight" (string_of_int weight);
  style_pixels id "element" "height" height

let button title on_click = Tinyweb_external.make_button title on_click

let on_click c f = Tinyweb_external.on_mouse c f

let on_press c f = Tinyweb_external.watch_pointer c "press" f

let on_release c f = Tinyweb_external.watch_pointer c "release" f

let on_move c f = Tinyweb_external.watch_pointer c "move" f

let on_drag c f = Tinyweb_external.watch_pointer c "drag" f

let mouse c =
  let tmp57 = Tinyweb_external.pointer c "x" in
  let tmp58 = Tinyweb_external.pointer c "y" in
  Pointer (tmp57, tmp58, Tinyweb_external.pointer c "down" = 1)

let rec track_mouse c = Tinyweb_external.watch_pointer c "move" ignore2
and ignore2 _x _y = ()

let after seconds f =
  let id = Tinyweb_external.fresh_id "timer" in
  Tinyweb_external.watch id "timer" f;
  Tinyweb_external.command "after" id "" (pyk_float_str seconds) 0;
  id

let every seconds f =
  let id = Tinyweb_external.fresh_id "timer" in
  Tinyweb_external.watch id "timer" f;
  Tinyweb_external.command "every" id "" (pyk_float_str seconds) 0;
  id

let cancel timer = Tinyweb_external.command "cancel" timer "" "" 0

let sound__settings at volume rate pan voice =
  let v =
    if volume = 1.0 then
      (let Sound__Voice (tmp59, _, _, _, _, _) = voice in tmp59)
    else volume in
  let r =
    if rate = 1.0 then
      (let Sound__Voice (_, tmp60, _, _, _, _) = voice in tmp60)
    else rate in
  let p =
    if pan = 0.0 then
      (let Sound__Voice (_, _, tmp61, _, _, _) = voice in tmp61)
    else pan in
  floats4 at v r p ^ " " ^ string_of_int (let Sound__Voice (_, _, _, tmp62, _, _) = voice in tmp62) ^ " " ^ bit (let Sound__Voice (_, _, _, _, _, tmp63) = voice in tmp63)

let play__default__voice () =
  Sound__Voice (1.0, 1.0, 0.0, 0, false, false)

let play sample at volume rate pan voice =
  Tinyweb_external.command "play" sample "" (sound__settings at volume rate pan voice) 2

let play_file name =
  play (Tinyweb_external.load_sample name) 0.0 1.0 1.0 0.0 (play__default__voice ())

let sound__start__default__voice () =
  Sound__Voice (1.0, 1.0, 0.0, 0, false, false)

let sound__start sample at volume rate pan looping voice =
  let id = Tinyweb_external.fresh_id "voice" in
  let looped =
    if looping then true
    else (let Sound__Voice (_, _, _, _, tmp64, _) = voice in tmp64) in
  Tinyweb_external.command "start" id sample (sound__settings at volume rate pan voice ^ " " ^ bit looped) 2;
  id

let sound__stop voice at =
  Tinyweb_external.command "stop" voice "" (pyk_float_str at) 2

let sound__fade voice volume over =
  Tinyweb_external.command "fade" voice "" (floats2 volume over) 2

let sound__stop_all () = Tinyweb_external.command "stop_all" "" "" "" 2

let sound__master_volume volume =
  Tinyweb_external.command "master" "" "" (pyk_float_str volume) 1

let sound__tone frequency at duration wave volume pan channel =
  Tinyweb_external.command "tone" "" wave (floats4 frequency at duration volume ^ " " ^ pyk_float_str pan ^ " " ^ string_of_int channel) 2

let rec sound__note name =
  let semitones = sound__semitones name in
  if semitones < -1000 then 0.0
  else 440.0 *. Math.pow 2.0 (float_of_int (semitones - 57) /. 12.0)
and sound__rate_of name base =
  let origin = sound__semitones base in
  let target = sound__semitones name in
  if origin < -1000 then 1.0
  else if target < -1000 then 1.0
  else Math.pow 2.0 (float_of_int (target - origin) /. 12.0)
and sound__semitones name =
  let base =
    match Text.char_at name 0 with
        | (67 | 99) -> 0
        | (68 | 100) -> 2
        | (69 | 101) -> 4
        | (70 | 102) -> 5
        | (71 | 103) -> 7
        | (65 | 97) -> 9
        | (66 | 98) -> 11
        | _ -> -10000 in
  let shift =
    match Text.char_at name 1 with
        | 35 -> 1
        | 98 -> -1
        | _ -> 0 in
  let rest =
    Text.slice name (if shift = 0 then 1 else 2) (Text.length name) in
  let octave = if rest = "" then 4 else pyk_int_of_string rest in
  let valid =
    if base < 0 then false
    else if rest = "" then true
    else string_of_int octave = rest in
  if valid then base + shift + octave * 12 else -10000

let sound__tempo bpm =
  Tinyweb_external.command "tempo" "" "" (pyk_float_str bpm) 1

let sound__swing amount =
  Tinyweb_external.command "swing" "" "" (pyk_float_str amount) 1

let sound__on_beat f steps =
  let id = Tinyweb_external.fresh_id "beat" in
  Tinyweb_external.watch_step id "beat" f;
  Tinyweb_external.command "beat" id "" (string_of_int steps) 0;
  id

let sound__beat () = Tinyweb_external.report_number "clock" 0

let sound__latency () = Tinyweb_external.report_number "clock" 1

let sound__pause () = Tinyweb_external.command "audio" "" "pause" "" 2

let sound__resume () = Tinyweb_external.command "audio" "" "resume" "" 2

let sound__channel_style channel volume pan echo echo_time feedback reverb low_pass =
  Tinyweb_external.command "channel" (string_of_int channel) "" (floats4 volume pan echo echo_time ^ " " ^ floats3 feedback reverb low_pass) 1

let sound__listen bins smoothing =
  Tinyweb_external.command "listen" "" "" (string_of_int bins ^ " " ^ pyk_float_str smoothing) 1

let sound__level () = Tinyweb_external.report_number "level" 0

let sound__band k = Tinyweb_external.report_number "band" k

let sound__bands () = Tinyweb_external.report_count "band"

let sound__wave k = Tinyweb_external.report_number "wave" k

let sound__render_wav seconds f name on_rendered =
  let id = Tinyweb_external.fresh_id "render" in
  Tinyweb_external.watch_pair id "rendered" on_rendered;
  Tinyweb_external.command "render" id name (pyk_float_str seconds) 2;
  f (); Tinyweb_external.command "render_end" id "" "" 2

let rec sound__render_wav__default__on_rendered () =
  sound__ignore_rendered
and sound__ignore_rendered _took _peak = ()

let bitmap__bitmap__default__background () = color__white

let bitmap__bitmap width height background =
  Tinyweb_external.make_bitmap width height (color__to_hex background)

let bitmap__set_pixel b x y pixel =
  Tinyweb_external.set_pixel b x y (color__to_hex pixel)

let bitmap__get_pixel b x y =
  color__hex (Tinyweb_external.get_pixel b x y)

let bitmap__fill_bitmap b fill =
  Tinyweb_external.fill_bitmap b (color__to_hex fill)

let bitmap__show_bitmap c b x y scale =
  Tinyweb_external.draw_bitmap c b x y scale

let layout__row () = Tinyweb_external.row ()

let layout__column () = Tinyweb_external.column ()

let layout__inside id = Tinyweb_external.inside id

let layout__outside () = Tinyweb_external.outside ()

let layout__text_area__default__on_change () = ignore_text

let layout__text_area words rows columns on_change =
  let id = Tinyweb_external.fresh_id "text" in
  Tinyweb_external.watch_text id "change" ("value." ^ id) on_change;
  Tinyweb_external.command "text_area" id words (numbers2 rows columns) 0;
  id

let net__save_canvas c name =
  Tinyweb_external.command "save_canvas" c name "" 2

let net__download name words =
  Tinyweb_external.command "download" name words "" 2

let net__file_button__default__on_load () = ignore_text

let net__file_button title on_load =
  let id = Tinyweb_external.fresh_id title in
  Tinyweb_external.watch_text id "loaded" "file" on_load;
  Tinyweb_external.command "file_button" id title "" 0; id

let net__file_text () = Tinyweb_external.report_text "file.text"

let game__cursor c name = Tinyweb_external.command "cursor" c name "" 1

let smooth__width_of width style =
  if width = 1.0 then
    float_of_int (let Style (_, _, tmp65, _, _) = style in tmp65)
  else width

let smooth__shape c kind numbers fill stroke width alpha paint style =
  Tinyweb_external.draw_shape c kind numbers (fill_of fill paint style) (stroke_of stroke style) (smooth__width_of width style) (alpha_of alpha style)

let smooth__stroked c kind numbers stroke width alpha style =
  Tinyweb_external.draw_shape c kind numbers "" (line_of stroke style) (smooth__width_of width style) (alpha_of alpha style)

let smooth__pairs points =
  List.concat_map (function | p -> [((let Smooth__Point (tmp66, _) = p in tmp66), (let Smooth__Point (_, tmp67) = p in tmp67))]) points

let smooth__circle__default__fill () = color__black

let smooth__circle__default__stroke () = color__none

let smooth__circle__default__paint () = Color__Plain color__none

let smooth__circle__default__style () =
  Style (field__default__Style__fill (), field__default__Style__stroke (), 1, 1.0, field__default__Style__paint ())

let smooth__circle c x y radius fill stroke width alpha paint style =
  smooth__shape c "circle" (floats3 x y radius) fill stroke width alpha paint style

let smooth__circles__default__fill () = color__black

let smooth__circles__default__stroke () = color__none

let smooth__circles__default__style () =
  Style (field__default__Style__fill (), field__default__Style__stroke (), 1, 1.0, field__default__Style__paint ())

let smooth__circles c circles fill stroke width alpha style =
  Tinyweb_external.draw_triples c "circles" circles (fill_of fill (Color__Plain color__none) style) (stroke_of stroke style) (smooth__width_of width style) (alpha_of alpha style)

let smooth__rect__default__fill () = color__black

let smooth__rect__default__stroke () = color__none

let smooth__rect__default__paint () = Color__Plain color__none

let smooth__rect__default__style () =
  Style (field__default__Style__fill (), field__default__Style__stroke (), 1, 1.0, field__default__Style__paint ())

let smooth__rect c x y w h fill stroke width alpha paint style radius =
  smooth__shape c "rect" (floats4 x y w h ^ " " ^ pyk_float_str radius) fill stroke width alpha paint style

let smooth__ellipse__default__fill () = color__black

let smooth__ellipse__default__stroke () = color__none

let smooth__ellipse__default__paint () = Color__Plain color__none

let smooth__ellipse__default__style () =
  Style (field__default__Style__fill (), field__default__Style__stroke (), 1, 1.0, field__default__Style__paint ())

let smooth__ellipse c x y rx ry fill stroke width alpha paint style =
  smooth__shape c "ellipse" (floats4 x y rx ry) fill stroke width alpha paint style

let smooth__arc__default__fill () = color__black

let smooth__arc__default__stroke () = color__none

let smooth__arc__default__paint () = Color__Plain color__none

let smooth__arc__default__style () =
  Style (field__default__Style__fill (), field__default__Style__stroke (), 1, 1.0, field__default__Style__paint ())

let smooth__arc c x y radius start end_ fill stroke width alpha paint style =
  smooth__shape c "arc" (floats3 x y radius ^ " " ^ floats2 start end_) fill stroke width alpha paint style

let smooth__polygon__default__fill () = color__black

let smooth__polygon__default__stroke () = color__none

let smooth__polygon__default__style () =
  Style (field__default__Style__fill (), field__default__Style__stroke (), 1, 1.0, field__default__Style__paint ())

let smooth__polygon c points fill stroke width alpha style =
  Tinyweb_external.draw_pairs c "polygon" (smooth__pairs points) (fill_of fill (Color__Plain color__none) style) (stroke_of stroke style) (smooth__width_of width style) (alpha_of alpha style)

let smooth__line__default__stroke () = color__black

let smooth__line__default__style () =
  Style (field__default__Style__fill (), field__default__Style__stroke (), 1, 1.0, field__default__Style__paint ())

let smooth__line c x1 y1 x2 y2 stroke width alpha style =
  smooth__stroked c "line" (floats4 x1 y1 x2 y2) stroke width alpha style

let smooth__lines__default__stroke () = color__black

let smooth__lines__default__style () =
  Style (field__default__Style__fill (), field__default__Style__stroke (), 1, 1.0, field__default__Style__paint ())

let smooth__lines c segments stroke width alpha style =
  Tinyweb_external.draw_quads c "lines" (List.concat_map (function | (a, b) -> [((let Smooth__Point (tmp68, _) = a in tmp68), (let Smooth__Point (_, tmp69) = a in tmp69), (let Smooth__Point (tmp70, _) = b in tmp70), (let Smooth__Point (_, tmp71) = b in tmp71))]) segments) "" (line_of stroke style) (smooth__width_of width style) (alpha_of alpha style)

let smooth__path__default__stroke () = color__black

let smooth__path__default__style () =
  Style (field__default__Style__fill (), field__default__Style__stroke (), 1, 1.0, field__default__Style__paint ())

let smooth__path c points stroke width alpha style =
  Tinyweb_external.draw_pairs c "path" (smooth__pairs points) "" (line_of stroke style) (smooth__width_of width style) (alpha_of alpha style)

let smooth__curve__default__stroke () = color__black

let smooth__curve__default__style () =
  Style (field__default__Style__fill (), field__default__Style__stroke (), 1, 1.0, field__default__Style__paint ())

let smooth__curve c x1 y1 cx cy x2 y2 stroke width alpha style =
  smooth__stroked c "curve" (floats2 x1 y1 ^ " " ^ floats4 cx cy x2 y2) stroke width alpha style

let smooth__bezier__default__stroke () = color__black

let smooth__bezier__default__style () =
  Style (field__default__Style__fill (), field__default__Style__stroke (), 1, 1.0, field__default__Style__paint ())

let smooth__bezier c x1 y1 ax ay bx by x2 y2 stroke width alpha style =
  smooth__stroked c "bezier" (floats4 x1 y1 ax ay ^ " " ^ floats4 bx by x2 y2) stroke width alpha style

let smooth__text__default__fill () = color__black

let smooth__text__default__stroke () = color__none

let smooth__text__default__paint () = Color__Plain color__none

let smooth__text__default__style () =
  Style (field__default__Style__fill (), field__default__Style__stroke (), 1, 1.0, field__default__Style__paint ())

let smooth__text c x y words fill size font align bold alpha baseline stroke width paint style =
  Tinyweb_external.draw_text c x y words (fill_of fill paint style) size font align baseline bold (stroke_of stroke style) (smooth__width_of width style) (alpha_of alpha style)

let smooth__clip_circle c x y radius =
  Tinyweb_external.set_state c "clip" "circle" (floats3 x y radius)

let smooth__clip_polygon c points =
  Tinyweb_external.set_state c "clip" "polygon" (float_points_text points)
