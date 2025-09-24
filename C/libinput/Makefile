CCARGS=-Wall -pedantic -Os -I./include
LDARGS=-lm -L./lib -linput

sources = $(wildcard *.c)
output = $(sources:.c=.out)

.PHONY: all clean distclean 

all: $(output)

clean:
	rm -f input/input.o

distclean: clean
	rm -f *.out
	rm -f lib/lib*.a

%.out : %.c lib/libinput.a include/input.h
	gcc -o $@ $< $(CCARGS) $(LDARGS) 

# Input Library
lib/libinput.a: input/input.c include/input.h
	mkdir -p lib
	gcc -c $< $(CCARGS) -o input/input.o
	ar cr $@ input/input.o
