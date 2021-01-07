#include <stdio.h>
#include <stdlib.h>

// Put your macro definitions here.  That should be all
// you need to do to complete this exercise.

#define DECL_LIST(type, l) \
int l##_cap = 5; \
int l##_len = 0; \
type *l = (type *) malloc( l##_cap * sizeof( type ) )

#define CHECK_CAP(type, l) \
if ( l##_len >= l##_cap ) { \
  l##_cap *= 2; \
  l = (type *) realloc( l, l##_cap * sizeof( type ) ); \
}

#define SIZE(l) l##_len

#define FOR(num, len) for ( int num = 0; num < len; num++ )

#define SWAP(type, a, b) \
{ \
  type temp = a; \
  a = b; \
  b = temp; \
}

// ...

int main()
{
  // Make a resizable list.
  DECL_LIST( double, list );

  double val;
  while ( scanf( "%lf", &val ) == 1 ) {
    // Grow the list when needed.
    CHECK_CAP( double, list );

    // Add this item to the list
    list[ SIZE( list ) ] = val;
    SIZE( list ) += 1;
  }

  // Bubble-sort the list.
  FOR( i, SIZE( list ) )
    FOR( j, SIZE( list ) - i - 1 )
      if ( list[ j ] > list[ j + 1 ] )
        SWAP( double, list[ j ], list[ j + 1 ] );

  // Print out the resulting, sorted list, one value per line.
  FOR( i, SIZE( list ) )
    printf( "%.2f\n", list[ i ] );
  
  return EXIT_SUCCESS;
}
