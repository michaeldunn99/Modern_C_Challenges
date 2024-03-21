#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

#ifndef HELPER_FUNCTIONS
#define HELPER_FUNCTIONS
void print_matrix(double** matrix, size_t height, size_t width);

void multiply_row_scalar(double scalar, double** matrix, size_t row, size_t starting_column, size_t width);

void scalar_multiple_addition(double **matrix, double scalar, size_t row_1, size_t row_2, size_t width);

void swap_rows(double** matrix, size_t row_1, size_t row_2, size_t width);

int free_matrix(double **matrix, size_t height);

int check_identity(double ** matrix, size_t size);

#endif