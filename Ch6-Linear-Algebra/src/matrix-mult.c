#include "matrix-mult.h"
#include "definitions.h"

 
/**
 * @brief This file includes the following helper functions: 
        - matrix_mult: Multiplies two matrices and returns a pointer to the result (or calls exit if the matrices cannot be multiplied)

        - free_matrix: Frees the memory allocated for a matrix

        - upper_echelon_form: Puts a matrix in upper echelon form and performs the same operations on an elementary matrix (to generate the inverse if applicable)

        - echelon_form_column: Puts a column in row reduced echelon form, and updates the elementary matrix accordingly (this function is called by upper_echelon_form)

        - invert_matrix_print_result:   Puts a matrix in upper echelon form by calling the upper_echelon_form function. Prints the result of the inversion (if applicable) and 
                                        the result of multiplying the original matrix with the calculated inverse (if applicable). In doing so, it dynamically allocates memory 
                                        for the result of the matrix multiplication and frees the memory after printing the result.

        More detailed explanation of each function is provided in the comments above the function definition 
*/


/**
 * @brief   The matrix_mult function muliplies two matrices, allocating memory dynamically for the resulting matrix and returns a pointer to the multplied matrix result. 
 *          The function calls the exit function if the matrices cannot be multiplied.
 *          The caller must remember to free the memory allocated for the multiplied matrix.
 * @param height_1 The height of the first matrix.
 * @param width_1 The width of the first matrix.
 * @param matrix_1 The first matrix.
 * @param height_2 The height of the second matrix.
 * @param width_2 The width of the second matrix.
 * @param matrix_2 The second matrix.
 * @return A pointer to the multiplied matrix.
 */
double** matrix_mult(size_t height_1, size_t width_1, double** matrix_1, size_t height_2, size_t width_2, double** matrix_2) {
    if (width_1 != height_2) {
        printf("Cannot multiply matrices - must have width_1 == height_2\nHOWEVER, %zu != %zu\n", width_1, height_2);
        // Maybe call exit here (is it OK to exit from a function that is not main)
        exit(-1);
    }
    double **multiplied_matrix = malloc(sizeof(double*)*height_1);
    if (multiplied_matrix == NULL) {
        printf("Memory allocation failed");
        exit(-1);
    }
    for (size_t i = 0; i < height_1; ++i) {
        multiplied_matrix[i] = malloc(sizeof(double)*width_2);
        if (multiplied_matrix[i] == NULL) {
            printf("Memory allocation failed");
            exit(-1);
        }
        for (int j = 0; j < width_2; ++j) {
            for (int k = 0; k < height_2; ++k) {
                multiplied_matrix[i][j] += matrix_1[i][k]*matrix_2[k][j];
            }
            if (fabs(multiplied_matrix[i][j]) < EPS) {
                (multiplied_matrix[i][j]) = 0.00;
            }
        }
    }

    //Return a pointer to the multipled matrix
    return multiplied_matrix;
}

/**
 * @brief   Transforms a matrix into upper echelon form using elementary row operations, and performs the same operations on an elementary matrix to generate the inverse if applicable.
 *          This function iteratively calls the echelon_form_column function below to transform each column of the matrix.
 *
 * @param height The number of rows in the matrix.
 * @param width The number of columns in the matrix.
 * @param matrix The input matrix to be transformed.
 * @param elementary_matrix The elementary matrix to be transformed according to the EROs applied to 'matrix'. 
 *                          It is assumed here that the caller passes an identity matrix of the same dimensions as 'matrix'.
 */
void upper_echelon_form(size_t height, size_t width, double** matrix, double**elementary_matrix) {
    
    //row_track is the tracker for the row (how far down) the leading 1 of a given column needs to be (if exists)
    size_t *row_track = malloc(sizeof(size_t));
    *row_track = 0;
    
    for (int j = 0; j < width; ++j) {
        echelon_form_column(j, row_track, height, width, matrix, elementary_matrix);
        if (*row_track == height) {
            break;
        }
    }
    free(row_track);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (fabs(matrix[i][j]) < EPS) {
                (matrix[i][j]) = 0.00;
            }
        }
    }
}

/**
 * @brief   Calculates the echelon form of particular row of a matrix by performing elementary row operations on a specific column, and the same operations on an elementary matrix.
 *          The function is called by the upper_echelon_form function.
 *
 * @param column The column index on which the elementary row operations will be performed.
 * @param row_track An array to keep track of the current row index for each column.
 * @param matrix_height The number of rows in the matrix.
 * @param matrix_width The number of columns in the matrix.
 * @param matrix The input matrix to be transformed.
 * @param elementary_matrix The elemetnary matrix on which the same elementary row operations are performed as on 'matrix'.
 *                          It is assumed here that the caller passes an identity matrix of the same dimensions as 'matrix'.
 */
void echelon_form_column(size_t column, size_t* row_track, size_t matrix_height, size_t matrix_width, double** matrix, double** elementary_matrix) {

    /*
    * If row_track entry is zero, swap it with the first-non-zero entry
    * If now non-zero entries, return
    */ 
    if (fabs(matrix[*row_track][column]) < EPS) {
        if ((*row_track)+1 == matrix_height) {
            return;
        }

        //Loop through the rows below until one is non-zero, and swap that with row_track
        for (int i = (*row_track)+1 ; i < matrix_height; ++i) {
            if (fabs(matrix[i][column])> EPS) {
                swap_rows(matrix, *row_track, i, matrix_width);
                swap_rows(elementary_matrix, *row_track, i, matrix_width);
                break;
            }
            //Return if all rows from row track down are zero
            if (i == matrix_height -1) {
                return;
            }
        }
    }

    /*
    * If the first entry is not one, multiply the row by its reciprocal
    * Note: This entry shouldn't be zero (because function would have return by then, with every row in column being zero) 
    * but we have checked anyway
    */
    if ((fabs(matrix[*row_track][column]) > EPS) && (fabs(matrix[*row_track][column]-1)>EPS)) {
        double scalar_matrix = 1 / matrix[*row_track][column];
        //double scalar_elementary = 1 / elementary_matrix[*row_track][column];
        multiply_row_scalar(scalar_matrix, matrix, *row_track, column, matrix_width);
        multiply_row_scalar(scalar_matrix, elementary_matrix, *row_track, column, matrix_width);
    }

    /*
    * Put column in row_reduced echelon form (We assume now that row_track entry has a value of 1)
    */
    for (int i = 0; i < matrix_height; ++i) {
        if ( i== *(row_track)) {
            continue;
        }
        if (fabs(matrix[i][column])> EPS) {
            double scalar_matrix = (- matrix[i][column]);
            //double scalar_elementary = (- elementary_matrix[i][column]);
            scalar_multiple_addition(matrix, scalar_matrix, i, *row_track, matrix_width);
            scalar_multiple_addition(elementary_matrix, scalar_matrix, i, *row_track, matrix_width);
        }
    }
    ++(*row_track);
}

/**
 * @brief   Inverts a matrix by calling the upper_echelon_form function and prints the result of the inversion (if applicable) else prints that the matrix is not invertible. 
 *          and also prints the result of multiplying the original matrix with the calculated inverse (if applicable) as a check (this result should be the identity matrix).
 *          The function also frees the memory allocated for the result of the matrix multiplication.
 *
 * @param height The height of the matrix.
 * @param width The width of the matrix.
 * @param matrix The matrix to be inverted.
 * @param elementary_matrix The elementary matrix to be transformed according to the EROs applied to 'matrix'
 *                          It is assumed here that the caller passes an identity matrix of the same dimensions as 'matrix'. 
 * @param original_matrix The original matrix before inversion (to be multiplied with the calculated inverse as a check).
 * @param question_number The number of the question (for printing purposes).
 */
void invert_matrix_print_result(size_t height, size_t width, double ** matrix, double**elementary_matrix, double**original_matrix, size_t question_number) {
    // Perform row operations to convert the matrix into upper echelon form
    upper_echelon_form(height, width, matrix, elementary_matrix);
    
    // Multiply the original matrix with the transformed elementary matrix (assumed to be transformed into the inverse of the original matrix)
    double **matrix_mult_check = matrix_mult(height, width,elementary_matrix, height, width, original_matrix);
    
    // Print the original matrix
    printf("Q4 - Original matrix %zu:\n", question_number);
    print_matrix(original_matrix, height, width);
    
    // Check if the matrix is invertible (i.e. if the transformed matrix in question is the identity matrix)
    if (!check_identity(matrix, height)) {
        // Print the calculated inverse
        printf("Inverse of matrix %zu:\n",question_number);
        print_matrix(elementary_matrix, height, width);
        
        // Print the result of multiplying the original matrix with the calculated inverse (if not the identity matrix, then the matrix is not invertible)
        
        if (!check_identity(matrix_mult_check, height)) {
            printf("Check: Result of matrix multiplying matrix %zu with calculated inverse (i.e should be the identity matrix):\n", question_number);
            print_matrix(matrix_mult_check, height, width);
        }
    } else {
        printf("Matrix %zu is not invertible\n", question_number);
    }
    
    // Free the memory allocated for matrix_mult_check
    free(matrix_mult_check);
}

