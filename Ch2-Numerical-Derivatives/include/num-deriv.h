#ifndef NUM_DERIV_H
#define NUM_DERIV_H

#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#define EPS 1e-14

//Declare f(x, F) (Derivative of a function F at a point x)
double f(double x, double (*F)(double));

//Declare delta(n);
double delta(double n);

#endif