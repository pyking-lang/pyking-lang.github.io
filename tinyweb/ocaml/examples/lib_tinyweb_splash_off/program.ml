(* Generated from lib_tinyweb_splash_off.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml5.5. Compile with:  ocamlopt <this file>
   or run it directly with:      ocaml <this file> *)

let () = Tinyweb.web_init 0; Tinyweb_external.set_splash ""

let snare = Tinyweb_external.load_sample "snare1.wav"

let hit () =
  let tmp1 = Tinyweb.play__default__at () in
  Tinyweb.play snare tmp1 0.5 (Tinyweb.play__default__rate ());
  print_endline "hit"

let () = ignore (Tinyweb.button "Hit" hit); Tinyweb_external.splash ()
