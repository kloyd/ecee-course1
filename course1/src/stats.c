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
 * @file stats.c
 * @brief simple statistics for an array of values
 *
 * Given an array of unsigned char values, calculate mininum, maximum, mean,
 * and median values.
 *
 * Provide a print function for the array and a sort in descending order function.
 *
 * @author Kelly Loyd
 * @date January 21 2018
 *
 */

#include <stdio.h>
#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)

void testfuncs() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  print_statistics(test, SIZE);

}

void print_statistics(unsigned char * array, int length) {

  print_array(array, length);

  PRINTF("-----\nArray statistics\n-----\n");

  unsigned char min = find_minimum(array, length);
  PRINTF("Minimum value = %3d\n", min);

  unsigned char max = find_maximum(array, length);
  PRINTF("Maximum value = %3d\n", max);

  unsigned char mean = find_mean(array, length);
  PRINTF("Mean value = %3d\n", mean);

  unsigned char median = find_median(array, length);
  PRINTF("Median value = %3d\n", median);

}

void print_array(unsigned char * array, int length) {
#ifdef VERBOSE
  for (int i = 0; i < length; i++) {
    PRINTF("Element %3d: %3d \n", i, array[i]);
  }
#endif
}

unsigned char find_median(unsigned char * array, int length) {
  // need the array sorted first
  sort_array(array, length);
  int median_idx = length / 2;
  unsigned char median_val = 0;
  if ( length % 2 == 0) {
    // even number, take index, index+1 and average
    median_val = (array[median_idx] + array[median_idx + 1]) / 2;
  } else {
    // odd number, take index value
    median_val = array[median_idx];
  }
  return median_val;
}

unsigned char find_mean(unsigned char * array, int length) {
  int sum = 0;
  for (int i = 0; i < length; i++) {
    sum += array[i];
  }
  unsigned char mean = sum / length;
  return mean;
}

unsigned char find_maximum(unsigned char * array, int length) {
  unsigned char test_val = array[0];
  for (int i = 1; i < length; i++) {
    if (test_val < array[i]) {
      test_val = array[i];
    }
  }
  return test_val;
}

unsigned char find_minimum(unsigned char * array, int length) {
  unsigned char test_val = array[0];
  for (int i = 1; i < length; i++) {
    if (test_val > array[i]) {
      test_val = array[i];
    }
  }
  return test_val;
}

void swap(unsigned char * a, unsigned char * b) {
  unsigned char t = *a;
  *a = *b;
  *b = t;
}

void sort_array(unsigned char * array, int length) {
  for( int i = 0; i < length; i++) {
    for (int j = i + 1; j < length; j++) {
      if (array[i] < array[j]) {
        swap(&array[i], &array[j]);
      }
    }
  }
}
