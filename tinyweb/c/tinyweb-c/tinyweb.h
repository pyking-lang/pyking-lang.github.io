/* tinyweb: graphics, widgets and sound on a web page the program
   serves itself, for C. Compile tinyweb.c with the program; it needs
   a POSIX system (sockets and select).

   Call tinyweb_web_init first. Once main has returned, the program
   keeps serving its page and calling the functions it handed over,
   until it is stopped. */

#ifndef TINYWEB_H
#define TINYWEB_H

/* Serves the program's page on port and prints its address, tinyweb:
   http://127.0.0.1:N/; port 0 picks any free port. Call it before
   anything else. With PYKING_TINYWEB_LOG set it does nothing. */
void tinyweb_web_init(int port);

/* A new canvas, width by height pixels, placed below what the page
   already shows. Answers the number that names it. */
int tinyweb_canvas(int width, int height);

/* Fills the whole canvas c with color, a CSS color such as "#ff0000"
   or "red". */
void tinyweb_fill_canvas(int c, const char *color);

/* A filled circle on the canvas c, centred at (x, y). */
void tinyweb_draw_circle(int c, int x, int y, int radius, const char *color);

/* A filled rectangle on the canvas c, with its top left corner at
   (x, y). */
void tinyweb_draw_rect(int c, int x, int y, int width, int height, const char *color);

/* A straight line on the canvas c, from (x1, y1) to (x2, y2), width
   pixels wide. */
void tinyweb_draw_line(int c, int x1, int y1, int x2, int y2, const char *color, int width);

/* words written on the canvas c, with the top left corner of the
   text at (x, y), size pixels high. */
void tinyweb_draw_text(int c, int x, int y, const char *words, const char *color, int size);

/* A button showing title, placed below what the page already shows,
   which calls on_click each time it is pressed. Answers the number
   that names it. */
int tinyweb_make_button(const char *title, void (*on_click)(void));

/* A line of text, placed below what the page already shows. Answers
   the number that names it to set_label. */
int tinyweb_label(const char *text);

/* Replaces the text of the label id with text. */
void tinyweb_set_label(int id, const char *text);

/* A slider from low to high, starting at value, placed below what
   the page already shows, which calls on_change with each new value
   it is moved to. Answers the number that names it. */
int tinyweb_make_slider(int low, int high, int value, void (*on_change)(int));

/* Changes the page's look. With kind "theme", value names a theme:
   "light" (the default), "dark", "plain", "paper" or "retro". With
   kind "page", "button", "label", "slider" or "canvas", property of
   every element of that kind becomes value; with kind "element",
   only the element id's. property is one of background, color,
   border, radius, font, size, padding, gap, accent and width, and
   value is CSS, such as "#336699" or "12px". id is 0 except for an
   element. */
void tinyweb_apply_style(int id, const char *kind, const char *property, const char *value);

/* Starts loading the sound file name and answers a number naming it
   to play_sample. The name is looked up beside where the program
   runs first, and then among the samples tinyweb ships in
   tinyweb_assets/: kick1.wav, snare1.wav, hihat1.wav and
   piano_c1.wav. */
int tinyweb_load_sample(const char *name);

/* Plays the sample sample: at the time at on the page's clock, or
   now if that has passed; volume times as loud, and rate times as
   fast, which raises its pitch as much. */
void tinyweb_play_sample(int sample, double at, double volume, double rate);

/* The page's clock, in seconds, as the page last reported it: inside
   an on_frame callback, the time the frame is for. It is the audio
   clock once sound has started, so a time read here is a time
   play_sample can be given. */
double tinyweb_time(void);

/* Calls draw before each frame the page shows, with the time the
   frame is for. */
void tinyweb_on_frame(void (*draw)(double));

/* Calls click with the position, in pixels from the top left corner,
   of every click on the canvas c. */
void tinyweb_on_mouse(int c, void (*click)(int, int));

/* Calls pressed with the name of every key pressed while the page
   has the focus: a letter or digit as itself, and otherwise the
   browser's name for it, such as "ArrowLeft", "Enter" or " ". */
void tinyweb_on_key(void (*pressed)(const char *));

#endif
