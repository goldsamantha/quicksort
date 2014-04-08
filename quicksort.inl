#include <sys/time.h>  // for gettimeofday and struct timeval
#include <stdlib.h>    // for srand48 and lrand48
#include <iostream>

using namespace std;

//////////////////////////////////////////////////////////////////////
//                      Function declarations.                      //
//////////////////////////////////////////////////////////////////////

/** 
 * partition:  Given an array and bounds left and right (inclusive), 
 * partition part of the array around a randomly-chosen pivot item.
 *
 * Returns:  The final location of the pivot in the partitioned array.
 */
template <typename T> int partition(T a[], int left, int right);


/**
 * quickSort(T[] a, int left, int right) is an internal quicksort helper
 * function that quickSorts an array within the given left-right (inclusive)
 * range.
 */
template <typename T> void quickSort(T a[], int left, int right);



/**
 * swap:  Given an array a and two positions in the array, swaps the items
 * in those positions in the array.
 *
 * Returns:  nothing, but changes the array as a side effect.
 */
template <typename T> void swap(T a[], int i, int j);


//////////////////////////////////////////////////////////////////////
//                      Function implementations.                   //
//////////////////////////////////////////////////////////////////////

/** 
 * quickSort:  Given an array of n items, sorts the array.
 * Returns:    Nothing.  The input array is sorted as a side effect.
 */
template <typename T> void quickSort(T a[], int n) {
  struct timeval tv;
  gettimeofday(&tv, NULL);          // Gets the time of day and uses it to
  srand48(tv.tv_sec + tv.tv_usec);  // seed the pseudo-random number generator.
  quickSort(a, 0, n-1);             // Calls the quickSort helper function,
                                    // which sorts a given range of an array.
}


/**
 * quickSort(T[] a, int left, int right) is an internal quicksort helper
 * function that quickSorts an array within the given left-right (inclusive)
 * range.
 *
 * quickSort partition the segment and then recursively call quicksort on 
 * the two halves.
 */
template <typename T> void quickSort(T a[], int left, int right) {
  if (left < right) {
    int p = partition(a, left, right);   
    quickSort(a, left, p-1);
    //printArray(a, p-1-left);   for error checking.
    quickSort(a, p+1, right);
    //printArray(a, right - p+1); for error checking.

  }
}


/** 
 * partition:  Given an array and bounds left and right (inclusive), 
 * partition part of the array around a randomly-chosen pivot item.
 *
 * Returns:  The final location of the pivot in the partitioned array.
 */
template <typename T> int partition(T a[], int left, int right) {
  // Chooses a random pivot in the range left-right (inclusive)
  int pivotLocation = (lrand48() % (right-left+1)) + left;
  swap(a, pivotLocation, right);      // swaps pivot to rightmost position

  int l = left;                 // indexes for left
  int r = right-1;              // and right.
  T pivot = a[right];           // makes pivote the far right value.
  while (l <= r){               // while l is less or equal to r:
    if (a[l] <= pivot){         // if item in left index is less than piv.
      l++;                      // increase left index.
    }
    else if (a[r] > pivot){     // if item in index r is greater than
      r--;                      // pivot, move r left (decrease r)
    } else{                     // if none of those,
      swap(a, l, r);            // swap items in l and r.
    }
  }
  swap(a, l, right);            // Swap the left item with the right

  

  return l;  // At the end, l is the position of the pivot in the partitioned
}            // array.


/**
 * swap:  Given an array a and two positions in the array, swaps the items
 * in those positions in the array.
 *
 * Returns:  nothing, but changes the array as a side effect.
 */
template <typename T> void swap(T a[], int i, int j) {
  T tmp(a[i]);          
  a[i] = a[j];
  a[j] = tmp;
}
