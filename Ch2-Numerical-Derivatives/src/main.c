#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#define EPS 1e-14
#include "num-deriv.h"


//USER DEFINED FUNCTION (Enter your function below)
#define func cos
//USER DEFINED FUNCTION WORD (Enter the name of the function below)
#define func_name "cosine"
//USER DEFINED FUNCTION DERIVATIVE
#define func_deriv sin

// Declare and define F(x)
double F(double x) {
    return func(x);
}

/**
 * @brief Main function to calculate the numerical derivative of a function at a given point.
 * 
 * This function calculates the numerical derivative of a function at a given point by calling the derivative function f from num-deriv.c
 * 
 * @return 1 if the derivative does not converge, 0 otherwise.
 */
int main(void) {

    // Explicity define the point x at which to calulate the derivative
    double x = M_PI;

    // Call the function f to calculate the derivative of F at x (F is defined above as cos(x))
    double f_dash_x = f(x,F);
    if (f_dash_x == -1000) {
        printf("Function derivative does not converge");
        return 1;
    // Compare the calculated derivative with the expected derivative
    } else if (!(fabs(f_dash_x + func_deriv(M_PI)) < 1e-7)) {
        printf("Derivative did not converge");
        return 1;
    }
    printf("When F(x) = %s(x) and x = pi, F'(x) = %.2f\n",func_name,f_dash_x);
    return 0;
}



