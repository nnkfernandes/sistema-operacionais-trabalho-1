#ifndef UTILS
#define UTILS

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int file_to_matrix ( int rows, int columns, float matrix[rows][columns]);

void print_matrix ( int rows, int columns, float matrix[ rows ][ columns ]);

#endif
