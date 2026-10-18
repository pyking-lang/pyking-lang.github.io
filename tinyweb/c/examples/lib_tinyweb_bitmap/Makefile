# Made by `pyk compile -t c23`: `make` builds the program, `make run`
# runs it (`make run ARGS='a b'` passes it arguments), and `make clean`
# removes what `make` made. The next `pyk compile` replaces this folder.

CC ?= cc

all: program

program: tinyweb_external.c tinyweb.c program.c
	$(CC) -std=c23 -o program tinyweb_external.c tinyweb.c program.c -lm

run: all
	./program $(ARGS)

clean:
	rm -f program

.PHONY: all run clean
