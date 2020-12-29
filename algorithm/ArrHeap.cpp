/**
 * File : ArrHeap.cpp
 * Create : 2020-12-25
 * Update : 2020-12-26
 * Details
 *	This is heap implements based an array.
 * See
 *	ArrHeap.h
 *
 * Copyright 2020. Youngman all rights reserved
 */

#include "ArrHeap.h"

typedef struct {
	ArrHeapElement heap[ARRHEAP_ELEMENT_LIMIT];
	int cnt;
	ArrHeapType type;
} ArrHeap;

ArrHeap h;

void initArrHeap(ArrHeapType type) {
	h.type = type;
	h.cnt = 0;
}

int insertArrHeap(ArrHeapElement newValue) {
	if (isFulledArrHeap()) {
		return -1;
	}

	int i = ++(h.cnt);
	if (h.type == MAX_HEAP) {
		while ((i != 1) && (newValue.value > h.heap[i / 2].value)) {
			h.heap[i] = h.heap[i / 2];
			i /= 2;
		}
	}
	else {
		while ((i != 1) && (newValue.value < h.heap[i / 2].value)) {
			h.heap[i] = h.heap[i / 2];
			i /= 2;
		}
	}

	h.heap[i] = newValue;
}

ArrHeapElement removeArrHeap(void) {
	ArrHeapElement item = h.heap[1];
	ArrHeapElement temp = h.heap[(h.cnt)--];
	int parent = 1, child = 2;

	while (child <= h.cnt) {
		if (h.type == MAX_HEAP) {
			if ((child < h.cnt)
				&& ((h.heap[child].value) < h.heap[child + 1].value)) {
				child++;
			}
			if (temp.value >= h.heap[child].value) {
				break;
			}
		}
		else {
			if ((child < h.cnt)
				&& ((h.heap[child].value) > h.heap[child + 1].value)) {
				child++;
			}
			if (temp.value <= h.heap[child].value) {
				break;
			}
		}
		
		h.heap[parent] = h.heap[child];
		parent = child;
		child *= 2;
	}

	h.heap[parent] = temp;
	return item;
}

int isEmptyArrHeap(void) {
	return (h.cnt == 0);
}

int isFulledArrHeap(void) {
	return (h.cnt == ARRHEAP_ELEMENT_LIMIT - 1);
}

unsigned int elementCountArrHeap(void) {
	return h.cnt;
}
