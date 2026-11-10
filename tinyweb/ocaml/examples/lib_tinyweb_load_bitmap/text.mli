(* Generated from text.pyk by the Pyking compiler. Do not edit. *)
(* What the module 'text' exports; everything else in
   the file beside this one is private to it. *)

val length : string -> int

val slice : string -> int -> int -> string

val char_at : string -> int -> int

val code : int -> int

val from_code : int -> int

val chars : string -> int list

val from_chars : int list -> string

val find : string -> string -> int -> int

val contains : string -> string -> bool

val starts_with : string -> string -> bool

val ends_with : string -> string -> bool

val upper : string -> string

val lower : string -> string

val trim : string -> string

val replace : string -> string -> string -> string

val repeat : string -> int -> string

val split : string -> string -> string list

val words : string -> string list

val join : string list -> string -> string

val lines : string -> string list
