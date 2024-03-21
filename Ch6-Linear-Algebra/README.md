# Linear Algebra

This programme implements a computationally efficient algorithm for finding matrix inverses, using Gaussain elimination.

Concretely, the programme performs Gaussian Elimination row operations on a matrix (and its corresponding elementary matrix), until the matrix is in row reduced upper echelon form.

If that form is the identity matrix, the program will also have found the matrix inverse, having performed the same Gaussian Elimination steps on the elementary matrix.

## Challenge Posed

    "Some of the most important problems for which arrays are used stem from linear algebra.
    Can you write functions that do vector-to-vector or matrix-to-vector products at this point?
    What about Gauß elimination or iterative algorithms for matrix inversion?"



## Description

 In my first linear algebra course at University (Oxford Univeristy, Prelims, 2017, 'Linear Algebra I') we were asked in Problem Sheet II

       Q2: "Use Elementary Row Operations (EROs) (Gauss Elimination) to reduce each of the following matrices to echelon form..."
       Q4: "Use EROs (Gauss Elimination) to find the inverses of each of the following matrices..."

Find a link to a pdf version of the Problem Sheet here: [Link to Problem Sheet](./LA_I_Sheet2.pdf)

As such, this program provides solutions in C Code to these Problem Sheet questions. In doing so, it implements a function that multiplies two matrices, as well as a function that inverts a matrix using Elementary Row Operations (EROs) (also known as Gauss Elimination as stated above), thus fulfilling the requirements of the challenge.

Underlying mathematically is the fact that if the row reduced upper echelon form of a matrix is the identity matrix, then that matrix is invertible. Its inverse can be found be applying the
same sequence of EROs to an elementary matrix (identity matrix).

As a reminder, the definition of echelon form (and row reduced echelon form) is as follows: 

    Let E be an m x n matrix (i.e. m rows and n columns). Then E is in echlon form if each of the following hold:

    1. If row r of E has any non-zero entries then the first of these is 1;
    2. If 1<=r<=s<=m and rows r, s of E contain non-zero entries,the first of which are e_(r,j) and e_(s,k) respectively, then j < k (the leading entries of lower rows occur to the right of those in higher rows);
    3. If row r of E contains non-zero entries and row s does not (that is e_(sj) = 0 for 1<=j<=n) then r < s (zero rows, if any exist, appear below all non-zero rows).

    In addition, an m × n matrix E is said to be in row reduced echelon form (RRE form) if it is in echelon form and each column that contains the leading entry of a row has all other entries 0.






 The questions posed by the Problem Sheet are as follows:

    Question 2: Use Elementary Row Operations to reduce each of the following matrices to echelon form:

       1. |2  4 -3  0|
          |1 -4  3  0|
          |3 -5  2  1|

       2. |1  2  3  0|
          |2  3  4  1|
          |3  4  5  2|

       3. |1  2  3  0|
          |2  3  4  2|
          |3  4  5  2|


    Question 4: Use Elementary Row Operations to find the inverse of each of the following matrices:

        1. |2 3|
           |3 2|
 
        2. |1 1 0|
           |1 0 1|
           |0 1 1|

        3. |1 -1  0  0|
           |1  0 -1  0|
           |1  0  0 -1|
           |0  1  1  1|

When executed, this program will transform the matrices to row reduced echelon form, and in doing so, find the inverses of the matrices if they are invertible (using a corresponding elementary matrix and applying the same EROs). The program will then print the resultant matrices to the console (as well as the original matrices for comparison).

Please see the documention within the source code for detailed descriptions of each of the functions involved.

## Structure

The program comprises:

- Three sources files, saved in the 'src' sub-directory:
    - main.c
        -   Defines the matrices to be operated on, and calls the respective functions to put them in echelon form or find their inverses; frees any dynamically allocated memory
    - matrix-mult.c
        -   Contains functions for multiplying matrices, transforming matrices to row reduced echelon form, and a wrapper function for inverting matrices and checking the inverse
                calculated is correct
    - helper-functions.c
        -   Contains helper functions such as functions to execute the individual row operations, a function to print a matrix,
                and a function that checks if a matrix is the identity matrix
    
- Three header files, saved in the 'include' sub-directory:
    - definitions.h
        -   Contains preprocessor directives for the dimensions of the matrices to be calculated, as well as the error term used to estimate equality (as working
            with floating point representations)
    - matrix-mult.h
        -   Contains the declarations for the functions in matrix-mult.c, as well as other necessary C standard libraries
    - helper-functions.h
        -   Contains the declarations for the functions in helper-functions.c, as well as other necessary C standard libaries
    
These are compiled using the custom Makefile which compiles each of the source files into object files before linking them to an executable stored in the bin folder.

## Usage

In order to use the program:
        
1. Navigate to the Ch6-Linear-Algebra folder

2. To compile run:

    ```bash
    make linear-algebra
    ```

3. To execute, run:

    ```bash
    ./bin/linear-algebra
    ```