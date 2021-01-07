/**
    @file fields.c
    @author Revanth Bobba (rsbobba)
    This file inputs some text and outputs a correctly formatted output file.
    Outputs error messages for lines with bad formatting.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


/**
    Program Starting Point.
    Contains the methodology for the file.
    @return Program Exit Status
*/
int main()
{
    // Open the input file and print an error message if we're unsuccessful.
    // (the error message is mostly to help you with debugging.  We won't test
    // this behavior).
    // ...
    
    FILE * infile;
    infile = fopen("input.txt", "r");
    if (infile == NULL) {
        fprintf(stderr, "Error.\n");
        return EXIT_FAILURE;
        
    }

    // Counting input lines, so we can report errors.
    int lineCount = 1;
 
    // Keep reading input lines until we reach the end-of-file.
    // Write an output line or an error message for each one.
    // ...
    
    char first[ 12 ];
    char last[ 12 ];
    char id[ 9 ];
    int phonefirst = 0;
    int phonesecond = 0;
    int phonethird = 0;
    char end[100];
    int ch = 0;
    
    while ( ( ch = fgetc( infile ) ) != EOF ) {

        ungetc(ch, infile);

        if(fscanf( infile, "%11s %11s %*d %8[^@]@%*[^ ]  %*[^0-9]  %3d %*[^0-9] %3d %*[^0-9] %4d", first, last, id, &phonefirst, &phonesecond, &phonethird) != 6) {

            fprintf( stderr, "Invalid input, line %d\n", lineCount);
            fscanf(infile, "%[^\n]", end);
            fgetc(infile);
            lineCount++;
            continue;
        }

        fscanf(infile, "%[^\n]", end);
        fgetc(infile);
        printf("%8s %11s %11s (%03d)%03d-%04d\n", id, first, last, phonefirst, phonesecond, phonethird);
        lineCount++;
    }

    
    fclose( infile );

    return EXIT_SUCCESS;
}
