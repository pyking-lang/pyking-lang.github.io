(* Generated from lib_tinyweb_timers.pyk by the Pyking compiler. Do not edit. *)
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

let ticks = ref 0

let repeating = ref ""

let tick () =
  ticks := !ticks + 1;
  print_endline ("tick" ^ " " ^ string_of_int !ticks ^ " " ^ pyk_float_str (Tinyweb_external.time ()));
  if !ticks = 3 then Tinyweb.cancel !repeating

let once () =
  let tmp1 = Tinyweb_external.time () in
  let tmp2 = Tinyweb.sound__beat () in
  let tmp3 = Tinyweb.sound__latency () in
  print_endline ("once at" ^ " " ^ pyk_float_str tmp1 ^ " " ^ "beat" ^ " " ^ pyk_float_str tmp2 ^ " " ^ "latency" ^ " " ^ pyk_float_str tmp3 ^ " " ^ "level" ^ " " ^ pyk_float_str (Tinyweb.sound__level ()));
  let tmp4 = Tinyweb.sound__bands () in
  let tmp5 = Tinyweb.sound__band 0 in
  let tmp6 = Tinyweb.sound__band 1 in
  print_endline ("bands" ^ " " ^ string_of_int tmp4 ^ " " ^ pyk_float_str tmp5 ^ " " ^ pyk_float_str tmp6 ^ " " ^ pyk_float_str (Tinyweb.sound__band 9));
  print_endline ("typed" ^ " " ^ Tinyweb.value_of "name")

let () = repeating := Tinyweb.every 0.5 tick

let later = Tinyweb.after 2.0 once

let () = print_endline (!repeating ^ " " ^ later)
