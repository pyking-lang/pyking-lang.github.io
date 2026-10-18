(* Generated from lib_tinyweb_paint.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml5.5. Compile with:  ocamlopt <this file>
   or run it directly with:      ocaml <this file> *)

let pyk_truncate x =
  if Float.is_nan x then 0
  else
    let t = Float.trunc x in
    if t < -2147483648.0 || t > 2147483647.0 then 0 else int_of_float t

let () = Tinyweb.web_init 0

let c = Tinyweb_external.canvas 300 200

let sky =
  Tinyweb.colors__linear_gradient 0.0 0.0 0.0 200.0 "#1a237e" "#ffb74d"

let sky2 = Tinyweb.colors__stop sky 0.6 "#e91e63"

let () = Tinyweb.clear c sky2

let ball =
  Tinyweb.colors__radial_gradient 40.0 40.0 4.0 50.0 50.0 30.0 "white" "crimson"

let () =
  let tmp1 = Tinyweb.circle__default__outline () in
  let tmp2 = Tinyweb.circle__default__outline_width () in
  Tinyweb.circle c 50 50 30 ball tmp1 tmp2 (Tinyweb.circle__default__alpha ())

let wheel =
  Tinyweb.colors__stop (Tinyweb.colors__stop (Tinyweb.colors__conic_gradient 150.0 50.0 90.0 "red" "red") 0.33 "lime") 0.67 "blue"

let () =
  Tinyweb.circle c 150 50 30 wheel "white" 2 (Tinyweb.circle__default__alpha ());
  Tinyweb.push c;
  let tmp3 = Tinyweb.line_style__default__dash2 () in
  Tinyweb.line_style c "butt" "bevel" 8.0 4.0 2.0 tmp3 (Tinyweb.line_style__default__gap2 ());
  let tmp4 = Tinyweb.rect__default__alpha () in
  Tinyweb.rect c 200 20 80 60 "" "white" 3 tmp4 (Tinyweb.rect__default__radius ());
  let tmp5 = Tinyweb.line_style__default__cap () in
  let tmp6 = Tinyweb.line_style__default__join () in
  let tmp7 = Tinyweb.line_style__default__gap () in
  let tmp8 = Tinyweb.line_style__default__offset () in
  let tmp9 = Tinyweb.line_style__default__dash2 () in
  Tinyweb.line_style c tmp5 tmp6 3.0 tmp7 tmp8 tmp9 (Tinyweb.line_style__default__gap2 ());
  Tinyweb.line c 200 90 280 90 "yellow" 2 (Tinyweb.line__default__alpha ());
  Tinyweb.pop c;
  Tinyweb.push c;
  Tinyweb.clip_rect c 10 100 60 40;
  let tmp10 = Tinyweb.circle__default__outline () in
  let tmp11 = Tinyweb.circle__default__outline_width () in
  Tinyweb.circle c 40 120 35 "orange" tmp10 tmp11 (Tinyweb.circle__default__alpha ());
  Tinyweb.pop c;
  Tinyweb.push c;
  Tinyweb.clip_circle c 120 130 25;
  let tmp12 = Tinyweb.rect__default__outline () in
  let tmp13 = Tinyweb.rect__default__outline_width () in
  let tmp14 = Tinyweb.rect__default__alpha () in
  Tinyweb.rect c 90 100 60 60 "teal" tmp12 tmp13 tmp14 (Tinyweb.rect__default__radius ());
  Tinyweb.pop c;
  Tinyweb.bezier c 160 160 190 100 230 200 260 120 "black" 3 (Tinyweb.bezier__default__alpha ());
  Tinyweb.erase c 270 150 20 20;
  let tmp15 = Tinyweb.text__default__font () in
  let tmp16 = Tinyweb.text__default__align () in
  let tmp17 = Tinyweb.text__default__bold () in
  Tinyweb.text c 10 190 "bottom" "white" 14 tmp15 tmp16 tmp17 (Tinyweb.text__default__alpha ()) "bottom" "black" 3;
  let tmp18 = Tinyweb.text__default__font () in
  let tmp19 = Tinyweb.text__default__align () in
  let tmp20 = Tinyweb.text__default__bold () in
  let tmp21 = Tinyweb.text__default__alpha () in
  let tmp22 = Tinyweb.text__default__outline () in
  Tinyweb.text c 80 185 "middle" "white" 14 tmp18 tmp19 tmp20 tmp21 "middle" tmp22 (Tinyweb.text__default__outline_width ());
  let tmp23 = Tinyweb.text__default__font () in
  let tmp24 = Tinyweb.text__default__align () in
  let tmp25 = Tinyweb.text__default__bold () in
  let tmp26 = Tinyweb.text__default__alpha () in
  Tinyweb.text c 150 185 "alphabetic" "" 14 tmp23 tmp24 tmp25 tmp26 "alphabetic" "white" (Tinyweb.text__default__outline_width ());
  Tinyweb.smooth__circle c 250.5 130.25 6.5 "gold" "black" 0.5 (Tinyweb.smooth__circle__default__alpha ());
  let tmp27 = Tinyweb.smooth__rect__default__outline_width () in
  Tinyweb.smooth__rect c 200.5 100.5 30.0 15.0 "" "white" tmp27 (Tinyweb.smooth__rect__default__alpha ()) 4.0;
  let tmp28 = Tinyweb.smooth__ellipse__default__outline () in
  let tmp29 = Tinyweb.smooth__ellipse__default__outline_width () in
  Tinyweb.smooth__ellipse c 100.0 180.0 12.5 6.25 "plum" tmp28 tmp29 (Tinyweb.smooth__ellipse__default__alpha ());
  Tinyweb.smooth__arc c 30.0 170.0 10.0 0.0 270.0 "" "cyan" 2.5 (Tinyweb.smooth__arc__default__alpha ());
  Tinyweb.smooth__line c 0.0 199.5 300.0 198.5 "white" 0.8 (Tinyweb.smooth__line__default__alpha ());
  Tinyweb.smooth__curve c 5.0 5.0 50.0 0.5 95.0 5.0 "white" 1.5 (Tinyweb.smooth__curve__default__alpha ());
  Tinyweb.smooth__bezier c 5.0 95.0 30.0 70.0 70.0 120.0 95.0 95.0 "white" 1.5 0.5;
  let tmp30 = Tinyweb.smooth__text__default__font () in
  let tmp31 = Tinyweb.smooth__text__default__bold () in
  let tmp32 = Tinyweb.smooth__text__default__alpha () in
  let tmp33 = Tinyweb.smooth__text__default__outline () in
  Tinyweb.smooth__text c 150.5 100.25 "smooth" "white" 12 tmp30 "center" tmp31 tmp32 "middle" tmp33 (Tinyweb.smooth__text__default__outline_width ());
  Tinyweb.push c;
  Tinyweb.smooth__clip_circle c 50.5 50.5 20.0;
  let tmp34 = Tinyweb.rect__default__outline () in
  let tmp35 = Tinyweb.rect__default__outline_width () in
  Tinyweb.rect c 30 30 20 40 "black" tmp34 tmp35 0.3 (Tinyweb.rect__default__radius ());
  Tinyweb.pop c

let underline width =
  Tinyweb.line c 10 60 (10 + pyk_truncate width) 60 "white" 2 (Tinyweb.line__default__alpha ())

let () =
  Tinyweb.measure_text "Hello, canvas!" underline 20 (Tinyweb.measure_text__default__font ()) true
