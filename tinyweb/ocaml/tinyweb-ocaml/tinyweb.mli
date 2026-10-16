(** tinyweb: graphics, widgets and sound on a web page the program
    serves itself, for OCaml. Link it with unix.

    Call [web_init] first. Once the program's top level has ended, it
    keeps serving its page and calling the functions it handed over,
    until it is stopped. *)

(** Serves the program's page on port and prints its address,
    tinyweb: http://127.0.0.1:N/; port 0 picks any free port. Call it
    before anything else. With PYKING_TINYWEB_LOG set it does
    nothing. *)
val web_init : int -> unit

(** A new canvas, width by height pixels, placed below what the page
    already shows. Answers the number that names it. *)
val canvas : int -> int -> int

(** Fills the whole canvas c with color, a CSS color such as
    "#ff0000" or "red". *)
val fill_canvas : int -> string -> unit

(** A filled circle on the canvas c, centred at (x, y). *)
val draw_circle : int -> int -> int -> int -> string -> unit

(** A filled rectangle on the canvas c, with its top left corner at
    (x, y). *)
val draw_rect : int -> int -> int -> int -> int -> string -> unit

(** A straight line on the canvas c, from (x1, y1) to (x2, y2), width
    pixels wide. *)
val draw_line : int -> int -> int -> int -> int -> string -> int -> unit

(** words written on the canvas c, with the top left corner of the
    text at (x, y), size pixels high. *)
val draw_text : int -> int -> int -> string -> string -> int -> unit

(** A button showing title, placed below what the page already shows,
    which calls on_click each time it is pressed. Answers the number
    that names it. *)
val make_button : string -> (unit -> unit) -> int

(** A line of text, placed below what the page already shows. Answers
    the number that names it to set_label. *)
val label : string -> int

(** Replaces the text of the label id with text. *)
val set_label : int -> string -> unit

(** A slider from low to high, starting at value, placed below what
    the page already shows, which calls on_change with each new value
    it is moved to. Answers the number that names it. *)
val make_slider : int -> int -> int -> (int -> unit) -> int

(** Changes the page's look. With kind "theme", value names a theme:
    "light" (the default), "dark", "plain", "paper" or "retro". With
    kind "page", "button", "label", "slider" or "canvas", property of
    every element of that kind becomes value; with kind "element",
    only the element id's. property is one of background, color,
    border, radius, font, size, padding, gap, accent and width, and
    value is CSS, such as "#336699" or "12px". id is 0 except for an
    element. *)
val apply_style : int -> string -> string -> string -> unit

(** Starts loading the sound file name and answers a number naming it
    to play_sample. The name is looked up beside where the program
    runs first, and then among the samples tinyweb ships in
    tinyweb_assets/: kick1.wav, snare1.wav, hihat1.wav and
    piano_c1.wav. *)
val load_sample : string -> int

(** Plays the sample sample: at the time at on the page's clock, or
    now if that has passed; volume times as loud, and rate times as
    fast, which raises its pitch as much. *)
val play_sample : int -> float -> float -> float -> unit

(** The page's clock, in seconds, as the page last reported it:
    inside an on_frame callback, the time the frame is for. It is the
    audio clock once sound has started, so a time read here is a time
    play_sample can be given. *)
val time : unit -> float

(** Calls draw before each frame the page shows, with the time the
    frame is for. *)
val on_frame : (float -> unit) -> unit

(** Calls click with the position, in pixels from the top left
    corner, of every click on the canvas c. *)
val on_mouse : int -> (int -> int -> unit) -> unit

(** Calls pressed with the name of every key pressed while the page
    has the focus: a letter or digit as itself, and otherwise the
    browser's name for it, such as "ArrowLeft", "Enter" or " ". *)
val on_key : (string -> unit) -> unit

(** {2 Serving the page from a loop of your own}

    The page is otherwise served once the program's top level has
    ended. A program that keeps running a loop of its own can serve it
    from there instead: wait on [descriptors ()] beside its own, and
    call [handle ()] when one is ready. *)

(** What the server waits on: nothing until [web_init]. *)
val descriptors : unit -> Unix.file_descr list

(** Answers what is waiting and calls what the page's events reach,
    without waiting for anything more. *)
val handle : unit -> unit
