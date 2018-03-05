/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */


#ifndef __MEMORY_H__
#define __MEMORY_H__

// Typedefs for prototypes
#include <stddef.h>

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief Memory Move bytes in an array.
 *
 * Take two byte pointers and a length of bytes, move from
 * source location to destination location for length.
 * @param src Pointer to source array.
 * @param dst Pointer to destination array.
 * @param length Number of elements to move.
 *
 * @return Pointer to source array.
 */
uint8_t * my_memmove(uint8_t *src, uint8_t *dst, size_t length);

/**
 * @brief Memory Copy bytes in an array.
 *
 * Take two byte pointers and a length of bytes, copy from
 * source location to destination location for length.
 * @param src Pointer to source array.
 * @param dst Pointer to destination array.
 * @param length Number of elements to move.
 *
 * @return Pointer to source array.
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Memory Set bytes in an array.
 *
 * Take a byte pointer and a length of bytes,
 * set each location to the passed in value.
 * @param src Pointer to source array.
 * @param length Number of elements to move.
 * @param value - Value to store.
 *
 * @return Pointer to source array.
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Memory zero bytes in an array.
 *
 * Take a byte pointer and a length of bytes,
 * clear number of bytes specified.
 * @param src Pointer to source array.
 * @param length Number of elements to move.
 *
 * @return Pointer to source array.
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverse bytes in an array.
 *
 * Given an array of bytes, reverse the array.
 * @param src Pointer to source array.
 * @param length Number of elements to move.
 *
 * @return Pointer to source array.
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Allocate array of words (int32)
 *
 * @param length - number of words to allocate.
 *
 * @return Pointer to array.
 */
int32_t * reserve_words(size_t length);

/**
 * @brief Free previously allocated memory.
 *
 * Given pointer to memory, free it.
 * @param src Pointer to source array.
 *
 * @return void 
 */
void free_words(uint32_t * src);

#endif /* __MEMORY_H__ */
