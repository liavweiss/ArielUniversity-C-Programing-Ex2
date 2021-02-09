CC=gcc
C_BANK=myBank.c
C_MAIN=main.c
FLAGS= -Wall -g

all: libmyBank.a main

main: main.o libmyBank.a
	$(CC) $(FLAGS) -o main main.o libmyBank.a

libmyBank.a: myBank.o main.o
	ar -rcs libmyBank.a main.o myBank.o

main.o:$(C_MAIN) myBank.h
	$(CC) $(FLAGS) -c $(C_MAIN)

mybank.o: $(C_BANK) myBank.h
	$(CC) $(FLAGS) -c $(C_BANK)

.PHONY: clean all

clean:
	rm -f *.o *.a