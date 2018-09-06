CC = gcc 
FLAGS = -Wall -g
INCLUDES = -lm

all: kaprekarDemo kaprekarTest kaprekarTestCmocka

kaprekarDemo: kaprekarUtils.o kaprekarDemo.c
	$(CC) $(FLAGS) $(INCLUDES) kaprekarDemo.c kaprekarUtils.o -o kaprekarDemo

kaprekarTest: kaprekarUtils.o kaprekarTest.c
	$(CC) $(FLAGS) $(INCLUDES) kaprekarTest.c kaprekarUtils.o -o kaprekarTest

kaprekarTestCmocka: kaprekarUtils.o kaprekarTestCmocka.c
	$(CC) $(FLAGS) $(INCLUDES) -l cmocka kaprekarTestCmocka.c kaprekarUtils.o -o kaprekarTestCmocka

kaprekarUtils.o: kaprekarUtils.c kaprekarUtils.h
	$(CC) $(FLAGS) $(INCLUDES) -c -o kaprekarUtils.o kaprekarUtils.c

clean:
	rm -f *.o *~ kaprekarDemo kaprekarTest kaprekarTestCmocka
