/* tinyweb: graphics, widgets and sound on a web page the program
   serves itself, for C. Compile tinyweb.c with the program; it needs
   a POSIX system (sockets and select).

   Call tinyweb_web_init first. Once main has returned, the program
   keeps serving its page and calling the functions it handed over,
   until it is stopped. */

#ifndef TINYWEB_H
#define TINYWEB_H

/* A Bool is bool from c99 on, and int in c89, which has none. */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#include <stdbool.h>
#elif !defined(TINYWEB_BOOL)
#define TINYWEB_BOOL
typedef int bool;
#define true 1
#define false 0
#endif

/* Serves the program's page on port and prints its address, tinyweb:
   http://127.0.0.1:N/; port 0 picks any free port. Call it before
   anything else. With PYKING_TINYWEB_LOG set it does nothing. */
void tinyweb_web_init(int port);

/* A new canvas, width by height pixels, placed below what the page
   already shows. Answers the string that names it: "canvas", with a
   number added where something on the page has that name already. */
const char *tinyweb_canvas(int width, int height);

/* Fills the whole canvas c with color, a CSS color such as "#ff0000"
   or "red". */
void tinyweb_fill_canvas(const char *c, const char *color);

/* One shape on the canvas c. kind is "rect", "circle", "ellipse",
   "arc", "line", "lines", "curve", "bezier", "polygon", "path" or
   "erase", and numbers its numbers as words: x y width height radius
   for a rect, x y r for a circle, x y rx ry for an ellipse, x y r
   start end (radians) for an arc, x1 y1 x2 y2 for a line, x1 y1 x2
   y2 for each of many lines, x1 y1 cx cy x2 y2 for a curve, x1 y1 ax
   ay bx by x2 y2 for a bezier, x y x y ... for a polygon or a path,
   and x y width height for the rectangle erase makes transparent. It
   is filled with color and outlined with outline, width pixels
   thick, each unless it is "", at alpha from 0.0 to 1.0. A color may
   be a gradient: "linear-gradient(x1 y1 x2 y2); 0.0 red; 1.0 blue",
   "radial-gradient(x1 y1 r1 x2 y2 r2); ..." or "conic-gradient(x y
   angle); ...", each stop its place from 0.0 to 1.0 and a CSS color. */
void tinyweb_draw_shape(const char *c, const char *kind, const char *numbers, const char *color, const char *outline, double width, double alpha);

/* words written on the canvas c at (x, y): its left end there, or
   with align "center" or "right" its middle or right end, and its
   top there, or with baseline "middle", "alphabetic" or "bottom"
   that part of it. size pixels high, in font ("" for the page's
   own), bold where bold is true, filled with color and outlined with
   outline outline_width pixels thick, each unless it is "", at
   alpha. */
void tinyweb_draw_text(const char *c, double x, double y, const char *words, const char *color, int size, const char *font, const char *align, const char *baseline, bool bold, const char *outline, double outline_width, double alpha);

/* Changes what the next drawing on the canvas c is drawn with. kind
   "translate", "rotate" or "scale" take their numbers (x y, radians,
   sx sy) in numbers; "push" and "pop" save and restore the state;
   "reset" takes every transformation off; "shadow" takes a color in
   value ("" for none) and blur dx dy in numbers; "blend" takes
   "normal" or "add" in value; "line_style" takes how lines end and
   turn in value ("round round", "butt miter", ...) and the dash
   offset followed by the dash and gap lengths in numbers; "clip"
   keeps what is drawn after it inside a shape, its kind in value and
   its numbers as draw_shape takes them. fill_canvas starts the
   canvas afresh. */
void tinyweb_set_state(const char *c, const char *kind, const char *value, const char *numbers);

/* Asks the page how wide words is written size pixels high in font,
   bold where bold is true, and calls answer with the width in pixels
   once the page has said. */
void tinyweb_measure(const char *words, int size, const char *font, bool bold, void (*answer)(double));

/* Calls f with where the pointer is on the canvas c, in pixels from
   its top left corner, each time it goes down there (kind "press"),
   comes up ("release"), moves over it ("move") or moves with the
   button held ("drag"). */
void tinyweb_watch_pointer(const char *c, const char *kind, void (*f)(int, int));

/* Where the pointer was last seen on the canvas c: which "x" or "y"
   for its position, "down" for 1 while its button is held and 0
   otherwise. The canvas reports the pointer once watch_pointer has
   been called for it. */
int tinyweb_pointer(const char *c, const char *which);

/* Draws a loaded picture on the canvas c, its top left corner at (x,
   y), stretched to width by height, at alpha. One still loading is
   drawn once it has loaded, and what is drawn after it waits until
   then. */
void tinyweb_draw_image(const char *c, const char *picture, int x, int y, int width, int height, double alpha);

/* A picture width by height pixels the program builds, every pixel
   background to start with, as set_pixel takes a color, kept by the
   program: setting a pixel sends nothing. Answers the string that
   names it: "bitmap", with a number added where something on the
   page has that name already. */
const char *tinyweb_make_bitmap(int width, int height, int background);

/* Sets the pixel (x, y) of the bitmap b to color, red times 65536
   plus green times 256 plus blue. A pixel outside it is left alone. */
void tinyweb_set_pixel(const char *b, int x, int y, int color);

/* The color of the pixel (x, y) of the bitmap b, as set_pixel takes
   one; 0 outside it. */
int tinyweb_get_pixel(const char *b, int x, int y);

/* Sets every pixel of the bitmap b to color. */
void tinyweb_fill_bitmap(const char *b, int color);

/* Draws the bitmap b on the canvas c, its top left corner at (x, y),
   each pixel scale pixels across: sharp squares above 1.0. What
   changed since it was last drawn is sent to the page. */
void tinyweb_draw_bitmap(const char *c, const char *b, int x, int y, double scale);

/* Starts loading the picture name, looked for as a sample is, and
   answers the string that names it to draw_image. */
const char *tinyweb_load_image(const char *name);

/* A button showing title, placed below what the page already shows,
   which calls on_click each time it is pressed. Answers the string
   that names it: title, with a number added where something on the
   page has that name already. */
const char *tinyweb_make_button(const char *title, void (*on_click)(void));

/* A line of text, placed below what the page already shows. Answers
   the string that names it to set_label: text, with a number added
   where something on the page has that name already. */
const char *tinyweb_label(const char *text);

/* A box placed below what the page already shows, whose elements go
   side by side, wrapping where the page is too narrow. Answers the
   string that names it to inside: "row", with a number added where
   something on the page has that name already. */
const char *tinyweb_row(void);

/* A box whose elements go one below another, as the page's own do:
   inside a row, it stands beside the row's other elements. Answers
   the string that names it to inside. */
const char *tinyweb_column(void);

/* Makes every element made after it go into the row or column id,
   until outside or another inside. */
void tinyweb_inside(const char *id);

/* Makes every element made after it go on the page again, below what
   is there. */
void tinyweb_outside(void);

/* Replaces the text of the label id, or the title of the button id,
   with text. */
void tinyweb_set_label(const char *id, const char *text);

/* A slider from low to high, starting at value, placed below what
   the page already shows, which calls on_change with each new value
   it is moved to. Answers the string that names it: "slider", with a
   number added where something on the page has that name already. */
const char *tinyweb_make_slider(int low, int high, int value, void (*on_change)(int));

/* A checkbox showing title, ticked where checked is true, which
   calls on_change with whether it is ticked each time the reader
   changes it. Answers the string that names it. */
const char *tinyweb_make_checkbox(const char *title, bool checked, void (*on_change)(bool));

/* A radio button showing title in the group group: choosing one
   clears the others. The first of a group starts chosen unless one
   says chosen. Calls on_pick with title when the reader chooses it.
   Answers the string that names it. */
const char *tinyweb_make_radio(const char *group, const char *title, bool chosen, void (*on_pick)(const char *));

/* A dropdown of options, one per line, the one at position chosen
   chosen, which calls on_change with the position the reader
   chooses. Answers the string that names it. */
const char *tinyweb_make_choice(const char *options, int chosen, void (*on_change)(int));

/* A line to type text into, showing placeholder while empty, which
   calls on_enter with the text when Enter is pressed in it. Answers
   the string that names it. */
const char *tinyweb_make_text_input(const char *placeholder, void (*on_enter)(const char *));

/* A field for a whole number from low to high, starting at value,
   which calls on_change with each new number. Answers the string
   that names it. */
const char *tinyweb_make_number_input(int low, int high, int value, void (*on_change)(int));

/* Ticks or clears the checkbox id, or chooses the radio button id. */
void tinyweb_set_checked(const char *id, bool checked);

/* Moves the slider or number field id to value, or picks the
   dropdown choice at that position. */
void tinyweb_set_value(const char *id, int value);

/* Changes the page's look. With kind "theme", value names a theme:
   "light" (the default), "dark", "plain", "paper" or "retro". With
   kind "page", "button", "label", "slider" or "canvas", property of
   every element of that kind becomes value; with kind "element",
   only the element id's. property is one of background, color,
   border, radius, font, size, padding, gap, accent and width, and
   value is CSS, such as "#336699" or "12px". id is "" except for an
   element. */
void tinyweb_apply_style(const char *id, const char *kind, const char *property, const char *value);

/* Starts loading the sound file name and answers a string naming it
   to play_sample: name, with a number added where something on the
   page has that name already. The name is looked up beside where the
   program runs first, and then among the samples tinyweb ships in
   tinyweb_assets/: kick1.wav, snare1.wav, hihat1.wav and
   piano_c1.wav. */
const char *tinyweb_load_sample(const char *name);

/* A new element's identifier: name, with a number added where
   something on the page has that name already. Sends nothing; what
   command makes takes it. */
const char *tinyweb_fresh_id(const char *name);

/* Sends the page one command, by kind, with an element id, a text
   and its numbers as words. Sound: "play" (id the sample; numbers at
   volume rate pan channel reverse), "start" (id a new voice, text
   the sample, numbers as play's then loop), "stop" (at), "fade"
   (volume over), "stop_all", "tone" (text the wave; frequency at
   duration volume pan channel), "master" (volume), "tempo" (bpm),
   "swing" (amount), "beat" (steps; reports "beat" for id), "channel"
   (id the channel; volume pan echo echo_time feedback reverb
   low_pass), "listen" (bins smoothing), "audio" (text pause or
   resume), "render" and "render_end". Timers: "after" and "every"
   (seconds; reports "timer"), "cancel". The page: "set_text",
   "visible" and "enabled" (1 or 0), "remove", "text_area" (rows
   columns), "file_button", "cursor", "save_canvas", "download". mode
   says what a page connecting later is sent again: 0 kept, 1 the
   last of its kind and id, 2 like a sound, 3 nothing. */
void tinyweb_command(const char *kind, const char *id, const char *text, const char *numbers, int mode);

/* Calls f each time the page reports kind for the element id: a
   timer's "timer", a beat's "beat", a text area's "change", a file
   button's "loaded", a rendering's "rendered". */
void tinyweb_watch(const char *id, const char *kind, void (*f)(void));

/* The kth number the page last reported under name: "clock" (the
   beat, the latency, whether sound runs), "beat" (a beat's step and
   time), "level", "band" and "wave" once listening, "rendered"
   (seconds taken, peak). 0.0 where there is none. */
double tinyweb_report_number(const char *name, int k);

/* The text the page last reported under name: "value." and an
   input's identifier for what it holds, "file" and "file.text" for a
   file loaded. Empty where there is none. */
const char *tinyweb_report_text(const char *name);

/* How many numbers the page last reported under name. */
int tinyweb_report_count(const char *name);

/* Calls f each time the page reports kind for the element id, with
   the text it last reported under name: a text area's "change" with
   "value." and its identifier, a file button's "loaded" with "file". */
void tinyweb_watch_text(const char *id, const char *kind, const char *name, void (*f)(const char *));

/* Calls f each time the page reports kind for the element id, with
   the first number reported under kind as a whole number and the
   second: a beat's step and when it sounds. */
void tinyweb_watch_step(const char *id, const char *kind, void (*f)(int, double));

/* Calls f each time the page reports kind for the element id, with
   the first two numbers reported under kind: a rendering's seconds
   taken and its peak. */
void tinyweb_watch_pair(const char *id, const char *kind, void (*f)(double, double));

/* Shows the splash screen: the page dimmed, and a message asking the
   reader to click, since a browser plays no sound before the reader
   has clicked or pressed a key. The page waits there -- what the
   program draws next, its frames and its clock -- until the reader
   does. It is shown at most once, and not at all where the reader
   has already clicked. The first play_sample before a click shows it
   too; a program that plays sound only from callbacks calls it at
   the end of its main code. */
void tinyweb_splash(void);

/* Sets what the splash screen says, "Click to Start" until it is
   set. An empty message turns the splash screen off. */
void tinyweb_set_splash(const char *message);

/* The page's clock, in seconds, as the page last reported it: inside
   an on_frame callback, the time the frame is for. It is the audio
   clock once sound has started, so a time read here is a time
   play_sample can be given. */
double tinyweb_time(void);

/* Waits until the page's audio clock is time seconds after the last
   sdelay ended (after now, for the first), so a loop of them does
   not drift; one that has fallen behind goes on at once. The page's
   events are delivered while it waits, and a sound played next with
   no time of its own starts exactly at the end. */
void tinyweb_sdelay(double time);

/* Calls draw before each frame the page shows, with the time the
   frame is for. */
void tinyweb_on_frame(void (*draw)(double));

/* Calls click with the position, in pixels from the top left corner,
   of every click on the canvas c. */
void tinyweb_on_mouse(const char *c, void (*click)(int, int));

/* Calls pressed with the name of every key pressed while the page
   has the focus: a letter or digit as itself, and otherwise the
   browser's name for it, such as "ArrowLeft", "Enter" or " ". */
void tinyweb_on_key(void (*pressed)(const char *));

/* Calls released with the name of each key let go while the page has
   the focus. Leaving the page lets go of every key held. */
void tinyweb_on_key_up(void (*released)(const char *));

/* Whether the key named key is held down now. */
bool tinyweb_key_down(const char *key);

#endif
