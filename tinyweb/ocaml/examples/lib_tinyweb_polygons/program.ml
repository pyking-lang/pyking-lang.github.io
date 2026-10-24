(* Generated from lib_tinyweb_polygons.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml4.14. Compile with:  ocamlopt <this file>
   or run it directly with:      ocaml <this file> *)

let () = Tinyweb.web_init 0

let c = Tinyweb_external.canvas 200 200

let ocean = Tinyweb.color__palette "ocean"

let () =
  print_endline (string_of_int (List.length ocean));
  let tmp1 = Tinyweb.polygon__default__paint () in
  Tinyweb.polygon c [Tinyweb.Point (100, 10); Tinyweb.Point (130, 90); Tinyweb.Point (70, 90)] Tinyweb.color__orange Tinyweb.color__black 1 1.0 tmp1 (Tinyweb.polygon__default__style ());
  Tinyweb.path c [Tinyweb.Point (10, 190); Tinyweb.Point (60, 120); Tinyweb.Point (110, 170); Tinyweb.Point (190, 110)] Tinyweb.color__teal 3 1.0 (Tinyweb.path__default__style ());
  let tmp2 = Tinyweb.polygon__default__stroke () in
  let tmp3 = Tinyweb.polygon__default__paint () in
  Tinyweb.polygon c [] Tinyweb.color__red tmp2 1 1.0 tmp3 (Tinyweb.polygon__default__style ());
  Tinyweb.lines c [(Tinyweb.Point (0, 0), Tinyweb.Point (20, 20)); (Tinyweb.Point (20, 0), Tinyweb.Point (0, 20))] Tinyweb.color__navy 1 1.0 (Tinyweb.lines__default__style ());
  print_endline (string_of_int (List.length (Tinyweb.color__palette "nothing")))
