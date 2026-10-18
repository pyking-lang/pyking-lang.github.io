# Made by `pyk compile -t node24`: `make` builds the program, `make run`
# runs it (`make run ARGS='a b'` passes it arguments), and `make clean`
# removes what `make` made. The next `pyk compile` replaces this folder.

NODE ?= node

all:

run: all
	$(NODE) program.js $(ARGS)

clean:
	@true

.PHONY: all run clean
