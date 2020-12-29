/**
 * File : SortingAlg.h
 * Create : 2020-12-26
 * Update : 2020-12-26
 * Details
 *	This is sorting algorithm.
 *
 * Copyright 2020. Youngman all rights reserved
 */

#include "ArrHeap.h"

typedef enum {
	ASC, DESC
} SortOrder;

// O(n^2) sorting algorithm
void bubbleSort(int* arr, int size, SortOrder order);
void selectionSort(int* arr, int size, SortOrder order);
void insertionSort(int* arr, int size, SortOrder order);

// O(nlogn) sorting algorithm
void mergeSort(int* arr, int size, SortOrder order);
void quickSort(int* arr, int size, SortOrder order);
void heapSort(int* arr, int size, SortOrder order);

// ETC
void shellSort(int* arr, int size, SortOrder order);