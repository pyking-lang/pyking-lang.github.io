(* Generated from lib_tinyweb_input.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml5.5. Compile with:  ocamlopt <this file>
   or run it directly with:      ocaml <this file> *)

let () = Tinyweb.web_init 0

let c = Tinyweb_external.canvas 300 200

let () =
  let tmp1 = Tinyweb.rect__default__outline () in
  let tmp2 = Tinyweb.rect__default__outline_width () in
  let tmp3 = Tinyweb.rect__default__alpha () in
  Tinyweb.rect c 0 0 300 200 "#eeeeee" tmp1 tmp2 tmp3 (Tinyweb.rect__default__radius ());
  let tmp4 = Tinyweb.line__default__color () in
  let tmp5 = Tinyweb.line__default__width () in
  Tinyweb.line c 0 0 300 200 tmp4 tmp5 (Tinyweb.line__default__alpha ());
  Tinyweb.line c 0 200 300 0 "red" 3 (Tinyweb.line__default__alpha ());
  let tmp6 = Tinyweb.text__default__color () in
  let tmp7 = Tinyweb.text__default__font () in
  let tmp8 = Tinyweb.text__default__align () in
  let tmp9 = Tinyweb.text__default__bold () in
  let tmp10 = Tinyweb.text__default__alpha () in
  let tmp11 = Tinyweb.text__default__baseline () in
  let tmp12 = Tinyweb.text__default__outline () in
  Tinyweb.text c 10 10 "click \"me\"" tmp6 20 tmp7 tmp8 tmp9 tmp10 tmp11 tmp12 (Tinyweb.text__default__outline_width ())

let status = Tinyweb_external.label "nothing yet"

let clicked x y =
  Tinyweb_external.set_label status ("clicked at " ^ string_of_int x ^ ", " ^ string_of_int y);
  let tmp13 = Tinyweb.circle__default__outline () in
  let tmp14 = Tinyweb.circle__default__outline_width () in
  Tinyweb.circle c x y 5 "blue" tmp13 tmp14 (Tinyweb.circle__default__alpha ())

let pressed key =
  print_endline ("key [" ^ key ^ "]");
  if key = "Enter" then Tinyweb.play_file "snare1.wav"

let moved value =
  Tinyweb_external.set_label status ("slider at " ^ string_of_int value)

let () =
  Tinyweb_external.on_mouse c clicked;
  Tinyweb_external.on_key pressed;
  ignore (Tinyweb.slider 0 10 5 moved);
  ignore (Tinyweb.slider 1 3 2 (Tinyweb.slider__default__on_change ()));
  Tinyweb_external.splash ()
