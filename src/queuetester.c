/****************************************************************************
 File name:  	qdriver1.c
 Author:     	chadd williams
 Date:       	Oct 17, 2019
 Class:			 	CS 300
 Assignment:	Queue
 Purpose:			Basic Q functionality
 ****************************************************************************/

#include "../include/queue.h"
#include "../include/driverUtil.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define LOW 0
#define HIGH 1

typedef struct TempRecord
{
	int aTemps[2]; // LOW, HIGH
	int month;
	int day;
	int year;
} TempRecord;

/****************************************************************************
 Function: 	 	main

 Description: test all the functionality of the list

 Parameters:	none
 Returned:	 	none
 ****************************************************************************/

int main () {
	Queue sTheQ;
	int dataValue = -1;
	int i;
	const int MAX_ITEMS = 4;
	
	puts ("Program Start\n");

	// create a queue for ints
	queueCreate (&sTheQ, sizeof (int));

	assert (queueCount (&sTheQ) == 0, "after create queueCount is 0");

	// TODO: Validate that the queue is empty



	for (i = 0; i < MAX_ITEMS; ++i) {
		queueEnqueue (&sTheQ, &i);

		// TODO: Validate the Enqueue worked


	}

	// TODO: Validate that the queue contains MAX_ITEMS



	queueDequeue(&sTheQ, &dataValue);
	// TODO: Validate that dataValue contains the correct value


	// TODO: Validate the remaining queue functions


	queueTerminate (&sTheQ);
	assert (queueCount (&sTheQ) == 0, "after terminate queueCount is 0");


	// TODO: create a separate queue for TempRecords
	// test all of the queue functions.

	puts ("\nProgram End");

	return EXIT_SUCCESS;
}
