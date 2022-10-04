#include "utils.h"

int matrix_to_file ( char filePath[], int rows, int columns, float matrix[ rows ][ columns ])
{
  FILE *filePt;

  filePt = fopen(filePath, "w");

  if(filePt == NULL)
  {
    fprintf( stderr, "File doest exist!" );
    return -1;
  }

  fprintf(filePt,"%d %d\n", rows, columns);

  for ( int i = 0; i < rows; ++i )
  {
    for ( int j = 0; j < columns; ++j )
    {
      fprintf(filePt,"c%d%d %.2f\n", i+1, j+1,  matrix[ i ][ j ]);
    }
  }

  fclose(filePt);

  return 0;
}

float** file_to_matrix (char filePath[], int* rows, int* columns)
{
  FILE * filePt ;

  char dataToBeRead[100];

  filePt = fopen(filePath, "r"); 

  if ( filePt == NULL )
  {
    printf("%s file failed to open.", filePath);
    exit( -1 );
  }

  fscanf(filePt, "%d %d\n", rows, columns);

  printf("n: %d, m: %d \n", *rows, *columns);

  float** matrix = (float**)calloc(*rows, sizeof(float*));

  if (matrix == NULL) {
    printf("Unable to allocate memory\n");
    exit( -1 );
  }

  for(int i = 0; i < *rows; ++i)
  {
    matrix[i] = (float*)calloc(*columns, sizeof(float));
    for(int j = 0; j < *columns; ++j)
    {
      fscanf(filePt, "c%*d %f\n", &matrix[i][j]);
      printf("[%d, %d]: %.2f\n", i, j, matrix[i][j]);
    }
  }

  fclose(filePt);

  return matrix;
}

void print_matrix ( int rows, int columns, float** matrix)
{
  for ( int i = 0; i < rows; ++i )
  {
    for ( int j = 0; j < columns; ++j )
    {
      printf("[%d, %d]: %.2f\n", i, j, matrix[i][j]);
    }
  }
}
