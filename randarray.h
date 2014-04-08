#ifndef RANDARRAY_H
#define RANDARRAY_H

#include "point.h"

/* Returns a random integer x with low <= x < high. */
int randInRange(int low, int high);

/* Populate pre-allocated array of given size with numbers between
 * low and high-1, inclusive. */
void randArray(int array[], int size, int low, int high);
void randArray(Point array[], int size, int low, int high);

/* Print each element of the array of given size. */
void printArray(int array[], int size);
void printArray(Point array[], int size);

#endif
