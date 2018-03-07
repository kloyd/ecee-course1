#include <stdint.h>
#include <stdio.h>
#include "data.h"
#include "platform.h"
#include "memory.h"
#include "course1.h"

/*
 *
 * data.c
 *
 * Data manipulation routines.
 *
 */

void reverse( uint8_t * ptr, uint32_t length)
{
	int start = 0;
	int end = length - 1;
	uint8_t temp;
	while(start < end)
	{
		temp = *(ptr+start);
		*(ptr+start) = *(ptr+end);
		*(ptr+end) = temp;
		start++;
		end--;
	}
}

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
	// data - input number
	// ptr - empty string of length DATA_SET_SIZE_W
	// base - base of number desired.
	// return number of characters in string.

        int i = 0;
	int isNegative = 0;
	int length = 0;
	uint8_t * tmpstr;

	// Trivial case, number is zero.
	if (data == 0) 
	{
		*ptr = '0';
		*(ptr+1) = 0;
		return 2;
	}

	// make temp string pointer
        tmpstr = (uint8_t*) reserve_words( DATA_SET_SIZE_W );

	// Don't assume that the ptr has been cleared, set all to nulls.
	 for(int n = 0; n < DATA_SET_SIZE_W; n++)
	{
		*(ptr + n) = 0;
	}
        

	if (data < 0 ) 
	{
		isNegative = 1;
		data = -data;
	}

	while(data != 0)
	{
		int rem = data % base;
		*(tmpstr+i) = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		i++;
		data = data / base;
	}

	if(isNegative)
	{
		*(tmpstr+i) = '-';
	}

	reverse(tmpstr, DATA_SET_SIZE_W);
	// copy out to ptr
	for(int n = 0; n < DATA_SET_SIZE_W; n++)
	{
		if (*(tmpstr+n) != 0)
		{
			*(ptr+length) = *(tmpstr+n);
			length++;
		}
	}
        free_words( (uint32_t*)tmpstr );

	return length;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
	// ptr - point to string
	// digits - number of characters in string.
	// base - number base, e.g. 16, 10, 2
	//
	int32_t result = 0;
	int sign = 1;
	while ( *ptr != 0) {
		if (*ptr == ' ') {
#ifdef VERBOSE
			PRINTF("space ");
#endif
			ptr++;
			continue;
		}
		if (*ptr == '-') {
			sign = -1;
			ptr++;
#ifdef VERBOSE
			PRINTF("negative ");
#endif
		}
		if (*ptr >= '0' && *ptr <= 'F')
		{
#ifdef VERBOSE
			PRINTF("%c ", *ptr);
#endif
			result *= base;
			result += *ptr  - '0';
			ptr++;
		}
	}
#ifdef VERBOSE
	PRINTF("\n");
#endif

	result *= sign;

	return result ;
}
