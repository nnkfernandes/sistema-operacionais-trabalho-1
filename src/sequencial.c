#include "utils.h"
#include <time.h>

int main ( int argc, char** argv )
{

  // Checks if 2 arguments were given.
  if ( argc != 3 )
  {
    fprintf ( stderr, "You need to give exactly 2 files path!" );
    exit ( -1 );
  }

  int rows1, rows2, columns1, columns2;

  double** matrix1 = file_to_matrix ( argv[1], &rows1, &columns1 );
  double** matrix2 = file_to_matrix ( argv[2], &rows2, &columns2 );
  double** resultMatrix;

  //print_matrix(columns1, rows1, matrix1);
  //print_matrix(columns2, rows2, matrix2);

  // Multiply the matrices

  if ( columns1==rows2 )
  {
    clock_t time = clock();
    resultMatrix = ( double** ) calloc ( rows1, sizeof ( double* ) );
    for ( int i = 0; i < rows1; ++i )
    {
      resultMatrix[i] = ( double* ) calloc ( columns2, sizeof ( double ) );
      for ( int j = 0; j < columns2; ++j )
      {
        for ( int k = 0; k < rows2; ++k )
        {
          resultMatrix[ i ][ j ] += matrix1[i][k] * matrix2[k][j];
          printf ( "%d - %d - %d | %.2f - %.2f - %.2f\n", i, j, k, resultMatrix[i][j], matrix1[i][k], matrix2[k][j] );
        }
      }
    }

    print_matrix ( rows1, columns2, resultMatrix );
    printf ( "End multi\n" );
    time = clock() - time;
    double cpuTimeUsed = ( ( double ) time ) / CLOCKS_PER_SEC;
    printf ( "End multi\n" );
    matrix_to_file ( "out/matrix-3-seq.out", rows1, columns2, resultMatrix );
    printf ( "End multi\n" );
    cpu_time_to_file ( "out/matrix-3-seq.out", cpuTimeUsed );
    printf ( "End multi\n" );
  }
  else
  {
    fprintf ( stderr, "Can't multiply the matrices. columns1!=rows2" );
    exit ( -1 );
  }

  for ( int i = 0; i < rows1; i++ )
    free ( matrix1[i] );

  free ( matrix1 );

  for ( int i = 0; i < rows2; i++ )
    free ( matrix2[i] );

  free ( matrix2 );

  for ( int i = 0; i < rows2; i++ )
    free ( resultMatrix[i] );

  free ( resultMatrix );
  return 0;
}
