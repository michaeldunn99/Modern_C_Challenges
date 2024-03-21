#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <tgmath.h>
#include "helper-functions.h"

/*
* Declaration of two functions: 
* 1. matrix_mult: multiplies two matrices and returns the result
* 2. free_matrix: frees the memory allocated for a matrix
*/

#ifndef MATRIX_MULT
#define MATRIX_MULT

double** matrix_mult(size_t height_1, size_t width_1, double** matrix_1,  size_t height_2, size_t width_2, double** matrix_2);

void upper_echelon_form(size_t height, size_t width, double** matrix, double**elementary_matrix);

void echelon_form_column(size_t column, size_t* row_track, size_t matrix_height, size_t matrix_width, double**matrix, double**elementary_matrix);

void invert_matrix_print_result(size_t height, size_t width, double ** matrix, double**elementary_matrix, double**original_matrix, size_t question_number);



#endif
