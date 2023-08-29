/**************************************************************************
 File name:		  queue.c
 Author:        
 Date:
 Class:         CS300
 Assignment:    queue
 Purpose:       This file defines the functions for the queue ADT
 *************************************************************************/

#include "../include/queue.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


/**************************************************************************
 Function: 	 	processError - DO NOT EDIT


 Description: Print the filename and line number of an error

 Parameters:	szFile - filename
              line - the line number

 Returned:	 	None
 *************************************************************************/
void processError(const char* szFile, const int line)
{
  fprintf(stderr, "ERROR: %s: %d\n", szFile, line);
  fflush(NULL);
  exit(EXIT_FAILURE);
}

/**************************************************************************
*										Allocation and Deallocation
**************************************************************************/
void queueCreate (QueuePtr psQueue, size_t itemSize)
{

}


void queueTerminate (QueuePtr psQueue)
{

}

/**************************************************************************
*									Checking number of elements in queue
**************************************************************************/
size_t queueCount (const QueuePtr psQueue)
{
	size_t count = 0;

	return count;
}

bool queueIsEmpty (const QueuePtr psQueue)
{
	return false;
}

bool queueIsFull (const QueuePtr psQueue)
{
	return false;
}

size_t queueCapacity(const QueuePtr psQueue)
{
	return Q_SIZE;
}
 
/**************************************************************************
*									Inserting and retrieving values
**************************************************************************/
void queueEnqueue (QueuePtr psQueue, const void *pBuffer)
{

}

// requires: psQueue is not full
// results: Insert the element into the FIFO queue.

void *queueDequeue (QueuePtr psQueue, void *pBuffer)
{
	return NULL;
}
// requires: psQueue is not empty
// results: Remove the element from the front of a non-empty queue

/**************************************************************************
*													Peek Operations
**************************************************************************/
void *queuePeek (QueuePtr psQueue, void *pBuffer)
{
	return NULL;
}
