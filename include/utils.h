#ifndef UTILS
#define UTILS

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int matrix_to_file ( char filePath[], int rows, int columns, double** matrix);

int cpu_time_to_file(char filePath[], double cpuTimeUsed);

double** file_to_matrix (char filePath[], int* rows, int* columns);

void print_matrix ( int rows, int columns, double** matrix);

#endif
