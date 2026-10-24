(* Generated from lib_tinyweb_frames.pyk by the Pyking compiler. Do not edit. *)
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

let c = Tinyweb_external.canvas 200 100

let kick = Tinyweb_external.load_sample "kick1.wav"

let beat = 0.5

let next_beat = ref 0.0

let draw t =
  Tinyweb.clear c (Tinyweb.color__hex 1118481);
  let tmp1 = Tinyweb.color__hex 16763904 in
  let tmp2 = Tinyweb.circle__default__stroke () in
  let tmp3 = Tinyweb.circle__default__paint () in
  Tinyweb.circle c (pyk_truncate (t *. 100.0)) 50 10 tmp1 tmp2 1 1.0 tmp3 (Tinyweb.circle__default__style ());
  if t >= !next_beat then
    (print_endline ("beat scheduled at " ^ pyk_float_str (!next_beat +. beat) ^ ", drawn at " ^ pyk_float_str t);
    Tinyweb.play kick (!next_beat +. beat) 1.0 1.0 0.0 (Tinyweb.play__default__voice ());
    next_beat := !next_beat +. beat)

let () =
  Tinyweb_external.on_frame draw;
  print_endline (pyk_float_str (Tinyweb_external.time ()));
  Tinyweb_external.splash ()
