// Common trigonometric function implementations.

#ifndef TRIGFUNCS_H
#define TRIGFUNCS_H

#include <stdlib.h>
#include <math.h>
#include "misc.h"

double CalculateSin(double, const int); // Taylor series approximation based sine function that returns the sine value of the provided angle in radians.
double Sin(double); // Wrapper function for CalculateSin(double, const int), takes angle in degrees as input.

double CalculateCos(); // Taylor series approximation based cosine function that returns the cosine value of the provided angle in degrees.
double Cos(double); // Wrapper function for CalculateCos(double, const int), takes angle in degrees as input.

double Cosec(double);
double Sec(double);
double Tan(double);
double Cot(double);

int GetRecurranceCount(double); // Finds the cyclic function recurrance count for angles in radians.

int GetSign(const int);  // Returns a signed or unsigned value for the taylor series depending upon the provided value.

int GetRecurranceCount(double angle)
{
    return (angle / (PI));
}

int GetSign(const int n)
{
    return (n % 2 == 1) * -1 | (!(n % 2));
}

double CalculateSin(double angle, const int maxIterations)
{
    double sinval = 0,
        numerator = 0,
        factorial = 0;

    const int n = GetRecurranceCount(angle), // Gets the repeatation of PI
        sign = GetSign(n); // Quadrant sign

    angle -= n * PI;

    for (int x = 0; x < maxIterations; x++)
    {
        numerator = pow(angle, (2 * x) + 1);
        factorial = Factorial((2 * x) + 1);

        sinval += pow(-1, x) * (numerator / factorial);
    }

    return (sign * sinval);
}

double Sin(double angle)
{
    return CalculateSin(RADIANS(angle), 10);
}

double CalculateCos(double angle, int maxIterations)
{
    double cosval = 0,
        numerator = 0,
        factorial = 0;

    const int n = GetRecurranceCount(angle), // Gets the repeatation of PI
        sign = GetSign(n); // Quadrant sign

    angle -= n * PI;

    for (int x = 1; x <= maxIterations; x++)
    {
        numerator = pow(angle, 2 * x);
        factorial = Factorial(2 * x);

        cosval += pow(-1, x) * (numerator / factorial);
    }

    return (sign * cosval);
}

double Cos(double angle)
{
    return Sin(angle + 1.570796327);

//    return CalculateCos(RADIANS(angle), 10);
}

#endif
