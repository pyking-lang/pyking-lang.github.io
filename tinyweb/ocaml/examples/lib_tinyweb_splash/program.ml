(* Generated from lib_tinyweb_splash.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml4.14. Compile with:  ocamlopt <this file>
   or run it directly with:      ocaml <this file> *)

let () =
  Tinyweb.web_init 0;
  Tinyweb_external.set_splash "Click for drums"

let c = Tinyweb_external.canvas 200 100

let () = Tinyweb.clear c (Tinyweb.color__hex 2105376)

let kick = Tinyweb_external.load_sample "kick1.wav"

let () =
  Tinyweb.play kick 0.25 1.0 1.0 0.0 (Tinyweb.play__default__voice ());
  let tmp1 = Tinyweb.color__hex 16763904 in
  let tmp2 = Tinyweb.circle__default__stroke () in
  let tmp3 = Tinyweb.circle__default__paint () in
  Tinyweb.circle c 100 50 30 tmp1 tmp2 1 1.0 tmp3 (Tinyweb.circle__default__style ())

let again () =
  Tinyweb.play kick 0.0 1.0 1.0 0.0 (Tinyweb.play__default__voice ());
  print_endline "kick again"

let () =
  ignore (Tinyweb.button "Again" again);
  print_endline "built the page"; Tinyweb_external.splash ()
