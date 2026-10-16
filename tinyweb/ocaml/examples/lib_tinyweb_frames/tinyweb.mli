(* Generated from tinyweb.pyk by the Pyking compiler. Do not edit. *)
(* What the module 'tinyweb' exports; everything else in
   the file beside this one is private to it. *)

val clear__default__color : unit -> string

val clear : int -> string -> unit

val circle__default__color : unit -> string

val circle : int -> int -> int -> int -> string -> unit

val rect__default__color : unit -> string

val rect : int -> int -> int -> int -> int -> string -> unit

val line__default__color : unit -> string

val line__default__width : unit -> int

val line : int -> int -> int -> int -> int -> string -> int -> unit

val text__default__color : unit -> string

val text__default__size : unit -> int

val text : int -> int -> int -> string -> string -> int -> unit

val button__default__on_click : unit -> unit -> unit

val button : string -> (unit -> unit) -> int

val slider__default__on_change : unit -> int -> unit

val slider : int -> int -> int -> (int -> unit) -> int

val theme : string -> unit

val page_style__default__background : unit -> string

val page_style__default__color : unit -> string

val page_style__default__font : unit -> string

val page_style__default__size : unit -> int

val page_style__default__padding : unit -> int

val page_style__default__gap : unit -> int

val page_style : string -> string -> string -> int -> int -> int -> unit

val button_style__default__background : unit -> string

val button_style__default__color : unit -> string

val button_style__default__border : unit -> string

val button_style__default__radius : unit -> int

val button_style__default__font : unit -> string

val button_style__default__size : unit -> int

val button_style__default__padding : unit -> int

val button_style : string -> string -> string -> int -> string -> int -> int -> unit

val label_style__default__background : unit -> string

val label_style__default__color : unit -> string

val label_style__default__border : unit -> string

val label_style__default__radius : unit -> int

val label_style__default__font : unit -> string

val label_style__default__size : unit -> int

val label_style__default__padding : unit -> int

val label_style : string -> string -> string -> int -> string -> int -> int -> unit

val slider_style__default__accent : unit -> string

val slider_style__default__width : unit -> int

val slider_style__default__color : unit -> string

val slider_style__default__font : unit -> string

val slider_style__default__size : unit -> int

val slider_style : string -> int -> string -> string -> int -> unit

val canvas_style__default__border : unit -> string

val canvas_style__default__radius : unit -> int

val canvas_style : string -> int -> unit

val set_colors__default__color : unit -> string

val set_colors__default__background : unit -> string

val set_colors : int -> string -> string -> unit

val set_style__default__background : unit -> string

val set_style__default__color : unit -> string

val set_style__default__border : unit -> string

val set_style__default__radius : unit -> int

val set_style__default__font : unit -> string

val set_style__default__size : unit -> int

val set_style__default__padding : unit -> int

val set_style__default__accent : unit -> string

val set_style__default__width : unit -> int

val set_style : int -> string -> string -> string -> int -> string -> int -> int -> string -> int -> unit

val play__default__at : unit -> float

val play__default__volume : unit -> float

val play__default__rate : unit -> float

val play : int -> float -> float -> float -> unit

val play_file : string -> unit
