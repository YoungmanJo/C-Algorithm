/**
 * File : ArrQueue.cpp
 * Create : 2020-12-25
 * Update : 2020-12-25
 * Details
 *	This is circular queue implements based an array.
 * See
 *	ArrQueue.h
 *
 * Copyright 2020. Youngman all rights reserved
 */

#include "ArrQueue.h"

typedef struct {
	ArrQueueElement queue[ARRQUEUE_ELEMENT_LIMIT];
	int front;
	int end;
} ArrQueue;

ArrQueue q;

void initArrQueue(void) {
	q.front = 0;
	q.end = 1;
}

int pushArrQueue(ArrQueueElement newValue) {
	if (isFulledArrQueue()) {
		return -1;
	}
	q.queue[(q.end)++] = newValue;
	q.end %= ARRQUEUE_ELEMENT_LIMIT;
	return 0;
}

ArrQueueElement popArrQueue(void) {
	if (isEmptyArrQueue()) {
		ArrQueueElement ret = { 0, -1 };
		return ret;
	}
	q.front++;
	q.front %= ARRQUEUE_ELEMENT_LIMIT;
	return q.queue[q.front];
}

int isEmptyArrQueue(void) {
	int a = q.front, b = q.end;
	if (a > b) {
		b += ARRQUEUE_ELEMENT_LIMIT;
	}
	return (a == (b - 1) ? 1 : 0);
}

int isFulledArrQueue(void) {
	return (q.front == q.end ? 1 : 0);
}

unsigned int elementCountArrQueue(void) {
	int a = q.front, b = q.end;
	if (a > b) {
		b += ARRQUEUE_ELEMENT_LIMIT;
	}
	return b - a - 1;
}
