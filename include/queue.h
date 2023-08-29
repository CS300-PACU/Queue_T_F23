/**************************************************************************
 File name:		  queue.h
 Author:        CS, Pacific University
 Date:
 Class:         CS300
 Assignment:    Queue
 Purpose:       This file defines the constants, data structures, and
                function prototypes for implementing a queue data
                structure
 *************************************************************************/


#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdbool.h>
#include <stdlib.h> // size_t

//*************************************************************************
// Error reporting functions
//*************************************************************************
extern void processError(const char* szFile, const int line);
// helper function to report errors

// macro to report error
#define reportError   processError(__FILE__, __LINE__)

#define Q_SIZE  100000

//*************************************************************************
// User-defined types
//*************************************************************************
typedef struct Queue *QueuePtr;
typedef struct Queue
{
	void* apData[Q_SIZE +1];
	int head; // remove
	int tail; // add
	int maxSize;
	size_t itemSize;
} Queue;

// if tail+1 == head then full
// if tail == head then empty
// only fill size-1 items
// initially, tail = head = 0

/**************************************************************************
*										Allocation and Deallocation
**************************************************************************/
extern void queueCreate (QueuePtr psQueue, size_t itemSize);
// results: If Q can be created, then Q exists and is empty

extern void queueTerminate (QueuePtr psQueue);
// results: If Q can be terminated, then Q no longer exists and is empty

/**************************************************************************
*									Checking number of elements in queue
**************************************************************************/
extern size_t queueCount (const QueuePtr psQueue);
// results: Returns the number of elements in the Q

extern bool queueIsEmpty (const QueuePtr psQueue);
// results: If Q is empty, return true; otherwise, return false

extern bool queueIsFull (const QueuePtr psQueue);
// results: If Q is empty, return true; otherwise, return false

extern size_t queueCapacity(const QueuePtr psQueue);

/**************************************************************************
*									Inserting and retrieving values
**************************************************************************/
extern void queueEnqueue (QueuePtr psQueue, const void *pBuffer);
// requires: psQueue is not full
// results: Insert the element into the FIFO queue.

extern void *queueDequeue (QueuePtr psQueue, void *pBuffer);
// requires: psQueue is not empty
// results: Remove the element from the front of a non-empty queue

/**************************************************************************
*													Peek Operations
**************************************************************************/
extern void *queuePeek (QueuePtr psQueue, void *pBuffer);
// requires: psQueue is not empty
// results: The value of the first element is returned through the
//					argument list
// IMPORTANT: Do not remove element from the queue

#endif /* QUEUE_H_ */
