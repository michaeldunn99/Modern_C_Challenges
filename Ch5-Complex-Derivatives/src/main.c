#include <stdio.h>
#include <tgmath.h>
#define _USE_MATH_DEFINES
#define EPS 1e-14
#include "complex-deriv.h"


//USER DEFINED FUNCTION (Enter your function below)
#define func csin
//USER DEFINED FUNCTION WORD (Enter the name of the function below)
#define func_name "sin"
//USER DEFINED FUNCTION DERIVATIVE
#define func_deriv ccos

// Declare and define F(x)
double complex F(double complex z) {
    return func(z);
}

/**
 * @brief Calculates the derivative of a complex function at a given point and prints the result.
 * 
 * This function calculates the derivative of a complex function at a given point using the function `f`, by calling the derivative function from the header file `complex-deriv.h`.
 * If the derivative does not converge, it prints an error message and returns 1.
 * Otherwise, it compares the calculated derivative with the expected derivative using the function `func_deriv`.
 * If the calculated derivative does not match the expected derivative within a tolerance of 1e-7, it prints an error message and returns 1.
 * Finally, it prints the calculated derivative.
 * 
 * @return 0 if the derivative calculation is successful, 1 otherwise.
 */

int main(void) {

    //Explicity define the point z at which to calulate the derivative
    double complex z = M_PI/2*(1 + I);

    //Call the function f to calculate the derivative of F at z (F is defined above as sin(z))
    double complex f_dash_z = f(z,F);
    if (f_dash_z == -1000) {
        printf("Function derivative does not converge");
        return 1;
    }

    //Compare the calculated derivative with the expected derivative
    if ((!(cabs(f_dash_z - func_deriv(z)) < 1e-7))) {
    printf("Derivative did not converge\n");
    return 1;
    }

    //Print the calculated derivative
    printf("When F(z) = %s(z) and z = %.2f + %.2fi, F'(z) = %.2f + %.2fi\n", func_name,creal(z), cimag(z), creal(f_dash_z), cimag(f_dash_z));
}