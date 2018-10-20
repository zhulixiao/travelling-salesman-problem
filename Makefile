CC=g++
CFLAGS=-I
make: nearest.o exhaustive.o randomNum.o ExhaustiveUpdate.o
	$(CC) -o nearest nearest.cpp
	$(CC) -o exhaustive exhaustive.cpp
	$(CC) -o randomNum randomNum.cpp
	$(CC) -o ExhaustiveUpdate ExhaustiveUpdate.cpp