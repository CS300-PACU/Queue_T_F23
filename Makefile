#############################################################################
# File name:  Makefile
# Author:     chadd williams
# Date:       Sept 1, 2021
# Class:      CS360
# Assignment: 
# Purpose:    
#############################################################################


ENSCRIPT_FLAGS=-C -T 2 -p - -M Letter -Ecpp --color -fCourier8
VALGRIND_FLAGS=-v --leak-check=yes --track-origins=yes --leak-check=full --show-leak-kinds=all 

#compiler=clang++
compiler=gcc
	

TARGETS=bin/qdriver1 bin/qMemTest bin/queuedriver

all: ${TARGETS}


bin/qdriver1: bin/queue.o bin/qdriver1.o
	gcc -o bin/qdriver1 -g -Wall bin/qdriver1.o bin/queue.o

bin/qdriver1.o: src/qdriver1.c include/queue.h 
	gcc -o bin/qdriver1.o src/qdriver1.c -c -g -Wall


bin/queuedriver: bin/queue.o bin/queuedriver.o
	gcc -o bin/queuedriver -g -Wall bin/queuedriver.o bin/queue.o

bin/queuedriver.o: src/queuedriver.c include/queue.h 
	gcc -o bin/queuedriver.o src/queuedriver.c -c -g -Wall

bin/qMemTest: bin/queue.o bin/qMemTest.o 
	gcc -o bin/qMemTest -g -Wall bin/qMemTest.o bin/queue.o

bin/qMemTest.o: src/qMemTest.c include/queue.h
	gcc -o bin/qMemTest.o src/qMemTest.c -c -g -Wall

bin/queue.o: src/queue.c include/queue.h
	gcc -o bin/queue.o src/queue.c -c -g -Wall

valgrind1: bin/qdriver1
	valgrind ${VALGRIND_FLAGS} bin/qdriver1

valgrindMem: bin/qMemTest
	valgrind ${VALGRIND_FLAGS} bin/qMemTest

valgrindDriver: bin/queuedriver
	valgrind ${VALGRIND_FLAGS} bin/queuedriver data/input.txt
 
clean:
	rm -rf ${TARGETS} bin/*.o bin/main.dSYM bin/*.pdf
