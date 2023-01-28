.PHONY: clean install uninstall

all: build/ build/ember 

Makefile.cfg:
	$(error Makefile.cfg not setup please run ./configure)

include Makefile.cfg
include Make/pkg.deb

build/:
	mkdir -p build

build/ember: build/Main.o build/libEmberLexer.so build/libEmberCompiler.so build/libEmberCore.so
	$(_CPP) $(_GLOBAL_CPP_FLAGS) build/Main.o -Lbuild/ -lEmberLexer -lEmberCompiler -lEmberCore -o $@

build/libEmberCore.so: build/Data.o build/ColourMod.o
	$(_CPP) -shared $(_GLOBAL_CPP_FLAGS) $^ -o $@

build/libEmberCompiler.so: build/Compiler.o
	$(_CPP) -shared $(_GLOBAL_CPP_FLAGS) $< -o $@

build/libEmberLexer.so: build/Lexer.o
	$(_CPP) -shared $(_GLOBAL_CPP_FLAGS) $< -o $@

build/Main.o: src/Main.cc src/Includes/Main.hh
	$(_CPP) -c $(_GLOBAL_CPP_FLAGS) $< -o $@

build/Lexer.o: src/Lexer.cc src/Includes/Lexer.hh
	$(_CPP) -c $(_GLOBAL_CPP_FLAGS) $< -o $@

build/Data.o: src/Data.cc src/Includes/Data.hh
	$(_CPP) -c $(_GLOBAL_CPP_FLAGS) $< -o $@

build/Compiler.o: src/Compiler.cc src/Includes/Compiler.hh
	$(_CPP) -c $(_GLOBAL_CPP_FLAGS) $< -o $@

build/ColourMod.o: src/ColourMod.cc src/Includes/ColourMod.hh
	$(_CPP) -c $(_GLOBAL_CPP_FLAGS) $<* -o $@

clean:
	-rm -rf build/*

install: $(PREFIX)

$(PREFIX): $(_LIBS_FULL) $(_BINS_FULL)
	mkdir -p $@
	mkdir -p $@/lib
	mkdir -p $@/bin

	for FILE in $(_LIBS); do cp build/$$FILE $(PREFIX)/lib/$$FILE; done
	for FILE in $(_BINS); do cp build/$$FILE $(PREFIX)/bin/$$FILE; done

uninstall:
	-for FILE in $(_LIBS); do rm $(PREFIX)/lib/$$FILE; done 
	-for FILE in $(_BINS); do rm $(PREFIX)/bin/$$FILE; done

pkg.src: build/pkg.src

build/pkg.src:
	mkdir -p $@
	mkdir -p $@/src

	cp -r src $@
	cp -r info $@
	cp -r info $@
	cp -r examples $@
	cp -r Make $@

	cp Makefile $@
	cp LICENCE.txt $@
	cp readme.md $@
	cp SECURITY.md $@
	cp configure $@
	cp CONTRIBUTING.md $@

pkg: build/pkg

build/pkg: $(_LIBS_FULL) $(_BINS_FULL)
	mkdir -p build/pkg
	mkdir -p build/pkg/bin
	mkdir -p build/pkg/lib

	for FILE in $(_LIBS); do cp build/$$FILE build/pkg/lib/$$FILE; done
	for FILE in $(_BINS); do cp build/$$FILE build/pkg/bin/$$FILE; done

