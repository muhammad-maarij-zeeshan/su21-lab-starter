CC=gcc
CFLAGS=-Wall -std=c99 -g

run: all
	./exec	

all: exec

exec: pwd_checker.o test_pwd_checker.o
	$(CC) -o exec pwd_checker.o test_pwd_checker.o

pwd_checker.o: pwd_checker.c pwd_checker.h
	$(CC) $(CFLAGS) -c pwd_checker.c

test_pwd_checker.o: test_pwd_checker.c pwd_checker.h
	$(CC) $(CFLAGS) -c test_pwd_checker.c

clean:
	rm -rf exec pwd_checker.o test_pwd_checker.o