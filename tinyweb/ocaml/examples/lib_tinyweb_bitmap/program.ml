(* Generated from lib_tinyweb_bitmap.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml5.5. Compile with:  ocamlopt <this file>
   or run it directly with:      ocaml <this file> *)

let pyk_truncate x =
  if Float.is_nan x then 0
  else
    let t = Float.trunc x in
    if t < -2147483648.0 || t > 2147483647.0 then 0 else int_of_float t

let () = Tinyweb.web_init 0

let c = Tinyweb_external.canvas 160 100

let b = Tinyweb_external.bitmap 16 10

let () =
  print_endline ("a new bitmap is black:" ^ " " ^ string_of_int (Tinyweb_external.get_pixel b 3 3));
  let rec tmp1 _tmp2 tmp8 =
    match tmp8 with
        | [] -> ()
        | y :: tmp3 -> tmp1 (let rec tmp4 _tmp5 tmp7 =
      match tmp7 with
          | [] -> ()
          | x :: tmp6 -> (Tinyweb_external.set_pixel b x y (Tinyweb.pixel_color (x * 16) (y * 25) 128);
      tmp4 () tmp6) in
    tmp4 () (List.init (max 0 16) Fun.id)) tmp3 in
  tmp1 () (List.init (max 0 10) Fun.id);
  let tmp9 = Tinyweb.show_bitmap__default__x () in
  Tinyweb.show_bitmap c b tmp9 (Tinyweb.show_bitmap__default__y ()) 10.0

let orange = Tinyweb.pixel_color 255 136 0

let () =
  let tmp10 = Tinyweb.red orange in
  let tmp11 = Tinyweb.green orange in
  print_endline ("orange is" ^ " " ^ string_of_int orange ^ " " ^ string_of_int tmp10 ^ " " ^ string_of_int tmp11 ^ " " ^ string_of_int (Tinyweb.blue orange));
  print_endline ("clamped:" ^ " " ^ string_of_int (Tinyweb.pixel_color 300 (-5) 70));
  Tinyweb_external.set_pixel b 4 2 orange;
  Tinyweb_external.set_pixel b 7 5 orange;
  Tinyweb_external.set_pixel b 40 2 orange;
  let tmp12 = Tinyweb_external.get_pixel b 4 2 in
  print_endline ("pixel (4, 2):" ^ " " ^ string_of_int tmp12 ^ " " ^ "outside:" ^ " " ^ string_of_int (Tinyweb_external.get_pixel b (-1) 0));
  Tinyweb.show_bitmap c b 0 0 10.0;
  Tinyweb.show_bitmap c b 5 5 (Tinyweb.show_bitmap__default__scale ())

let small = Tinyweb_external.bitmap 4 4

let () =
  Tinyweb_external.fill_bitmap small (Tinyweb.pixel_color 0 0 255);
  print_endline ("filled:" ^ " " ^ string_of_int (Tinyweb.blue (Tinyweb_external.get_pixel small 3 3)));
  Tinyweb.show_bitmap c small 120 60 0.5

let frame t =
  Tinyweb_external.set_pixel small 1 1 (Tinyweb.pixel_color (pyk_truncate (t *. 100.0)) 0 0);
  Tinyweb.show_bitmap c small 120 60 2.0

let () = Tinyweb_external.on_frame frame
