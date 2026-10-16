(* Generated from lib_tinyweb_input.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml5.5. Compile with:  ocamlopt <this file>
   or run it directly with:      ocaml <this file> *)

let () = Tinyweb_external.web_init 0

let c = Tinyweb_external.canvas 300 200

let () =
  Tinyweb.rect c 0 0 300 200 "#eeeeee";
  let tmp1 = Tinyweb.line__default__color () in
  Tinyweb.line c 0 0 300 200 tmp1 (Tinyweb.line__default__width ());
  Tinyweb.line c 0 200 300 0 "red" 3;
  Tinyweb.text c 10 10 "click \"me\"" (Tinyweb.text__default__color ()) 20

let status = Tinyweb_external.label "nothing yet"

let clicked x y =
  Tinyweb_external.set_label status ("clicked at " ^ string_of_int x ^ ", " ^ string_of_int y);
  Tinyweb.circle c x y 5 "blue"

let pressed key =
  print_endline ("key [" ^ key ^ "]");
  if key = "Enter" then Tinyweb.play_file "snare1.wav"

let moved value =
  Tinyweb_external.set_label status ("slider at " ^ string_of_int value)

let () =
  Tinyweb_external.on_mouse c clicked;
  Tinyweb_external.on_key pressed;
  ignore (Tinyweb.slider 0 10 5 moved);
  ignore (Tinyweb.slider 1 3 2 (Tinyweb.slider__default__on_change ()))
