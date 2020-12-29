/**
 * File : ArrStack.h
 * Create : 2020-12-25
 * Update : 2020-12-26
 * Details
 *	This is stack based an array.
 * 
 * Copyright 2020. Youngman all rights reserved
 */

#ifndef __ARRSTACK_H__
#define __ARRSTACK_H__

/**
 * Struct : ArrStackElement
 * Member
 *	int value	: Value of element. Can change data-type.
 *	int status	: Status of element. (0 is ok else error)
 */
typedef struct {
	int value;
	int status;
} ArrStackElement;

/**
 * Define : ARRSTACK_ELEMENT_LIMIT
 * Details
 *	Limit of stack-size. Can change before compile.
 */
#define ARRSTACK_ELEMENT_LIMIT 100

/**
 * Function : void initArrStack(void)
 * Parameter
 *	void
 * Return
 *	void
 * Details
 *	Initialize ArrStack. Must be called before using ArrStack.
 */
void initArrStack(void);

/**
 * Function : int pushArrStack(ArrStackElement newValue)
 * Parameter
 *	ArrStackElement newValue : New element of ArrStack.
 * Return
 *  int : Result of pushing.
 * Details
 *	Push new element to ArrStack.
 *	If 'return' is not 0, failed push new element.
 */
int pushArrStack(ArrStackElement newValue);

/**
 * Function : ArrStackElement popArrStack(void)
 * Parameter
 *	void
 * Return
 *	ArrStackElement : An element, stored in ArrStack.
 * Details
 *	Return an element from ArrStack.
 *	If element.status is not 0, ArrStack is empty.
 */
ArrStackElement popArrStack(void);

/**
 * Function : int isEmptyArrStack(void)
 * Parameter
 *	void
 * return
 *	int : True and false by 1 or 0.
 * Details
 *	Checks if the stack is empty, returns a result.
 */
int isEmptyArrStack(void);

/**
 * Function : int isFulledArrStack(void)
 * Parameter
 *	void
 * return
 *	int : True and false by 1 or 0.
 * Details
 *	Checks if the stack is fulled and returns a status.
 */
int isFulledArrStack(void);

/**
 * Function : unsigned int elementCountArrStack(void)
 * Parameter
 *	void
 * Return
 *	unsigned int : Element count of ArrStack.
 * Details
 *	Return a element count of ArrStack.
 */
unsigned int elementCountArrStack(void);

#endif