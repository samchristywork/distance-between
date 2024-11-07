CC=gcc
CFLAGS=-Wall -Wextra -pedantic -g
LIBS=-lm

all: build/main

build/%.o: src/%.c
	mkdir -p build
	$(CC) -c $(CFLAGS) $< -o $@ $(LIBS)

build/main: build/args.o build/haversine.o build/main.o
	mkdir -p build
	${CC} $? ${LIBS} -o $@

build/test: build/args.o build/haversine.o build/test.o
	mkdir -p build
	${CC} $? ${LIBS} -o $@

.PHONY: test
test: build/test
	./build/test

.PHONY: run
run: build/main
	./build/main

.PHONY: debug
debug: clean build/main
	gdb ./build/main

.PHONY: watch
watch:
	ls src/*.c | entr make run

.PHONY: clean
clean:
	rm -rf build
