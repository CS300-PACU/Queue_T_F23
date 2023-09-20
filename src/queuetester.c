/****************************************************************************
 File name:  	qdriver1.c
 Author:     	chadd williams
 Date:       	Oct 17, 2019
 Class:			 	CS 300
 Assignment:	Queue
 Purpose:			Basic Q functionality
 ****************************************************************************/

#include "../include/queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct TempRecord
{
	double temp;
	int month;
	int day;
	int year;
} TempRecord;

#define assert(cond, trueMsg, falseMsg)   checkAssert(cond, trueMsg, falseMsg, __FILE__, __LINE__)


 /****************************************************************************
	Function: 	 	success

	Description: print a success message

	Parameters:	szStr - the message to print

	Returned:	 	none
	****************************************************************************/
static void success (char* szStr) {
	printf ("SUCCESS: %s", szStr);
}

/****************************************************************************
 Function: 	 	failure

 Description: print a failure message

 Parameters:	szStr - the message to print

 Returned:	 	none
 ****************************************************************************/
static void failure (char* szStr) {
	printf ("FAILURE: %s", szStr);
}

/****************************************************************************
 Function: 	 	assert

 Description: if the expression is true, assert success; otherwise, assert
							failure

 Parameters:	szStr - the message to print

 Returned:	 	none
 ****************************************************************************/
static void checkAssert (bool bExpression, char* pTrue, char* pFalse, char *szFile, int line) {
	if (bExpression) {
		success (pTrue);
	}
	else {
		failure (pFalse);
	}
	printf(" - %s:%d\n", szFile, line);
}

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


	success ("Q Create");

	assert (queueCount (&sTheQ) == 0, "queueCount is 0",
		"queueCount is not 0");

	// TODO: Validate that the queue is empty


	
	// TODO: create a separate queue for TempRecords
	

	for (i = 0; i < MAX_ITEMS; ++i) {
		queueEnqueue (&sTheQ, &i);

		// TODO: Validate the Enqueue worked


	}

	// TODO: Validate that the queue contains MAX_ITEMS



	queueDequeue(&sTheQ, &dataValue);
	// TODO: Validate that dataValue contains the correct value




	// TODO: Validate the remaining queue functions



	queueTerminate (&sTheQ);
	success ("Q Terminate");

	puts ("\nProgram End");

	return EXIT_SUCCESS;
}
