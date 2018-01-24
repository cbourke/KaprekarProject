CC = gcc -lm -Wall

all: kaprekarDemo kaprekarTest

kaprekarDemo: kaprekarUtils.o kaprekarDemo.c
	$(CC) kaprekarDemo.c kaprekarUtils.o -o kaprekarDemo

kaprekarTest: kaprekarUtils.o kaprekarTest.c
	$(CC) kaprekarTest.c kaprekarUtils.o -o kaprekarTest

kaprekarUtils.o: kaprekarUtils.c kaprekarUtils.h
	$(CC) -c -o kaprekarUtils.o kaprekarUtils.c

clean:
	rm -f *.o *~ kaprekarDemo kaprekarTest