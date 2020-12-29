/**
 * File : KMP.cpp
 * Create : 2020-12-26
 * Update : 2020-12-29
 * Details
 *	This is KMP algorithm implements.
 *
 * Copyright 2020. Youngman all rights reserved
 */

#include <string.h>
#include <stdlib.h>
#include "KMP.h"

// Failure Function
void makePi(const char* pattern, int length, int* pi) {
	for (int i = 1, j = 0; i < length; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = pi[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			pi[i] = ++j;
		}
	}
}

SearchResults searchByKMP(const char* s, const char* pattern) {
	SearchResults searchResult = { {0}, 0, 0 };
	int p_length = strlen(pattern);
	int* pi = (int*)calloc(p_length, sizeof(int));
	if (pi == NULL) {
		searchResult.res = -1;
		return searchResult;
	}
	makePi(pattern, p_length, pi);

	int s_length = strlen(s);
	for (int i = 0, j = 0; i < s_length; i++) {
		while (j > 0 && s[i] != pattern[j]) {
			j = pi[j - 1];
		}
		if (s[i] == pattern[j]) {
			if (j == p_length - 1) {
				searchResult.position[searchResult.cnt++] = i - p_length + 1;
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}

	free(pi);

	return searchResult;
}