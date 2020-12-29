/**
 * File : SortingAlg.cpp
 * Create : 2020-12-26
 * Update : 2020-12-26
 * Details
 *	This is sorting algorithm implements.
 * See
 *	SortingAlg.h
 *
 * Copyright 2020. Youngman all rights reserved
 */

#include "SortingAlg.h"
#include <stdlib.h>
#include <stdio.h>

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int* arr, int size, SortOrder order) {
	for (int i = size - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (order == ASC) {
				if (arr[j] > arr[j + 1]) {
					swap(&arr[j], &arr[j + 1]);
				}
			}
			else {
				if (arr[j] < arr[j + 1]) {
					swap(&arr[j], &arr[j + 1]);
				}
			}
		}
		if (i == 8) {
			printf("[bubbleSort, i = %d]\n", i);
			for (int k = 0; k < size; k++) {
				printf("%d ", arr[k]);
			}
			puts("");
		}
	}
}

void selectionSort(int* arr, int size, SortOrder order) {
	for (int i = 0; i < size - 1; i++) {
		int target = i;
		for (int j = i + 1; j < size; j++) {
			if (order == ASC) {
				if (arr[j] < arr[target]) {
					target = j;
				}
			}
			else {
				if (arr[j] > arr[target]) {
					target = j;
				}
			}
		}
		swap(&arr[i], &arr[target]);
	}
}

void insertionSort(int* arr, int size, SortOrder order) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j > 0; j--) {
			if (order == ASC) {
				if (arr[j] < arr[j - 1]) {
					swap(&arr[j], &arr[j - 1]);
				}
			}
			else {
				if (arr[j] > arr[j - 1]) {
					swap(&arr[j], &arr[j - 1]);
				}
			}
		}
	}
}

void _mergeSort(int* arr, int l, int r, int* res, SortOrder order) {
	if (l >= r) return;

	int mid = (l + r) / 2;

	_mergeSort(arr, l, mid, res, order);
	_mergeSort(arr, mid + 1, r, res, order);

	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++) {
		if (j > r) {
			res[k] = arr[i++];
		}
		else if (i > mid) {
			res[k] = arr[j++];
		}
		else if (order == ASC) {
			if (arr[i] <= arr[j]) {
				res[k] = arr[i++];
			}
			else {
				res[k] = arr[j++];
			}
		}
		else {
			if (arr[i] >= arr[j]) {
				res[k] = arr[i++];
			}
			else {
				res[k] = arr[j++];
			}
		}
	}

	for (int i = l; i <= r; i++) {
		arr[i] = res[i];
	}
}

void mergeSort(int* arr, int size, SortOrder order) {
	int* res = (int*)calloc(size, sizeof(int));
	_mergeSort(arr, 0, size - 1, res, order);
	free(res);
}

void _quickSort(int* arr, int l, int r, SortOrder order) {
	if (l >= r) return;

	int pivot = r;
	int i = l, j = r - 1;

	while (i <= j) {
		if (order == ASC) {
			while (i < r && arr[i] <= arr[pivot]) {
				i++;
			}
			while (j > l && arr[j] >= arr[pivot]) {
				j--;
			}
		}
		else {
			while (i < r && arr[i] >= arr[pivot]) {
				i++;
			}
			while (j > l && arr[j] <= arr[pivot]) {
				j--;
			}
		}

		if (i < j) {
			swap(&arr[i], &arr[j]);
		}
		else {
			swap(&arr[i], &arr[pivot]);
		}
	}

	_quickSort(arr, l, i - 1, order);
	_quickSort(arr, i + 1, r, order);
}

void quickSort(int* arr, int size, SortOrder order) {
	_quickSort(arr, 0, size - 1, order);
}

void heapSort(int* arr, int size, SortOrder order) {
	initArrHeap((order == ASC ? MIN_HEAP : MAX_HEAP));
	
	for (int i = 0; i < size; i++) {
		ArrHeapElement item = { arr[i], 0 };
		insertArrHeap(item);
	}
	for (int i = 0; i < size; i++) {
		ArrHeapElement item = removeArrHeap();
		arr[i] = item.value;
	}
}

void shellSort(int* arr, int size, SortOrder order) {
	int h = 1;
	while (h < size) {
		h = 3 * h + 1;
	}
	h /= 3;

	while (h > 0) {
		for (int i = h; i < size; i++) {
			int k = i - h;
			int key = arr[i];
			if (order == ASC) {
				while (k >= 0 && key < arr[k]) {
					arr[k + h] = arr[k];
					k -= h;
				}
			}
			else {
				while (k >= 0 && key > arr[k]) {
					arr[k + h] = arr[k];
					k -= h;
				}
			}
			arr[k + h] = key;
		}
		h /= 3;
	}
}