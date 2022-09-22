#include <stdio.h>
#include <stdlib.h>


int main( )
{
 
    FILE *filePointer ;
     
    char dataToBeRead[100];
    
    filePointer = fopen("../out/m1.txt", "r"); 
    if ( filePointer == NULL )
    {
        printf( "m1.txt file failed to open." ) ;

        return 1;
    }

    int n, m;

    fscanf(filePointer, "%d %d", &n, &m);

    printf("n: %d, m: %d", n, m);
    

}

