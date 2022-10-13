#include "taylor_sine.h"

#include <math.h>
#include <stdio.h>

double taylor_sine(double x, int n) {
    // Initiate the varaiales for the function
    int exp = 1;      // Exponent of x
    double fact = 1;  // The divisor on each line, the factorial term
    int sign = 1;     // The sign of each term change every time
    double sin = 0;   // The return value, left side of the equation.
    for (int i = 0; i < n; i++) {
        // Add the next term
        sin += sign * (pow(x, exp) / fact);

        // Increment the values for the next term in the equation
        sign *= -1;
        exp += 2;
        fact *= exp * (exp - 1);
    }

    return sin;
}
