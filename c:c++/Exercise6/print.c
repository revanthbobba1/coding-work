/**
    @file print.c
    @author Revanth Bobba (rsbobba)
    This program counts the number of spaces in a string, and replaces them with dashes.
*/
#include "print.h"
#include <stdio.h>

/** Description below */
// Add a new global variable to keep a count of the spaces we print.
int spaceCount = 0;
// ...

/**
    Description is below
    @param ch the current character in the string.
*/
// Print the given character, counting spaces as we print and
// replacing each space with a '-'. The parameter type is char here,
// since we don't expect EOF to be passed to the function, just legal
// characters.
void dashesForSpaces( char ch )
{

    // Fill in the body of this function.
    if(ch == ' ') {
        putchar('-');
        spaceCount++;
    }
    else{
        putchar(ch);
    }
   // ...
}
