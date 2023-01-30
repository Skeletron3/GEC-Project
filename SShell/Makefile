_CC = /usr/bin/cc
_CPP = /usr/bin/c++

.PHONY: clean

all: build_program_simpleshell

build_program_simpleshell: build build/sshell

build:
	mkdir -p $@

build/sshell: build/main.o
	$(_CPP) $^ -o $@ -Wall -Wextra -s -O3

build/main.o: src/main.cc
	$(_CPP) -c $< -o $@ -Wall -Wextra -s -O3

clean:
	rm -rf build