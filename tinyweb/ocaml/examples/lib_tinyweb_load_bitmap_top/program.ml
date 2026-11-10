(* Generated from lib_tinyweb_load_bitmap_top.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml4.14. Compile with:  ocamlopt <this file>
   or run it directly with:      ocaml <this file> *)

let () = Tinyweb.web_init 0

let c = Tinyweb_external.canvas 100 100

let loaded b =
  let (w, h) = Tinyweb.bitmap__size b in
  print_endline ("ball.png is" ^ " " ^ string_of_int w ^ " " ^ "by" ^ " " ^ string_of_int h);
  let p = Tinyweb.bitmap__get_pixel b (w / 2) (h / 2) in
  print_endline ("its middle:" ^ " " ^ string_of_int (let Tinyweb.Color__Color (tmp1, _, _, _) = p in tmp1) ^ " " ^ string_of_int (let Tinyweb.Color__Color (_, tmp2, _, _) = p in tmp2) ^ " " ^ string_of_int (let Tinyweb.Color__Color (_, _, tmp3, _) = p in tmp3));
  Tinyweb.bitmap__show_bitmap c b 10 10 1.0

let () =
  Tinyweb.bitmap__load_bitmap "ball.png" loaded;
  Tinyweb.bitmap__load_bitmap "no_such_picture.png" loaded;
  print_endline "asked for two pictures"
