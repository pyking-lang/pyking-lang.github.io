(* Generated from lib_tinyweb_polygons.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml5.5. Compile with:  ocamlopt <this file>
   or run it directly with:      ocaml <this file> *)

let pyk_quote text =
  let out = Buffer.create (String.length text + 2) in
  Buffer.add_char out '\'';
  String.iter
    (fun c ->
      match c with
      | '\\' -> Buffer.add_string out "\\\\"
      | '\'' -> Buffer.add_string out "\\'"
      | '\n' -> Buffer.add_string out "\\n"
      | '\t' -> Buffer.add_string out "\\t"
      | '\r' -> Buffer.add_string out "\\r"
      | c -> Buffer.add_char out c)
    text;
  Buffer.add_char out '\'';
  Buffer.contents out

let () = Tinyweb.web_init 0

let c = Tinyweb_external.canvas 200 200

let ocean = Tinyweb.colors__palette "ocean"

let () =
  print_endline (string_of_int (List.length ocean));
  let tmp1 = Tinyweb.polygon__default__outline_width () in
  Tinyweb.polygon c [(100, 10); (130, 90); (70, 90)] "orange" "black" tmp1 (Tinyweb.polygon__default__alpha ());
  Tinyweb.path c [(10, 190); (60, 120); (110, 170); (190, 110)] "teal" 3 (Tinyweb.path__default__alpha ());
  let tmp2 = Tinyweb.polygon__default__outline () in
  let tmp3 = Tinyweb.polygon__default__outline_width () in
  Tinyweb.polygon c [] "red" tmp2 tmp3 (Tinyweb.polygon__default__alpha ());
  print_endline ("[" ^ String.concat ", " (List.map (function | tmp4 -> pyk_quote tmp4) (Tinyweb.colors__palette "nothing")) ^ "]")
