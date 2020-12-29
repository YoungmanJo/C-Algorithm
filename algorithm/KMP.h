/**
 * File : KMP.h
 * Create : 2020-12-26
 * Update : 2020-12-29
 * Details
 *	This is KMP algorithm.
 *
 * Copyright 2020. Youngman all rights reserved
 */

#ifndef __KMP_H__
#define __KMP_H__

/**
 * Define : RESULT_POSITION_LIMIT
 * Details
 *	Limit of result-size. Can change before compile.
 */
#define RESULT_POSITION_LIMIT 100

/**
 * Struct : SearchResults
 * Member
 *	int position[RESULT_POSITION_LIMIT]	: An array about start-indexes of pattern founded.
 *	int cnt	: Count of 'position'.
 *	int res	: Search result. (0 is ok, else error.)
 */
typedef struct {
	int position[RESULT_POSITION_LIMIT];
	int cnt;
	int res;
} SearchResults;

/**
 * Function : SearchResults searchByKMP(const char* s, const char* pattern)
 * Parameter
 *	const char* s		: Original string
 *	const char* pattern	: Target string
 * Return
 *	SearchResults		: Result of searchByKMP (See declaration of 'SearchResults')
 * Details
 *	Search a pattern from origin string by KMP algorithm.
 */
SearchResults searchByKMP(const char* s, const char* pattern);

#endif