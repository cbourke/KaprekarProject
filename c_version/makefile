CC = gcc
FLAGS = -Wall -g
INCLUDES = -lm
CMOCKA = -l cmocka

all: kaprekarDemo kaprekarTest kaprekarTestCmocka

kaprekarDemo: kaprekarUtils.o kaprekarDemo.c
	$(CC) $(FLAGS) kaprekarDemo.c kaprekarUtils.o $(INCLUDES) -o kaprekarDemo

kaprekarTest: kaprekarUtils.o kaprekarTest.c
	$(CC) $(FLAGS) kaprekarTest.c kaprekarUtils.o $(INCLUDES) -o kaprekarTest

kaprekarTestCmocka: kaprekarUtils.o kaprekarTestCmocka.c
	$(CC) $(FLAGS) kaprekarTestCmocka.c kaprekarUtils.o $(INCLUDES) -o kaprekarTestCmocka $(CMOCKA)

kaprekarUtils.o: kaprekarUtils.c kaprekarUtils.h
	$(CC) $(FLAGS) -c kaprekarUtils.c $(INCLUDES) -o kaprekarUtils.o

clean:
	rm -f *.o *~ kaprekarDemo kaprekarTest kaprekarTestCmocka
