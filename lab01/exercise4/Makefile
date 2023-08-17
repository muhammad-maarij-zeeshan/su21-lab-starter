CC=gcc
CFLAGS=-Wall -std=c99 -g

run: all
	./exec	

all: exec

exec: ll_cycle.o test_ll_cycle.o
	$(CC) -o exec ll_cycle.o test_ll_cycle.o

ll_cycle.o: ll_cycle.c ll_cycle.h
	$(CC) $(CFLAGS) -c ll_cycle.c

test_ll_cycle.o: test_ll_cycle.c ll_cycle.h
	$(CC) $(CFLAGS) -c test_ll_cycle.c

clean:
	rm -rf exec ll_cycle.o test_ll_cycle.o