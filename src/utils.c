#include "utils.h"

int file_to_matrix ( char* filePath , int rows, int columns, float matrix[rows][columns])
{
  FILE * filePt ;

  char dataToBeRead[100];

  filePt = fopen(filePath, "r"); 

  if ( filePt == NULL )
  {
    printf("%s file failed to open.", filePath);
    return -1;
  }

  fscanf(filePt, "%d %d\n", &rows, &columns);

  //printf("n: %d, m: %d \n", rows, columns);

  for(int i = 0; i < rows; ++i)
  {
    for(int j = 0; j < columns; ++j)
    {
      fscanf(filePt, "c%*d %f\n", matrix[i][j]);
    }
  }

  fclose(filePt);

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
