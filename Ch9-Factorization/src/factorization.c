#include <stdio.h>
#include <tgmath.h>
#include <stdlib.h>
#include "prime-fac.h"

/**
 * @brief   Main function that validates user input, performs factorization for multiple numbers
 *          by calling the prime_fac function and prints the prime factorization of each number.
 * 
 * @param argc The number of command-line arguments.
 * @param argv An array of strings containing the command-line arguments.
 * @return int The exit status of the program.
 */
int main(int argc, char* argv[argc+1]) {
    
    // Check if the user has provided any arguments.
    if (argc == 1) {
        printf("Usage: %s <number> <number> <number> etc...\n", argv[0]);
        return -1;
    }

    //Allocate memory for endptr
    char*** endptr = malloc(sizeof(char**)*(argc-1));
    long args[argc-1];
    size_t array_sizes[argc-1];

    //Validate user input by ensuring that all arguments are positive numbers greater than or equal to 2
    for (int i = 0; i < argc-1; ++i) {
        //Allocate memory for endptr[i]
        endptr[i] = malloc(sizeof(char*));
        //Call the strtol function to convert the input string to a long 
        args[i] = strtol(argv[i+1], endptr[i], 10);
        if (**endptr[i] != '\0' || args[i] <= 1) {
            printf("Argument %d is not a positive number greater than or equal to 2\n", i+1);
            return -1;
        }
        // Make the array of size log2(n) + 1 because cannot have more than log2(n) different prime factors
        array_sizes[i] = log2(args[i]) + 1;
    }
   

    /*  Declare factor array, first column will hold the different prime factors, second column will hold the exponent
    *   of the corresponding prime factor in that row */
    for (int i = 0; i < argc-1; i++) {
        size_t array_size = array_sizes[i];
        size_t n = args[i];
        size_t factor_array[array_size][2];
    
        /* Initialize VLA to zero */
        for (int j = 0; j < array_size; ++j) {
            factor_array[j][0] = 0;
            factor_array[j][1] = 0;
        }
        
        // Call the prime_fac function to calculate the prime factorization of the number
        prime_fac(n, array_size, factor_array);
        // Print the prime factorization of each number
        printf("%zu: ", n);
        for (int j = 0; j < factor_array[array_size - 1][0]; j++) {
            printf("%zu^%zu ", factor_array[j][0], factor_array[j][1]);
        }
        printf("\n\n");
    }

    //Free memory allocated for endptr
    for (int i = 0; i < argc - 1; ++i) {
        free(endptr[i]); 
    }
    free(endptr);
}
