#ifndef PRIME_FAC_H
#define PRIME_FAC_H

#include <stdlib.h>
#include <tgmath.h>

//Function to calculate the smallest prime factor of a number
size_t small_prime_fac(size_t n, size_t prev_prime);

//Declaration for prime factorization function (this is a wrapper for the recursive function prime_fac_rec)
void prime_fac(size_t n, size_t array_size, size_t factor_array[array_size][2]);

//Recursive function to calculate the prime factorization of a number
int prime_fac_rec(size_t diff_factors, size_t current_n, size_t previous_fac, size_t array_size, size_t factor_array[array_size][2]);

//Alternative declaration for prime factorization when using iteration rather than recursion

//void prime_fac(size_t n, size_t array_size, size_t factor_array[array_size][2])
#endif