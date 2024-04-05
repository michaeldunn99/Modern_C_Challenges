#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <tgmath.h>
#include "matrix-mult.h"
#include "definitions.h"
#include "helper-functions.h"




/**
* @brief This programme is a solution to Challenge 6 of Modern C by Jens Gustedt, which is posed as:
*
*    "Some of the most important problems for which arrays are used stem from linear algebra.
*    Can you write functions that do vector-to-vector or matrix-to-vector products at this point?
*    What about Gauß elimination or iterative algorithms for matrix inversion?"
*
* In my first linear algebra course at University (Oxford Univeristy, Prelims, 2017,'Linear Algebra I') we were asked in Problem Sheet II (see README.md)
*       Q2: "Use Elementary Row Operations (EROs) (Gauss Elimination) to reduce each of the following matrices to echelon form..."
*       Q4: "Use EROs (Gauss Elimination) to find the inverses of each of the following matrices..."
*
* As such, this programme provides solutions in C Code to these Problem Sheet questions. In doing so, it implements a function that multiplies two matrices, as well as 
* a functions that inverts a matrix using EROs (Gauss Elimination), thus fulfilling the requirements of the challenge.
*
* The questions posed by the Problem Sheet are as follows:
*   Question 2: Use Elementary Row Operations to reduce each of the following matrices to echelon form:
*
*       1. |2  4 -3  0|
*          |1 -4  3  0|
*          |3 -5  2  1|
*
*       2. |1  2  3  0|
*          |2  3  4  1|
*          |3  4  5  2|
*
*       3. |1  2  3  0|
*          |2  3  4  2|
*          |3  4  5  2|
*
*
*   Question 4: Use Elementary Row Operations to find the inverse of each of the following matrices:
*
*       1. |2 3|
*          |3 2|
* 
*       2. |1 1 0|
*          |1 0 1|
*          |0 1 1|
*
*       3. |1 -1  0  0|
*          |1  0 -1  0|
*          |1  0  0 -1|
*          |0  1  1  1|
*
*   When executed, this program will reduce the matrices to row reduced echelon form, and in doing so, 
*   find the inverses of the matrices (using a corresponding elementary matrix and applying the same EROs) if they are invertible.
*   The program will then print the resultant matirces to the console (as well as the original matrices for comparison).
*
*
*/


int main(void) {
    printf("\n");

/* **************************************************************************************************** */
/*  Question 2: Use Elementary Row Operations to reduce each of the following matrices to echelon form: */
/* **************************************************************************************************** */

/* ******************/
/*  Question 2(a)   */
/* **************** */


double Q2_matrix_1_stat[Q2_MATRIX_1_HEIGHT][Q2_MATRIX_1_WIDTH] = {
    {2,  4, -3, 0},
    {1, -4, 3, 0},
    {3, -5,  2, 1},
};

double **Q2_matrix_1 = malloc(sizeof(double*)*Q2_MATRIX_1_HEIGHT);
double **Q2_matrix_1_elementary = malloc(sizeof(double*)*Q2_MATRIX_1_HEIGHT);
double **Q2_matrix_1_original_copy = malloc(sizeof(double*)*Q2_MATRIX_1_HEIGHT);
    
// Copy the values from the statically allocated array to the dynamically allocated array
for (int i = 0; i < Q2_MATRIX_1_HEIGHT; i++) {
    Q2_matrix_1[i] = malloc(sizeof(double)*Q2_MATRIX_1_WIDTH);
    Q2_matrix_1_elementary[i] = malloc(sizeof(double)*Q2_MATRIX_1_WIDTH);
    Q2_matrix_1_original_copy[i] = malloc(sizeof(double)*Q2_MATRIX_1_WIDTH);
    for (int j = 0; j < Q2_MATRIX_1_WIDTH; j++) {
        Q2_matrix_1[i][j] = Q2_matrix_1_stat[i][j];
        Q2_matrix_1_original_copy[i][j] = Q2_matrix_1_stat[i][j];
        if (i==j) {
            Q2_matrix_1_elementary[i][j] = 1;
        } else  {
            Q2_matrix_1_elementary[i][j] = 0;
        }
    }
}

/*
* Call the upper echelon form function which applies Elementary Row Opertions to 'Q2_matrix_1', reducing it to row reduced upper echelon form.
*/
upper_echelon_form(Q2_MATRIX_1_HEIGHT, Q2_MATRIX_1_WIDTH, Q2_matrix_1, Q2_matrix_1_elementary);


/*
* Call the print_matrix function to print the orignal matrix and the result of the EROs on 'Q2_matrix_1' to the console (i.e. the row reduced upper echelon form)
*/
printf("Original Q2_matrix_1:\n");
print_matrix(Q2_matrix_1_original_copy, Q2_MATRIX_1_HEIGHT, Q2_MATRIX_1_WIDTH);
printf("Upper echelon form of Q2_matrix_1:\n");
print_matrix(Q2_matrix_1, Q2_MATRIX_1_HEIGHT, Q2_MATRIX_1_WIDTH);


/* ******************/
/*  Question 2(b)   */
/* **************** */

double Q2_matrix_2_stat[Q2_MATRIX_2_HEIGHT][Q2_MATRIX_2_WIDTH] = {
    {1, 2, 3, 0},
    {2, 3, 4, 1},
    {3, 4, 5, 2},
};

double **Q2_matrix_2 = malloc(sizeof(double*)*Q2_MATRIX_2_HEIGHT);
double **Q2_matrix_2_elementary = malloc(sizeof(double*)*Q2_MATRIX_2_HEIGHT);
double **Q2_matrix_2_original_copy = malloc(sizeof(double*)*Q2_MATRIX_2_HEIGHT);
    
// Copy the values from the statically allocated array to the dynamically allocated array
for (int i = 0; i < Q2_MATRIX_2_HEIGHT; i++) {
    Q2_matrix_2[i] = malloc(sizeof(double)*Q2_MATRIX_2_WIDTH);
    Q2_matrix_2_elementary[i] = malloc(sizeof(double)*Q2_MATRIX_2_WIDTH);
    Q2_matrix_2_original_copy[i] = malloc(sizeof(double)*Q2_MATRIX_2_WIDTH);
    for (int j = 0; j < Q4_MATRIX_2_WIDTH; j++) {
        Q2_matrix_2[i][j] = Q2_matrix_2_stat[i][j];
        Q2_matrix_2_original_copy[i][j] = Q2_matrix_2_stat[i][j];
        if (i==j) {
            Q2_matrix_2_elementary[i][j] = 1;
        } else  {
            Q2_matrix_2_elementary[i][j] = 0;
        }
    }
}

/*
* Call the upper echelon form function which applies Elementary Row Opertions to 'Q2_matrix_2', reducing it to row reduced upper echelon form.
*/
upper_echelon_form(Q2_MATRIX_2_HEIGHT, Q2_MATRIX_2_WIDTH, Q2_matrix_2, Q2_matrix_2_elementary);


/*
* Call the print_matrix function to print the original matrix as well as the result of the EROs on 'Q2_matrix_2' to the console (i.e. the row reduced upper echelon form)
*/

printf("Original Q2_matrix_2:\n");
print_matrix(Q2_matrix_2_original_copy, Q2_MATRIX_2_HEIGHT, Q2_MATRIX_2_WIDTH);
printf("Upper echelon form of Q2_matrix_2:\n");
print_matrix(Q2_matrix_2, Q2_MATRIX_2_HEIGHT, Q2_MATRIX_2_WIDTH);

/* ******************/
/*  Question 2(c)   */
/* **************** */

double Q2_matrix_3_stat[Q2_MATRIX_3_HEIGHT][Q2_MATRIX_3_WIDTH] = {
    {1, 2, 3, 0},
    {2, 3, 4, 2},
    {3, 4, 5, 2},
};

double **Q2_matrix_3 = malloc(sizeof(double*)*Q2_MATRIX_3_HEIGHT);
double **Q2_matrix_3_elementary = malloc(sizeof(double*)*Q2_MATRIX_3_HEIGHT);
double **Q2_matrix_3_original_copy = malloc(sizeof(double*)*Q2_MATRIX_3_HEIGHT);
    
// Copy the values from the statically allocated array to the dynamically allocated array
for (int i = 0; i < Q2_MATRIX_3_HEIGHT; i++) {
    Q2_matrix_3[i] = malloc(sizeof(double)*Q2_MATRIX_3_WIDTH);
    Q2_matrix_3_elementary[i] = malloc(sizeof(double)*Q2_MATRIX_3_WIDTH);
    Q2_matrix_3_original_copy[i] = malloc(sizeof(double)*Q2_MATRIX_3_WIDTH);
    for (int j = 0; j < Q4_MATRIX_3_WIDTH; j++) {
        Q2_matrix_3[i][j] = Q2_matrix_3_stat[i][j];
        Q2_matrix_3_original_copy[i][j] = Q2_matrix_3_stat[i][j];
        if (i==j) {
            Q2_matrix_3_elementary[i][j] = 1;
        } else  {
            Q2_matrix_3_elementary[i][j] = 0;
        }
    }
}

/*
* Call the upper echelon form function which applies Elementary Row Opertions to 'Q2_matrix_3', reducing it to row reduced upper echelon form.
*/
upper_echelon_form(Q2_MATRIX_3_HEIGHT, Q2_MATRIX_3_WIDTH, Q2_matrix_3, Q2_matrix_3_elementary);


/*
* Call the print_matrix function to print the result of the EROs on 'Q2_matrix_3' to the console (i.e. the row reduced upper echelon form)
*/

printf("Original Q2_matrix_3:\n");
print_matrix(Q2_matrix_3_original_copy, Q2_MATRIX_3_HEIGHT, Q2_MATRIX_3_WIDTH);
printf("Upper echelon form of Q2_matrix_3:\n");
print_matrix(Q2_matrix_3, Q2_MATRIX_3_HEIGHT, Q2_MATRIX_3_WIDTH);



   

/* **************************************************************************************************** */
/*  Question 4: Use Elementary Row Operations to find the inverse of each of the following matrices:    */
/* **************************************************************************************************** */

/* ******************/
/*  Question 4(a)   */
/* **************** */

   // Define the first matrix statically
    double Q4_matrix_1_stat[Q4_MATRIX_1_HEIGHT][Q4_MATRIX_1_WIDTH] = {
        {2, 3},
        {3, 2},
    };

    /* Dynamically allocate memory for the first matrix and associated matrices uses in the calculation 
    * Concretely, the associated matrices are: 
    *   1. An original copy of the matrix, stored dynamically (this will not be altered by EROs and is used as a check to ensure inverse multiplied by original yields the identity)
    *   2. An elementary matrix to which EROs are applied - this will become the inverse after all EROs are applied
    */
    double **Q4_matrix_1 = malloc(sizeof(double*)*Q4_MATRIX_1_HEIGHT);
    double **Q4_matrix_1_original_copy = malloc(sizeof(double*)*Q4_MATRIX_1_HEIGHT);
    double **Q4_matrix_1_elementary = malloc(sizeof(double*)*Q4_MATRIX_1_HEIGHT);
        
    // Copy the values from the statically allocated array to the dynamically allocated array
    for (int i = 0; i < Q4_MATRIX_1_HEIGHT; i++) {
        Q4_matrix_1[i] = malloc(sizeof(double)*Q4_MATRIX_1_WIDTH);
        Q4_matrix_1_original_copy[i] = malloc(sizeof(double)*Q4_MATRIX_1_WIDTH);
        Q4_matrix_1_elementary[i] = malloc(sizeof(double)*Q4_MATRIX_1_WIDTH);
        for (int j = 0; j < Q4_MATRIX_1_WIDTH; j++) {
            Q4_matrix_1[i][j] = Q4_matrix_1_stat[i][j];
            Q4_matrix_1_original_copy[i][j] = Q4_matrix_1_stat[i][j];
            if (i==j) {
                Q4_matrix_1_elementary[i][j] = 1;
            } else  {
                Q4_matrix_1_elementary[i][j] = 0;
            }
        }
    }


    /*
    * Call the 'invert_matrix_print_result' function which applies Elementary Row Opertions to 'Q4_matrix_1', and the same operations to  the elementary matrix 
    * 'Q4_matrix_1_elementary', until 'Q4_matrix_1' has been transformed into row reduced upper echelon form. 
    * 
    * If this transformed (row reduced upper echelon form) matrix 'Q4_matrix_1' is the identity matrix, then the  matrix produced by applying that same sequence
    * of EROs to the elementary matrix 'Q4_matrix_1_elementary' will be the inverse of the original 'Q4_matrix_1' matrix, as the question requires.
    * 
    * This assertion (that we have found the inverse) is checked by multiplying the transformed elementary matrix (assumed to be the inverse) with the original matrix in question ('Q4_matrix_1_original_copy')
    * and verifying that the result of multiplication is indeed the identity matrix
    * 
    * If this assertion is true and we have found the inverse, then the inverse is printed, else a message is printed indicating that the matrix is not invertible
    */
    invert_matrix_print_result(Q4_MATRIX_1_HEIGHT, Q4_MATRIX_1_WIDTH, Q4_matrix_1, Q4_matrix_1_elementary, Q4_matrix_1_original_copy, 1);

/* ******************/
/*  Question 4(b)   */
/* **************** */

    //Create second matrix statically
    double Q4_matrix_2_stat[Q4_MATRIX_2_HEIGHT][Q4_MATRIX_2_WIDTH] = {
        {1,1,0},
        {1,0,1},
        {0,1,1},
    };

    //Dynamically allocate memory for the second matrix
   double **Q4_matrix_2 = malloc(sizeof(double*)*Q4_MATRIX_2_HEIGHT);
   double **Q4_matrix_2_elementary = malloc(sizeof(double*)*Q4_MATRIX_2_HEIGHT);
   double **Q4_matrix_2_original_copy = malloc(sizeof(double*)*Q4_MATRIX_2_HEIGHT);

   // Copy the values from the statically allocated array to the dynamically allocated array
   for (int i = 0; i < Q4_MATRIX_2_HEIGHT; i++) {
       Q4_matrix_2[i] = malloc(sizeof(double)*Q4_MATRIX_2_WIDTH);
       Q4_matrix_2_original_copy[i] = malloc(sizeof(double)*Q4_MATRIX_2_WIDTH);
       Q4_matrix_2_elementary[i] = malloc(sizeof(double)*Q4_MATRIX_2_WIDTH);
       for (int j = 0; j < Q4_MATRIX_2_WIDTH; j++) {
           Q4_matrix_2[i][j] = Q4_matrix_2_stat[i][j];
           Q4_matrix_2_original_copy[i][j] = Q4_matrix_2_stat[i][j];
           if (i==j) {
            Q4_matrix_2_elementary[i][j] = 1;
           } else  {
            Q4_matrix_2_elementary[i][j] = 0;
           }
       }
   }

   /*
   * As with question 1, call the 'invert_matrix_print_result' function which applies Elementary Row Opertions to 'Q4_matrix_2', and the same operations to the corresponding elementary matrix.
   * If the inverse is found, it is printed, else a message is printed indicating that the matrix is not invertible
   */   
   invert_matrix_print_result(Q4_MATRIX_2_HEIGHT, Q4_MATRIX_2_WIDTH, Q4_matrix_2, Q4_matrix_2_elementary, Q4_matrix_2_original_copy, 2);

/* ******************/
/*  Question 4(c)   */
/* **************** */

    double Q4_matrix_3_stat[Q4_MATRIX_3_HEIGHT][Q4_MATRIX_3_WIDTH] = {
        { 1, 1, 1, 1},
        { 1, 2, 3, 4},
        { 1, 4, 9,16},
        { 1, 8,27,64},
    };

    //Dynaically allocate memory for the square matrix
   double **Q4_matrix_3 = malloc(sizeof(double*)*Q4_MATRIX_3_HEIGHT);
   double **Q4_matrix_3_original_copy = malloc(sizeof(double*)*Q4_MATRIX_3_HEIGHT);
   double **Q4_matrix_3_elementary = malloc(sizeof(double*)* Q4_MATRIX_3_HEIGHT);

   // Copy the values from the statically allocated array to the dynamically allocated array
   for (int i = 0; i < Q4_MATRIX_3_HEIGHT; i++) {
       Q4_matrix_3[i] = malloc(sizeof(double)*Q4_MATRIX_3_WIDTH);
       Q4_matrix_3_original_copy[i] = malloc(sizeof(double)*Q4_MATRIX_3_WIDTH);
       Q4_matrix_3_elementary[i] = malloc(sizeof(double)*Q4_MATRIX_3_WIDTH);
       for (int j = 0; j < Q4_MATRIX_3_WIDTH; j++) {
           Q4_matrix_3[i][j] = Q4_matrix_3_stat[i][j];
           Q4_matrix_3_original_copy[i][j] = Q4_matrix_3_stat[i][j];
           if (i==j) {
            Q4_matrix_3_elementary[i][j] = 1;
           } else  {
            Q4_matrix_3_elementary[i][j] = 0;
           }
       }
   }

   invert_matrix_print_result(Q4_MATRIX_3_HEIGHT, Q4_MATRIX_3_WIDTH, Q4_matrix_3, Q4_matrix_3_elementary, Q4_matrix_3_original_copy, 3);


    //Free the memory allocated for the matrices by calling the free_matrix function as required
    free_matrix(Q2_matrix_1, Q2_MATRIX_1_HEIGHT);
    free_matrix(Q2_matrix_1_elementary, Q2_MATRIX_1_HEIGHT);
    free_matrix(Q2_matrix_1_original_copy, Q2_MATRIX_1_HEIGHT);

    free_matrix(Q2_matrix_2, Q2_MATRIX_2_HEIGHT);
    free_matrix(Q2_matrix_2_elementary, Q2_MATRIX_2_HEIGHT);
    free_matrix(Q2_matrix_2_original_copy, Q2_MATRIX_2_HEIGHT);
    
    free_matrix(Q2_matrix_3, Q2_MATRIX_3_HEIGHT);
    free_matrix(Q2_matrix_3_elementary, Q2_MATRIX_3_HEIGHT);
    free_matrix(Q2_matrix_3_original_copy, Q2_MATRIX_3_HEIGHT);

    free_matrix(Q4_matrix_1, Q4_MATRIX_1_HEIGHT);
    free_matrix(Q4_matrix_1_elementary, Q4_MATRIX_1_HEIGHT);
    free_matrix(Q4_matrix_1_original_copy, Q4_MATRIX_1_HEIGHT);

    free_matrix(Q4_matrix_2, Q4_MATRIX_2_HEIGHT);
    free_matrix(Q4_matrix_2_elementary, Q4_MATRIX_2_HEIGHT);
    free_matrix(Q4_matrix_2_original_copy, Q4_MATRIX_2_HEIGHT);

    free_matrix(Q4_matrix_3, Q4_MATRIX_3_HEIGHT);
    free_matrix(Q4_matrix_3_elementary, Q4_MATRIX_3_HEIGHT);
    free_matrix(Q4_matrix_3_original_copy, Q4_MATRIX_3_HEIGHT);
}






