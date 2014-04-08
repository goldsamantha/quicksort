#include <stdlib.h>  // Needed for srand48, to generate pseudo-random numbers.
#include <iostream>

#include "point.h"

using namespace std;

/* Returns a random integer x with low <= x < high. */
int randInRange(int low, int high){
  int range = high - low;
  return (lrand48() % range) + low;
}

/* Populate pre-allocated array of given size with numbers between
 * low and high-1, inclusive. */
void randArray(int array[], int size, int low, int high){
  for (int i = 0; i < size; ++i){
    array[i] = randInRange(low, high);
  }
}

/* Populate pre-allocated array of given size with Points, with coordinates
 * between low and high-1, inclusive. */
void randArray(Point array[], int size, int low, int high){
  for (int i = 0; i < size; ++i){
    int x = randInRange(low, high);
    int y = randInRange(low, high);
    array[i] = Point(x, y);
  }
}

/* Print each element of the array of given size. */
void printArray(int array[], int size){
  cout << "[";
  if (size > 0) {
    cout << array[0];
  }
  for(int i = 1; i < size; i++){
    cout << " " << array[i];
  }
  cout << "]" << endl;
}
/* Print each element of the array of given size. */
void printArray(Point array[], int size){
  cout << "[";
  if (size > 0) {
    cout << array[0];
  }
  for(int i = 1; i < size; i++){
    cout << " " << array[i];
  }
  cout << "]" << endl;
}
