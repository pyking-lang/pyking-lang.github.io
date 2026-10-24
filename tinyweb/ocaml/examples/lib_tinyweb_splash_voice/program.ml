(* Generated from lib_tinyweb_splash_voice.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml4.14. Compile with:  ocamlopt <this file>
   or run it directly with:      ocaml <this file> *)

let () =
  Tinyweb.web_init 0;
  Tinyweb.sound__tone (Tinyweb.sound__note "A4") 0.0 0.25 "sine" 0.5 0.0 0

let hum () =
  print_endline (let sample__arg = Tinyweb_external.load_sample "piano_c1.wav" in
  let voice__arg = Tinyweb.sound__start__default__voice () in
  Tinyweb.sound__start sample__arg 0.0 0.3 1.0 0.0 true voice__arg)

let () = ignore (Tinyweb.button "Hum" hum); Tinyweb_external.splash ()
