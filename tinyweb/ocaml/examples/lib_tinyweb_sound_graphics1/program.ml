(* Generated from lib_tinyweb_sound_graphics1.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml4.14. Compile with:  ocamlopt <this file>
   or run it directly with:      ocaml <this file> *)

let () = Tinyweb.web_init 0

let kick = Tinyweb_external.load_sample "kick1.wav"

let snare = Tinyweb_external.load_sample "snare1.wav"

let canvas = Tinyweb_external.canvas 400 200

let () =
  let tmp1 = Tinyweb.circle__default__stroke () in
  let tmp2 = Tinyweb.circle__default__paint () in
  Tinyweb.circle canvas 100 50 30 Tinyweb.color__red tmp1 1 1.0 tmp2 (Tinyweb.circle__default__style ());
  let tmp3 = Tinyweb.circle__default__fill () in
  let tmp4 = Tinyweb.circle__default__stroke () in
  let tmp5 = Tinyweb.circle__default__paint () in
  Tinyweb.circle canvas 100 50 20 tmp3 tmp4 1 1.0 tmp5 (Tinyweb.circle__default__style ())

let presses = ref 0

let play_kick () =
  Tinyweb.play kick 0.0 1.0 1.0 0.0 (Tinyweb.play__default__voice ())

let play_sound () =
  presses := !presses + 1;
  print_endline ("snare, press " ^ string_of_int !presses);
  Tinyweb.play snare 0.0 0.5 1.0 0.0 (Tinyweb.play__default__voice ())

let () =
  ignore (Tinyweb.button "Play kick" play_kick);
  ignore (Tinyweb.button "Play snare" play_sound);
  ignore (Tinyweb.button "Does nothing" (Tinyweb.button__default__on_click ()));
  print_endline "built the page"; Tinyweb_external.splash ()
