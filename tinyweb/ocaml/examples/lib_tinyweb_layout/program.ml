(* Generated from lib_tinyweb_layout.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml5.5. Compile with:  ocamlopt <this file>
   or run it directly with:      ocaml <this file> *)

let () =
  Tinyweb.web_init (Tinyweb.web_init__default__port ());
  let tmp1 = Tinyweb.page_style__default__background () in
  let tmp2 = Tinyweb.page_style__default__color () in
  let tmp3 = Tinyweb.page_style__default__font () in
  let tmp4 = Tinyweb.page_style__default__size () in
  let tmp5 = Tinyweb.page_style__default__padding () in
  Tinyweb.page_style tmp1 tmp2 tmp3 tmp4 tmp5 (Tinyweb.page_style__default__gap ()) "center"

let title = Tinyweb_external.label "Layout"

let () =
  let tmp6 = Tinyweb.set_style__default__background () in
  let tmp7 = Tinyweb.set_style__default__color () in
  let tmp8 = Tinyweb.set_style__default__border () in
  let tmp9 = Tinyweb.set_style__default__radius () in
  let tmp10 = Tinyweb.set_style__default__font () in
  let tmp11 = Tinyweb.set_style__default__padding () in
  let tmp12 = Tinyweb.set_style__default__accent () in
  let tmp13 = Tinyweb.set_style__default__width () in
  Tinyweb.set_style title tmp6 tmp7 tmp8 tmp9 tmp10 28 tmp11 tmp12 tmp13 700 (Tinyweb.set_style__default__height ())

let buttons = Tinyweb_external.row ()

let () = Tinyweb_external.inside buttons

let clicked () = print_endline "clicked"

let () =
  ignore (Tinyweb.button "one" clicked);
  ignore (Tinyweb.button "two" (Tinyweb.button__default__on_click ()));
  Tinyweb_external.outside ();
  ignore (Tinyweb_external.canvas 100 40)

let controls = Tinyweb_external.row ()

let () =
  Tinyweb_external.inside controls;
  ignore (Tinyweb_external.label "speed");
  ignore (Tinyweb.slider 0 10 5 (Tinyweb.slider__default__on_change ()));
  Tinyweb_external.inside buttons;
  ignore (Tinyweb.button "three" (Tinyweb.button__default__on_click ()));
  Tinyweb_external.outside ()

let figures = Tinyweb_external.row ()

let () = Tinyweb_external.inside figures

let left = Tinyweb_external.column ()

let () = Tinyweb_external.inside left

let small = Tinyweb_external.canvas 50 20

let () =
  let tmp14 = Tinyweb.set_style__default__background () in
  let tmp15 = Tinyweb.set_style__default__color () in
  let tmp16 = Tinyweb.set_style__default__border () in
  let tmp17 = Tinyweb.set_style__default__radius () in
  let tmp18 = Tinyweb.set_style__default__font () in
  let tmp19 = Tinyweb.set_style__default__size () in
  let tmp20 = Tinyweb.set_style__default__padding () in
  let tmp21 = Tinyweb.set_style__default__accent () in
  Tinyweb.set_style small tmp14 tmp15 tmp16 tmp17 tmp18 tmp19 tmp20 tmp21 100 (Tinyweb.set_style__default__weight ()) 40;
  ignore (Tinyweb_external.label "stretched");
  Tinyweb_external.inside figures

let right = Tinyweb_external.column ()

let () =
  Tinyweb_external.inside right;
  ignore (Tinyweb_external.canvas 100 40);
  ignore (Tinyweb_external.label "as it is");
  Tinyweb_external.outside ();
  ignore (Tinyweb_external.label "the end")
