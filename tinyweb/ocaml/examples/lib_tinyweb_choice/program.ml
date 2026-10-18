(* Generated from lib_tinyweb_choice.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml5.5. Compile with:  ocamlopt <this file>
   or run it directly with:      ocaml <this file> *)

let () = Tinyweb.web_init 0

let names = ["ocean"; "candy"; "forest"]

let shown = Tinyweb_external.label "ocean"

let changed position =
  Tinyweb_external.set_label shown ("chose " ^ string_of_int position)

let menu =
  Tinyweb.choice names (Tinyweb.choice__default__chosen ()) changed

let () =
  ignore (Tinyweb.choice ["one"] 0 (Tinyweb.choice__default__on_change ()));
  Tinyweb_external.set_value menu 2
