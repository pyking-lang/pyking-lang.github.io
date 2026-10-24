(* Generated from lib_tinyweb_paint.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml4.14. Compile with:  ocamlopt <this file>
   or run it directly with:      ocaml <this file> *)

let pyk_truncate x =
  if Float.is_nan x then 0
  else
    let t = Float.trunc x in
    if t < -2147483648.0 || t > 2147483647.0 then 0 else int_of_float t

let () = Tinyweb.web_init 0

let c = Tinyweb_external.canvas 300 200

let sky =
  let tmp1 = Tinyweb.color__hex 1713022 in
  Tinyweb.Color__Linear (0.0, 0.0, 0.0, 200.0, tmp1, Tinyweb.color__hex 16758605, "")

let () =
  let tmp2 = Tinyweb.rect__default__fill () in
  let tmp3 = Tinyweb.rect__default__stroke () in
  let tmp4 = Tinyweb.color__stop sky 0.6 (Tinyweb.color__hex 15277667) in
  Tinyweb.rect c 0 0 300 200 tmp2 tmp3 1 1.0 tmp4 (Tinyweb.rect__default__style ()) 0

let ball =
  Tinyweb.Color__Radial (40.0, 40.0, 4.0, 50.0, 50.0, 30.0, Tinyweb.color__white, Tinyweb.color__hex 14423100, "")

let () =
  let tmp5 = Tinyweb.circle__default__fill () in
  let tmp6 = Tinyweb.circle__default__stroke () in
  Tinyweb.circle c 50 50 30 tmp5 tmp6 1 1.0 ball (Tinyweb.circle__default__style ())

let wheel =
  Tinyweb.color__stop (Tinyweb.color__stop (Tinyweb.Color__Conic (150.0, 50.0, Math.pi /. 2.0, Tinyweb.color__red, Tinyweb.color__red, "")) 0.33 (Tinyweb.color__hex 65280)) 0.67 Tinyweb.color__blue

let () =
  let fill__arg = Tinyweb.circle__default__fill () in
  let style__arg = Tinyweb.circle__default__style () in
  Tinyweb.circle c 150 50 30 fill__arg Tinyweb.color__white 2 1.0 wheel style__arg;
  Tinyweb.push c;
  Tinyweb.line_style c "butt" "bevel" 8.0 4.0 2.0 0.0 0.0;
  let tmp7 = Tinyweb.rect__default__paint () in
  Tinyweb.rect c 200 20 80 60 Tinyweb.color__none Tinyweb.color__white 3 1.0 tmp7 (Tinyweb.rect__default__style ()) 0;
  Tinyweb.line_style c "round" "round" 3.0 0.0 0.0 0.0 0.0;
  Tinyweb.line c 200 90 280 90 Tinyweb.color__yellow 2 1.0 (Tinyweb.line__default__style ());
  Tinyweb.pop c;
  Tinyweb.push c;
  Tinyweb.clip_rect c 10 100 60 40;
  let tmp8 = Tinyweb.circle__default__stroke () in
  let tmp9 = Tinyweb.circle__default__paint () in
  Tinyweb.circle c 40 120 35 Tinyweb.color__orange tmp8 1 1.0 tmp9 (Tinyweb.circle__default__style ());
  Tinyweb.pop c;
  Tinyweb.push c;
  Tinyweb.clip_circle c 120 130 25;
  let tmp10 = Tinyweb.rect__default__stroke () in
  let tmp11 = Tinyweb.rect__default__paint () in
  Tinyweb.rect c 90 100 60 60 Tinyweb.color__teal tmp10 1 1.0 tmp11 (Tinyweb.rect__default__style ()) 0;
  Tinyweb.pop c;
  Tinyweb.bezier c 160 160 190 100 230 200 260 120 Tinyweb.color__black 3 1.0 (Tinyweb.bezier__default__style ());
  Tinyweb.erase c 270 150 20 20;
  let tmp12 = Tinyweb.text__default__paint () in
  Tinyweb.text c 10 190 "bottom" Tinyweb.color__white 14 "" "left" false 1.0 "bottom" Tinyweb.color__black 3 tmp12 (Tinyweb.text__default__style ());
  let tmp13 = Tinyweb.text__default__stroke () in
  let tmp14 = Tinyweb.text__default__paint () in
  Tinyweb.text c 80 185 "middle" Tinyweb.color__white 14 "" "left" false 1.0 "middle" tmp13 1 tmp14 (Tinyweb.text__default__style ());
  let tmp15 = Tinyweb.text__default__paint () in
  Tinyweb.text c 150 185 "alphabetic" Tinyweb.color__none 14 "" "left" false 1.0 "alphabetic" Tinyweb.color__white 1 tmp15 (Tinyweb.text__default__style ());
  let tmp16 = Tinyweb.color__hex 16766720 in
  let tmp17 = Tinyweb.smooth__circle__default__paint () in
  Tinyweb.smooth__circle c 250.5 130.25 6.5 tmp16 Tinyweb.color__black 0.5 1.0 tmp17 (Tinyweb.smooth__circle__default__style ());
  let tmp18 = Tinyweb.smooth__rect__default__paint () in
  Tinyweb.smooth__rect c 200.5 100.5 30.0 15.0 Tinyweb.color__none Tinyweb.color__white 1.0 1.0 tmp18 (Tinyweb.smooth__rect__default__style ()) 4.0;
  let tmp19 = Tinyweb.color__hex 14524637 in
  let tmp20 = Tinyweb.smooth__ellipse__default__stroke () in
  let tmp21 = Tinyweb.smooth__ellipse__default__paint () in
  Tinyweb.smooth__ellipse c 100.0 180.0 12.5 6.25 tmp19 tmp20 1.0 1.0 tmp21 (Tinyweb.smooth__ellipse__default__style ());
  let tmp22 = Tinyweb.smooth__arc__default__paint () in
  Tinyweb.smooth__arc c 30.0 170.0 10.0 0.0 (1.5 *. Math.pi) Tinyweb.color__none Tinyweb.color__cyan 2.5 1.0 tmp22 (Tinyweb.smooth__arc__default__style ());
  Tinyweb.smooth__line c 0.0 199.5 300.0 198.5 Tinyweb.color__white 0.8 1.0 (Tinyweb.smooth__line__default__style ());
  Tinyweb.smooth__curve c 5.0 5.0 50.0 0.5 95.0 5.0 Tinyweb.color__white 1.5 1.0 (Tinyweb.smooth__curve__default__style ());
  Tinyweb.smooth__bezier c 5.0 95.0 30.0 70.0 70.0 120.0 95.0 95.0 Tinyweb.color__white 1.5 0.5 (Tinyweb.smooth__bezier__default__style ());
  let tmp23 = Tinyweb.smooth__text__default__stroke () in
  let tmp24 = Tinyweb.smooth__text__default__paint () in
  Tinyweb.smooth__text c 150.5 100.25 "smooth" Tinyweb.color__white 12 "" "center" false 1.0 "middle" tmp23 1.0 tmp24 (Tinyweb.smooth__text__default__style ());
  Tinyweb.push c;
  Tinyweb.smooth__clip_circle c 50.5 50.5 20.0;
  let tmp25 = Tinyweb.rect__default__stroke () in
  let tmp26 = Tinyweb.rect__default__paint () in
  Tinyweb.rect c 30 30 20 40 Tinyweb.color__black tmp25 1 0.3 tmp26 (Tinyweb.rect__default__style ()) 0;
  Tinyweb.pop c

let outlined =
  Tinyweb.Style (Tinyweb.color__navy, Tinyweb.color__yellow, 2, 0.8, Tinyweb.field__default__Style__paint ())

let () =
  let tmp27 = Tinyweb.circle__default__fill () in
  let tmp28 = Tinyweb.circle__default__stroke () in
  Tinyweb.circle c 20 20 8 tmp27 tmp28 1 1.0 (Tinyweb.circle__default__paint ()) outlined;
  let tmp29 = Tinyweb.rect__default__stroke () in
  Tinyweb.rect c 40 10 20 20 Tinyweb.color__red tmp29 1 1.0 (Tinyweb.rect__default__paint ()) outlined 0;
  Tinyweb.line c 0 0 30 30 (Tinyweb.line__default__stroke ()) 1 1.0 outlined;
  let tmp31 = Tinyweb.circle__default__fill () in
  let tmp32 = Tinyweb.circle__default__stroke () in
  let tmp33 = Tinyweb.circle__default__paint () in
  Tinyweb.circle c 70 20 8 tmp31 tmp32 1 1.0 tmp33 (let tmp30 = Tinyweb.field__default__Style__fill () in
  Tinyweb.Style (tmp30, Tinyweb.field__default__Style__stroke (), 1, 1.0, ball));
  let tmp34 = Tinyweb.smooth__circle__default__fill () in
  let tmp35 = Tinyweb.smooth__circle__default__stroke () in
  Tinyweb.smooth__circle c 90.0 20.0 8.0 tmp34 tmp35 1.0 1.0 (Tinyweb.smooth__circle__default__paint ()) outlined

let underline width =
  Tinyweb.line c 10 60 (10 + pyk_truncate width) 60 Tinyweb.color__white 2 1.0 (Tinyweb.line__default__style ())

let () = Tinyweb.measure_text "Hello, canvas!" underline 20 "" true
