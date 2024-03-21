#include "num-deriv.h"

double delta(double n) {
    return pow(10, -n);

}

/**
 * Calculates the numerical derivative of a function F at a given point x.
 *
 * @param x The point at which to calculate the derivative.
 * @param F The function for which to calculate the derivative.
 * @return The numerical derivative of F at x, or -1000 if the derivative cannot be calculated.
 */
double f(double x, double (*F)(double)) {
    // Iterate over a range of values for delta
    for (int i = 10; i < 16; i++) {
        // Calculate the forward difference approximation
        double f_dash_plus = (F(x + delta(i)) - F(x)) / (delta(i));
        // Calculate the backward difference approximation
        double f_dash_minus = (F(x) - F(x-delta(i))) / (delta(i));
        // Check if the difference between the two approximations is within the desired tolerance
        if (fabs(f_dash_plus-f_dash_minus) < EPS) {
            // Return the average of the two approximations as the numerical derivative
            return (f_dash_plus + f_dash_minus) / 2;
        }
    };
    // Return -1000 if the derivative cannot be calculated
    return -1000;
}