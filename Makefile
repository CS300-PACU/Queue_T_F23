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
	
TARGETS=bin/queuetester

all: clean_objects ${TARGETS}

bin/queuetester: bin/queue.o bin/queuetester.o 
	gcc -o bin/queuetester -g -Wall bin/queuetester.o bin/queue.o -lm

bin/queuetester.o: src/queuetester.c include/queue.h
	gcc -o bin/queuetester.o src/queuetester.c -c -g -Wall

bin/queue.o: src/queue.c include/queue.h
	gcc -o bin/queue.o src/queue.c -c -g -Wall

valgrind: all
	valgrind ${VALGRIND_FLAGS} bin/queuetester
	
printAll:
	enscript ${ENSCRIPT_FLAGS} -Emakefile  Makefile  | ps2pdf - bin/Makefile.pdf
	enscript ${ENSCRIPT_FLAGS} -Ec src/queue.c  | ps2pdf - bin/queue.pdf
	enscript ${ENSCRIPT_FLAGS} -Ec src/queuetester.c  | ps2pdf - bin/queuetester.pdf
	pdfunite bin/queue.pdf bin/queuetester.pdf bin/Makefile.pdf bin/${USER}_queue.pdf
	@echo
	@echo File produced: bin/${USER}_queue.pdf
	@echo
	@ls -l bin/${USER}_queue.pdf
	@echo

clean_objects:
	rm -f ${TARGETS} bin/*.o

clean_pdfs:
	rm -f bin/*.pdf

clean: clean_objects clean_pdfs
