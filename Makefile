CC = g++
CFLAGS = -Wall -Wextra -std=c++17

all: main

main: main.o vigenere.o
	$(CC) $(CFLAGS) -o main main.o vigenere.o

main.o: main.cpp vigenere.h
	$(CC) $(CFLAGS) -c main.cpp

vigenere.o: vigenere.cpp vigenere.h
	$(CC) $(CFLAGS) -c vigenere.cpp

clean:
	rm -f main *.o