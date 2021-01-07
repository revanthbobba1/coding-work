// Do some I/O and math with unsigned types.

#include <stdlib.h>
#include <stdio.h>

/**
   Add up all the digits in the value, x, and return the sum.
*/
unsigned int digitSum( unsigned long x )
{
  // ...
    unsigned int sum = 0;
    
    while(x > 0) {
        sum += (x % 10);
        x /= 10;
    }
    
    return sum;
}

int main()
{
  // Range of values we're supposed to check.
    unsigned long low, high;

  // Target sum we're supposed to look for.
    unsigned int target;
    
    int results = 0;

  // Read the range of values from the user.
  // ...
    results = scanf("%lu", &low);
    
    if(results != 1) {
        return EXIT_FAILURE;
    }
    
    results = 0;
    results = scanf("%lu", &high);
    
    if(results != 1) {
        return EXIT_FAILURE;
    }
  // Read the digit sum we're supposed to look for.
  // ...
    
    results = 0;
    results = scanf("%u", &target);
    
    if(results != 1) {
        return EXIT_FAILURE;
    }

  // Check all values from low up to high (inclusive), and report the ones
  // that have the given digit sum.
  // ...
    unsigned int sumdigit = 0;
        
    for(unsigned long i = low; i < (high + 1) ; i++) {
        sumdigit = digitSum(i);
        
        if(sumdigit == target)
            printf("%lu\n", i);
    }

  return EXIT_SUCCESS;
}
