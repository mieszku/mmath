all: mmath
clean:
	-rm mmath

run: mmath
	./mmath

mmath: main.c mmath.c
	gcc main.c mmath.c -lm -std=gnu99 -o mmath -MMD -Wall

-include mmath.d
