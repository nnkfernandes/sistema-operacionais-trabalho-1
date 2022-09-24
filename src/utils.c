#include "utils.h"

int file_to_matrix ( int rows, int columns, float matrix[rows][columns])
{
  printf("hello");
  FILE * filePt ;

  char dataToBeRead[100];

  filePt = fopen("out/m1.txt", "r"); 

  if ( filePt == NULL )
  {
    printf("%s file failed to open.", "out/m1.txt");
    return -1;
  }

  fscanf(filePt, "%d %d\n", &rows, &columns);

  printf("n: %d, m: %d \n", rows, columns);

  for(int i = 0; i < rows; ++i)
  {
    for(int j = 0; j < columns; ++j)
    {
      fscanf(filePt, "c%*d %f\n", &matrix[i][j]);
    }
  }

  fclose(filePt);

  print_matrix(3, 3, matrix);

  return 0;
}

void print_matrix ( int rows, int columns, float matrix[ rows ][ columns ])
{
  for ( int i = 0; i < rows; ++i )
  {
    for ( int j = 0; j < columns; ++j )
    {
      printf("[%d, %d] = %.2f\n", i, j, matrix[i][j]);
    }
  }
}
