#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "ArrStack.h"
#include "ArrQueue.h"
#include "SortingAlg.h"
#include "KMP.h"
#include <string.h>

#define TRUE 1
#define FALSE 0
#define PRINTOUT_PUSH_POP 0

const unsigned int usingStack = TRUE;

void init() {
	if (usingStack) {
		initArrStack();
	}
	else {
		initArrQueue();
	}
}

void push(int value) {
	if (usingStack) {
		ArrStackElement element = { value, 0 };
		pushArrStack(element);
	}
	else {
		ArrQueueElement element = { value, 0 };
		pushArrQueue(element);
	}

#if PRINTOUT_PUSH_POP
	printf("Push: %d\n", element.value);
#endif
}

int pop() {
	int ret, status;
	if (usingStack) {
		ArrStackElement element = popArrStack();
		status = element.status;
		if (status == 0) {
			ret = element.value;
		}
		else {
			ret = -1;
		}
	}
	else {
		ArrQueueElement element = popArrQueue();
		status = element.status;
		if (status == 0) {
			ret = element.value;
		}
		else {
			ret = -1;
		}
	}

#if PRINTOUT_PUSH_POP
	if (status == 0) {
		printf("Pop: %d\n", element.value);
	}
	else {
		puts("Pop: Error");
	}
#endif

	return ret;
}

int isEmpty() {
	return (usingStack ? isEmptyArrStack() : isEmptyArrQueue());
}

unsigned int elementCount() {
	return (usingStack ? elementCountArrStack() : elementCountArrQueue());
}

void stackOrQueue() {
	int arr[10] = { 3, 2, 5, 1, 10, 8, 6, 4, 9, 7 };
	int popOrder[10] = { 0 };
	int popIdx = 0;

	init();

	for (int i = 0; i < 10; i++) {
		if (arr[i] <= 6) {
			push(arr[i]);
		}
		else if (elementCount() > 2) {
			while (elementCount() > 2) {
				popOrder[popIdx++] = pop();
			}
			push(arr[i]);
		}
		else {
			push(arr[i]);
		}
	}
	while (isEmpty() == FALSE) {
		popOrder[popIdx++] = pop();
	}

	puts("[Pop order]");
	for (int i = 0; i < 10; i++) {
		printf("%d ", popOrder[i]);
	}
	puts("");
}

void sortingAlgorithm() {
	int arr[10] = { 3, 2, 10, 1, 5, 8, 6, 9, 4, 7 };

	puts("<Before>");
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	puts("");

	// Bubble sort
	bubbleSort(arr, 10, ASC);
	//bubbleSort(arr, 10, DESC);

	// Selection sort
	//selectionSort(arr, 10, ASC);
	//selectionSort(arr, 10, DESC);

	// Insertion sort
	//insertionSort(arr, 10, ASC);
	//insertionSort(arr, 10, DESC);

	// Merge sort
	//mergeSort(arr, 10, ASC);
	//mergeSort(arr, 10, DESC);

	// Quick sort
	//quickSort(arr, 10, ASC);
	//quickSort(arr, 10, DESC);

	// Heap sort
	//heapSort(arr, 10, ASC);
	//heapSort(arr, 10, DESC);

	// Shell sort
	//shellSort(arr, 10, ASC);
	//shellSort(arr, 10, DESC);

	puts("<After>");
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	puts("");
}

void KMP() {
	char s[31] = "ABCDABABAABABBAACABCDBCAABACDC";
	char pattern[5] = "ABA";

	SearchResults searchResults = searchByKMP(s, pattern);
	if (searchResults.res != 0) {
		puts("Error : searchByKMP is fail.");
		return;
	}
	puts("[KMP Algorithm]");
	printf("Found: %d\n", searchResults.cnt);
	printf("Position: ");
	for (int i = 0; i < searchResults.cnt; i++) {
		printf("%d ", searchResults.position[i]);
	}
	puts("");

	puts("[Check]");
	for (int i = 0; i < searchResults.cnt; i++) {
		for (int j = searchResults.position[i], k = 0; k < strlen(pattern); j++, k++) {
			printf("%c", s[j]);
		}
		puts("");
	}
}

int main(void) {
	//stackOrQueue();
	//sortingAlgorithm();
	KMP();

	return 0;
}