#include "helper-functions.h"
#include "definitions.h"

/**
 * Prints a matrix with side borders.
 *
 * @param matrix The matrix to be printed.
 * @param height The number of rows in the matrix.
 * @param width The number of columns in the matrix.
 */
void print_matrix(double** matrix, size_t height, size_t width) {
   
    //Print the multiplied matrix by printing the matrix values and adding borders

    //Print the side border and matrix values, line by line
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            if (width-1 == 0) {
                if (matrix[i][j] < -EPS) {
                    printf("|%.2f|\n", matrix[i][j]);
                } else {
                    printf("| %.2f|\n", matrix[i][j]);
                }
            }
            else if (j == 0) {
                if (matrix[i][j] < -EPS){
                    printf("|%.2f", matrix[i][j]);
                }
                else {
                    printf("| %.2f", matrix[i][j]);
                }
            }
            else if (j == width-1) {
                if (matrix[i][j] < -EPS){
                    printf(" %.2f|\n", matrix[i][j]);
                } else {
                    printf("  %.2f|\n", matrix[i][j]);
                }
            }
            else {
                if (matrix[i][j] < -EPS) {
                    printf(" %.2f", matrix[i][j]);
                } else {
                    printf("  %.2f", matrix[i][j]);
                }
                
            }
        }
    }
    printf("\n");
}

/* 
* Elementary Row Operation Function
* Multiply a row by a scalar
*/
void multiply_row_scalar(double scalar, double** matrix, size_t row, size_t starting_column, size_t width) {
    for (int j = 0; j < width; ++j) {
        matrix[row][j] *= scalar; 
    }
}


/*
* Elementary Row Operation Function
* Swap two rows
*/
void swap_rows(double** matrix, size_t row_1, size_t row_2, size_t width) {
    double temp_row[width]; 
    for (int j = 0; j < width; ++j) {
        //Read row 1 into temporary array
        temp_row[j] = matrix[row_1][j];
        //Read row 2 into row 1
        matrix[row_1][j] = matrix[row_2][j];
        //Read temp_row (original row 1) into row 2
        matrix[row_2][j] = temp_row[j];
    }
}


/* 
* Elementary Row Operation Function
* Add lambda times row 2 to row 1 
*/
void scalar_multiple_addition(double **matrix, double scalar, size_t row_1, size_t row_2, size_t width) {
    for (int j = 0; j < width; ++j) {
        matrix[row_1][j] += scalar * matrix[row_2][j]; 
    }
}


/**
 * @brief   The free_matrix function frees the memory allocated for a matrix.
 * @param matrix The matrix to be freed.
 * @param height The height of the matrix.
 * @return 0 if the function is successful.
 */
int free_matrix(double **matrix, size_t height) {
    for (size_t i = 0; i < height; ++i) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}

/*
Note that this must be called on a square matrix
*/
int check_identity(double ** matrix, size_t size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i!=j && (fabs(matrix[i][j]) > EPS)) {
                return -1;
            } else if (i==j && (fabs(matrix[i][j] - 1) > EPS)) {
                printf("Matrix is not invertible\n");
                return -1;
            }
        }
    }
    return 0;
}



