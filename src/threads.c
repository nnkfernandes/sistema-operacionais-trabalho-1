#include "utils.h"
#include <time.h>
#include <pthread.h>

struct threadData
{
  double** matrix1;
  double** matrix2;
  double** resultMatrix;
  int rows1;
  int columns2;
  int rows2;
  int start;
  int end;
  int threadNum;
};

void* multiply_matrices ( void* threadArgs )
{

  //time = clock() - time;
  //double cpuTimeUsed = ( ( double ) time ) / CLOCKS_PER_SEC;
  //matrix_to_file ( "out/matrix-3-seq.out", rows2, columns1, resultMatrix );
  //cpu_time_to_file ( "out/matrix-3-seq.out", cpuTimeUsed );
  struct threadData* data;
  data = ( struct threadData* ) threadArgs;

  double** matrix1 = data->matrix1;
  double** matrix2 = data->matrix2;
  double** resultMatrix = data->resultMatrix;
  int rows1 = data->rows1;
  int columns2 = data->columns2;
  int rows2 = data->rows2;
  int start = data->start;
  int end = data->end;
  int threadNum = data->threadNum;

  int i;
  int j;
  printf ( "%d - %d - %d\n", threadNum, start, end );

  while ( start < end+1 )
  {
    i = start/columns2;
    j = start%columns2;

    for ( int k = 0; k < rows2; ++k )
    {
      resultMatrix[ i ][ j ] += matrix1[i][k] * matrix2[k][j];
    }

    printf ( "%d - [%d, %d] = %.2f | %.2f | %.2f\n",
             threadNum, i, j, resultMatrix[i][j], matrix1[i][j], matrix2[i][j] );
    ++start;
  }

}

int main ( int argc, char** argv )
{

  // Checks if 3 arguments were given.
  if ( argc != 4 )
  {
    fprintf ( stderr, "You need to give exactly 2 files path and a partition number!" );
    exit ( -1 );
  }

  int rows1, rows2, columns1, columns2, partitions = atoi ( argv[3] );

  double** matrix1 = file_to_matrix ( argv[1], &rows1, &columns1 );
  double** matrix2 = file_to_matrix ( argv[2], &rows2, &columns2 );
  double** resultMatrix;

  // Checks if the matrices multiplication is possible.
  if ( columns1 == rows2 )
  {
    pthread_t threads[partitions];
    struct threadData data[partitions];

    resultMatrix = ( double** ) calloc ( rows2, sizeof ( double* ) );

    int matrixSize = rows1 * columns2;
    // TODO: can bug: -1
    int elPerPart = ( matrixSize / partitions ) - 1;
    int partRemaind = matrixSize % partitions;

    printf ( "In main: %d - %d - %d\n", matrixSize, elPerPart, partRemaind );

    int start = 0;

    int i;

    resultMatrix = ( double** ) calloc ( rows1, sizeof ( double* ) );
    for ( int i = 0; i < rows1; ++i )
    {
      resultMatrix[i] = ( double* ) calloc ( columns2, sizeof ( double ) );
    }

    for ( i = 0; i < partitions; ++i )
    {
      data[i].matrix1 = matrix1;
      data[i].matrix2 = matrix2;
      data[i].resultMatrix = resultMatrix;
      data[i].rows1 = rows1;
      data[i].columns2 = columns2;
      data[i].rows2 = rows2;
      data[i].start = start;
      data[i].end = start + elPerPart;
      if ( i == partitions - 1 )
        data[i].end += partRemaind;
      data[i].threadNum = i;

      if ( pthread_create ( &threads[i], NULL, &multiply_matrices, ( void* ) &data[i] ) )
      {
        fprintf ( stderr, "Can't create thread!\n" );
        exit ( -2 );
      }
      start = data[i].end + 1;
    }

    for ( i = 0; i < partitions; ++i )
    {
      if ( pthread_join ( threads[i], NULL ) )
      {
        fprintf ( stderr, "Can't join thread!\n" );
        exit ( -3 );
      }
    }

  }
  else
  {
    fprintf ( stderr, "Can't multiply the matrices. columns1!=rows2" );
    exit ( -1 );
  }

  // Free the memory.

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
