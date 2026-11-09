(* Generated from lib_tinyweb_shapes.pyk by the Pyking compiler. Do not edit. *)
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
        let s = Stdlib.Printf.sprintf "%.*e" p a in
        if p >= 16 || float_of_string s = a then s else shortest (p + 1)
      in
      let s = shortest 0 in
      let at = Stdlib.String.index s 'e' in
      let digits =
        Stdlib.String.concat "" (Stdlib.String.split_on_char '.' (Stdlib.String.sub s 0 at))
      in
      let rec trim n =
        if n > 1 && digits.[n - 1] = '0' then trim (n - 1) else n
      in
      let digits = Stdlib.String.sub digits 0 (trim (Stdlib.String.length digits)) in
      let len = Stdlib.String.length digits in
      let decpt =
        int_of_string (Stdlib.String.sub s (at + 1) (Stdlib.String.length s - at - 1))
        + 1
      in
      let zeros n = Stdlib.String.make (max 0 n) '0' in
      if decpt <= -4 || decpt > 16 then
        let mantissa =
          if len = 1 then digits
          else Stdlib.String.sub digits 0 1 ^ "." ^ Stdlib.String.sub digits 1 (len - 1)
        in
        sign ^ mantissa ^ "e" ^ string_of_int (decpt - 1)
      else if decpt <= 0 then sign ^ "0." ^ zeros (-decpt) ^ digits
      else if decpt >= len then sign ^ digits ^ zeros (decpt - len) ^ ".0"
      else
        sign ^ Stdlib.String.sub digits 0 decpt ^ "."
        ^ Stdlib.String.sub digits decpt (len - decpt)

let () = Tinyweb.web_init 0

let c = Tinyweb_external.canvas 300 200

let () = Tinyweb.clear c (Tinyweb.color__rgb 17 17 17)

let gold = Tinyweb.color__hex 16766720

let () =
  let tmp1 = Tinyweb.circle__default__paint () in
  Tinyweb.circle c 50 50 30 gold Tinyweb.color__white 3 1.0 tmp1 (Tinyweb.circle__default__style ());
  let tmp2 = Tinyweb.color__rgba 0 128 255 0.5 in
  let tmp3 = Tinyweb.circle__default__stroke () in
  let tmp4 = Tinyweb.circle__default__paint () in
  Tinyweb.circle c 80 50 30 tmp2 tmp3 1 1.0 tmp4 (Tinyweb.circle__default__style ());
  let tmp5 = Tinyweb.color__hsl 120.0 100.0 50.0 in
  let tmp6 = Tinyweb.rect__default__paint () in
  Tinyweb.rect c 120 20 60 40 Tinyweb.color__none tmp5 1 1.0 tmp6 (Tinyweb.rect__default__style ()) 8;
  let tmp7 = Tinyweb.color__hex 14315734 in
  let tmp8 = Tinyweb.ellipse__default__stroke () in
  let tmp9 = Tinyweb.ellipse__default__paint () in
  Tinyweb.ellipse c 220 40 50 20 tmp7 tmp8 1 0.75 tmp9 (Tinyweb.ellipse__default__style ());
  let tmp10 = Tinyweb.arc__default__stroke () in
  let tmp11 = Tinyweb.arc__default__paint () in
  Tinyweb.arc c 50 140 40 (Math.pi /. 6.0) (11.0 *. Math.pi /. 6.0) Tinyweb.color__yellow tmp10 1 1.0 tmp11 (Tinyweb.arc__default__style ());
  let tmp12 = Tinyweb.arc__default__paint () in
  Tinyweb.arc c 150 140 40 Math.pi (2.0 *. Math.pi) Tinyweb.color__none Tinyweb.color__red 4 1.0 tmp12 (Tinyweb.arc__default__style ());
  Tinyweb.line c 200 100 290 190 Tinyweb.color__cyan 2 1.0 (Tinyweb.line__default__style ());
  Tinyweb.curve c 200 190 245 60 290 190 Tinyweb.color__white 2 0.5 (Tinyweb.curve__default__style ());
  let tmp13 = Tinyweb.text__default__stroke () in
  let tmp14 = Tinyweb.text__default__paint () in
  Tinyweb.text c 150 180 "Step 1" Tinyweb.color__white 18 "serif" "center" true 1.0 "top" tmp13 1 tmp14 (Tinyweb.text__default__style ())

let show c =
  string_of_int (let Tinyweb.Color__Color (tmp15, _, _, _) = c in tmp15) ^ " " ^ string_of_int (let Tinyweb.Color__Color (_, tmp16, _, _) = c in tmp16) ^ " " ^ string_of_int (let Tinyweb.Color__Color (_, _, tmp17, _) = c in tmp17) ^ " " ^ pyk_float_str (let Tinyweb.Color__Color (_, _, _, tmp18) = c in tmp18)

let () =
  print_endline (show (Tinyweb.color__rgb 255 136 0));
  print_endline (show (Tinyweb.color__rgb (-5) 300 16));
  print_endline (show (Tinyweb.color__hsl 200.0 50.0 25.0));
  let tmp19 = Tinyweb.color__to_hex (Tinyweb.color__hex 16746496) in
  print_endline (string_of_int tmp19 ^ " " ^ string_of_int (Tinyweb.color__to_hex (Tinyweb.color__rgb 1 2 3)));
  let tmp20 =
    Tinyweb.color__same (Tinyweb.color__hex 65535) Tinyweb.color__cyan in
  print_endline (string_of_bool tmp20 ^ " " ^ string_of_bool (Tinyweb.color__same Tinyweb.color__red Tinyweb.color__blue));
  print_endline (show (Tinyweb.color__mix Tinyweb.color__black Tinyweb.color__white 0.5));
  print_endline (show (Tinyweb.color__with_alpha Tinyweb.color__red 0.25));
  let tmp21 = show (Tinyweb.color__rgba 10 20 30 0.5) in
  print_endline (tmp21 ^ " " ^ show Tinyweb.color__none)
