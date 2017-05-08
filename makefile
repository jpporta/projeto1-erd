### Makefile ###

all: prog run clean rmpoper

prog: main.o lista.o matriz.o
	gcc -Wall -o prog main.o lista.o matriz.o -lm

matriz.o: matriz.c
	gcc -c matriz.c

lista.o: lista.c
	gcc -c lista.c

main.o: main.c
	gcc -c main.c

clean:
	rm -rf  *.o

rmpoper: clean
	rm -rf prog

run: prog clean
	./prog <in.txt #>out.txt
