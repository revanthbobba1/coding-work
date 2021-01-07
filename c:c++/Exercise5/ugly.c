/**
    @file ugly.c
    @author Revanth Bobba (rsbobba)
    This file calculates prime numbers within a range, using go-to labels, not loops.
 */


// Same prime-detection strategy, but without any structured
// looping constructs.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
    Program Starting Point.    
    Report a list of prime values.
    @return program exit status
 */
int main( void )
{
    // Get the range of values we're supposed to test.
    unsigned int low, high;
    if ( scanf( "%d%d", &low, &high ) != 2 ) {
        printf( "Invalid input\n" );
        exit( EXIT_FAILURE );
    }
  
    // Write your own, ugly solution, using goto instead of structured looping.
    
    // value we are currently looking at
    unsigned int val = low;
    unsigned int fact;

    // Top of the loop. Loops through all elements in the range. 
    topOfLoop:

        fact = 2;
        if (val > high)
            goto doneWithLoop;
        goto insideLoop;
    
    // Checks for each number if it is prime or not.
    insideLoop:

        if(fact*fact > val) {
            if(val == 1) {
                val++;
                goto topOfLoop;
            }
            goto success;
        }
    
        if (val % fact == 0) {
            val++;
            goto topOfLoop;
        }
        
        fact++;
        goto insideLoop;
    
    // The value of val is a prime number.
    success:
        
        printf("%u\n", val);
        val++;
        goto topOfLoop;
      
    // End of the loop.          
    doneWithLoop:
    
  // ...
  
  return EXIT_SUCCESS;
}
