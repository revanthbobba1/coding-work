#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void readGrid( int rows, int cols, int grid[ rows ][ cols ] )
{
  // Add code to read in all the elements of grid from standard input.
  // ...
    
    
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            grid[i][j] = 0;
        }
    }
    
//    for(int i = 0; i < rows; i++) {
//        for(int j = 0; j < cols; j++) {
//            printf("%d ", grid[i][j]);
//        }
//        printf("\n");
//    }
    
    for(int i = 0; i < rows; i++) {
        
        if(i == 0 || i == rows - 1) {
            for(int j = 0; j < cols; j++) {
                grid[i][j] = 0;
            }
        }
        
        else {
            grid[i][0] = 0;
                
            for(int j = 1; j < cols - 1; j++) {
                
                int num = 0;
                scanf("%d", &num);
                grid[i][j] = num;
                
                int c = getchar();
                if(c == '\n')
                    break;

            }
            
            grid[i][cols - 1] = 0;
        }
        
    }
}

// Add parameters to to pass a variable-sized array to the following
// function.  It's the same as the previous function, but I want you
// to get a chance to type it in yourself.
void reportMaxima(int rows, int cols, int grid[rows][cols])
{
  // Add code to find local maxima and print them out in row major order.
  // ...
        
    for(int i = 1; i < rows - 1; i++) {
        for(int j = 1; j < cols - 1; j++) {
            int max = grid[i][j];

            
            if(grid[i-1][j-1] > max) {
                continue;

            }
            
            if(grid[i-1][j] >= max ||
               grid[i-1][j+1] >= max ||
               grid[i][j-1] >= max ||
               grid[i][j+1] >= max ||
               grid[i+1][j-1] >= max ||
               grid[i+1][j] >= max ||
               grid[i+1][j+1] >= max) {
                continue;
            }
            
            printf("%d %d\n", i - 1, j - 1);

        }
    }
    
}

int main()
{
  // Add code to read in the grid size from standard input.
  // ...
    int rows = 0;
    int cols = 0;
    
    scanf("%d %d", &rows, &cols);

  // Declare a variable-sized array to hold the grid.
  // ...
    
    int grid[rows + 2][cols + 2];

  // Call readGrid() to populate the array.
  // ...
    
    readGrid(rows + 2, cols + 2, grid);
  
  // Call reportMaxima() to print out all local maxima.
  // ...
    
    reportMaxima(rows + 2, cols + 2, grid);
  
  return EXIT_SUCCESS;
}
