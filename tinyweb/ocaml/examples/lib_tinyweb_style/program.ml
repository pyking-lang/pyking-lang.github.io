(* Generated from lib_tinyweb_style.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml4.14. Compile with:  ocamlopt <this file>
   or run it directly with:      ocaml <this file> *)

let () =
  Tinyweb.web_init 0;
  Tinyweb.theme "paper";
  Tinyweb.theme "no such theme";
  let tmp1 = Tinyweb.color__hex 16643811 in
  Tinyweb.page_style tmp1 (Tinyweb.color__hex 5795445) "serif" 18 12 16 "";
  Tinyweb.button_style (Tinyweb.color__hex 2526162) Tinyweb.color__white Tinyweb.color__none (-1) 14 "monospace" 16 8;
  let tmp2 = Tinyweb.color__hex 16777184 in
  let tmp3 = Tinyweb.color__hex 3355443 in
  Tinyweb.label_style tmp2 tmp3 (Tinyweb.color__hex 16766720) 1 4 "sans-serif" 14 6;
  let tmp4 = Tinyweb.color__hex 14423100 in
  Tinyweb.slider_style tmp4 240 (Tinyweb.color__hex 14423100) "monospace" 20;
  Tinyweb.canvas_style Tinyweb.color__teal 3 10

let title = Tinyweb_external.label "Styled"

let () =
  Tinyweb.set_style title Tinyweb.color__navy Tinyweb.color__white Tinyweb.color__orange 2 0 "Georgia" 28 10 (Tinyweb.set_style__default__accent ()) 300 (-1) (-1)

let level =
  Tinyweb.slider 0 10 4 (Tinyweb.slider__default__on_change ())

let () =
  let tmp5 = Tinyweb.set_style__default__background () in
  let tmp6 = Tinyweb.color__hex 3050327 in
  let tmp7 = Tinyweb.set_style__default__border () in
  Tinyweb.set_style level tmp5 tmp6 tmp7 (-1) (-1) "" (-1) (-1) (Tinyweb.set_style__default__accent ()) (-1) (-1) (-1)

let c = Tinyweb_external.canvas 120 60

let () =
  let tmp8 = Tinyweb.set_style__default__background () in
  let tmp9 = Tinyweb.set_style__default__foreground () in
  Tinyweb.set_style c tmp8 tmp9 Tinyweb.color__black 1 (-1) "" (-1) (-1) (Tinyweb.set_style__default__accent ()) (-1) (-1) (-1)

let pressed () =
  Tinyweb.theme "retro";
  let tmp10 = Tinyweb.set_style__default__foreground () in
  let tmp11 = Tinyweb.set_style__default__border () in
  Tinyweb.set_style title Tinyweb.color__black tmp10 tmp11 (-1) (-1) "" (-1) (-1) (Tinyweb.set_style__default__accent ()) (-1) (-1) (-1);
  print_endline "now retro"

let ok = Tinyweb.button "Retro" pressed

let () =
  let background__arg = Tinyweb.color__rgba 255 215 0 0.5 in
  let border__arg = Tinyweb.set_style__default__border () in
  let accent__arg = Tinyweb.set_style__default__accent () in
  Tinyweb.set_style ok background__arg Tinyweb.color__black border__arg (-1) (-1) "" (-1) (-1) accent__arg (-1) (-1) (-1)
