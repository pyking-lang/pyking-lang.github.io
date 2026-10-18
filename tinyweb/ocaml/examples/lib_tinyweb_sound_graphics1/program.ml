(* Generated from lib_tinyweb_sound_graphics1.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml5.5. Compile with:  ocamlopt <this file>
   or run it directly with:      ocaml <this file> *)

let () = Tinyweb.web_init 0

let kick = Tinyweb_external.load_sample "kick1.wav"

let snare = Tinyweb_external.load_sample "snare1.wav"

let canvas = Tinyweb_external.canvas 400 200

let () =
  let tmp1 = Tinyweb.circle__default__outline () in
  let tmp2 = Tinyweb.circle__default__outline_width () in
  Tinyweb.circle canvas 100 50 30 "#ff0000" tmp1 tmp2 (Tinyweb.circle__default__alpha ());
  let tmp3 = Tinyweb.circle__default__color () in
  let tmp4 = Tinyweb.circle__default__outline () in
  let tmp5 = Tinyweb.circle__default__outline_width () in
  Tinyweb.circle canvas 100 50 20 tmp3 tmp4 tmp5 (Tinyweb.circle__default__alpha ())

let presses = ref 0

let play_kick () =
  let tmp6 = Tinyweb.play__default__at () in
  let tmp7 = Tinyweb.play__default__volume () in
  Tinyweb.play kick tmp6 tmp7 (Tinyweb.play__default__rate ())

let play_sound () =
  presses := !presses + 1;
  print_endline ("snare, press " ^ string_of_int !presses);
  let tmp8 = Tinyweb.play__default__at () in
  Tinyweb.play snare tmp8 0.5 (Tinyweb.play__default__rate ())

let () =
  ignore (Tinyweb.button "Play kick" play_kick);
  ignore (Tinyweb.button "Play snare" play_sound);
  ignore (Tinyweb.button "Does nothing" (Tinyweb.button__default__on_click ()));
  print_endline "built the page"; Tinyweb_external.splash ()
