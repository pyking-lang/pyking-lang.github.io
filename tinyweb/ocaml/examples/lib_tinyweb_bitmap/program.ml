(* Generated from lib_tinyweb_bitmap.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml4.14. Compile with:  ocamlopt <this file>
   or run it directly with:      ocaml <this file> *)

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

let () = Tinyweb.web_init 0

let c = Tinyweb_external.canvas 160 100

let show p =
  string_of_int (let Tinyweb.Color__Color (tmp1, _, _, _) = p in tmp1) ^ " " ^ string_of_int (let Tinyweb.Color__Color (_, tmp2, _, _) = p in tmp2) ^ " " ^ string_of_int (let Tinyweb.Color__Color (_, _, tmp3, _) = p in tmp3)

let b =
  Tinyweb.bitmap__bitmap 16 10 (Tinyweb.bitmap__bitmap__default__background ())

let () =
  print_endline ("a new bitmap is white:" ^ " " ^ show (Tinyweb.bitmap__get_pixel b 3 3));
  print_endline ("or its background:" ^ " " ^ show (Tinyweb.bitmap__get_pixel (Tinyweb.bitmap__bitmap 2 2 Tinyweb.color__green) 1 1));
  let rec tmp4 _tmp5 tmp11 =
    match tmp11 with
        | [] -> ()
        | y :: tmp6 -> tmp4 (let rec tmp7 _tmp8 tmp10 =
      match tmp10 with
          | [] -> ()
          | x :: tmp9 -> (Tinyweb.bitmap__set_pixel b x y (Tinyweb.color__rgb (x * 16) (y * 25) 128);
      tmp7 () tmp9) in
    tmp7 () (List.init (max 0 16) Fun.id)) tmp6 in
  tmp4 () (List.init (max 0 10) Fun.id);
  Tinyweb.bitmap__show_bitmap c b 0 0 10.0

let orange = Tinyweb.color__rgb 255 136 0

let () =
  Tinyweb.bitmap__set_pixel b 4 2 orange;
  Tinyweb.bitmap__set_pixel b 7 5 orange;
  Tinyweb.bitmap__set_pixel b 40 2 orange;
  print_endline ("pixel (4, 2):" ^ " " ^ show (Tinyweb.bitmap__get_pixel b 4 2) ^ " " ^ "outside:" ^ " " ^ show (Tinyweb.bitmap__get_pixel b (-1) 0) ^ " " ^ pyk_float_str (let Tinyweb.Color__Color (_, _, _, tmp12) = Tinyweb.bitmap__get_pixel b (-1) 0 in tmp12));
  Tinyweb.bitmap__show_bitmap c b 0 0 10.0;
  Tinyweb.bitmap__show_bitmap c b 5 5 1.0

let small =
  Tinyweb.bitmap__bitmap 4 4 (Tinyweb.bitmap__bitmap__default__background ())

let () =
  Tinyweb.bitmap__fill_bitmap small Tinyweb.color__blue;
  print_endline ("filled:" ^ " " ^ string_of_int (let Tinyweb.Color__Color (_, _, tmp13, _) = Tinyweb.bitmap__get_pixel small 3 3 in tmp13))

let frame t =
  Tinyweb.bitmap__set_pixel small 1 1 (Tinyweb.color__rgb (pyk_truncate (t *. 100.0)) 0 0);
  Tinyweb.bitmap__show_bitmap c small 120 60 2.0

let () =
  Tinyweb.bitmap__show_bitmap c small 120 60 0.5;
  Tinyweb_external.on_frame frame
