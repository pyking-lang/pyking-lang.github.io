(* Generated from lib_tinyweb_pointer.pyk by the Pyking compiler. Do not edit. *)
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

let c = Tinyweb_external.canvas 200 100

let other = Tinyweb_external.canvas 50 50

let () = Tinyweb.track_mouse c

let pressed x y =
  print_endline ("press at" ^ " " ^ string_of_int x ^ " " ^ string_of_int y ^ " " ^ "down" ^ " " ^ string_of_bool (let Tinyweb.Pointer (_, _, tmp1) = Tinyweb.mouse c in tmp1));
  let tmp2 = Tinyweb.color__hex 14423100 in
  let tmp3 = Tinyweb.circle__default__stroke () in
  let tmp4 = Tinyweb.circle__default__paint () in
  Tinyweb.circle c x y 4 tmp2 tmp3 1 1.0 tmp4 (Tinyweb.circle__default__style ())

let dragged x y =
  print_endline ("drag to" ^ " " ^ string_of_int x ^ " " ^ string_of_int y ^ " " ^ "down" ^ " " ^ string_of_bool (let Tinyweb.Pointer (_, _, tmp5) = Tinyweb.mouse c in tmp5));
  Tinyweb.line c 0 0 x y Tinyweb.color__black 2 1.0 (Tinyweb.line__default__style ())

let moved x y =
  print_endline ("move to" ^ " " ^ string_of_int x ^ " " ^ string_of_int y ^ " " ^ "down" ^ " " ^ string_of_bool (let Tinyweb.Pointer (_, _, tmp6) = Tinyweb.mouse c in tmp6))

let released x y =
  print_endline ("release at" ^ " " ^ string_of_int x ^ " " ^ string_of_int y ^ " " ^ "down" ^ " " ^ string_of_bool (let Tinyweb.Pointer (_, _, tmp7) = Tinyweb.mouse c in tmp7))

let nothing _x _y = ()

let () =
  Tinyweb.on_press c pressed;
  Tinyweb.on_drag c dragged;
  Tinyweb.on_move c moved;
  Tinyweb.on_release c released; Tinyweb.on_move other nothing

let start = Tinyweb.mouse c

let () =
  print_endline ("before any event" ^ " " ^ string_of_int (let Tinyweb.Pointer (tmp8, _, _) = start in tmp8) ^ " " ^ string_of_int (let Tinyweb.Pointer (_, tmp9, _) = start in tmp9) ^ " " ^ string_of_bool (let Tinyweb.Pointer (_, _, tmp10) = start in tmp10))

let let_go key =
  print_endline ("let go of" ^ " " ^ key ^ " " ^ "still held:" ^ " " ^ string_of_bool (Tinyweb_external.key_down key))

let () = Tinyweb_external.on_key_up let_go

let frame t =
  let left = Tinyweb_external.key_down "ArrowLeft" in
  let right = Tinyweb_external.key_down "ArrowRight" in
  print_endline ("frame" ^ " " ^ pyk_float_str t ^ " " ^ "left" ^ " " ^ string_of_bool left ^ " " ^ "right" ^ " " ^ string_of_bool right)

let () = Tinyweb_external.on_frame frame
