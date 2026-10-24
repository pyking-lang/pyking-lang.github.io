# Made by `pyk compile -t ocaml4.14`: `make` builds the program, `make run`
# runs it (`make run ARGS='a b'` passes it arguments), and `make clean`
# removes what `make` made. The next `pyk compile` replaces this folder.

OCAMLOPT ?= ocamlopt

all: program

program: math_external.ml math.ml text_external.ml text.ml tinyweb_external.ml tinyweb.ml program.ml
	$(OCAMLOPT) -I +unix unix.cmxa -I . -o program math_external.ml math.mli math.ml text_external.ml text.mli text.ml tinyweb_external.ml tinyweb.mli tinyweb.ml program.ml

run: all
	./program $(ARGS)

clean:
	rm -f program *.cmi *.cmx *.o

.PHONY: all run clean
