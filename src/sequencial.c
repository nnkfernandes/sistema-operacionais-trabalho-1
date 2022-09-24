#include "utils.h"

int main ()
{
  int rows1, rows2, columns1, columns2;
  rows1 = rows2 = columns1 = columns2 = 3;

  float matrix1[rows1][columns1];
  float matrix2[rows2][columns2];

  float matrix3[rows1][columns2];

  file_to_matrix("out/m1.txt", rows1, columns1, matrix1);

  print_matrix(3, 3, matrix1);

  //if(columns1==rows2)
  //{
  //  for(i = 0; i < rows1; ++i)
  //  {
  //    for(j = 0; j < columns2; ++j)
  //    {
  //      M3[i][j] = 0;
  //      for(int k = 0; k < columns1; ++k)
  //      {
  //        resultMatrix[ i ][ j ] += matrix1[i][k]*matrix2[k][j];
  //        //printf("%d - %d - %d | %.2f - %.2f - %.2f\n", i, j, k, M3[i][j], M1[i][k], M2[k][j]);
  //      }
  //      //printf("%.2f ", M3[i][j]);
  //    }
  //    //printf("\n");
  //  }
  //}

  return 0;
}
