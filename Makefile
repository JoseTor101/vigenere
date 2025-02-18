CC = g++
CFLAGS = -Wall -g

main: main.o vigenere.o
	$(CC) $(CFLAGS) -o main main.o vigenere.o

main.o: main.cpp vigenere.h
	$(CC) $(CFLAGS) -c main.cpp


vigenere.o: vigenere.cpp vigenere.h
	$(CC) $(CFLAGS) -c vigenere.cpp