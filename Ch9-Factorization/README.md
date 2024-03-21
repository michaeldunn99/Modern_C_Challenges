# Factorization

This program accepts a list of positive integers at the command line, calculates the prime factors of each of those integers (and their corresponding exponents), then prints out each prime factorization

## Challenge Posed


*"Now that we’ve covered functions, see if you can implement a program 'factorization' that receives a number N on the command line and prints out:*    
  
    N: F0 F1 F2 ...  
  
*where F0 and so on are all the prime factors of N.*  
  
*The core of your implementation should be a function that, given a value of type size_t, returns its smallest prime factor."*  

*Extend this program to receive a list of such numbers and output such a line for each of them.*  

## Description

This program is comprised of two source files:  

    factorization.c

    prime-fac.c

- *factorization.c* contains the *main* function, which expects a list of positive integers as command line arguments (CLAs) and initializes arrays (one for each CLA) to store the different prime factors and their corresponding exponents. The file then calls the prime factorization function to populate these arrays with the prime factors of each number, before printing the results to the Terminal.

- *prime-fac.c* contains the functions which calcuate the prime factors (and their respective exponents) for a given input number. *prime-fac.c* then populates the prime factor arrays created in main.c. The file does this through the following functions: 
    - *prime_fac* : Wrapper function for the recursive *prime_fac_rec* function. *prime_fac* initializes the relevant variables then calls the *prime_fac_rec* function
    - *prime_fac_rec* : Finds the prime factors of a number (n) by:
        1. Calling the *smallest_prime_fac* function to find the smallest prime factor (p) of the input number (n)
        2. Updating n to be the quotient  q = n / p
        3. Recursively calling *prime_fac_rec* with argument new n = q (Repeat until termination condition q = 1)
    - *small_prime_fac* : Calculates and returns the smallest prime factor (p) of a positive integer input n

## Compilation

- Project uses the custom *Makefile* which: 
    1. Compiles the source code files in sub-directory *src* into object files, and stores them in sub-directory *bin/obj*
    2. Links the object files using the header file *prime-fac.h* in sub-directory *include*, into an executable named *factorization* which is stored in sub-directory *bin*

## Usage

1. Navigate to the Challenges/Ch9-Factorization directory

2. To compile run:

    ```bash
    make factorization
    ```
    

3. To execute, run:

    ```bash
    ./bin/factorization n1 n2 n3 ... (etc)
    ```
    where n1, n2, n3,  ... (etc) are positive integer (>= 2) command line arguments of your choice

