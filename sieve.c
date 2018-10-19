#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "sieve.h"

// average of 0.236 s on Stuy computer for 2,000,000th prime

// odds only
int sieve(int n) {
  if (n == 1) {
    return 2;
  }

  n--;

  float c = (n < 5000) ? 1.3 : 1.15; // constant for next step

  // nth prime will be before this #
  // we're dividing by 2 because we're not going to test evens
  int max_index = ceil(c * n * log(n)) / 2;

  // allocated 1 byte for each num we're testing. sets all to 0
  // calloc is (can be?) faster than allocating memory then zeroing
  char* nums = calloc(sizeof(char), max_index);

  // using this so we don't have to count from the beginning
  // interesting --> this doesn't make it faster...
  int pcounter = 0;
  char* current_prime = nums;

  // starting at index 0
  int i_at = 0;

  // traversing through indices till we get to sqrt(max_index)
  for ( ; i_at * i_at <= max_index; i_at++) {

    // if the num stored at i_at is prime
    if (!(*(nums + i_at))) {

      int hop_by = 2 * (i_at + 1) + 1;
      char* x = nums + i_at + hop_by;
      char* stop = nums + max_index;
      for ( ; x < stop; x += hop_by) {
        if (!(*(x))) *x = 1;
      }
    }
  }

  char* onums = nums;

  for ( ; n >= -1; n--) {
    //printf("%d\n", nums);
    while (*nums != 0) {
      nums += 1;
    }
    nums += 1;
  }
  nums -= 1;

  // char* r = nums;
  // int w;
  // for(w = 0; w < max_index; w++) {
  //   printf("%d: %d\n", w, *(r + w));
  // }

  free(onums);
  return 2 * ((nums - onums) - 1) + 1;
}
