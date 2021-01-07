/**
    @file main.c
    @author Revanth Bobba (rsbobba)
    This program replaces all spaces in a string with dashes, and prints how many spaces 
    were in the initial string.
*/

#include <stdio.h>
#include <stdlib.h>
#include "print.h"

/**
    Program Starting point.
    Calls the dashesForSpaces method, which replaces spaces with dashes and counts spaces.
    @return program exit status.
*/
int main()
{
    int ch;
  
    // Read all the characters from standard input.
    while ( ( ch = getchar() ) != EOF ) {
        // Let the print component print out this character.
        dashesForSpaces( ch );
    }

    // Report the number of spaces, as counted by the print component.
    printf( "\n" );
    printf( "That contained %d spaces\n", spaceCount );

    return EXIT_SUCCESS;
}
