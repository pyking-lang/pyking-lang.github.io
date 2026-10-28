(* Generated from text.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml4.14. The module 'text' of the program; compile it
   before the ones that import it. *)

let pyk_char_length s =
  let rec go k n =
    if k >= String.length s then n
    else go (k + Uchar.utf_decode_length (String.get_utf_8_uchar s k)) (n + 1)
  in
  go 0 0

let pyk_char_at s i =
  let rec go k j =
    if i < 0 || k >= String.length s then invalid_arg "index out of range"
    else
      let d = String.get_utf_8_uchar s k in
      if j = i then Uchar.to_int (Uchar.utf_decode_uchar d)
      else go (k + Uchar.utf_decode_length d) (j + 1)
  in
  go 0 0

let pyk_char_of_int n =
  if n >= 0 && n <= 0x10FFFF && not (n >= 0xD800 && n <= 0xDFFF) then n else 0

let pyk_chars s =
  let rec go k out =
    if k >= String.length s then List.rev out
    else
      let d = String.get_utf_8_uchar s k in
      go (k + Uchar.utf_decode_length d) (Uchar.to_int (Uchar.utf_decode_uchar d) :: out)
  in
  go 0 []

let pyk_char_text c =
  let out = Buffer.create 4 in
  Buffer.add_utf_8_uchar out (Uchar.of_int c);
  Buffer.contents out

let within k top = if k < 0 then 0 else if k > top then top else k

let blank c =
  match c with
      | (32 | 9 | 10 | 13) -> true
      | _ -> false

let filled s = if s = "" then false else true

let length s = Text_external.host_length s

let slice s start stop =
  let n = Text_external.host_length s in
  let a = within start n in
  let b = within stop n in
  if b <= a then "" else Text_external.host_slice s a b

let char_at s k =
  if k < 0 then 0
  else if k < pyk_char_length s then pyk_char_at s k
  else 0

let code c = c

let from_code n = pyk_char_of_int n

let chars s = List.concat_map (function | c -> [c]) (pyk_chars s)

let find s part start =
  let n = Text_external.host_length s in
  if start > n then -1
  else if part = "" then within start n
  else Text_external.host_find s part (within start n)

let contains s part = find s part 0 >= 0

let starts_with s prefix =
  slice s 0 (Text_external.host_length prefix) = prefix

let ends_with s suffix =
  let n = Text_external.host_length s in
  let m = Text_external.host_length suffix in
  if m > n then false
  else Text_external.host_slice s (n - m) n = suffix

let upper s = Text_external.host_upper s

let lower s = Text_external.host_lower s

let trim s =
  let n = Text_external.host_length s in
  let first =
    let rec tmp1 i =
      if i < n then
        (if blank (Text_external.host_code s i) then tmp1 (i + 1) else i)
      else i in
    tmp1 0 in
  let last =
    let rec tmp2 j =
      if j > first then
        (if blank (Text_external.host_code s (j - 1)) then tmp2 (j - 1)
        else j)
      else j in
    tmp2 n in
  if last <= first then "" else Text_external.host_slice s first last

let replace s old new_ =
  if old = "" then s else Text_external.host_replace s old new_

let repeat s n =
  let (_, _, out) =
    let rec tmp3 (k, piece, out) =
      if k <= 0 then (k, piece, out)
      else
        (let half = k / 2 in
        let more = if k - half * 2 = 1 then out ^ piece else out in
        tmp3 (half, (if half = 0 then piece else piece ^ piece), more)) in
    tmp3 (n, s, "") in
  out

let split s by =
  if by = "" then [s]
  else
    (let m = Text_external.host_length by in
    let (at, parts) =
      let rec tmp4 (at, parts) =
        let k = Text_external.host_find s by at in
        if k < 0 then (at, parts)
        else tmp4 (k + m, parts @ [Text_external.host_slice s at k]) in
      tmp4 (0, []) in
    parts @ [Text_external.host_slice s at (Text_external.host_length s)])

let words s =
  let spaced =
    Text_external.host_replace (Text_external.host_replace (Text_external.host_replace s "\t" " ") "\n" " ") "\r" " " in
  List.concat_map (function | w -> if filled w then [w] else []) (split spaced " ")

let rec from_chars cs =
  join (List.concat_map (function | c -> [pyk_char_text c]) cs) ""
and join parts between =
  let whole = ref "" in
  let chunk = ref "" in
  let count = ref 0 in
  let chunks = ref 0 in
  let rec tmp5 _tmp6 tmp8 =
    match tmp8 with
        | [] -> ()
        | part :: tmp7 -> (chunk := if !count = 0 then part else !chunk ^ between ^ part;
    count := !count + 1;
    if !count = 128 then
      (whole := if !chunks = 0 then !chunk else !whole ^ between ^ !chunk;
      chunks := !chunks + 1; chunk := ""; count := 0);
    tmp5 () tmp7) in
  tmp5 () parts;
  if !count = 0 then !whole
  else if !chunks = 0 then !chunk
  else !whole ^ between ^ !chunk

let lines s =
  if s = "" then []
  else
    (let unix = Text_external.host_replace s "\r\n" "\n" in
    let ended =
      if ends_with unix "\n" then
        Text_external.host_slice unix 0 (Text_external.host_length unix - 1)
      else unix in
    split ended "\n")
