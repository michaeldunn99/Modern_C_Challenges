#include <stdio.h>
#include <tgmath.h>
#include <stdlib.h>
#include "prime-fac.h"

int main(int argc, char* argv[argc+1]) {
    
    if (argc == 1) {
        printf("Usage: %s <number> <number> <number> etc...\n", argv[0]);
        return -1;
    }

    char*** endptr = malloc(sizeof(char**)*(argc-1));
    long args[argc-1];
    size_t array_sizes[argc-1];
    for (int i = 0; i < argc-1; ++i) {
        endptr[i] = malloc(sizeof(char*));
        args[i] = strtol(argv[i+1], endptr[i], 10);
        if (**endptr[i] != '\0' || args[i] <= 1) {
            printf("Argument %d is not a positive number greater than or equal to 2\n", i+1);
            return -1;
        }
        array_sizes[i] = log2(args[i]) + 1;
    }
    /* Initialize VLA of to hold prime factors and exponents
    * Make the array of size log2(n) + 1 because cannot have more than log2(n) different prime factors
    */
   
    /*  Declare factor array, first column will hold the different prime factors, second column will hold the exponent
    *   of the corresponding prime factor in that row
    */

    for (int i = 0; i < argc-1; i++) {
        size_t array_size = array_sizes[i];
        size_t n = args[i];
        size_t factor_array[array_size][2];

        /* Initialize VLA to zero */
        for (int j = 0; j < array_size; ++j) {
            factor_array[j][0] = 0;
            factor_array[j][1] = 0;
        }
        
        prime_fac(n, array_size, factor_array);
        printf("%zu: ", n);
        for (int j = 0; j < factor_array[array_size - 1][0]; j++) {
            printf("%zu^%zu ", factor_array[j][0], factor_array[j][1]);
        }
        printf("\n\n");
    }

    for (int i = 0; i < argc - 1; ++i) {
        free(endptr[i]); 
    }
    free(endptr);
}