(* Generated from lib_tinyweb_smooth.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml5.5. Compile with:  ocamlopt <this file>
   or run it directly with:      ocaml <this file> *)

let pyk_range start stop step =
  if step = 0 then failwith "'range' step must not be zero";
  let rec go n out =
    if (step > 0 && n >= stop) || (step < 0 && n <= stop) then
      List.rev out
    else go (n + step) (n :: out)
  in
  go start []

let () = Tinyweb.web_init 0

let c = Tinyweb_external.canvas 200 120

let () =
  Tinyweb.smooth__polygon c [(100.0, 10.5); (180.5, 90.5); (19.5, 90.5)] "orange" "black" 0.5 (Tinyweb.smooth__polygon__default__alpha ());
  Tinyweb.smooth__path c [(10.0, 110.0); (60.5, 20.5); (110.25, 70.0); (190.0, 10.0)] "teal" 2.5 (Tinyweb.smooth__path__default__alpha ())

let rays =
  List.concat_map (function | i -> [(100.0, 60.0, 100.0 +. 45.0 *. float_of_int (i - i / 3 * 3), 5.0 *. float_of_int i)]) (List.init (max 0 8) Fun.id)

let () =
  Tinyweb.smooth__lines c rays "crimson" 0.8 0.5;
  let tmp1 = Tinyweb.lines__default__width () in
  Tinyweb.lines c (List.concat_map (function | x -> [(x, 0, x, 120)]) (pyk_range 0 200 40)) "#cccccc" tmp1 (Tinyweb.lines__default__alpha ());
  Tinyweb.push c;
  Tinyweb.smooth__clip_polygon c [(100.0, 5.5); (190.5, 115.0); (9.5, 115.0)];
  let tmp2 = Tinyweb.rect__default__outline () in
  let tmp3 = Tinyweb.rect__default__outline_width () in
  Tinyweb.rect c 0 60 200 60 "gold" tmp2 tmp3 0.4 (Tinyweb.rect__default__radius ());
  Tinyweb.pop c;
  Tinyweb.push c;
  Tinyweb.clip_polygon c [(0, 0); (60, 0); (0, 60)];
  let tmp4 = Tinyweb.rect__default__outline () in
  let tmp5 = Tinyweb.rect__default__outline_width () in
  let tmp6 = Tinyweb.rect__default__alpha () in
  Tinyweb.rect c 0 0 60 60 "navy" tmp4 tmp5 tmp6 (Tinyweb.rect__default__radius ());
  Tinyweb.pop c

let many =
  List.concat_map (function | i -> [(float_of_int i, 0.0, float_of_int i +. 0.5, 120.0)]) (List.init (max 0 300) Fun.id)

let () =
  Tinyweb.smooth__lines c many "black" 0.25 0.1;
  print_endline ("drew" ^ " " ^ string_of_int (List.length many) ^ " " ^ "lines in one go")
