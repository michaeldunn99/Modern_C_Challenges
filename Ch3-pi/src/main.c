
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include <errno.h>

//declare pi_digits function
double pi_digits(int num_digits);


/*
* This is the main function which calls the pi_digits function to calculate pi to a given number of decimal places.
* @param argc - the number of command line arguments
* @param argv - the command line arguments (should be a positive integer strictly less than 15)
* @return - returns 0 to indicate success
*
* IMPORTANT NOTE: The command line argument must be a positive integer strictly less than 15
*/

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide a command-line argument.\n");
        return 1;
    }
    char *end;
    errno = 0;  // To distinguish success/failure after call to strtol
    long num = strtol(argv[1], &end, 10);

    // Check for conversion errors
    if (errno != 0 || *end != '\0' || num <= 0) {
        printf("The argument is not a positive integer.\n");
        return 1;
    } else if (num >= 15) {
        printf("The argument is not strictly less than 15.\n");
        return 1;
    }

    int num_digits = atoi(argv[1]);
    printf("Pi to %d decimal places = %.*f\n", num_digits, num_digits, pi_digits(num_digits));
}


/*
* This function calculates pi to a given number of decimal places, so long as the number of decimal places is less than 15.
* @param num_digits - the number of decimal places to calculate pi to (NOTE: COMMAND LINE ARGUMENT MUST BE A POSITIVE INTEGER LESS THAN 15)
* @return - returns the value of pi to the given number of decimal places
*
* This function uses the Gauss-Legendre algorithm to calculate pi to a given number of decimal places.
* This algorithm converges quadratically, meaning that the number of correct decimal places roughly doubles with each iteration.
* The algorithm is as follows:

* 1.   Set a = 1, b = 1/sqrt(2), t = 1/4, and n = 0
* 2.   Repeat the following steps until the desired number of decimal places is reached:
*     a.   Set a_new = (a + b) / 2
*     b.   Set b = sqrt(a * b)
*     c.   Set t = t - 2^n * (a - a_new)^2
*     d.   Set a = a_new
*     e.   Calculate pi_approx = (a + b)^2 / (4 * t)
*     f.   If the number of decimal places in pi_approx is equal to the desired number of decimal places, return pi_approx
*     g.   Increment n by 1
*/

double pi_digits(int num_digits) {
    printf("%.15f\n",M_PI);
    double factor = pow(10.0, num_digits);
    double rounded_pi = round(M_PI* factor) / factor;
    double a = 1;
    double b = 1 / sqrt(2.0);
    double t = (double) 1/ (double) 4;
    int n = 0;
    double a_new;


    for (;;) {
        a_new = (a + b) / 2;
        b = sqrt(a * b);
        t = t - pow(2,(n)) * pow((a - a_new),2);
        a = a_new;
    
        double pi_approx = pow((a + b), 2.0) / (4 * t);
        double factor = pow(10.0, num_digits);
        double rounded_pi_approx = round(pi_approx * factor) / factor;
        if (rounded_pi_approx == rounded_pi) {
            return pi_approx;
        }
        n++;
    }
    return 0;
}