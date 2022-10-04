#include "auxiliate.h"

int populate_random_matrix (int rows, int columns, float matrix [ rows ][ columns ])
{
  for ( int i = 0; i < rows; ++i )
  {
    for ( int j = 0; j < columns; ++j )
    {
      // Create [0, 99] rowsumbers.
      //matrix[ i ][ j ] = ((float)rand()/(float)(RAND_MAX)) * 99.0;
      matrix[ i ][ j ] = 2;
    }
  }
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

  rows1 = atoi( argv[1] );
  columns1 = atoi( argv[2] );
  rows2 = atoi( argv[3] );
  columns2 = atoi( argv[4] );

  float matrix1[ rows1 ][ columns1 ], matrix2[ rows2 ][ columns2 ];


  populate_random_matrix (rows1, columns1, matrix1);
  populate_random_matrix (rows2, columns2, matrix2);

  matrix_to_file ( "out/matrix-1.out", rows1, columns1, matrix1);
  matrix_to_file ( "out/matrix-2.out", rows2, columns2, matrix2);

  return 0;
}
