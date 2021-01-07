#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

// One inch equals this many meters.
#define INCHES_TO_METERS 0.0254

// Representation for for an imperial measurement, as a length in
// inches.  The length is represented as a mixed numeral, with an
// integer number of inches and a simple fraction represented as
// numerator and denominator.  So, in inches, the length would be
// equivalent to inches + numerator / denominator.
typedef struct {
  int inches;
  int numerator;
  int denominator;
} ImperialLength;

// Remptesentation for a type of item in our inventory, with
// a length that's measured in metric or imperial units.
typedef struct {
  // Unique ID for this type of item.
  int sku;

  // Enumeration to indicate whether this is a metric or an imperial
  // measurement.
  enum { metric, imperial } mtype;

  // Length, represented in either imperial units (as an instance of
  // ImperialLength) or metric (as a double).  The mtype field says
  // which element of this union we're using.
  union {
    double mval;
    ImperialLength ival;
  } length;
} Item;

// Print a usage message, and exit unsuccessfully.
static void usage()
{
  fprintf( stderr, "usage: inventory <inventory-file>\n" );
  exit( EXIT_FAILURE );
}

// Complain if the inventory file is bad.
static void invalid()
{
  fprintf( stderr, "Invalid inventory file\n" );
  exit( EXIT_FAILURE );
}

// Comparison function for sorting items.
int itemComp( void const *pA, void const *pB )
{
  // These two pointers are really pointers to items.
  Item const *itemA = (Item *) pA;
  Item const *itemB = (Item *) pB;

  // Compare the length of the items pointed to by itemA and itemB.
  // ...
    double val1;
    if(itemA->mtype == imperial) {
        val1 = (itemA->length.ival.inches + (double) (itemA->length.ival.numerator) / (itemA->length.ival.denominator)) * INCHES_TO_METERS;
    }
    else {
        val1 = itemA->length.mval;
    }
    
    double val2;
    if(itemB->mtype == imperial) {
        val2 = (itemB->length.ival.inches + (double) (itemB->length.ival.numerator) / (double) (itemB->length.ival.denominator) ) * INCHES_TO_METERS;
    }
    else {
        val2 = itemB->length.mval;
    }
    
    if (val1 < val2)
        return -1;
    else if (val1 > val2)
        return 1;
    else
        return 0;

  return 0;
}

int main( int argc, char *argv[] )
{
  // Validate input arguments, and open the inventory input file.
  if ( argc != 2 )
    usage();

  FILE *fp = fopen( argv[ 1 ], "r" );
  if ( !fp ) {
    fprintf( stderr, "Can't open input file: %s\n", argv[ 1 ] );
    exit( EXIT_FAILURE );
  }

  // Read the inventory, first the number of items.
  int icount;
  if ( fscanf( fp, "%d", &icount ) != 1 )
    invalid();

  // Then, read all the inventory items.
  Item *ilist = (Item *) malloc( icount * sizeof( Item ) );
  for ( int i = 0; i < icount; i++ ) {
    // Read an item and store it in element i of ilist.
    // ...
      
      fscanf( fp, "%d", &ilist[i].sku );
      //printf("system is: %d\n", ilist[i].sku);
      char system;
      fscanf( fp, " %c", &system );
      if(system == 'i') {
          //printf("Imperial\n");
          ilist[i].mtype = imperial;
          fscanf( fp, "%d %d / %d", &ilist[i].length.ival.inches, &ilist[i].length.ival.numerator, &ilist[i].length.ival.denominator);
          //printf("%d %d and %d\n", ilist[i].length.ival.inches, ilist[i].length.ival.numerator, ilist[i].length.ival.denominator);
      }

      else {
          ilist[i].mtype = metric;
          fscanf( fp, "%lf", &ilist[i].length.mval );
          //printf("val is %lf\n", ilist[i].length.mval );
      }
      
      //printf("\ncount is %d\n", i);
//      char str[100];
//      fscanf( fp, "%[^\n]\n", str );
//
//      printf("%s\n", str);
//
//      sscanf(str, "%d %s")
  }
    
    //printf("\n\n");

  // Sort the items by length.
  qsort( ilist, icount, sizeof( Item ), itemComp );

  // Print out the sorted list, in the same format as the input.
  printf( "%d\n", icount );
  for ( int i = 0; i < icount; i++ ) {
    // Print item i from ilist, with a real-valued length if it's metric, or
    // as a mixed numeral if it's metric.
    // ...
      if(ilist[i].mtype == imperial)
          printf("%d i %d %d / %d\n", ilist[i].sku, ilist[i].length.ival.inches, ilist[i].length.ival.numerator, ilist[i].length.ival.denominator);
      else
          printf("%d m %lf\n", ilist[i].sku, ilist[i].length.mval );
  }

  // Free the resources and exit successfully.
  free( ilist );
  fclose( fp );
  return EXIT_SUCCESS;
}
