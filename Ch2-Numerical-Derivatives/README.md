# Complex Numerical Derivatives

This program finds an approximate numerical derivative for the cosine function at a point.

## Challenge Posed

    "Something we’ll deal with a lot is the concept of numerical algorithms. To get your hands dirty, see if you can implement the numerical derivative double f(double x) of a function double F(double x).
    Implement this with an example F for the function that you use for this exercise. A good primary choice for F would be a function for which you know the derivative, such as sin, cos, or sqrt. This allows you to check your results for correctness."

## Description

This program accepts calculates an approximate numerical derivative for the cosine function at the point x = pi and prints the result to the screen.

This program is composed of two source files:
- **main.c** : Defines the function F whose derivative is to be calculated, the point x at which the derivative is to be calcuated, calls the derivative function and prints the result
- **num-deriv.c** : Calculates and returns the numerical derivative of a function F at a given point x.

## Usage

1. Navigate to the Challenges/Ch2-Numerical-Derivatives folder

2. To compile run:

    ```bash
    make num-deriv
    ```

3. To execute, run:

    ```bash
    ./bin/num-deriv
    ```