CC=gcc
CFLAGS=-Wall -std=c99 -g

run: all
	./exec	

all: exec

exec: linked_list.o test_linked_list.o
	$(CC) -o exec linked_list.o test_linked_list.o

linked_list.o: linked_list.c linked_list.h
	$(CC) $(CFLAGS) -c linked_list.c

test_linked_list.o: test_linked_list.c linked_list.h
	$(CC) $(CFLAGS) -c test_linked_list.c

clean:
	rm -rf exec linked_list.o test_linked_list.o