(* Generated from lib_tinyweb_splash.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml5.5. Compile with:  ocamlopt <this file>
   or run it directly with:      ocaml <this file> *)

let () =
  Tinyweb.web_init 0;
  Tinyweb_external.set_splash "Click for drums"

let c = Tinyweb_external.canvas 200 100

let () = Tinyweb.clear c "#202020"

let kick = Tinyweb_external.load_sample "kick1.wav"

let () =
  let tmp1 = Tinyweb.play__default__volume () in
  Tinyweb.play kick 0.25 tmp1 (Tinyweb.play__default__rate ());
  let tmp2 = Tinyweb.circle__default__outline () in
  let tmp3 = Tinyweb.circle__default__outline_width () in
  Tinyweb.circle c 100 50 30 "#ffcc00" tmp2 tmp3 (Tinyweb.circle__default__alpha ())

let again () =
  let tmp4 = Tinyweb.play__default__at () in
  let tmp5 = Tinyweb.play__default__volume () in
  Tinyweb.play kick tmp4 tmp5 (Tinyweb.play__default__rate ());
  print_endline "kick again"

let () =
  ignore (Tinyweb.button "Again" again);
  print_endline "built the page"; Tinyweb_external.splash ()
