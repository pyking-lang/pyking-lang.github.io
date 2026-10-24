(* Generated from lib_tinyweb_widgets.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml4.14. Compile with:  ocamlopt <this file>
   or run it directly with:      ocaml <this file> *)

let () = Tinyweb.web_init 0

let shown = Tinyweb_external.label "nothing yet"

let trails on =
  Tinyweb.set_text shown (if on then "trails on" else "trails off")

let mode title = Tinyweb.set_text shown ("mode: " ^ title)

let entered name = Tinyweb.set_text shown ("hello, " ^ name)

let balls n = Tinyweb.set_text shown (string_of_int n ^ " balls")

let box = Tinyweb.checkbox "Trails" false trails

let () =
  ignore (Tinyweb.checkbox "Slow frames" true (Tinyweb.checkbox__default__on_change ()));
  ignore (Tinyweb.radio "mode" "time-based" false mode)

let frame_based = Tinyweb.radio "mode" "frame-based" false mode

let () =
  ignore (Tinyweb.radio "speed" "slow" false (Tinyweb.radio__default__on_pick ()));
  ignore (Tinyweb.radio "speed" "fast" true (Tinyweb.radio__default__on_pick ()));
  ignore (Tinyweb.text_input "your name" entered);
  ignore (Tinyweb.text_input "" (Tinyweb.text_input__default__on_enter ()))

let count = Tinyweb.number_input 1 20 3 balls

let speed =
  Tinyweb.slider 0 10 5 (Tinyweb.slider__default__on_change ())

let () =
  Tinyweb_external.set_checked box true;
  Tinyweb_external.set_checked frame_based true;
  Tinyweb_external.set_value count 5;
  Tinyweb_external.set_value speed 8

let gone = Tinyweb_external.label "going"

let () =
  Tinyweb.hide gone;
  Tinyweb.show gone;
  Tinyweb.disable speed;
  Tinyweb.enable speed; Tinyweb.disable box; Tinyweb.remove gone

let blank = Tinyweb_external.label ""

let () =
  Tinyweb.set_text blank "filled in";
  print_endline (frame_based ^ " " ^ blank)
