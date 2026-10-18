(* Generated from lib_tinyweb_transform.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml5.5. Compile with:  ocamlopt <this file>
   or run it directly with:      ocaml <this file> *)

let () = Tinyweb.web_init 0

let c = Tinyweb_external.canvas 200 200

let draw t =
  Tinyweb.clear c "black";
  Tinyweb.push c;
  Tinyweb.translate c 100.0 100.0;
  Tinyweb.rotate c (t *. 90.0);
  let tmp1 = Tinyweb.rect__default__outline () in
  let tmp2 = Tinyweb.rect__default__outline_width () in
  let tmp3 = Tinyweb.rect__default__alpha () in
  Tinyweb.rect c (-20) (-20) 40 40 "crimson" tmp1 tmp2 tmp3 (Tinyweb.rect__default__radius ());
  Tinyweb.push c;
  Tinyweb.scale c 0.5 2.0;
  let tmp4 = Tinyweb.circle__default__outline () in
  let tmp5 = Tinyweb.circle__default__outline_width () in
  Tinyweb.circle c 60 0 10 "white" tmp4 tmp5 (Tinyweb.circle__default__alpha ());
  Tinyweb.pop c;
  Tinyweb.pop c;
  let tmp6 = Tinyweb.shadow__default__dx () in
  Tinyweb.shadow c "white" 12 tmp6 (Tinyweb.shadow__default__dy ());
  let tmp7 = Tinyweb.circle__default__outline () in
  let tmp8 = Tinyweb.circle__default__outline_width () in
  Tinyweb.circle c 30 30 10 "gold" tmp7 tmp8 (Tinyweb.circle__default__alpha ());
  let tmp9 = Tinyweb.shadow__default__blur () in
  let tmp10 = Tinyweb.shadow__default__dx () in
  Tinyweb.shadow c "" tmp9 tmp10 (Tinyweb.shadow__default__dy ());
  Tinyweb.blend c "add";
  let tmp11 = Tinyweb.circle__default__outline () in
  let tmp12 = Tinyweb.circle__default__outline_width () in
  Tinyweb.circle c 160 160 20 "#800000" tmp11 tmp12 (Tinyweb.circle__default__alpha ());
  let tmp13 = Tinyweb.circle__default__outline () in
  let tmp14 = Tinyweb.circle__default__outline_width () in
  Tinyweb.circle c 175 160 20 "#000080" tmp13 tmp14 (Tinyweb.circle__default__alpha ());
  Tinyweb.blend c "normal";
  Tinyweb.blend c "multiply"; Tinyweb.reset c

let () = Tinyweb_external.on_frame draw
