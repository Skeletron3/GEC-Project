_CC = /usr/bin/cc

.PHONY: clean

all: build_program_cls

build_program_cls: build/cls build/cls/cls

build/cls:
	mkdir -p $@

build/cls/cls: build/cls/main.o
	$(_CC) $^ -o $@ -Wall -Wextra -s -O3

build/cls/main.o: src/cls/main.c
	$(_CC) -c $< -o $@ -Wall -Wextra -s -O3