/**
    @file passByReference.c
    @author Revanth Bobba (rsbobba)
    This program does various operations using pointers and passing by reference.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>  // For NULL, although we don't need it.

// Define your functions here.

/**
    Increments three variables by a constant.
    @param a first variable
    @param b second variable
    @param c third variable
    @param constant constant number that the three variables should be incremented by.
*/
void incrementAll(int * const a, int * const b, int * const c, int constant)
{
    *a = *a + constant;
    *b = *b + constant;
    *c = *c + constant;
}

/**
    Rotates the values in each of the variables.
    Sets the value in b to a, the value in c to b, and the value in a to c.
    @param a first variable
    @param b second variable
    @param c third variable
*/
void rotate(int * const a, int * const b, int * const c)
{
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

/**
    Gets the address of the largest of the three variables passed in.
    @param a first variable
    @param b second variable
    @param c third variable
    @return largest address of the largest variable
*/
int * getLargest(int * const a, int * const b, int * const c)
{
    int * largest = a;
    
    if(*b > *largest)
        largest = b;
    
    if(*c > *largest)
        largest = c;
    
    return largest;
}

/**
    Program Starting Point.
    Defines variables and calls all necessary methods for the program.
    @return Program Exit Status
*/
int main()
{
  int a = 100;
  int b = 50;
  int c = 25;

  // Get initial values for a, b and c.
  printf( "a = %d b = %d c = %d\n", a, b, c );

  // Call a function to increment all the values by the given constant
  // (10 here)
  incrementAll( &a, &b, &c, 10 );

  // Report current values for a, b and c.
  printf( "a = %d b = %d c = %d\n", a, b, c );

  // Simultaneously move the value from b to a, from c to b and from a
  // to c.
  rotate( &a, &b, &c );

  // Report current values for a, b and c.
  printf( "a = %d b = %d c = %d\n", a, b, c );

  // Get back a pointer to the largest value.
  int *largest = getLargest( &a, &b, &c );

  // Make this value smaller.  We do need the parentheses here.
  (*largest)--;

  // Report final values for a, b and c.
  printf( "a = %d b = %d c = %d\n", a, b, c );

  return EXIT_SUCCESS;
}
