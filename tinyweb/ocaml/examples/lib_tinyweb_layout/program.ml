(* Generated from lib_tinyweb_layout.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml4.14. Compile with:  ocamlopt <this file>
   or run it directly with:      ocaml <this file> *)

let () =
  Tinyweb.web_init 0;
  let tmp1 = Tinyweb.page_style__default__background () in
  Tinyweb.page_style tmp1 (Tinyweb.page_style__default__foreground ()) "" (-1) (-1) (-1) "center"

let title = Tinyweb_external.label "Layout"

let () =
  let tmp2 = Tinyweb.set_style__default__background () in
  let tmp3 = Tinyweb.set_style__default__foreground () in
  let tmp4 = Tinyweb.set_style__default__border () in
  Tinyweb.set_style title tmp2 tmp3 tmp4 (-1) (-1) "" 28 (-1) (Tinyweb.set_style__default__accent ()) (-1) 700 (-1)

let buttons = Tinyweb.layout__row ()

let () = Tinyweb.layout__inside buttons

let clicked () = print_endline "clicked"

let () =
  ignore (Tinyweb.button "one" clicked);
  ignore (Tinyweb.button "two" (Tinyweb.button__default__on_click ()));
  Tinyweb.layout__outside ();
  ignore (Tinyweb_external.canvas 100 40)

let controls = Tinyweb.layout__row ()

let () =
  Tinyweb.layout__inside controls;
  ignore (Tinyweb_external.label "speed");
  ignore (Tinyweb.slider 0 10 5 (Tinyweb.slider__default__on_change ()));
  Tinyweb.layout__inside buttons;
  ignore (Tinyweb.button "three" (Tinyweb.button__default__on_click ()));
  Tinyweb.layout__outside ()

let figures = Tinyweb.layout__row ()

let () = Tinyweb.layout__inside figures

let left = Tinyweb.layout__column ()

let () = Tinyweb.layout__inside left

let small = Tinyweb_external.canvas 50 20

let () =
  let tmp5 = Tinyweb.set_style__default__background () in
  let tmp6 = Tinyweb.set_style__default__foreground () in
  let tmp7 = Tinyweb.set_style__default__border () in
  Tinyweb.set_style small tmp5 tmp6 tmp7 (-1) (-1) "" (-1) (-1) (Tinyweb.set_style__default__accent ()) 100 (-1) 40;
  ignore (Tinyweb_external.label "stretched");
  Tinyweb.layout__inside figures

let right = Tinyweb.layout__column ()

let () =
  Tinyweb.layout__inside right;
  ignore (Tinyweb_external.canvas 100 40);
  ignore (Tinyweb_external.label "as it is");
  Tinyweb.layout__outside ()

let edited words = print_endline ("notes:" ^ " " ^ words)

let notes =
  Tinyweb.layout__text_area "first line\nsecond \"line\"" 3 30 edited

let () =
  ignore (Tinyweb.layout__text_area "" 4 40 (Tinyweb.layout__text_area__default__on_change ()));
  ignore (Tinyweb_external.label "the end");
  print_endline (notes ^ " " ^ Tinyweb.value_of notes)
