CC		?= gcc
CFLAGS	?= -std=c++11
LFLAGS  ?= -lstdc++

BIN		?= bin
SRC 	?= src
HEAPS 	?= heaps

.PHONY: runtests clean tester generator

runtests: tester
		bash $(SRC)/runtests.sh

clean:
		rm -f generator tester

tester: $(SRC)/tester.cpp
		$(CC) $(CFLAGS) $(SRC)/tester.cpp $(LFLAGS) -o tester

generator: $(SRC)/generator.cpp
		$(CC) $(CFLAGS) $(SRC)/generator.cpp $(LFLAGS) -o generator
	

