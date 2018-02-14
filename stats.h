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
 * @file stats.h
 * @brief Basic statistics functions for an array of unsigned char values.
 *
 * Functions to sort, print, find maximum, minimum values, mean and media values
 * given an array of unsigned char values as input.
 *
 * @author Kelly Loyd
 * @date 2018-01-22
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief print all of the statistics of an array.
 *
 * A function that prints the statistics of an array including minimum,
 * maximum, mean, and median.
 *
 * @param array pointer to unsigned char array
 *
 * @return void
 */
 void print_statistics(unsigned char * array, int length);

 /**
  * @brief print an array.
  *
  * Given an array of data and a length, prints the array to the screen.
  *
  * @param array pointer to unsigned char array
  *
  * @return void
  */
void print_array(unsigned char * array, int length);

/**
 * @brief find median value of an array.
 *
 * Given an array of data and a length, determine and return the median value.
 *
 * @param array pointer to unsigned char array
 *
 * @return unsigned char
 */
unsigned char find_median(unsigned char * array, int length);

/**
 * @brief find mean value of an array.
 *
 * Given an array of data and a length, determine and return the mean value.
 *
 * @param array pointer to unsigned char array
 *
 * @return unsigned char
 */
unsigned char find_mean(unsigned char * array, int length);


/**
 * @brief find maximum value of an array.
 *
 * Given an array of data and a length, determine and return the maximum value.
 *
 * @param array pointer to unsigned char array
 *
 * @return unsigned char
 */
unsigned char find_maximum(unsigned char * array, int length);

/**
 * @brief find minimum value of an array.
 *
 * Given an array of data and a length, determine and return the minimum value.
 *
 * @param array pointer to unsigned char array
 *
 * @return unsigned char
 */
unsigned char find_minimum(unsigned char * array, int length);

/**
 * @brief sort an array in descending order.
 *
 * Given an array of data and a length, determine and return the minimum value.
 *
 * @param array pointer to unsigned char array
 *
 * @return void
 */
void sort_array(unsigned char * array, int length);

#endif /* __STATS_H__ */
