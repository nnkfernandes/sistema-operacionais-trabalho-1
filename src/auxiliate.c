#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main ( int argc, char **argv )
{
  srand((unsigned int)time(NULL));

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
  int i, j;

  // Populate M1.
  for ( i = 0; i < n1; ++i )
  {
    for ( j = 0; j < m1; ++j )
    {
      M1[ i ][ j ] = ((float)rand()/(float)(RAND_MAX)) * 99.0;
    }
  }

  // Populate M2.
  for ( i = 0; i < n2; ++i )
  {
    for ( j = 0; j < m2; ++j )
    {
      M2[ i ][ j ] = ((float)rand()/(float)(RAND_MAX)) * 99.0;
    }
  }

  for ( i = 0; i < n1; ++i )
  {
    for ( j = 0; j < m1; ++j )
    {
      printf("%f.2 ", M1[ i ][ j ]);
    }
    printf("\n");
  }

  FILE *fptr;

  fptr = fopen("out/M1.out","w");

  if(fptr == NULL)
  {
    fprintf( stderr, "File doest exist!" );
    exit(1);
  }

  fprintf(fptr,"%d %d\n", n1, m1);
  for ( i = 0; i < n1; ++i )
  {
    for ( j = 0; j < m1; ++j )
    {
      fprintf(fptr,"c%d%d %.2f\n", i+1, j+1, M1[ i ][ j ]);
    }
  }

  fclose(fptr);

  fptr = fopen("out/M2.out","w");

  if(fptr == NULL)
  {
    fprintf( stderr, "File doest exist!" );
    exit(1);
  }

  fprintf(fptr,"%d %d\n", n1, m1);
  for ( i = 0; i < n2; ++i )
  {
    for ( j = 0; j < m2; ++j )
    {
      fprintf(fptr,"c%d%d %.2f\n", i+1, j+1, M2[ i ][ j ]);
    }
  }

  fclose(fptr);

  return 0;
}
