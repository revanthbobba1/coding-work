/**
    @file arguments.c
    @author Revanth Bobba (rsbobba)
    Dynamically allocate a 2D array that holds the same set of strings as the command line arguments.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
    Prints the items in 2-D array
    @param rows number of rows in the array
    @param cols number of columns in the array
    @param args the 2-D aray conrtaining the string
 */
void printArguments( int rows, int cols, char args[][ cols ] )
{
  // Each row of the args array contains a string.  Print out each of the
  // strings.

  // ...
    
    for(int i = 0; i < rows; i++) {
        printf("%s\n", args[i]);
    }
}

/**
    Program Starting Point.
    Driver class for the program that does all need emthodfology and calls needed method.
    @param argc number of arguments in the command line
    @param argv list of arguments in the command line
    @return Program exit success
 */
int main( int argc, char *argv[] )
{
  // Figure out the length of the longest command-line argument.
  int longest = 0;

  // ...
    
    for(int i = 0; i < argc; i++) {
        int counter = 0;
        for(int j = 0; argv[i][j] != '\0'; j++) {
            counter++;
        }
        
        if (counter > longest)
            longest = counter;
    }
    
  // Dynamically allocate a 2D array of characers, with one row for every
  // command-line argument and (exactly) enough columns to hold a copy of the
  // widest command-line argument (including the null terminator at the end).
  char (*words)[ longest + 1 ];

  // ...
    
    words = malloc(argc * (longest + 1) * sizeof(char));
    

  // Copy each command-line argumetn to a row of this new array.
  
  // ..
    
    for(int i = 0 ; i < argc; i++) {
        strcpy(words[i], argv[i]);
    }
    
    

  // Call a function that's expecting the command-line arguments as a 2D array
  // (not as an array of pointers).
  printArguments( argc, longest + 1, words );

  return 0;
}
