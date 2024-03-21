#ifndef COMP_DERIV_H
#define COMP_DERIV_H

#define _USE_MATH_DEFINES
#include <stdio.h>
#include <tgmath.h>
#define EPS 1e-14

//Declare f(x, F) (Derivative of a function F at a point x)
double complex f(double complex x, double complex (*F)(double complex));

//Declare delta(n);
double delta(double n);

#endif