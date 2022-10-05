#ifndef UTILS
#define UTILS

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int matrix_to_file ( char filePath[], int rows, int columns, float matrix[ rows ][ columns ]);

int cpu_time_to_file(char filePath[], double cpuTimeUsed);

float** file_to_matrix (char filePath[], int* rows, int* columns);

void print_matrix ( int rows, int columns, float** matrix);

#endif
