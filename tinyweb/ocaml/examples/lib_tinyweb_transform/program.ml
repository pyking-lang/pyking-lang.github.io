(* Generated from lib_tinyweb_transform.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml4.14. Compile with:  ocamlopt <this file>
   or run it directly with:      ocaml <this file> *)

let () = Tinyweb.web_init 0

let c = Tinyweb_external.canvas 200 200

let draw t =
  Tinyweb.clear c Tinyweb.color__black;
  Tinyweb.push c;
  Tinyweb.translate c 100.0 100.0;
  Tinyweb.rotate c (t *. Math.pi /. 2.0);
  let tmp1 = Tinyweb.color__hex 14423100 in
  let tmp2 = Tinyweb.rect__default__stroke () in
  let tmp3 = Tinyweb.rect__default__paint () in
  Tinyweb.rect c (-20) (-20) 40 40 tmp1 tmp2 1 1.0 tmp3 (Tinyweb.rect__default__style ()) 0;
  Tinyweb.push c;
  Tinyweb.scale c 0.5 2.0;
  let tmp4 = Tinyweb.circle__default__stroke () in
  let tmp5 = Tinyweb.circle__default__paint () in
  Tinyweb.circle c 60 0 10 Tinyweb.color__white tmp4 1 1.0 tmp5 (Tinyweb.circle__default__style ());
  Tinyweb.pop c;
  Tinyweb.pop c;
  Tinyweb.shadow c Tinyweb.color__white 12 0 0;
  let tmp6 = Tinyweb.color__hex 16766720 in
  let tmp7 = Tinyweb.circle__default__stroke () in
  let tmp8 = Tinyweb.circle__default__paint () in
  Tinyweb.circle c 30 30 10 tmp6 tmp7 1 1.0 tmp8 (Tinyweb.circle__default__style ());
  Tinyweb.shadow c Tinyweb.color__none 10 0 0;
  Tinyweb.blend c "add";
  let tmp9 = Tinyweb.color__hex 8388608 in
  let tmp10 = Tinyweb.circle__default__stroke () in
  let tmp11 = Tinyweb.circle__default__paint () in
  Tinyweb.circle c 160 160 20 tmp9 tmp10 1 1.0 tmp11 (Tinyweb.circle__default__style ());
  let tmp12 = Tinyweb.color__hex 128 in
  let tmp13 = Tinyweb.circle__default__stroke () in
  let tmp14 = Tinyweb.circle__default__paint () in
  Tinyweb.circle c 175 160 20 tmp12 tmp13 1 1.0 tmp14 (Tinyweb.circle__default__style ());
  Tinyweb.blend c "normal";
  Tinyweb.blend c "multiply"; Tinyweb.reset c

let () = Tinyweb_external.on_frame draw
