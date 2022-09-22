#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main( )
{

    FILE *filePointer ;
     
    char dataToBeRead[100];
    
    filePointer = fopen("out/m1.txt", "r"); 
    if ( filePointer == NULL )
    {
        printf( "m1.txt file failed to open.") ;

        return 1;
    }

    int n1, m1;

    fscanf(filePointer, "%d %d\n", &n1, &m1);

    printf("n: %d, m: %d \n", n1, m1);


    float M1 [ n1 ][ m1 ];
    int i, j;
    for(i = 0; i < n1; ++i)
    {
        for(j = 0; j < m1; ++j)
        {
            fscanf(filePointer, "c%*d %f\n", &M1[i][j]);
        }
    }

    for(i = 0; i < n1; ++i)
    {
        for(j = 0; j < m1; ++j)
        {
            printf("%.2f ", M1[i][j]);
        }
        printf("\n");
    }
    

    fclose(filePointer);

    filePointer = fopen("out/m2.txt", "r"); 

    int n2, m2;

    fscanf(filePointer, "%d %d\n", &n2, &m2);

    float M2 [ n2 ][ m2 ];

    for(i = 0; i < n2; ++i)
    {
        for(j = 0; j < m2; ++j)
        {
            fscanf(filePointer, "c%*d %f\n", &M2[i][j]);
        }
    }
    for(i = 0; i < n2; ++i)
    {
        for(j = 0; j < m2; ++j)
        {
            printf("%.2f ", M2[i][j]);
        }
        printf("\n");
    }

    fclose(filePointer);

    int n3 = n1;
    int m3 = m2;
    float M3 [ n3 ][ m3 ];
    

    if(m1==n2)
    {
        for(i = 0; i < n3; ++i)
        {
            for(j = 0; j < m3; ++j)
            {
                for(int k = 0; k < m1; ++k)
                {
                    M3[ i ][ j ] += M1[i+k][j]*M2[i][j+k];
                    printf("%d %d - %d %d - %d %d\n", i, j, i+k, j, i, j+k);
                    printf("%.2f - %.2f - %.2f\n", M3[i][j], M1[i+k][j], M1[i][j+k]);
                }
            }
        }
    }


    return 0;
}

 