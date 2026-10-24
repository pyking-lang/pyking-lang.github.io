(* Generated from lib_tinyweb_files.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml4.14. Compile with:  ocamlopt <this file>
   or run it directly with:      ocaml <this file> *)

let () = Tinyweb.web_init 0

let c = Tinyweb_external.canvas 100 100

let () =
  let tmp1 = Tinyweb.circle__default__stroke () in
  let tmp2 = Tinyweb.circle__default__paint () in
  Tinyweb.circle c 50 50 40 Tinyweb.color__green tmp1 1 1.0 tmp2 (Tinyweb.circle__default__style ());
  Tinyweb.game__cursor c "crosshair";
  Tinyweb.game__cursor c "none";
  Tinyweb.net__save_canvas c "canvas.png";
  Tinyweb.net__save_canvas c "circle.png";
  Tinyweb.net__download "notes.txt" "line one\nline \"two\"";
  print_endline ("before:" ^ " " ^ "[" ^ Tinyweb.net__file_text () ^ "]")

let loaded name =
  print_endline ("loaded" ^ " " ^ name ^ " " ^ "holding" ^ " " ^ Tinyweb.net__file_text ())

let picker = Tinyweb.net__file_button "Open" loaded

let () = print_endline picker
