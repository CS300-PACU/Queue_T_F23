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

 /****************************************************************************
	Function: 	 	success

	Description: print a success message

	Parameters:	szStr - the message to print

	Returned:	 	none
	****************************************************************************/
static void success (char* szStr) {
	printf ("SUCCESS: %s\n", szStr);
}

/****************************************************************************
 Function: 	 	failure

 Description: print a failure message

 Parameters:	szStr - the message to print

 Returned:	 	none
 ****************************************************************************/
static void failure (char* szStr) {
	printf ("FAILURE: %s\n", szStr);
}

/****************************************************************************
 Function: 	 	assert

 Description: if the expression is true, assert success; otherwise, assert
							failure

 Parameters:	szStr - the message to print

 Returned:	 	none
 ****************************************************************************/
static void assert (bool bExpression, char* pTrue, char* pFalse) {
	if (bExpression) {
		success (pTrue);
	}
	else {
		failure (pFalse);
	}
}

/****************************************************************************
 Function: 	 	main

 Description: test all the functionality of the list

 Parameters:	none
 Returned:	 	none
 ****************************************************************************/

int main () {
	Queue sTheQ;
	int dataValue;
	int i;
	const int MAX_ITEMS = 4;
	int MAX_Q_SIZE = 6;

	puts ("Program Start\n");

	queueCreate (&sTheQ, sizeof (int));
	success ("Q Create");
	queueDequeue (&sTheQ, &dataValue);

	assert (queueCount (&sTheQ) == 0, "queueCount is 0",
		"queueCount is not 0");

	assert (queueIsEmpty (&sTheQ), "queueIsEmpty", "!queueIsEmpty");


	for (i = 0; i < MAX_ITEMS; ++i) {
		queueEnqueue (&sTheQ, &i);
	}

	assert (MAX_ITEMS == queueCount (&sTheQ), "queueCount is correct",
		"queueCount is not correct");



	for (i = 0; i < MAX_ITEMS; ++i) {
		queueDequeue (&sTheQ, &dataValue);

		if (dataValue != i) {
			assert (dataValue == i, "", "DataValue 0-3 error");
		}
	}

	assert (queueCount (&sTheQ) == 0, "queueCount is 0",
		"queueCount is not 0");

	queueTerminate (&sTheQ);
	success ("Q Terminate");

	puts ("\nProgram End");

	return EXIT_SUCCESS;
}
