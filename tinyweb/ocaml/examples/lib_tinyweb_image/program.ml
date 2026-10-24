(* Generated from lib_tinyweb_image.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml4.14. Compile with:  ocamlopt <this file>
   or run it directly with:      ocaml <this file> *)

let pyk_truncate x =
  if Float.is_nan x then 0
  else
    let t = Float.trunc x in
    if t < -2147483648.0 || t > 2147483647.0 then 0 else int_of_float t

let () = Tinyweb.web_init 0

let c = Tinyweb_external.canvas 200 100

let ball = Tinyweb_external.load_image "ball.png"

let star = Tinyweb_external.load_image "star.png"

let again = Tinyweb_external.load_image "ball.png"

let () = print_endline again

let draw t =
  Tinyweb.clear c (Tinyweb.color__hex 2105408);
  Tinyweb.image c ball (pyk_truncate (t *. 100.0)) 20 40 40 1.0;
  Tinyweb.image c star 140 20 50 50 0.5

let () = Tinyweb_external.on_frame draw
