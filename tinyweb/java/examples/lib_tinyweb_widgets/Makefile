# Made by `pyk compile -t java21`: `make` builds the program, `make run`
# runs it (`make run ARGS='a b'` passes it arguments), and `make clean`
# removes what `make` made. The next `pyk compile` replaces this folder.

JAVAC ?= javac
JAVA ?= java

all: Program.class

Program.class: TinywebExternal.java Tinyweb.java Program.java
	$(JAVAC) --release 21 -d . TinywebExternal.java Tinyweb.java PykRuntime.java Program.java

run: all
	$(JAVA) -cp . Program $(ARGS)

clean:
	rm -f *.class

.PHONY: all run clean
