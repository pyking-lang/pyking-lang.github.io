# Made by `pyk compile -t ocaml5.5`: `make` builds the program, `make run`
# runs it (`make run ARGS='a b'` passes it arguments), and `make clean`
# removes what `make` made. The next `pyk compile` replaces this folder.

OCAMLOPT ?= ocamlopt

all: program

program: tinyweb_external.ml tinyweb.ml program.ml
	$(OCAMLOPT) -I +unix unix.cmxa -I . -o program tinyweb_external.ml tinyweb.mli tinyweb.ml program.ml

run: all
	./program $(ARGS)

clean:
	rm -f program *.cmi *.cmx *.o

.PHONY: all run clean
