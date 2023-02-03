.PHONY: clean install uninstall

all: build build/ember 

include Makefile.cfg
include Make/pkg.deb

build:
	mkdir -p build

build/ember: build/Main.o build/libEmberLexer.so build/libEmberCore.so
	$(_CPP) $(_GLOBAL_CPP_FLAGS) build/Main.o -Lbuild/ -lEmberLexer -lEmberCore -o $@

build/libEmberCore.so: build/Data.o build/ColourMod.o
	$(_CPP) -shared $(_GLOBAL_CPP_FLAGS) $^ -o $@

build/libEmberLexer.so: build/Lexer.o
	$(_CPP) -shared $(_GLOBAL_CPP_FLAGS) $< -o $@

build/Main.o: src/Main.cc Makefile.cfg
	$(_CPP) -c $(_GLOBAL_CPP_FLAGS) $< -o $@

build/Lexer.o: src/Lexer.cc Makefile.cfg
	$(_CPP) -c $(_GLOBAL_CPP_FLAGS) $< -o $@

build/Data.o: src/Data.cc Makefile.cfg
	$(_CPP) -c $(_GLOBAL_CPP_FLAGS) $< -o $@

build/ColourMod.o: src/ColourMod.cc Makefile.cfg
	$(_CPP) -c $(_GLOBAL_CPP_FLAGS) $< -o $@

clean:
	-rm -rf build

clean.complete:
	-rm -rf build
	-rm Makefile
	-rm Makefile.cfg

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

pkg: build build/pkg

build/pkg: $(_LIBS_FULL) $(_BINS_FULL)
	mkdir -p build/pkg
	mkdir -p build/pkg/bin
	mkdir -p build/pkg/lib

	for FILE in $(_LIBS); do cp build/$$FILE build/pkg/lib/$$FILE; done
	for FILE in $(_BINS); do cp build/$$FILE build/pkg/bin/$$FILE; done

exe: build build/ember.bin
	
build/ember.bin: $(_OBJECTS_FULL)
	$(_CPP) $^ -o $@

exe.static: build build/ember.static.bin

build/ember.static.bin: $(_OBJECTS_FULL)
	$(_CPP) -static $^ -o $@

# DANGER ZONE LEAVE DO NOT REMOVE
