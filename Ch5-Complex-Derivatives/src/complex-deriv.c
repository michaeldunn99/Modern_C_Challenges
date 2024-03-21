#include "complex-deriv.h"

/**
 * @brief This function generates a delta error term for a given value of n, where delta(n) = 5^-n.
 * 
 * The purpose of this function is to generate a small error term for use in the calculation of the complex derivative of a function.
 * 
 * @param n The value of n.
 * @return The value of delta(n).
 */

double delta(double n) {
    return pow(5, -n);

}


/**
 * @brief This function the complex derivative of a function f at a given point z.
 * 
 * This function assumes that f is differentiable at z and calculates the complex derivative of f at z by approaching along the real axis.
 *
 * @param z The point at which to calculate the derivative.
 * @param F A pointer to the function f.
 * @return The complex derivative of f at z, or -1000 if the derivative cannot be determined.
 */
double complex f(double complex z, double complex (*F)(double complex)) {
    for (int i = 10; i < 16; i++) {
        
        // Here we assume f is differentiable and take the complex derivative by approaching along the real axis
        double complex f_dash_plus = (F(z + delta(i)) - F(z)) / (delta(i));
        double complex f_dash_minus = (F(z) - F(z-delta(i))) / (delta(i));
        if (cabs(f_dash_plus-f_dash_minus) < EPS) {
            return (f_dash_plus + f_dash_minus) / 2;
        }
    };
    return -1000;
}