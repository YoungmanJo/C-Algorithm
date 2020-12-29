/**
 * File : ArrHeap.h
 * Create : 2020-12-25
 * Update : 2020-12-26
 * Details
 *	This is heap based an array.
 *
 * Copyright 2020. Youngman all rights reserved
 */

#ifndef __ARRHEAP_H__
#define __ARRHEAP_H__

/**
 * Struct : HeapElement
 * Member
 *	int value	: Value of element. Can change data-type.
 *	int status	: Status of element. (0 is ok else error)
 */
typedef struct {
	int value;
	int status;
} ArrHeapElement;

/**
 * Define : ARRHEAP_ELEMENT_LIMIT
 * Details
 *	Limit of heap-size. Can change before compile.
 */
#define ARRHEAP_ELEMENT_LIMIT 100

/**
 * Enum : HeapType
 * Member
 *	MAX_HEAP : Maximum heap mode
 *	MIN_HEAP : Minimum heap mode
 */
typedef enum {
	MAX_HEAP, MIN_HEAP
} ArrHeapType;

/**
 * Function : void initArrHeap(HeapType type)
 * Parameter
 *	HeapType type : Heap mode of max or min.
 * Return
 *	void
 * Details
 *	Initialize heap and select mode of max or min.
 *	Must be called before using ArrHeap.
 */
void initArrHeap(ArrHeapType type);

/**
 * Function : int insertArrHeap(ArrHeapElement newValue)
 * Parameter
 *	ArrHeapElement newValue : New element of ArrHeap.
 * Return
 *  int : Result of insertion.
 * Details
 *	Insert new element to ArrHeap.
 *	If 'return' is not 0, failed insert new element.
 */
int insertArrHeap(ArrHeapElement newValue);

/**
 * Function : ArrHeapElement removeArrHeap(void)
 * Parameter
 *	void
 * Return
 *	ArrHeapElement : A root element from ArrHeap.
 * Details
 *	Return a root element from ArrHeap.
 *	If element.status is not 0, ArrHeap is empty.
 */
ArrHeapElement removeArrHeap(void);

/**
 * Function : int isEmptyArrHeap(void)
 * Parameter
 *	void
 * return
 *	int : True and false by 1 or 0.
 * Details
 *	Checks if the heap is empty, returns a result.
 */
int isEmptyArrHeap(void);

/**
 * Function : int isFulledArrHeap(void)
 * Parameter
 *	void
 * return
 *	int : True and false by 1 or 0.
 * Details
 *	Checks if the heap is fulled, returns a result.
 */
int isFulledArrHeap(void);

/**
 * Function : unsigned int elementCountArrHeap(void)
 * Parameter
 *	void
 * Return
 *	unsigned int : Element count of ArrQueue.
 * Details
 *	Return a element count of ArrHeap.
 */
unsigned int elementCountArrHeap(void);

#endif