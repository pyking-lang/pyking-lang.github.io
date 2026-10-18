(* Generated from lib_tinyweb_widgets.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml5.5. Compile with:  ocamlopt <this file>
   or run it directly with:      ocaml <this file> *)

let () = Tinyweb.web_init 0

let shown = Tinyweb_external.label "nothing yet"

let trails on =
  Tinyweb_external.set_label shown (if on then "trails on" else "trails off")

let mode title = Tinyweb_external.set_label shown ("mode: " ^ title)

let entered name = Tinyweb_external.set_label shown ("hello, " ^ name)

let balls n =
  Tinyweb_external.set_label shown (string_of_int n ^ " balls")

let box =
  Tinyweb.checkbox "Trails" (Tinyweb.checkbox__default__checked ()) trails

let () =
  ignore (Tinyweb.checkbox "Slow frames" true (Tinyweb.checkbox__default__on_change ()));
  ignore (Tinyweb.radio "mode" "time-based" (Tinyweb.radio__default__chosen ()) mode)

let frame_based =
  Tinyweb.radio "mode" "frame-based" (Tinyweb.radio__default__chosen ()) mode

let () =
  ignore (let tmp1 = Tinyweb.radio__default__chosen () in
  Tinyweb.radio "speed" "slow" tmp1 (Tinyweb.radio__default__on_pick ()));
  ignore (Tinyweb.radio "speed" "fast" true (Tinyweb.radio__default__on_pick ()));
  ignore (Tinyweb.text_input "your name" entered);
  ignore (let tmp2 = Tinyweb.text_input__default__placeholder () in
  Tinyweb.text_input tmp2 (Tinyweb.text_input__default__on_enter ()))

let count = Tinyweb.number_input 1 20 3 balls

let speed =
  Tinyweb.slider 0 10 5 (Tinyweb.slider__default__on_change ())

let () =
  Tinyweb_external.set_checked box true;
  Tinyweb_external.set_checked frame_based true;
  Tinyweb_external.set_value count 5;
  Tinyweb_external.set_value speed 8; print_endline frame_based
