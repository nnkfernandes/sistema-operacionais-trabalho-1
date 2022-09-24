#include "auxiliate.h"

int populate_random_matrix (int ** matrix, int rows, int columns)
{
  srand((unsigned int)time(NULL));

  for ( int i = 0; i < rows; ++i )
  {
    for ( int j = 0; j < columns; ++j )
    {
      // Create [0, 99] rowsumbers. matrix[ i ][ j ] = ((float)rand()/(float)(RAND_MAX)) * 99.0; } }
}
}
}

int matrix_to_file (int **  matrix, int rows, int columns, char filePath[])
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

int main ( int argc, char **argv )
{
  printf("in main");
  // Checks if 4 arguments were given.
  if ( argc != 5 )
  {
    fprintf( stderr, "You need to give exactly 4 arguments!" );
    exit( -1 );
  }

  int n1, n2, m1, m2;
  n1 = atoi( argv[1] );
  m1 = atoi( argv[2] );
  n2 = atoi( argv[3] );
  m2 = atoi( argv[4] );

  float M1[ n1 ][ m1 ], M2[ n2 ][ m2 ];

  printf("Hello\n");
  return 0;
}
