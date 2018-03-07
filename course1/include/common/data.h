/*
 * Function definition for data manipulation routines.
 *
 */

#include <stdint.h>

/**
 * @brief Convert integer to string.
 *
 * Given an integer value, return a string representation.
 * Honor the Number Base.
 *
 * @param data Number to convert.
 * @param ptr Pointer to string space (must be allocated!)
 * @param base Base number system, e.g. 2 for Binary
 *
 * @return length.
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);


/**
 * @brief Convert numeric string into integer.
 *
 * Given a pointer to a char data set, convert into an integer
 *
 * @param ptr Pointer to data array
 * @param digits length of array
 * @param base Number Base system.
 *
 * @return numbervalue.
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

