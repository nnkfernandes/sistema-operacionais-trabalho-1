#include "utils.h"

int main ( int argc, char **argv )
{

  // Checks if 2 arguments were given.
  if ( argc != 3 )
  {
    fprintf( stderr, "You need to give exactly 2 files path!" );
    exit( -1 );
  }

  int rows1, rows2, columns1, columns2;

  float** matrix1 = file_to_matrix(argv[1], &rows1, &columns1);
  float** matrix2 = file_to_matrix(argv[2], &rows2, &columns2);

  //print_matrix(columns1, rows1, matrix1);
  //print_matrix(columns2, rows2, matrix2);

  // Multiply the matrix

  if(columns1==rows2)
  {
    float resultMatrix[rows2][columns1];
    for(int i = 0; i < rows1; ++i)
    {
      for(int j = 0; j < columns2; ++j)
      {
        resultMatrix[i][j] = 0;
        for(int k = 0; k < columns1; ++k)
        {
          resultMatrix[ i ][ j ] += matrix1[i][k]*matrix2[k][j];
          printf("%d - %d - %d | %.2f - %.2f - %.2f\n", i, j, k, resultMatrix[i][j], matrix1[i][k], matrix2[k][j]);
        }
      }
    }
    matrix_to_file ( "out/matrix-3-seq.out", rows2, columns1, resultMatrix);
  }
  else {
    fprintf( stderr, "Can't multiply the matrices. columns1!=rows2" );
    exit( -1 );
  }


  for (int i = 0; i < rows1; i++)
    free(matrix1[i]);

  free(matrix1);

  for (int i = 0; i < rows2; i++)
    free(matrix2[i]);

  free(matrix2);
  return 0;
}
