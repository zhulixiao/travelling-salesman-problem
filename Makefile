CC=g++
CFLAGS=-I
make: nearest.o exhaustive.o randomNum.o
	$(CC) -o nearest nearest.cpp
	$(CC) -o exhaustive exhaustive.cpp
	$(CC) -o randomNum randomNum.cpp