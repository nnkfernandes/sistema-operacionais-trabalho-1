#include "auxiliate.h"

double** populate_random_matrix (int rows, int columns)
{
  double** matrix = (double**)calloc(rows, sizeof(double*));

  if (matrix == NULL) 
  {
    printf("Unable to allocate memory\n");
    exit( -1 );
  }

  for(int i = 0; i < rows; ++i)
  {
    matrix[i] = (double*)calloc(columns, sizeof(double));
    for(int j = 0; j < columns; ++j)
    {
      matrix[ i ][ j ] = ((double)rand()/(double)(RAND_MAX)) * 99.0;
    }
  }

  return matrix;
}

int main ( int argc, char **argv )
{
  srand((unsigned int)time(NULL));

  // Checks if 4 arguments were given.
  if ( argc != 5 )
  {
    fprintf( stderr, "You need to give exactly 4 arguments!" );
    exit( -1 );
  }

  int rows1, rows2, columns1, columns2;

  printf("hello");
  rows1 = atoi( argv[1] );
  columns1 = atoi( argv[2] );
  rows2 = atoi( argv[3] );
  columns2 = atoi( argv[4] );

  double** matrix1;
  double** matrix2;

  printf("Hello");
  matrix1 = populate_random_matrix (rows1, columns1);
  matrix2 = populate_random_matrix (rows2, columns2);

  matrix_to_file ( "out/matrix-1.out", rows1, columns1, matrix1);
  matrix_to_file ( "out/matrix-2.out", rows2, columns2, matrix2);


  for (int i = 0; i < rows1; i++)
    free(matrix1[i]);

  free(matrix1);

  for (int i = 0; i < rows2; i++)
    free(matrix2[i]);

  free(matrix2);

  return 0;
}
