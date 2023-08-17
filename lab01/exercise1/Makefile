CC=gcc
CFLAGS=-Wall -std=c99 -g

run: all
	./exec	

all: exec

exec: ex1.o test_ex1.o
	$(CC) -o exec ex1.o test_ex1.o

ex1.o: ex1.c ex1.h
	$(CC) $(CFLAGS) -c ex1.c

test_ex1.o: test_ex1.c ex1.h
	$(CC) $(CFLAGS) -c test_ex1.c

clean:
	rm -rf exec ex1.o test_ex1.o