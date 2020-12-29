/**
 * File : ArrQueue.h
 * Create : 2020-12-25
 * Update : 2020-12-26
 * Details
 *	This is circular queue based an array.
 * 
 * Copyright 2020. Youngman all rights reserved
 */

#ifndef __ARRQUEUE_H__
#define __ARRQUEUE_H__

/**
 * Struct : ArrQueueElement
 * Member
 *	int value	: Value of element. Can change data-type.
 *	int status	: Status of element. (0 is ok else error)
 */
typedef struct {
	int value;
	int status;
} ArrQueueElement;

/**
 * Define : ARRQUEUE_ELEMENT_LIMIT
 * Details
 *	Limit of queue-size. Can change before compile.
 */
#define ARRQUEUE_ELEMENT_LIMIT 100

/**
 * Function : void initArrQueue(void)
 * Parameter
 *	void
 * Return
 *	void
 * Details
 *	Initialize ArrQueue. Must be called before using ArrQueue.
 */
void initArrQueue(void);

/**
 * Function : int pushArrQueue(ArrQueueElement newValue)
 * Parameter
 *	ArrQueueElement newValue : New element of ArrQueue.
 * Return
 *  int : Result of pushing.
 * Details
 *	Push new element to ArrQueue.
 *	If 'return' is not 0, failed push new element.
 */
int pushArrQueue(ArrQueueElement newValue);

/**
 * Function : ArrQueueElement popArrQueue(void)
 * Parameter
 *	void
 * Return
 *	ArrQueueElement : An element, stored in ArrQueue
 * Details
 *	Return an element from ArrQueue.
 *	If element.status is not 0, ArrQueue is empty.
 */
ArrQueueElement popArrQueue(void);

/**
 * Function : int isEmptyArrQueue(void)
 * Parameter
 *	void
 * return
 *	int : True and false by 1 or 0.
 * Details
 *	Checks if the queue is empty, returns a result.
 */
int isEmptyArrQueue(void);

/**
 * Function : int isFulledArrQueue(void)
 * Parameter
 *	void
 * return
 *	int : True and false by 1 or 0.
 * Details
 *	Checks if the queue is fulled, returns a result.
 */
int isFulledArrQueue(void);

/**
 * Function : unsigned int elementCountArrQueue(void)
 * Parameter
 *	void
 * Return
 *	unsigned int : Element count of ArrQueue.
 * Details
 *	Return a element count of ArrQueue.
 */
unsigned int elementCountArrQueue(void);

#endif