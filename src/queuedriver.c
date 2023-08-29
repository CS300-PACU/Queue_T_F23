/****************************************************************************
 File name:  	queuedriver.c
 Author:     	chadd williams
 Date:       	June 23, 2023
 Class:			 	CS 300
 Assignment:	Queue
 Purpose:			Basic Q functionality
 ****************************************************************************/

#include "../include/queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

 /****************************************************************************
	Function: 	 	addItem

	Description: Add an item to the queue

	Parameters:	pTheQ - the queue
							 dataValue - the int to add

	Returned:	 	none
	****************************************************************************/
void addItem (Queue* pTheQ, int dataValue) {
}

/****************************************************************************
 Function: 	 	printItems

 Description: Print and remove items from the Queue

 Parameters:	pTheQ - the queue
							count - the number of items to remove

 Returned:	 	none
 ****************************************************************************/
void printItems (Queue* pTheQ, int count) {
	size_t originalSize;
	int dataValue;

	int index;


}

/****************************************************************************
 Function: 	 	main

 Description: test all the functionality of the queue

 Parameters:	none
 Returned:	 	none
 ****************************************************************************/

int main (int argc, char* argv[]) {
	Queue sTheQ;
	int dataValue;
	int count;
	char action = 'X';
	const char QUIT = 'Q';
	const char STORE = 'S';
	const char PRINT = 'P';

	FILE* pFile;

	queueCreate (&sTheQ, sizeof (int));
	pFile = fopen (argv[1], "r");

	while (QUIT != action) {
		fscanf (pFile, "%c", &action);

		if (STORE == action) {
			fscanf (pFile, "%d", &dataValue);
			addItem (&sTheQ, dataValue);
		}
		else if (PRINT == action) {
			fscanf (pFile, "%d", &count);
			printItems (&sTheQ, count);
		}
	}

	fclose (pFile);

	queueTerminate (&sTheQ);

	return EXIT_SUCCESS;
}
