(* Generated from lib_tinyweb_style.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml5.5. Compile with:  ocamlopt <this file>
   or run it directly with:      ocaml <this file> *)

let () =
  Tinyweb.web_init 0;
  Tinyweb.theme "paper";
  Tinyweb.theme "no such theme";
  Tinyweb.page_style "#fdf6e3" "#586e75" "serif" 18 12 16 (Tinyweb.page_style__default__align ());
  Tinyweb.button_style "#268bd2" "white" "none" 14 "monospace" 16 8;
  Tinyweb.label_style "lightyellow" "#333333" "1px solid gold" 4 "sans-serif" 14 6;
  Tinyweb.slider_style "crimson" 240 "crimson" "monospace" 20;
  Tinyweb.canvas_style "3px solid teal" 10

let title = Tinyweb_external.label "Styled"

let () =
  let tmp1 = Tinyweb.set_style__default__accent () in
  let tmp2 = Tinyweb.set_style__default__weight () in
  Tinyweb.set_style title "navy" "white" "2px dashed orange" 0 "Georgia" 28 10 tmp1 300 tmp2 (Tinyweb.set_style__default__height ())

let level =
  Tinyweb.slider 0 10 4 (Tinyweb.slider__default__on_change ())

let () =
  Tinyweb.set_colors level "seagreen" (Tinyweb.set_colors__default__background ())

let c = Tinyweb_external.canvas 120 60

let () =
  let tmp3 = Tinyweb.set_style__default__background () in
  let tmp4 = Tinyweb.set_style__default__color () in
  let tmp5 = Tinyweb.set_style__default__radius () in
  let tmp6 = Tinyweb.set_style__default__font () in
  let tmp7 = Tinyweb.set_style__default__size () in
  let tmp8 = Tinyweb.set_style__default__padding () in
  let tmp9 = Tinyweb.set_style__default__accent () in
  let tmp10 = Tinyweb.set_style__default__width () in
  let tmp11 = Tinyweb.set_style__default__weight () in
  Tinyweb.set_style c tmp3 tmp4 "1px solid black" tmp5 tmp6 tmp7 tmp8 tmp9 tmp10 tmp11 (Tinyweb.set_style__default__height ())

let pressed () =
  Tinyweb.theme "retro";
  Tinyweb.set_colors title (Tinyweb.set_colors__default__color ()) "black";
  print_endline "now retro"

let ok = Tinyweb.button "Retro" pressed

let () = Tinyweb.set_colors ok "black" "gold"
