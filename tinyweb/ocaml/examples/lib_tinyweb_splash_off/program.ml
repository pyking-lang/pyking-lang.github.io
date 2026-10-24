(* Generated from lib_tinyweb_splash_off.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml4.14. Compile with:  ocamlopt <this file>
   or run it directly with:      ocaml <this file> *)

let () = Tinyweb.web_init 0; Tinyweb_external.set_splash ""

let snare = Tinyweb_external.load_sample "snare1.wav"

let hit () =
  Tinyweb.play snare 0.0 0.5 1.0 0.0 (Tinyweb.play__default__voice ());
  print_endline "hit"

let () = ignore (Tinyweb.button "Hit" hit); Tinyweb_external.splash ()
