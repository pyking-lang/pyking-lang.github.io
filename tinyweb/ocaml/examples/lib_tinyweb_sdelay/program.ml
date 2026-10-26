(* Generated from lib_tinyweb_sdelay.pyk by the Pyking compiler. Do not edit. *)
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

let () = Tinyweb.web_init 0

let c = Tinyweb_external.canvas 200 40

let piano = Tinyweb_external.load_sample "piano_c1.wav"

let round = ref 0

let () =
  let rec tmp1 _tmp2 =
    Tinyweb.play piano 0.0 1.0 1.0 0.0 (Tinyweb.play__default__voice ());
    print_endline ("round" ^ " " ^ string_of_int !round ^ " " ^ "at" ^ " " ^ pyk_float_str (Tinyweb_external.time ()));
    let tmp3 = Tinyweb.circle__default__stroke () in
    let tmp4 = Tinyweb.circle__default__paint () in
    Tinyweb.circle c (10 + 20 * !round) 20 8 Tinyweb.color__orange tmp3 1 1.0 tmp4 (Tinyweb.circle__default__style ());
    round := !round + 1;
    if !round = 8 then ()
    else
      (Tinyweb_external.sdelay (if !round = 4 then 0.5 else 0.25);
      tmp1 ()) in
  tmp1 ();
  Tinyweb_external.splash ()
