(* Generated from lib_tinyweb_beat.pyk by the Pyking compiler. Do not edit. *)
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

let hat = Tinyweb_external.load_sample "hihat1.wav"

let () =
  Tinyweb.sound__tempo 120.0;
  Tinyweb.sound__swing 0.2; Tinyweb.sound__listen 8 0.5

let step n time =
  print_endline ("step" ^ " " ^ string_of_int n ^ " " ^ "at" ^ " " ^ pyk_float_str time ^ " " ^ "beat" ^ " " ^ pyk_float_str (Tinyweb.sound__beat ()));
  if n - n / 4 * 4 = 0 then
    Tinyweb.play kick time 1.0 1.0 0.0 (Tinyweb.play__default__voice ());
  Tinyweb.play hat time 0.3 1.0 0.0 (Tinyweb.play__default__voice ());
  if n = 2 then Tinyweb.sound__tempo 90.0

let steps = Tinyweb.sound__on_beat step 2

let () = print_endline steps

let listened () =
  let tmp1 = Tinyweb.sound__level () in
  let tmp2 = Tinyweb.sound__bands () in
  let tmp3 = Tinyweb.sound__band 0 in
  let tmp4 = Tinyweb.sound__band 7 in
  let tmp5 = Tinyweb.sound__wave 0 in
  print_endline ("level" ^ " " ^ pyk_float_str tmp1 ^ " " ^ "bands" ^ " " ^ string_of_int tmp2 ^ " " ^ pyk_float_str tmp3 ^ " " ^ pyk_float_str tmp4 ^ " " ^ "wave" ^ " " ^ pyk_float_str tmp5 ^ " " ^ pyk_float_str (Tinyweb.sound__wave 3))

let () = ignore (Tinyweb.button "Listen" listened)

let toggle on =
  if on then Tinyweb.sound__resume () else Tinyweb.sound__pause ();
  print_endline ("playing" ^ " " ^ string_of_bool on)

let () = ignore (Tinyweb.checkbox "Playing" true toggle)

let song () =
  Tinyweb.play kick 0.0 1.0 1.0 0.0 (Tinyweb.play__default__voice ());
  Tinyweb.play kick 0.5 1.0 1.0 0.0 (Tinyweb.play__default__voice ());
  Tinyweb.sound__tone 220.0 1.0 0.25 "sine" 0.5 0.0 0

let done_ took peak =
  print_endline ("rendered in" ^ " " ^ pyk_float_str took ^ " " ^ "seconds, peak" ^ " " ^ pyk_float_str peak)

let () =
  Tinyweb.sound__render_wav 2.0 song "song.wav" done_;
  Tinyweb.sound__render_wav 1.0 song "tinyweb.wav" (Tinyweb.sound__render_wav__default__on_rendered ());
  print_endline ("latency" ^ " " ^ pyk_float_str (Tinyweb.sound__latency ()));
  Tinyweb_external.splash ()
