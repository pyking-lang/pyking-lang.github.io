(* Generated from lib_tinyweb_pointer.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml5.5. Compile with:  ocamlopt <this file>
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

let pressed x y =
  print_endline ("press at" ^ " " ^ string_of_int x ^ " " ^ string_of_int y ^ " " ^ "down" ^ " " ^ string_of_bool (Tinyweb.mouse_down c));
  let tmp1 = Tinyweb.circle__default__outline () in
  let tmp2 = Tinyweb.circle__default__outline_width () in
  Tinyweb.circle c x y 4 "crimson" tmp1 tmp2 (Tinyweb.circle__default__alpha ())

let dragged x y =
  print_endline ("drag to" ^ " " ^ string_of_int x ^ " " ^ string_of_int y);
  let tmp3 = Tinyweb.mouse_x c in
  let tmp4 = Tinyweb.mouse_y c in
  Tinyweb.line c tmp3 tmp4 x y "black" 2 (Tinyweb.line__default__alpha ())

let moved x y =
  print_endline ("move to" ^ " " ^ string_of_int x ^ " " ^ string_of_int y ^ " " ^ "down" ^ " " ^ string_of_bool (Tinyweb.mouse_down c))

let released x y =
  print_endline ("release at" ^ " " ^ string_of_int x ^ " " ^ string_of_int y ^ " " ^ "down" ^ " " ^ string_of_bool (Tinyweb.mouse_down c))

let () =
  Tinyweb.on_press c pressed;
  Tinyweb.on_drag c dragged;
  Tinyweb.on_move c moved;
  Tinyweb.on_release c released;
  Tinyweb.on_move other Tinyweb.ignore2;
  let tmp5 = Tinyweb.mouse_x c in
  let tmp6 = Tinyweb.mouse_y c in
  print_endline ("before any event" ^ " " ^ string_of_int tmp5 ^ " " ^ string_of_int tmp6 ^ " " ^ string_of_bool (Tinyweb.mouse_down c))

let let_go key =
  print_endline ("let go of" ^ " " ^ key ^ " " ^ "still held:" ^ " " ^ string_of_bool (Tinyweb_external.key_down key))

let () = Tinyweb_external.on_key_up let_go

let frame t =
  let left = Tinyweb_external.key_down "ArrowLeft" in
  let right = Tinyweb_external.key_down "ArrowRight" in
  print_endline ("frame" ^ " " ^ pyk_float_str t ^ " " ^ "left" ^ " " ^ string_of_bool left ^ " " ^ "right" ^ " " ^ string_of_bool right)

let () = Tinyweb_external.on_frame frame
