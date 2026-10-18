(* Generated from lib_tinyweb_shapes.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml5.5. Compile with:  ocamlopt <this file>
   or run it directly with:      ocaml <this file> *)

let () = Tinyweb.web_init 0

let c = Tinyweb_external.canvas 300 200

let () =
  Tinyweb.clear c (Tinyweb.colors__rgb 17 17 17);
  Tinyweb.circle c 50 50 30 "gold" "white" 3 (Tinyweb.circle__default__alpha ());
  let tmp1 = Tinyweb.circle__default__outline () in
  let tmp2 = Tinyweb.circle__default__outline_width () in
  Tinyweb.circle c 80 50 30 (Tinyweb.colors__rgba 0 128 255 0.5) tmp1 tmp2 (Tinyweb.circle__default__alpha ());
  let tmp3 = Tinyweb.rect__default__outline_width () in
  Tinyweb.rect c 120 20 60 40 "" (Tinyweb.colors__hsl 120 100 50) tmp3 (Tinyweb.rect__default__alpha ()) 8;
  let tmp4 = Tinyweb.ellipse__default__outline () in
  Tinyweb.ellipse c 220 40 50 20 "orchid" tmp4 (Tinyweb.ellipse__default__outline_width ()) 0.75;
  let tmp5 = Tinyweb.arc__default__outline () in
  let tmp6 = Tinyweb.arc__default__outline_width () in
  Tinyweb.arc c 50 140 40 30.0 330.0 "yellow" tmp5 tmp6 (Tinyweb.arc__default__alpha ());
  Tinyweb.arc c 150 140 40 180.0 360.0 "" "red" 4 (Tinyweb.arc__default__alpha ());
  Tinyweb.line c 200 100 290 190 "cyan" 2 (Tinyweb.line__default__alpha ());
  Tinyweb.curve c 200 190 245 60 290 190 "white" 2 0.5;
  let tmp7 = Tinyweb.text__default__alpha () in
  let tmp8 = Tinyweb.text__default__baseline () in
  let tmp9 = Tinyweb.text__default__outline () in
  Tinyweb.text c 150 180 "Step 1" "white" 18 "serif" "center" true tmp7 tmp8 tmp9 (Tinyweb.text__default__outline_width ());
  print_endline (Tinyweb.colors__rgb 255 136 0);
  print_endline (Tinyweb.colors__rgb (-5) 300 16);
  print_endline (Tinyweb.colors__hsl 200 50 25)
