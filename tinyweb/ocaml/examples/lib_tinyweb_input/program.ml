(* Generated from lib_tinyweb_input.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml4.14. Compile with:  ocamlopt <this file>
   or run it directly with:      ocaml <this file> *)

let () = Tinyweb.web_init 0

let c = Tinyweb_external.canvas 300 200

let () =
  let tmp1 = Tinyweb.color__hex 15658734 in
  let tmp2 = Tinyweb.rect__default__stroke () in
  let tmp3 = Tinyweb.rect__default__paint () in
  Tinyweb.rect c 0 0 300 200 tmp1 tmp2 1 1.0 tmp3 (Tinyweb.rect__default__style ()) 0;
  let tmp4 = Tinyweb.line__default__stroke () in
  Tinyweb.line c 0 0 300 200 tmp4 1 1.0 (Tinyweb.line__default__style ());
  Tinyweb.line c 0 200 300 0 Tinyweb.color__red 3 1.0 (Tinyweb.line__default__style ());
  let tmp5 = Tinyweb.text__default__fill () in
  let tmp6 = Tinyweb.text__default__stroke () in
  let tmp7 = Tinyweb.text__default__paint () in
  Tinyweb.text c 10 10 "click \"me\"" tmp5 20 "" "left" false 1.0 "top" tmp6 1 tmp7 (Tinyweb.text__default__style ())

let status = Tinyweb_external.label "nothing yet"

let clicked x y =
  Tinyweb.set_text status ("clicked at " ^ string_of_int x ^ ", " ^ string_of_int y);
  let tmp8 = Tinyweb.circle__default__stroke () in
  let tmp9 = Tinyweb.circle__default__paint () in
  Tinyweb.circle c x y 5 Tinyweb.color__blue tmp8 1 1.0 tmp9 (Tinyweb.circle__default__style ())

let pressed key =
  print_endline ("key [" ^ key ^ "]");
  if key = "Enter" then Tinyweb.play_file "snare1.wav"

let moved value =
  Tinyweb.set_text status ("slider at " ^ string_of_int value)

let () =
  Tinyweb.on_click c clicked;
  Tinyweb_external.on_key pressed;
  ignore (Tinyweb.slider 0 10 5 moved);
  ignore (Tinyweb.slider 1 3 2 (Tinyweb.slider__default__on_change ()));
  Tinyweb_external.splash ()
