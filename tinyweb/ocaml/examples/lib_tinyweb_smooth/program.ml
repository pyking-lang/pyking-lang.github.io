(* Generated from lib_tinyweb_smooth.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml4.14. Compile with:  ocamlopt <this file>
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
  Tinyweb.smooth__polygon c [Tinyweb.Smooth__Point (100.0, 10.5); Tinyweb.Smooth__Point (180.5, 90.5); Tinyweb.Smooth__Point (19.5, 90.5)] Tinyweb.color__orange Tinyweb.color__black 0.5 1.0 (Tinyweb.smooth__polygon__default__style ());
  Tinyweb.smooth__path c [Tinyweb.Smooth__Point (10.0, 110.0); Tinyweb.Smooth__Point (60.5, 20.5); Tinyweb.Smooth__Point (110.25, 70.0); Tinyweb.Smooth__Point (190.0, 10.0)] Tinyweb.color__teal 2.5 1.0 (Tinyweb.smooth__path__default__style ())

let rays =
  List.concat_map (function | i -> [(Tinyweb.Smooth__Point (100.0, 60.0), Tinyweb.Smooth__Point (100.0 +. 45.0 *. float_of_int (i - i / 3 * 3), 5.0 *. float_of_int i))]) (List.init (max 0 8) Fun.id)

let () =
  Tinyweb.smooth__lines c rays (Tinyweb.color__hex 14423100) 0.8 0.5 (Tinyweb.smooth__lines__default__style ());
  Tinyweb.lines c (List.concat_map (function | x -> [(Tinyweb.Point (x, 0), Tinyweb.Point (x, 120))]) (pyk_range 0 200 40)) (Tinyweb.color__hex 13421772) 1 1.0 (Tinyweb.lines__default__style ());
  Tinyweb.smooth__circles c [(10.5, 10.5, 3.0); (20.0, 10.0, 2.5)] Tinyweb.color__navy (Tinyweb.smooth__circles__default__stroke ()) 1.0 1.0 (Tinyweb.smooth__circles__default__style ());
  Tinyweb.push c;
  Tinyweb.smooth__clip_polygon c [Tinyweb.Smooth__Point (100.0, 5.5); Tinyweb.Smooth__Point (190.5, 115.0); Tinyweb.Smooth__Point (9.5, 115.0)];
  let tmp1 = Tinyweb.rect__default__stroke () in
  let tmp2 = Tinyweb.rect__default__paint () in
  Tinyweb.rect c 0 60 200 60 (Tinyweb.color__hex 16766720) tmp1 1 0.4 tmp2 (Tinyweb.rect__default__style ()) 0;
  Tinyweb.pop c;
  Tinyweb.push c;
  Tinyweb.clip_polygon c [Tinyweb.Point (0, 0); Tinyweb.Point (60, 0); Tinyweb.Point (0, 60)];
  let tmp3 = Tinyweb.rect__default__stroke () in
  let tmp4 = Tinyweb.rect__default__paint () in
  Tinyweb.rect c 0 0 60 60 Tinyweb.color__navy tmp3 1 1.0 tmp4 (Tinyweb.rect__default__style ()) 0;
  Tinyweb.pop c

let many =
  List.concat_map (function | i -> [(Tinyweb.Smooth__Point (float_of_int i, 0.0), Tinyweb.Smooth__Point (float_of_int i +. 0.5, 120.0))]) (List.init (max 0 300) Fun.id)

let () =
  Tinyweb.smooth__lines c many Tinyweb.color__black 0.25 0.1 (Tinyweb.smooth__lines__default__style ());
  print_endline ("drew" ^ " " ^ string_of_int (List.length many) ^ " " ^ "lines in one go")
