#include <stdint.h>
#include <stdio.h>
#include "data.h"
#include "platform.h"

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

#ifdef VERBOSE
	PRINTF("data : %d\n", data);
	PRINTF("base : %d\n", base);
#endif
        int i = 0;
	int isNegative = 0;

	if (data == 0) 
	{
		*ptr = '0';
		*(ptr+1) = 0;
		return data;
	}
	
	if (data < 0 ) 
	{
		isNegative = 1;
		data = -data;
	}

	while(data != 0)
	{
		int rem = data % base;
		*(ptr+i) = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		i++;
		PRINTF("data: %d, rem: %d, i: %d\n", data, rem, i);
		data = data / base;
	}

	if(isNegative)
	{
		*(ptr+i) = '-';
	}

	reverse(ptr, 10);

	return data;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
	// ptr - point to string
	// digits - result of conversion
	// base - number base, e.g. 16, 10, 2
	//
	int32_t result = 0;
	int sign = 1;
#ifdef VERBOSE
	printf("ptr : %s", (char *)ptr);
#endif
	while ( *ptr != 0) {
#ifdef VERBOSE
		printf("*ptr : %d", *ptr);
#endif
		if (*ptr == ' ') {
			ptr++;
			continue;
		}
		if (*ptr == '-') {
			sign = -1;
			ptr++;
		}
		if (*ptr >= '0' && *ptr <= '9')
		{
			result *= 10;
			result += *ptr;
			ptr++;
		}
	}

	result *= sign;

	return result ;
}
