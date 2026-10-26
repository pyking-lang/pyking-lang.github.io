(* Generated from lib_tinyweb_image_top.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml4.14. Compile with:  ocamlopt <this file>
   or run it directly with:      ocaml <this file> *)

let () = Tinyweb.web_init 0

let c = Tinyweb_external.canvas 200 100

let tile = Tinyweb_external.load_image "tile.png"

let star = Tinyweb_external.load_image "star.png"

let missing = Tinyweb_external.load_image "no_such_picture.png"

let () =
  Tinyweb.image c tile 0 0 200 100 1.0;
  let tmp1 = Tinyweb.rect__default__stroke () in
  let tmp2 = Tinyweb.rect__default__paint () in
  Tinyweb.rect c 20 20 60 30 (Tinyweb.color__hex 2113664) tmp1 1 1.0 tmp2 (Tinyweb.rect__default__style ()) 0;
  Tinyweb.image c star 100 10 50 50 0.5;
  Tinyweb.image c missing 10 60 30 30 1.0;
  let tmp3 = Tinyweb.circle__default__stroke () in
  let tmp4 = Tinyweb.circle__default__paint () in
  Tinyweb.circle c 170 70 15 (Tinyweb.color__hex 12595248) tmp3 1 1.0 tmp4 (Tinyweb.circle__default__style ());
  print_endline "drawn"
