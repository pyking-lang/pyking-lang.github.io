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
    already shows. Answers the string that names it: "canvas", with a
    number added where something on the page has that name already. *)
val canvas : int -> int -> string

(** Fills the whole canvas c with color, a CSS color such as
    "#ff0000" or "red". *)
val fill_canvas : string -> string -> unit

(** One shape on the canvas c. kind is "rect", "circle", "ellipse",
    "arc", "line", "lines", "curve", "bezier", "polygon", "path" or
    "erase", and numbers its numbers as words: x y width height
    radius for a rect, x y r for a circle, x y rx ry for an ellipse,
    x y r start end (radians) for an arc, x1 y1 x2 y2 for a line, x1
    y1 x2 y2 for each of many lines, x1 y1 cx cy x2 y2 for a curve,
    x1 y1 ax ay bx by x2 y2 for a bezier, x y x y ... for a polygon
    or a path, and x y width height for the rectangle erase makes
    transparent. It is filled with color and outlined with outline,
    width pixels thick, each unless it is "", at alpha from 0.0 to
    1.0. A color may be a gradient: "linear-gradient(x1 y1 x2 y2);
    0.0 red; 1.0 blue", "radial-gradient(x1 y1 r1 x2 y2 r2); ..." or
    "conic-gradient(x y angle); ...", each stop its place from 0.0 to
    1.0 and a CSS color. *)
val draw_shape : string -> string -> string -> string -> string -> float -> float -> unit

(** Many shapes' numbers in one go, as a list rather than as words:
    kind "polygon" or "path" through the points (x, y) in items,
    drawn as draw_shape draws one. Not in C, which cannot be given a
    list. *)
val draw_pairs : string -> string -> (float * float) list -> string -> string -> float -> float -> unit

(** Many circles in one go: kind "circles", each (x, y, radius) in
    items filled and outlined on its own, as draw_shape draws one.
    Not in C, which cannot be given a list. *)
val draw_triples : string -> string -> (float * float * float) list -> string -> string -> float -> float -> unit

(** Many separate lines in one go: kind "lines", each (x1, y1, x2,
    y2) in items, stroked together as one. Not in C, which cannot be
    given a list. *)
val draw_quads : string -> string -> (float * float * float * float) list -> string -> string -> float -> float -> unit

(** words written on the canvas c at (x, y): its left end there, or
    with align "center" or "right" its middle or right end, and its
    top there, or with baseline "middle", "alphabetic" or "bottom"
    that part of it. size pixels high, in font ("" for the page's
    own), bold where bold is true, filled with color and outlined
    with outline outline_width pixels thick, each unless it is "", at
    alpha. *)
val draw_text : string -> float -> float -> string -> string -> int -> string -> string -> string -> bool -> string -> float -> float -> unit

(** Changes what the next drawing on the canvas c is drawn with. kind
    "translate", "rotate" or "scale" take their numbers (x y,
    radians, sx sy) in numbers; "push" and "pop" save and restore the
    state; "reset" takes every transformation off; "shadow" takes a
    color in value ("" for none) and blur dx dy in numbers; "blend"
    takes "normal" or "add" in value; "line_style" takes how lines
    end and turn in value ("round round", "butt miter", ...) and the
    dash offset followed by the dash and gap lengths in numbers;
    "clip" keeps what is drawn after it inside a shape, its kind in
    value and its numbers as draw_shape takes them. fill_canvas
    starts the canvas afresh. *)
val set_state : string -> string -> string -> string -> unit

(** Asks the page how wide words is written size pixels high in font,
    bold where bold is true, and calls answer with the width in
    pixels once the page has said. *)
val measure : string -> int -> string -> bool -> (float -> unit) -> unit

(** Calls f with where the pointer is on the canvas c, in pixels from
    its top left corner, each time it goes down there (kind "press"),
    comes up ("release"), moves over it ("move") or moves with the
    button held ("drag"). *)
val watch_pointer : string -> string -> (int -> int -> unit) -> unit

(** Where the pointer was last seen on the canvas c: which "x" or "y"
    for its position, "down" for 1 while its button is held and 0
    otherwise. The canvas reports the pointer once watch_pointer has
    been called for it. *)
val pointer : string -> string -> int

(** Draws a loaded picture on the canvas c, its top left corner at
    (x, y), stretched to width by height, at alpha. One still loading
    is not drawn. *)
val draw_image : string -> string -> int -> int -> int -> int -> float -> unit

(** A picture width by height pixels the program builds, every pixel
    background to start with, as set_pixel takes a color, kept by the
    program: setting a pixel sends nothing. Answers the string that
    names it: "bitmap", with a number added where something on the
    page has that name already. *)
val make_bitmap : int -> int -> int -> string

(** Sets the pixel (x, y) of the bitmap b to color, red times 65536
    plus green times 256 plus blue. A pixel outside it is left alone. *)
val set_pixel : string -> int -> int -> int -> unit

(** The color of the pixel (x, y) of the bitmap b, as set_pixel takes
    one; 0 outside it. *)
val get_pixel : string -> int -> int -> int

(** Sets every pixel of the bitmap b to color. *)
val fill_bitmap : string -> int -> unit

(** Draws the bitmap b on the canvas c, its top left corner at (x,
    y), each pixel scale pixels across: sharp squares above 1.0. What
    changed since it was last drawn is sent to the page. *)
val draw_bitmap : string -> string -> int -> int -> float -> unit

(** Starts loading the picture name, looked for as a sample is, and
    answers the string that names it to draw_image. *)
val load_image : string -> string

(** A button showing title, placed below what the page already shows,
    which calls on_click each time it is pressed. Answers the string
    that names it: title, with a number added where something on the
    page has that name already. *)
val make_button : string -> (unit -> unit) -> string

(** A line of text, placed below what the page already shows. Answers
    the string that names it to set_label: text, with a number added
    where something on the page has that name already. *)
val label : string -> string

(** A box placed below what the page already shows, whose elements go
    side by side, wrapping where the page is too narrow. Answers the
    string that names it to inside: "row", with a number added where
    something on the page has that name already. *)
val row : unit -> string

(** A box whose elements go one below another, as the page's own do:
    inside a row, it stands beside the row's other elements. Answers
    the string that names it to inside. *)
val column : unit -> string

(** Makes every element made after it go into the row or column id,
    until outside or another inside. *)
val inside : string -> unit

(** Makes every element made after it go on the page again, below
    what is there. *)
val outside : unit -> unit

(** Replaces the text of the label id, or the title of the button id,
    with text. *)
val set_label : string -> string -> unit

(** A slider from low to high, starting at value, placed below what
    the page already shows, which calls on_change with each new value
    it is moved to. Answers the string that names it: "slider", with
    a number added where something on the page has that name already. *)
val make_slider : int -> int -> int -> (int -> unit) -> string

(** A checkbox showing title, ticked where checked is true, which
    calls on_change with whether it is ticked each time the reader
    changes it. Answers the string that names it. *)
val make_checkbox : string -> bool -> (bool -> unit) -> string

(** A radio button showing title in the group group: choosing one
    clears the others. The first of a group starts chosen unless one
    says chosen. Calls on_pick with title when the reader chooses it.
    Answers the string that names it. *)
val make_radio : string -> string -> bool -> (string -> unit) -> string

(** A dropdown of options, one per line, the one at position chosen
    chosen, which calls on_change with the position the reader
    chooses. Answers the string that names it. *)
val make_choice : string -> int -> (int -> unit) -> string

(** A line to type text into, showing placeholder while empty, which
    calls on_enter with the text when Enter is pressed in it. Answers
    the string that names it. *)
val make_text_input : string -> (string -> unit) -> string

(** A field for a whole number from low to high, starting at value,
    which calls on_change with each new number. Answers the string
    that names it. *)
val make_number_input : int -> int -> int -> (int -> unit) -> string

(** Ticks or clears the checkbox id, or chooses the radio button id. *)
val set_checked : string -> bool -> unit

(** Moves the slider or number field id to value, or picks the
    dropdown choice at that position. *)
val set_value : string -> int -> unit

(** Changes the page's look. With kind "theme", value names a theme:
    "light" (the default), "dark", "plain", "paper" or "retro". With
    kind "page", "button", "label", "slider" or "canvas", property of
    every element of that kind becomes value; with kind "element",
    only the element id's. property is one of background, color,
    border, radius, font, size, padding, gap, accent and width, and
    value is CSS, such as "#336699" or "12px". id is "" except for an
    element. *)
val apply_style : string -> string -> string -> string -> unit

(** Starts loading the sound file name and answers a string naming it
    to play_sample: name, with a number added where something on the
    page has that name already. The name is looked up beside where
    the program runs first, and then among the samples tinyweb ships
    in tinyweb_assets/: kick1.wav, snare1.wav, hihat1.wav and
    piano_c1.wav. *)
val load_sample : string -> string

(** A new element's identifier: name, with a number added where
    something on the page has that name already. Sends nothing; what
    command makes takes it. *)
val fresh_id : string -> string

(** Sends the page one command, by kind, with an element id, a text
    and its numbers as words. Sound: "play" (id the sample; numbers
    at volume rate pan channel reverse), "start" (id a new voice,
    text the sample, numbers as play's then loop), "stop" (at),
    "fade" (volume over), "stop_all", "tone" (text the wave;
    frequency at duration volume pan channel), "master" (volume),
    "tempo" (bpm), "swing" (amount), "beat" (steps; reports "beat"
    for id), "channel" (id the channel; volume pan echo echo_time
    feedback reverb low_pass), "listen" (bins smoothing), "audio"
    (text pause or resume), "render" and "render_end". Timers:
    "after" and "every" (seconds; reports "timer"), "cancel". The
    page: "set_text", "visible" and "enabled" (1 or 0), "remove",
    "text_area" (rows columns), "file_button", "cursor",
    "save_canvas", "download". mode says what a page connecting later
    is sent again: 0 kept, 1 the last of its kind and id, 2 like a
    sound, 3 nothing. *)
val command : string -> string -> string -> string -> int -> unit

(** Calls f each time the page reports kind for the element id: a
    timer's "timer", a beat's "beat", a text area's "change", a file
    button's "loaded", a rendering's "rendered". *)
val watch : string -> string -> (unit -> unit) -> unit

(** The kth number the page last reported under name: "clock" (the
    beat, the latency, whether sound runs), "beat" (a beat's step and
    time), "level", "band" and "wave" once listening, "rendered"
    (seconds taken, peak). 0.0 where there is none. *)
val report_number : string -> int -> float

(** The text the page last reported under name: "value." and an
    input's identifier for what it holds, "file" and "file.text" for
    a file loaded. Empty where there is none. *)
val report_text : string -> string

(** How many numbers the page last reported under name. *)
val report_count : string -> int

(** Calls f each time the page reports kind for the element id, with
    the text it last reported under name: a text area's "change" with
    "value." and its identifier, a file button's "loaded" with
    "file". *)
val watch_text : string -> string -> string -> (string -> unit) -> unit

(** Calls f each time the page reports kind for the element id, with
    the first number reported under kind as a whole number and the
    second: a beat's step and when it sounds. *)
val watch_step : string -> string -> (int -> float -> unit) -> unit

(** Calls f each time the page reports kind for the element id, with
    the first two numbers reported under kind: a rendering's seconds
    taken and its peak. *)
val watch_pair : string -> string -> (float -> float -> unit) -> unit

(** Shows the splash screen: the page dimmed, and a message asking
    the reader to click, since a browser plays no sound before the
    reader has clicked or pressed a key. The page waits there -- what
    the program draws next, its frames and its clock -- until the
    reader does. It is shown at most once, and not at all where the
    reader has already clicked. The first play_sample before a click
    shows it too; a program that plays sound only from callbacks
    calls it at the end of its main code. *)
val splash : unit -> unit

(** Sets what the splash screen says, "Click to Start" until it is
    set. An empty message turns the splash screen off. *)
val set_splash : string -> unit

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
val on_mouse : string -> (int -> int -> unit) -> unit

(** Calls pressed with the name of every key pressed while the page
    has the focus: a letter or digit as itself, and otherwise the
    browser's name for it, such as "ArrowLeft", "Enter" or " ". *)
val on_key : (string -> unit) -> unit

(** Calls released with the name of each key let go while the page
    has the focus. Leaving the page lets go of every key held. *)
val on_key_up : (string -> unit) -> unit

(** Whether the key named key is held down now. *)
val key_down : string -> bool

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
