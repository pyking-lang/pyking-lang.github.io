(* Generated from lib_tinyweb_load_bitmap.pyk by the Pyking compiler. Do not edit. *)
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

let c = Tinyweb_external.canvas 40 40

let show p =
  string_of_int (let Tinyweb.Color__Color (tmp1, _, _, _) = p in tmp1) ^ " " ^ string_of_int (let Tinyweb.Color__Color (_, tmp2, _, _) = p in tmp2) ^ " " ^ string_of_int (let Tinyweb.Color__Color (_, _, tmp3, _) = p in tmp3)

let made =
  Tinyweb.bitmap__bitmap 5 3 (Tinyweb.bitmap__bitmap__default__background ())

let () =
  let tmp4 = Tinyweb.bitmap__size made in
  print_endline ("made:" ^ " " ^ (let (tmp5, tmp6) = tmp4 in
  "(" ^ string_of_int tmp5 ^ ", " ^ string_of_int tmp6 ^ ")") ^ " " ^ "not a bitmap:" ^ " " ^ (let (tmp7, tmp8) = Tinyweb.bitmap__size "nothing" in
  "(" ^ string_of_int tmp7 ^ ", " ^ string_of_int tmp8 ^ ")"))

let loaded b =
  let (w, h) = Tinyweb.bitmap__size b in
  print_endline ("loaded" ^ " " ^ b ^ " " ^ "of" ^ " " ^ string_of_int w ^ " " ^ "by" ^ " " ^ string_of_int h);
  let rec tmp9 _tmp10 tmp18 =
    match tmp18 with
        | [] -> ()
        | y :: tmp11 -> tmp9 (let rec tmp12 _tmp13 tmp17 =
      match tmp17 with
          | [] -> ()
          | x :: tmp14 -> (let tmp16 = show (Tinyweb.bitmap__get_pixel b x y) in
      print_endline (" " ^ " " ^ string_of_int x ^ " " ^ string_of_int y ^ " " ^ tmp16 ^ " " ^ pyk_float_str (let Tinyweb.Color__Color (_, _, _, tmp15) = Tinyweb.bitmap__get_pixel b x y in tmp15));
      tmp12 () tmp14) in
    tmp12 () (Stdlib.List.init (max 0 w) Stdlib.Fun.id)) tmp11 in
  tmp9 () (Stdlib.List.init (max 0 h) Stdlib.Fun.id);
  Tinyweb.bitmap__set_pixel b 1 1 Tinyweb.color__black;
  Tinyweb.bitmap__show_bitmap c b 0 0 10.0

let broken b = print_endline ("never called for" ^ " " ^ b)

let () =
  Tinyweb.bitmap__load_bitmap "pic.png" loaded;
  Tinyweb.bitmap__load_bitmap "broken.png" broken;
  print_endline "asked for both"
