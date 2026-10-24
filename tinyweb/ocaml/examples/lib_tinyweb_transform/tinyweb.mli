(* Generated from tinyweb.pyk by the Pyking compiler. Do not edit. *)
(* What the module 'tinyweb' exports; everything else in
   the file beside this one is private to it. *)

type color__Color =
  | Color__Color of int * int * int * float
and color__Paint =
  | Color__Plain of color__Color
  | Color__Linear of float * float * float * float * color__Color * color__Color * string
  | Color__Radial of float * float * float * float * float * float * color__Color * color__Color * string
  | Color__Conic of float * float * float * color__Color * color__Color * string
and point =
  | Point of int * int
and style =
  | Style of color__Color * color__Color * int * float * color__Paint
and pointer =
  | Pointer of int * int * bool
and sound__Voice =
  | Sound__Voice of float * float * float * int * bool * bool
and smooth__Point =
  | Smooth__Point of float * float

val pyk_show_color__Color : color__Color -> string

val pyk_show_color__Paint : color__Paint -> string

val pyk_show_point : point -> string

val pyk_show_style : style -> string

val pyk_show_pointer : pointer -> string

val pyk_show_sound__Voice : sound__Voice -> string

val pyk_show_smooth__Point : smooth__Point -> string

val color__black : color__Color

val color__white : color__Color

val color__gray : color__Color

val color__red : color__Color

val color__green : color__Color

val color__blue : color__Color

val color__yellow : color__Color

val color__orange : color__Color

val color__purple : color__Color

val color__pink : color__Color

val color__navy : color__Color

val color__teal : color__Color

val color__brown : color__Color

val color__cyan : color__Color

val color__magenta : color__Color

val color__none : color__Color

val color__theme : color__Color

val color__rgb : int -> int -> int -> color__Color

val color__rgba : int -> int -> int -> float -> color__Color

val color__hsl : float -> float -> float -> color__Color

val color__hex : int -> color__Color

val color__to_hex : color__Color -> int

val color__with_alpha : color__Color -> float -> color__Color

val color__mix : color__Color -> color__Color -> float -> color__Color

val color__same : color__Color -> color__Color -> bool

val color__palette : string -> color__Color list

val color__stop : color__Paint -> float -> color__Color -> color__Paint

val web_init : int -> unit

val field__default__Style__fill : unit -> color__Color

val field__default__Style__stroke : unit -> color__Color

val field__default__Style__paint : unit -> color__Paint

val clear__default__fill : unit -> color__Color

val clear : string -> color__Color -> unit

val circle__default__fill : unit -> color__Color

val circle__default__stroke : unit -> color__Color

val circle__default__paint : unit -> color__Paint

val circle__default__style : unit -> style

val circle : string -> int -> int -> int -> color__Color -> color__Color -> int -> float -> color__Paint -> style -> unit

val rect__default__fill : unit -> color__Color

val rect__default__stroke : unit -> color__Color

val rect__default__paint : unit -> color__Paint

val rect__default__style : unit -> style

val rect : string -> int -> int -> int -> int -> color__Color -> color__Color -> int -> float -> color__Paint -> style -> int -> unit

val ellipse__default__fill : unit -> color__Color

val ellipse__default__stroke : unit -> color__Color

val ellipse__default__paint : unit -> color__Paint

val ellipse__default__style : unit -> style

val ellipse : string -> int -> int -> int -> int -> color__Color -> color__Color -> int -> float -> color__Paint -> style -> unit

val arc__default__fill : unit -> color__Color

val arc__default__stroke : unit -> color__Color

val arc__default__paint : unit -> color__Paint

val arc__default__style : unit -> style

val arc : string -> int -> int -> int -> float -> float -> color__Color -> color__Color -> int -> float -> color__Paint -> style -> unit

val polygon__default__fill : unit -> color__Color

val polygon__default__stroke : unit -> color__Color

val polygon__default__paint : unit -> color__Paint

val polygon__default__style : unit -> style

val polygon : string -> point list -> color__Color -> color__Color -> int -> float -> color__Paint -> style -> unit

val line__default__stroke : unit -> color__Color

val line__default__style : unit -> style

val line : string -> int -> int -> int -> int -> color__Color -> int -> float -> style -> unit

val path__default__stroke : unit -> color__Color

val path__default__style : unit -> style

val path : string -> point list -> color__Color -> int -> float -> style -> unit

val curve__default__stroke : unit -> color__Color

val curve__default__style : unit -> style

val curve : string -> int -> int -> int -> int -> int -> int -> color__Color -> int -> float -> style -> unit

val lines__default__stroke : unit -> color__Color

val lines__default__style : unit -> style

val lines : string -> (point * point) list -> color__Color -> int -> float -> style -> unit

val bezier__default__stroke : unit -> color__Color

val bezier__default__style : unit -> style

val bezier : string -> int -> int -> int -> int -> int -> int -> int -> int -> color__Color -> int -> float -> style -> unit

val erase : string -> int -> int -> int -> int -> unit

val line_style : string -> string -> string -> float -> float -> float -> float -> float -> unit

val clip_rect : string -> int -> int -> int -> int -> unit

val clip_circle : string -> int -> int -> int -> unit

val clip_polygon : string -> point list -> unit

val text__default__fill : unit -> color__Color

val text__default__stroke : unit -> color__Color

val text__default__paint : unit -> color__Paint

val text__default__style : unit -> style

val text : string -> int -> int -> string -> color__Color -> int -> string -> string -> bool -> float -> string -> color__Color -> int -> color__Paint -> style -> unit

val measure_text : string -> (float -> unit) -> int -> string -> bool -> unit

val translate : string -> float -> float -> unit

val rotate : string -> float -> unit

val scale : string -> float -> float -> unit

val push : string -> unit

val pop : string -> unit

val reset : string -> unit

val shadow : string -> color__Color -> int -> int -> int -> unit

val blend : string -> string -> unit

val image : string -> string -> int -> int -> int -> int -> float -> unit

val button__default__on_click : unit -> unit -> unit

val button : string -> (unit -> unit) -> string

val slider__default__on_change : unit -> int -> unit

val slider : int -> int -> int -> (int -> unit) -> string

val checkbox__default__on_change : unit -> bool -> unit

val checkbox : string -> bool -> (bool -> unit) -> string

val radio__default__on_pick : unit -> string -> unit

val radio : string -> string -> bool -> (string -> unit) -> string

val choice__default__on_change : unit -> int -> unit

val choice : string list -> int -> (int -> unit) -> string

val text_input__default__on_enter : unit -> string -> unit

val text_input : string -> (string -> unit) -> string

val number_input__default__on_change : unit -> int -> unit

val number_input : int -> int -> int -> (int -> unit) -> string

val set_text : string -> string -> unit

val show : string -> unit

val hide : string -> unit

val enable : string -> unit

val disable : string -> unit

val remove : string -> unit

val value_of : string -> string

val theme : string -> unit

val page_style__default__background : unit -> color__Color

val page_style__default__foreground : unit -> color__Color

val page_style : color__Color -> color__Color -> string -> int -> int -> int -> string -> unit

val button_style__default__background : unit -> color__Color

val button_style__default__foreground : unit -> color__Color

val button_style__default__border : unit -> color__Color

val button_style : color__Color -> color__Color -> color__Color -> int -> int -> string -> int -> int -> unit

val label_style__default__background : unit -> color__Color

val label_style__default__foreground : unit -> color__Color

val label_style__default__border : unit -> color__Color

val label_style : color__Color -> color__Color -> color__Color -> int -> int -> string -> int -> int -> unit

val slider_style__default__accent : unit -> color__Color

val slider_style__default__foreground : unit -> color__Color

val slider_style : color__Color -> int -> color__Color -> string -> int -> unit

val canvas_style__default__border : unit -> color__Color

val canvas_style : color__Color -> int -> int -> unit

val set_style__default__background : unit -> color__Color

val set_style__default__foreground : unit -> color__Color

val set_style__default__border : unit -> color__Color

val set_style__default__accent : unit -> color__Color

val set_style : string -> color__Color -> color__Color -> color__Color -> int -> int -> string -> int -> int -> color__Color -> int -> int -> int -> unit

val on_click : string -> (int -> int -> unit) -> unit

val on_press : string -> (int -> int -> unit) -> unit

val on_release : string -> (int -> int -> unit) -> unit

val on_move : string -> (int -> int -> unit) -> unit

val on_drag : string -> (int -> int -> unit) -> unit

val track_mouse : string -> unit

val mouse : string -> pointer

val after : float -> (unit -> unit) -> string

val every : float -> (unit -> unit) -> string

val cancel : string -> unit

val play__default__voice : unit -> sound__Voice

val play : string -> float -> float -> float -> float -> sound__Voice -> unit

val play_file : string -> unit

val sound__start__default__voice : unit -> sound__Voice

val sound__start : string -> float -> float -> float -> float -> bool -> sound__Voice -> string

val sound__stop : string -> float -> unit

val sound__fade : string -> float -> float -> unit

val sound__stop_all : unit -> unit

val sound__master_volume : float -> unit

val sound__tone : float -> float -> float -> string -> float -> float -> int -> unit

val sound__note : string -> float

val sound__rate_of : string -> string -> float

val sound__tempo : float -> unit

val sound__swing : float -> unit

val sound__on_beat : (int -> float -> unit) -> int -> string

val sound__beat : unit -> float

val sound__latency : unit -> float

val sound__pause : unit -> unit

val sound__resume : unit -> unit

val sound__channel_style : int -> float -> float -> float -> float -> float -> float -> float -> unit

val sound__listen : int -> float -> unit

val sound__level : unit -> float

val sound__band : int -> float

val sound__bands : unit -> int

val sound__wave : int -> float

val sound__render_wav__default__on_rendered : unit -> float -> float -> unit

val sound__render_wav : float -> (unit -> unit) -> string -> (float -> float -> unit) -> unit

val bitmap__bitmap__default__background : unit -> color__Color

val bitmap__bitmap : int -> int -> color__Color -> string

val bitmap__set_pixel : string -> int -> int -> color__Color -> unit

val bitmap__get_pixel : string -> int -> int -> color__Color

val bitmap__fill_bitmap : string -> color__Color -> unit

val bitmap__show_bitmap : string -> string -> int -> int -> float -> unit

val layout__row : unit -> string

val layout__column : unit -> string

val layout__inside : string -> unit

val layout__outside : unit -> unit

val layout__text_area__default__on_change : unit -> string -> unit

val layout__text_area : string -> int -> int -> (string -> unit) -> string

val net__save_canvas : string -> string -> unit

val net__download : string -> string -> unit

val net__file_button__default__on_load : unit -> string -> unit

val net__file_button : string -> (string -> unit) -> string

val net__file_text : unit -> string

val game__cursor : string -> string -> unit

val smooth__circle__default__fill : unit -> color__Color

val smooth__circle__default__stroke : unit -> color__Color

val smooth__circle__default__paint : unit -> color__Paint

val smooth__circle__default__style : unit -> style

val smooth__circle : string -> float -> float -> float -> color__Color -> color__Color -> float -> float -> color__Paint -> style -> unit

val smooth__circles__default__fill : unit -> color__Color

val smooth__circles__default__stroke : unit -> color__Color

val smooth__circles__default__style : unit -> style

val smooth__circles : string -> (float * float * float) list -> color__Color -> color__Color -> float -> float -> style -> unit

val smooth__rect__default__fill : unit -> color__Color

val smooth__rect__default__stroke : unit -> color__Color

val smooth__rect__default__paint : unit -> color__Paint

val smooth__rect__default__style : unit -> style

val smooth__rect : string -> float -> float -> float -> float -> color__Color -> color__Color -> float -> float -> color__Paint -> style -> float -> unit

val smooth__ellipse__default__fill : unit -> color__Color

val smooth__ellipse__default__stroke : unit -> color__Color

val smooth__ellipse__default__paint : unit -> color__Paint

val smooth__ellipse__default__style : unit -> style

val smooth__ellipse : string -> float -> float -> float -> float -> color__Color -> color__Color -> float -> float -> color__Paint -> style -> unit

val smooth__arc__default__fill : unit -> color__Color

val smooth__arc__default__stroke : unit -> color__Color

val smooth__arc__default__paint : unit -> color__Paint

val smooth__arc__default__style : unit -> style

val smooth__arc : string -> float -> float -> float -> float -> float -> color__Color -> color__Color -> float -> float -> color__Paint -> style -> unit

val smooth__polygon__default__fill : unit -> color__Color

val smooth__polygon__default__stroke : unit -> color__Color

val smooth__polygon__default__style : unit -> style

val smooth__polygon : string -> smooth__Point list -> color__Color -> color__Color -> float -> float -> style -> unit

val smooth__line__default__stroke : unit -> color__Color

val smooth__line__default__style : unit -> style

val smooth__line : string -> float -> float -> float -> float -> color__Color -> float -> float -> style -> unit

val smooth__lines__default__stroke : unit -> color__Color

val smooth__lines__default__style : unit -> style

val smooth__lines : string -> (smooth__Point * smooth__Point) list -> color__Color -> float -> float -> style -> unit

val smooth__path__default__stroke : unit -> color__Color

val smooth__path__default__style : unit -> style

val smooth__path : string -> smooth__Point list -> color__Color -> float -> float -> style -> unit

val smooth__curve__default__stroke : unit -> color__Color

val smooth__curve__default__style : unit -> style

val smooth__curve : string -> float -> float -> float -> float -> float -> float -> color__Color -> float -> float -> style -> unit

val smooth__bezier__default__stroke : unit -> color__Color

val smooth__bezier__default__style : unit -> style

val smooth__bezier : string -> float -> float -> float -> float -> float -> float -> float -> float -> color__Color -> float -> float -> style -> unit

val smooth__text__default__fill : unit -> color__Color

val smooth__text__default__stroke : unit -> color__Color

val smooth__text__default__paint : unit -> color__Paint

val smooth__text__default__style : unit -> style

val smooth__text : string -> float -> float -> string -> color__Color -> int -> string -> string -> bool -> float -> string -> color__Color -> float -> color__Paint -> style -> unit

val smooth__clip_circle : string -> float -> float -> float -> unit

val smooth__clip_polygon : string -> smooth__Point list -> unit
