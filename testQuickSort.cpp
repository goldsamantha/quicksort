#include <iostream>
#include <stdlib.h>     // Needed for pseudo-random number generator.
#include <sys/time.h>   // Needed for pseudo-random number generator.

#include "quicksort.h"
#include "randarray.h"

using namespace std;

int main() {
  struct timeval tv;                // Currents time and uses it to initialize
  gettimeofday(&tv, NULL);          // the pseudo-random number generator.
  srand48(tv.tv_sec + tv.tv_usec);

  int n;
  cout << "Please enter a size for the array:  ";
  cin >> n;

  //Point* data = new Point[n];
  int* data = new int[n];
  randArray(data, n, 0, 2*n);

  if (n <= 1000) {
    cout << "Initial random array:  ";
    printArray(data, n);
  }

  quickSort(data, n);
  if (n <= 1000) {
    cout << "Sorted array:  ";
    printArray(data, n);
  }

  delete [] data;
}

