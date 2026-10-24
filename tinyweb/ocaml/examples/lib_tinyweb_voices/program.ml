(* Generated from lib_tinyweb_voices.pyk by the Pyking compiler. Do not edit. *)
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

let kick = Tinyweb_external.load_sample "kick1.wav"

let piano = Tinyweb_external.load_sample "piano_c1.wav"

let () =
  Tinyweb.sound__master_volume 0.8;
  Tinyweb.sound__channel_style 1 0.7 (-.0.5) 0.4 0.25 0.5 0.0 0.0;
  Tinyweb.sound__channel_style 2 1.0 0.0 0.0 0.3 0.35 0.6 1200.0;
  Tinyweb.sound__channel_style 1 0.9 0.0 0.0 0.3 0.35 0.0 0.0;
  Tinyweb.play kick 0.0 1.0 1.0 0.0 (Tinyweb.play__default__voice ());
  Tinyweb.play kick 0.5 0.5 2.0 1.0 (Tinyweb.play__default__voice ())

let soft = Tinyweb.Sound__Voice (0.25, 1.0, 0.0, 1, false, false)

let () =
  Tinyweb.play kick 0.0 1.0 1.0 0.0 soft;
  Tinyweb.play kick 0.0 0.75 1.0 0.0 soft;
  Tinyweb.play piano 0.0 1.0 1.0 0.0 (Tinyweb.Sound__Voice (1.0, 1.0, 0.0, 2, false, true))

let hum =
  Tinyweb.sound__start piano 0.0 0.3 1.0 0.0 true (Tinyweb.sound__start__default__voice ())

let other =
  Tinyweb.sound__start piano 1.0 1.0 1.0 0.0 false (Tinyweb.Sound__Voice (1.0, 0.5, 0.0, 2, true, false))

let () =
  print_endline (hum ^ " " ^ other);
  Tinyweb.sound__tone 440.0 0.0 0.5 "sine" 0.5 0.0 0;
  Tinyweb.sound__tone (Tinyweb.sound__note "C5") 0.25 0.125 "square" 0.2 0.5 1;
  let tmp1 = Tinyweb.sound__note "A4" in
  let tmp2 = Tinyweb.sound__note "C4" in
  let tmp3 = Tinyweb.sound__note "C#4" in
  let tmp4 = Tinyweb.sound__note "Db4" in
  let tmp5 = Tinyweb.sound__note "H2" in
  print_endline (pyk_float_str tmp1 ^ " " ^ pyk_float_str tmp2 ^ " " ^ pyk_float_str tmp3 ^ " " ^ pyk_float_str tmp4 ^ " " ^ pyk_float_str tmp5 ^ " " ^ pyk_float_str (Tinyweb.sound__note "C"));
  let tmp6 = Tinyweb.sound__rate_of "C5" "C4" in
  let tmp7 = Tinyweb.sound__rate_of "C3" "C4" in
  let tmp8 = Tinyweb.sound__rate_of "G4" "G3" in
  print_endline (pyk_float_str tmp6 ^ " " ^ pyk_float_str tmp7 ^ " " ^ pyk_float_str tmp8 ^ " " ^ pyk_float_str (Tinyweb.sound__rate_of "nothing" "C4"))

let quieter () = Tinyweb.sound__fade hum 0.0 2.0; print_endline "fading"

let stop () =
  Tinyweb.sound__stop other 0.0;
  Tinyweb.sound__stop hum 3.0; print_endline "stopped"

let silence () = Tinyweb.sound__stop_all (); print_endline "silence"

let () =
  ignore (Tinyweb.button "Quieter" quieter);
  ignore (Tinyweb.button "Stop" stop);
  ignore (Tinyweb.button "Silence" silence);
  Tinyweb_external.splash ()
