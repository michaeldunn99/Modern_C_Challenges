#include "prime-fac.h"

/**
 * Calculates the smallest prime factor of a given number.
 * 
 * @param n The number to find the smallest prime factor of.
 * @param prev_prime The previous prime number to start checking from.
 * @return The smallest prime factor of the given number.
 */
size_t small_prime_fac(size_t n, size_t prev_prime) {
    /*  In order to calculate the smallest prime factor of a number, 
    *   you just have to check every prime less than or equal to the square root of that number 
    *   (because if the number had any prime factors strictly greater than the sqrt and strictly less than itself
    *   then there would be corresponding prime factor less than the squareroot 
    * */

    size_t sqrt_n = sqrt(n);
    /*  Loop through every number less than the square root, and break the loop if one of the numbers divides n
    *   If any number greater than one and less than the squareroot divides n, the first such number will necessarily be prime 
    */  

   /* Ensure that on first time this program is called that prev_prime (i.e. the first prime to look from) is 2*/
    if (prev_prime < 2) {
        prev_prime = 2;
    }

    for (size_t i = prev_prime; i < n+1; ++i) {
        if (!(n%i)) {
            return i;
        } 
    }
    return n;
}


/**
 * Calculates the prime factorization of a given number - this is a wrapper for the recursive function prime_fac_rec
 *
 * @param n The number to be factorized.
 * @param array_size The size of the factor_array.
 * @param factor_array The 2D array to store the prime factors and their exponents.
 */
void prime_fac(size_t n, size_t array_size, size_t factor_array[array_size][2]) {

    size_t diff_factors = 0;
    size_t current_n = n;
    size_t previous_fac = 0;
    prime_fac_rec(diff_factors, current_n, previous_fac, array_size, factor_array);
}

/**
 * Recursive function to calculate the prime factorization of a number.
 *
 * @param diff_factors The number of different prime factors found so far.
 * @param current_n The current number being factorized.
 * @param previous_fac The previous prime factor found.
 * @param array_size The size of the factor_array.
 * @param factor_array The array to store the prime factors and their frequencies.
 * @return 0 indicating successful execution.
 */
int prime_fac_rec(size_t diff_factors, size_t current_n, size_t previous_fac, size_t array_size, size_t factor_array[array_size][2]) {
    // Base case: current_n is 1, store the number of different prime factors and return.
    if (current_n == 1) {
        factor_array[array_size-1][0] = diff_factors;
        return 0;
    }
        
    // Find the smallest prime factor of current_n.
    size_t small_prime = small_prime_fac(current_n,previous_fac);

    // If the smallest prime factor is the same as the previous factor, increment its frequency.
    if (small_prime == previous_fac) {
        factor_array[diff_factors - 1][1]++;
        current_n = current_n / small_prime;
        prime_fac_rec(diff_factors, current_n, previous_fac, array_size, factor_array);
        return 0;
    }
    else {
        // Increment the number of different prime factors and store the new factor.
        ++ diff_factors;
        factor_array[diff_factors - 1][0] = small_prime;
        factor_array[diff_factors - 1][1]++;
        current_n = current_n / small_prime;
        previous_fac = small_prime;
        prime_fac_rec(diff_factors, current_n, previous_fac, array_size, factor_array);
        return 0;
    }
}







//Alternative version below that uses iteration rather than recursion
/*
 * Calculates the prime factorization of a given number using an iterative approach.
 *
 * @param n The number to be factorized.
 * @param array_size The size of the factor_array.
 * @param factor_array The 2D array to store the prime factors and their frequencies.
 */

/*
void prime_fac(size_t n, size_t array_size, size_t factor_array[array_size][2]) {

    size_t diff_factors = 0;
    size_t current_n = n;
    size_t previous_fac = 0;
    size_t small_prime;
    while (1) {
        if (current_n == 1) {
            break;
        }
        
        small_prime = small_prime_fac(current_n,previous_fac);

        if (small_prime == previous_fac) {
            factor_array[diff_factors - 1][1]++;
            current_n = current_n / small_prime;
        }
        else {
            ++ diff_factors;
            factor_array[diff_factors - 1][0] = small_prime;
            factor_array[diff_factors - 1][1]++;
            current_n = current_n / small_prime;
            previous_fac = small_prime;
        }
    }
    // Store number of different factors in bottom row of the array (which will not already be populated)
    factor_array[array_size-1][0] = diff_factors;
}
*/