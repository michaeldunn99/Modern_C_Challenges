# Complex Numerical Derivatives

This program, written in C, finds a numerical derivative for the complex sine function.

## Challenge Posed

*"Can you extend the derivative (Challenge 2) to the complex domain: that is, functions that receive and return double complex values?"*

## Description

This program accepts calculates an approximate numerical derivative for the complex since function at the point z = pi/2(1 + i) and prints the result to the screen.

It is assumed here that sin(z) is differentiable for each complex z. This program calculates the derivative by taking the limit as z+h approaches z along the real axis (since, given it is differentiable, we can take the limit on any line in the complex plane approaching z).

This program is composed of two source files:
- **main.c** : Defines the function F whose derivative is to be calculated, the point z at which the derivative is to be calcuated, calls the derivative function and prints the result
- **num-deriv.c** : Calculates and returns the numerical derivative of a function F at a given point z.

## Usage

1. Navigate to the Challenges/Ch5-Complex-Derivatives folder

2. To compile run:

    ```bash
    make comp-deriv
    ```

3. To execute, run:

    ```bash
    ./bin/comp-deriv
    ```