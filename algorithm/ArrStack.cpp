/**
 * File : ArrStack.cpp
 * Create : 2020-12-25
 * Update : 2020-12-25
 * Details
 *	This is stack implements based an array.
 * See
 *	ArrStack.h
 *
 * Copyright 2020. Youngman all rights reserved
 */

#include "ArrStack.h"

typedef struct {
	ArrStackElement stack[ARRSTACK_ELEMENT_LIMIT];
	int top;
} ArrStack;

ArrStack s;

void initArrStack(void) {
	s.top = -1;
}

int pushArrStack(ArrStackElement newValue) {
	if (isFulledArrStack()) {
		return -1;
	}
	s.stack[++(s.top)] = newValue;
	return 0;
}

ArrStackElement popArrStack(void) {
	if (isEmptyArrStack()) {
		ArrStackElement ret = { 0, -1 };
		return ret;
	}
	return s.stack[(s.top)--];
}

int isEmptyArrStack(void) {
	return (s.top == -1);
}

int isFulledArrStack(void) {
	return (s.top == ARRSTACK_ELEMENT_LIMIT);
}

unsigned int elementCountArrStack(void) {
	return (s.top + 1);
}
