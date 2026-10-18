(* Generated from tinyweb.pyk by the Pyking compiler. Do not edit. *)
(* What the module 'tinyweb' exports; everything else in
   the file beside this one is private to it. *)

val clear__default__color : unit -> string

val clear : string -> string -> unit

val web_init__default__port : unit -> int

val web_init : int -> unit

val circle__default__color : unit -> string

val circle__default__outline : unit -> string

val circle__default__outline_width : unit -> int

val circle__default__alpha : unit -> float

val circle : string -> int -> int -> int -> string -> string -> int -> float -> unit

val rect__default__color : unit -> string

val rect__default__outline : unit -> string

val rect__default__outline_width : unit -> int

val rect__default__alpha : unit -> float

val rect__default__radius : unit -> int

val rect : string -> int -> int -> int -> int -> string -> string -> int -> float -> int -> unit

val ellipse__default__color : unit -> string

val ellipse__default__outline : unit -> string

val ellipse__default__outline_width : unit -> int

val ellipse__default__alpha : unit -> float

val ellipse : string -> int -> int -> int -> int -> string -> string -> int -> float -> unit

val arc__default__color : unit -> string

val arc__default__outline : unit -> string

val arc__default__outline_width : unit -> int

val arc__default__alpha : unit -> float

val arc : string -> int -> int -> int -> float -> float -> string -> string -> int -> float -> unit

val polygon__default__color : unit -> string

val polygon__default__outline : unit -> string

val polygon__default__outline_width : unit -> int

val polygon__default__alpha : unit -> float

val polygon : string -> (int * int) list -> string -> string -> int -> float -> unit

val line__default__color : unit -> string

val line__default__width : unit -> int

val line__default__alpha : unit -> float

val line : string -> int -> int -> int -> int -> string -> int -> float -> unit

val path__default__color : unit -> string

val path__default__width : unit -> int

val path__default__alpha : unit -> float

val path : string -> (int * int) list -> string -> int -> float -> unit

val curve__default__color : unit -> string

val curve__default__width : unit -> int

val curve__default__alpha : unit -> float

val curve : string -> int -> int -> int -> int -> int -> int -> string -> int -> float -> unit

val lines__default__color : unit -> string

val lines__default__width : unit -> int

val lines__default__alpha : unit -> float

val lines : string -> (int * int * int * int) list -> string -> int -> float -> unit

val bezier__default__color : unit -> string

val bezier__default__width : unit -> int

val bezier__default__alpha : unit -> float

val bezier : string -> int -> int -> int -> int -> int -> int -> int -> int -> string -> int -> float -> unit

val erase : string -> int -> int -> int -> int -> unit

val line_style__default__cap : unit -> string

val line_style__default__join : unit -> string

val line_style__default__dash : unit -> float

val line_style__default__gap : unit -> float

val line_style__default__offset : unit -> float

val line_style__default__dash2 : unit -> float

val line_style__default__gap2 : unit -> float

val line_style : string -> string -> string -> float -> float -> float -> float -> float -> unit

val clip_rect : string -> int -> int -> int -> int -> unit

val clip_circle : string -> int -> int -> int -> unit

val clip_polygon : string -> (int * int) list -> unit

val text__default__color : unit -> string

val text__default__size : unit -> int

val text__default__font : unit -> string

val text__default__align : unit -> string

val text__default__bold : unit -> bool

val text__default__alpha : unit -> float

val text__default__baseline : unit -> string

val text__default__outline : unit -> string

val text__default__outline_width : unit -> int

val text : string -> int -> int -> string -> string -> int -> string -> string -> bool -> float -> string -> string -> int -> unit

val measure_text__default__size : unit -> int

val measure_text__default__font : unit -> string

val measure_text__default__bold : unit -> bool

val measure_text : string -> (float -> unit) -> int -> string -> bool -> unit

val translate : string -> float -> float -> unit

val rotate : string -> float -> unit

val scale : string -> float -> float -> unit

val push : string -> unit

val pop : string -> unit

val reset : string -> unit

val shadow__default__blur : unit -> int

val shadow__default__dx : unit -> int

val shadow__default__dy : unit -> int

val shadow : string -> string -> int -> int -> int -> unit

val blend : string -> string -> unit

val image__default__alpha : unit -> float

val image : string -> string -> int -> int -> int -> int -> float -> unit

val colors__rgb : int -> int -> int -> string

val colors__rgba : int -> int -> int -> float -> string

val colors__hsl : int -> int -> int -> string

val colors__palette : string -> string list

val colors__linear_gradient : float -> float -> float -> float -> string -> string -> string

val colors__radial_gradient : float -> float -> float -> float -> float -> float -> string -> string -> string

val colors__conic_gradient : float -> float -> float -> string -> string -> string

val colors__stop : string -> float -> string -> string

val button__default__on_click : unit -> unit -> unit

val button : string -> (unit -> unit) -> string

val slider__default__on_change : unit -> int -> unit

val slider : int -> int -> int -> (int -> unit) -> string

val checkbox__default__checked : unit -> bool

val checkbox__default__on_change : unit -> bool -> unit

val checkbox : string -> bool -> (bool -> unit) -> string

val radio__default__chosen : unit -> bool

val radio__default__on_pick : unit -> string -> unit

val radio : string -> string -> bool -> (string -> unit) -> string

val choice__default__chosen : unit -> int

val choice__default__on_change : unit -> int -> unit

val choice : string list -> int -> (int -> unit) -> string

val text_input__default__placeholder : unit -> string

val text_input__default__on_enter : unit -> string -> unit

val text_input : string -> (string -> unit) -> string

val number_input__default__on_change : unit -> int -> unit

val number_input : int -> int -> int -> (int -> unit) -> string

val theme : string -> unit

val page_style__default__background : unit -> string

val page_style__default__color : unit -> string

val page_style__default__font : unit -> string

val page_style__default__size : unit -> int

val page_style__default__padding : unit -> int

val page_style__default__gap : unit -> int

val page_style__default__align : unit -> string

val page_style : string -> string -> string -> int -> int -> int -> string -> unit

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

val set_colors : string -> string -> string -> unit

val set_style__default__background : unit -> string

val set_style__default__color : unit -> string

val set_style__default__border : unit -> string

val set_style__default__radius : unit -> int

val set_style__default__font : unit -> string

val set_style__default__size : unit -> int

val set_style__default__padding : unit -> int

val set_style__default__accent : unit -> string

val set_style__default__width : unit -> int

val set_style__default__weight : unit -> int

val set_style__default__height : unit -> int

val set_style : string -> string -> string -> string -> int -> string -> int -> int -> string -> int -> int -> int -> unit

val play__default__at : unit -> float

val play__default__volume : unit -> float

val play__default__rate : unit -> float

val play : string -> float -> float -> float -> unit

val play_file : string -> unit

val on_press : string -> (int -> int -> unit) -> unit

val on_release : string -> (int -> int -> unit) -> unit

val on_move : string -> (int -> int -> unit) -> unit

val on_drag : string -> (int -> int -> unit) -> unit

val mouse_x : string -> int

val mouse_y : string -> int

val mouse_down : string -> bool

val ignore2 : int -> int -> unit

val show_bitmap__default__x : unit -> int

val show_bitmap__default__y : unit -> int

val show_bitmap__default__scale : unit -> float

val show_bitmap : string -> string -> int -> int -> float -> unit

val pixel_color : int -> int -> int -> int

val red : int -> int

val green : int -> int

val blue : int -> int

val smooth__circle__default__color : unit -> string

val smooth__circle__default__outline : unit -> string

val smooth__circle__default__outline_width : unit -> float

val smooth__circle__default__alpha : unit -> float

val smooth__circle : string -> float -> float -> float -> string -> string -> float -> float -> unit

val smooth__circles__default__color : unit -> string

val smooth__circles__default__outline : unit -> string

val smooth__circles__default__outline_width : unit -> float

val smooth__circles__default__alpha : unit -> float

val smooth__circles : string -> (float * float * float) list -> string -> string -> float -> float -> unit

val smooth__rect__default__color : unit -> string

val smooth__rect__default__outline : unit -> string

val smooth__rect__default__outline_width : unit -> float

val smooth__rect__default__alpha : unit -> float

val smooth__rect__default__radius : unit -> float

val smooth__rect : string -> float -> float -> float -> float -> string -> string -> float -> float -> float -> unit

val smooth__ellipse__default__color : unit -> string

val smooth__ellipse__default__outline : unit -> string

val smooth__ellipse__default__outline_width : unit -> float

val smooth__ellipse__default__alpha : unit -> float

val smooth__ellipse : string -> float -> float -> float -> float -> string -> string -> float -> float -> unit

val smooth__arc__default__color : unit -> string

val smooth__arc__default__outline : unit -> string

val smooth__arc__default__outline_width : unit -> float

val smooth__arc__default__alpha : unit -> float

val smooth__arc : string -> float -> float -> float -> float -> float -> string -> string -> float -> float -> unit

val smooth__polygon__default__color : unit -> string

val smooth__polygon__default__outline : unit -> string

val smooth__polygon__default__outline_width : unit -> float

val smooth__polygon__default__alpha : unit -> float

val smooth__polygon : string -> (float * float) list -> string -> string -> float -> float -> unit

val smooth__line__default__color : unit -> string

val smooth__line__default__width : unit -> float

val smooth__line__default__alpha : unit -> float

val smooth__line : string -> float -> float -> float -> float -> string -> float -> float -> unit

val smooth__lines__default__color : unit -> string

val smooth__lines__default__width : unit -> float

val smooth__lines__default__alpha : unit -> float

val smooth__lines : string -> (float * float * float * float) list -> string -> float -> float -> unit

val smooth__path__default__color : unit -> string

val smooth__path__default__width : unit -> float

val smooth__path__default__alpha : unit -> float

val smooth__path : string -> (float * float) list -> string -> float -> float -> unit

val smooth__curve__default__color : unit -> string

val smooth__curve__default__width : unit -> float

val smooth__curve__default__alpha : unit -> float

val smooth__curve : string -> float -> float -> float -> float -> float -> float -> string -> float -> float -> unit

val smooth__bezier__default__color : unit -> string

val smooth__bezier__default__width : unit -> float

val smooth__bezier__default__alpha : unit -> float

val smooth__bezier : string -> float -> float -> float -> float -> float -> float -> float -> float -> string -> float -> float -> unit

val smooth__text__default__color : unit -> string

val smooth__text__default__size : unit -> int

val smooth__text__default__font : unit -> string

val smooth__text__default__align : unit -> string

val smooth__text__default__bold : unit -> bool

val smooth__text__default__alpha : unit -> float

val smooth__text__default__baseline : unit -> string

val smooth__text__default__outline : unit -> string

val smooth__text__default__outline_width : unit -> float

val smooth__text : string -> float -> float -> string -> string -> int -> string -> string -> bool -> float -> string -> string -> float -> unit

val smooth__clip_circle : string -> float -> float -> float -> unit

val smooth__clip_polygon : string -> (float * float) list -> unit
