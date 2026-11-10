# Made by `pyk compile -t python12`: `make` builds the program, `make run`
# runs it (`make run ARGS='a b'` passes it arguments), and `make clean`
# removes what `make` made. The next `pyk compile` replaces this folder.

PYTHON ?= python3

all:

run: all
	$(PYTHON) program.py $(ARGS)

clean:
	@true

.PHONY: all run clean
