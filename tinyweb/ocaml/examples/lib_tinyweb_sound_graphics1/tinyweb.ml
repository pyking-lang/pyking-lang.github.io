(* Generated from tinyweb.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml5.5. The module 'tinyweb' of the program; compile it
   before the ones that import it. *)

let nothing () = ()

let ignore _value = ()

let clear__default__color () = "#ffffff"

let clear c color = Tinyweb_external.fill_canvas c color

let circle__default__color () = "#000000"

let circle c x y radius color =
  Tinyweb_external.draw_circle c x y radius color

let rect__default__color () = "#000000"

let rect c x y width height color =
  Tinyweb_external.draw_rect c x y width height color

let line__default__color () = "#000000"

let line__default__width () = 1

let line c x1 y1 x2 y2 color width =
  Tinyweb_external.draw_line c x1 y1 x2 y2 color width

let text__default__color () = "#000000"

let text__default__size () = 16

let text c x y words color size =
  Tinyweb_external.draw_text c x y words color size

let button__default__on_click () = nothing

let button title on_click = Tinyweb_external.make_button title on_click

let slider__default__on_change () = ignore

let slider low high value on_change =
  Tinyweb_external.make_slider low high value on_change

let known_theme name =
  match name with
      | "light" -> true
      | "dark" -> true
      | "plain" -> true
      | "paper" -> true
      | "retro" -> true
      | _ -> false

let style_text id kind property value =
  if value = "" then ()
  else Tinyweb_external.apply_style id kind property value

let style_pixels id kind property value =
  if value < 0 then ()
  else
    Tinyweb_external.apply_style id kind property (string_of_int value ^ "px")

let theme name =
  if known_theme name then
    Tinyweb_external.apply_style 0 "theme" "name" name
  else
    prerr_endline ("tinyweb: there is no theme called \"" ^ name ^ "\"; the themes are light, dark, plain, paper and retro")

let page_style__default__background () = ""

let page_style__default__color () = ""

let page_style__default__font () = ""

let page_style__default__size () = -1

let page_style__default__padding () = -1

let page_style__default__gap () = -1

let page_style background color font size padding gap =
  style_text 0 "page" "background" background;
  style_text 0 "page" "color" color;
  style_text 0 "page" "font" font;
  style_pixels 0 "page" "size" size;
  style_pixels 0 "page" "padding" padding;
  style_pixels 0 "page" "gap" gap

let button_style__default__background () = ""

let button_style__default__color () = ""

let button_style__default__border () = ""

let button_style__default__radius () = -1

let button_style__default__font () = ""

let button_style__default__size () = -1

let button_style__default__padding () = -1

let button_style background color border radius font size padding =
  style_text 0 "button" "background" background;
  style_text 0 "button" "color" color;
  style_text 0 "button" "border" border;
  style_pixels 0 "button" "radius" radius;
  style_text 0 "button" "font" font;
  style_pixels 0 "button" "size" size;
  style_pixels 0 "button" "padding" padding

let label_style__default__background () = ""

let label_style__default__color () = ""

let label_style__default__border () = ""

let label_style__default__radius () = -1

let label_style__default__font () = ""

let label_style__default__size () = -1

let label_style__default__padding () = -1

let label_style background color border radius font size padding =
  style_text 0 "label" "background" background;
  style_text 0 "label" "color" color;
  style_text 0 "label" "border" border;
  style_pixels 0 "label" "radius" radius;
  style_text 0 "label" "font" font;
  style_pixels 0 "label" "size" size;
  style_pixels 0 "label" "padding" padding

let slider_style__default__accent () = ""

let slider_style__default__width () = -1

let slider_style__default__color () = ""

let slider_style__default__font () = ""

let slider_style__default__size () = -1

let slider_style accent width color font size =
  style_text 0 "slider" "accent" accent;
  style_pixels 0 "slider" "width" width;
  style_text 0 "slider" "color" color;
  style_text 0 "slider" "font" font;
  style_pixels 0 "slider" "size" size

let canvas_style__default__border () = ""

let canvas_style__default__radius () = -1

let canvas_style border radius =
  style_text 0 "canvas" "border" border;
  style_pixels 0 "canvas" "radius" radius

let set_colors__default__color () = ""

let set_colors__default__background () = ""

let set_colors id color background =
  style_text id "element" "color" color;
  style_text id "element" "accent" color;
  style_text id "element" "background" background

let set_style__default__background () = ""

let set_style__default__color () = ""

let set_style__default__border () = ""

let set_style__default__radius () = -1

let set_style__default__font () = ""

let set_style__default__size () = -1

let set_style__default__padding () = -1

let set_style__default__accent () = ""

let set_style__default__width () = -1

let set_style id background color border radius font size padding accent width =
  style_text id "element" "background" background;
  style_text id "element" "color" color;
  style_text id "element" "border" border;
  style_pixels id "element" "radius" radius;
  style_text id "element" "font" font;
  style_pixels id "element" "size" size;
  style_pixels id "element" "padding" padding;
  style_text id "element" "accent" accent;
  style_pixels id "element" "width" width

let play__default__at () = 0.0

let play__default__volume () = 1.0

let play__default__rate () = 1.0

let play sample at volume rate =
  Tinyweb_external.play_sample sample at volume rate

let play_file name =
  play (Tinyweb_external.load_sample name) (play__default__at ()) (play__default__volume ()) (play__default__rate ())
