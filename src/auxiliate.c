#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main ( int argc, char **argv )
{
  srand(time(NULL));
  // Checks if 4 arguments were given.
  if ( argc != 5 )
  {
    fprintf( stderr, "You need to give exactly 4 arguments!" );
    exit( -1 );
  }

  //// Print all arguments.
  //for ( int i = 0; i < argc; ++i )
  //{
  //  printf( "argv[%d]: %s\n", i, argv[i] );
  //}

  int n1, n2, m1, m2;
  n1 = atoi( argv[1] );
  m1 = atoi( argv[2] );
  n2 = atoi( argv[3] );
  m2 = atoi( argv[4] );

  int M1[ n1 ][ m1 ], M2[ n2 ][ m2 ];
  // Populate M1.
  for ( int i = 0; i < n1; ++i )
  {
    for ( int j = 0; j < m1; ++j )
    {
      M1[ i ][ j ] = rand() % 8;
    }
  }

  // Populate M2.
  for ( int i = 0; i < n2; ++i )
  {
    for ( int j = 0; j < m2; ++j )
    {
      M2[ i ][ j ] = rand() % 8;
    }
  }

  for ( int i = 0; i < n1; ++i )
  {
    for ( int j = 0; j < m1; ++j )
    {
      printf("%d", M1[ i ][ j ]);
    }
    printf("\n");
  }

  for ( int i = 0; i < n2; ++i )
  {
    for ( int j = 0; j < m2; ++j )
    {
      printf("%d", M2[ i ][ j ]);
    }
    printf("\n");
  }
   return 0;
}
