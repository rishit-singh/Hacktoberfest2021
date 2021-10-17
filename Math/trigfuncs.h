// Common trigonometric function implementations.

#ifndef TRIGFUNCS_H

#include <stdlib.h>
#include <math.h>
#include "misc.h"

double CalculateSin(double, const int); // Taylor series approximation based sine function that returns the sine value of the provided angle in radians.
double Sin(double); // Wrapper function for CalculateSin(double, const int);

double Cosec(double);
double Cos(double); // Taylor series approximation based cosine function that returns the cosine value of the provided angle in degrees.
double Sec(double);
double Tan(double);
double Cot(double);

int GetRecurranceCount(double); // Finds the cyclic function recurrance count for angles in radians.

int GetRecurranceCount(double angle)
{
    return (angle / (TWOPI));
}

double CalculateSin(double angle, const int maxIterations)
{
    double sinval = 0,
        numerator = 0,
        factorial = 0;

    /* if (angle > TWOPI) */
    /*     angle -= TWOPI * (int)(angle / (2 * PI)); */
     //   angle -= TWOPI * GetRecurranceCount(angle);


    for (int x = 0; x < maxIterations; x++)
    {
        numerator = pow(angle, (2 * x) + 1);
        factorial = Factorial((2 * x) + 1);

        sinval += pow(-1, x) * (numerator / factorial);
    }

    return (sinval);
}


#endif
