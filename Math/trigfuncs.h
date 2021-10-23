// Common trigonometric function implementations.

#ifndef TRIGFUNCS_H
#define TRIGFUNCS_H

#include <stdlib.h>
#include <math.h>
#include "misc.h"

double CalculateSin(double, const int); // Taylor series approximation based sine function that returns the sine value of the provided angle in radians.
double Sin(double); // Wrapper function for CalculateSin(double, const int), takes angle in degrees as input.

double CalculateCos(double, const int); // Taylor series approximation based cosine function that returns the cosine value of the provided angle in degrees.
double Cos(double); // Wrapper function for CalculateCos(double, const int), takes angle in degrees as input.

double Tan(double);
double Cosec(double);
double Sec(double);
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

double CalculateCos(double angle, const int maxIterations)
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
    return CalculateCos(RADIANS(angle), 10);
}

double CalculateTan(double angle, const int maxIterations)
{
    double bernoulliNumbers[10] = {
        1, 0.166667, -0.033333, 0.023809, 0.075757,
        -0.253114, 1.16667, -7.09216, 54.9712
    };

    double tanval = 0,
        numerator = 0,
        factorial = 0;

    const int n = GetRecurranceCount(angle), // Gets the repeatation of PI
        sign = GetSign(n); // Quadrant sign

    angle -= n * PI;

    int fourthPow = 0;

    for (int x = 1; x <= maxIterations; x++)
    {
        factorial = Factorial(2 * x);
        numerator = ((fourthPow = pow(4, x)) * (fourthPow - 1) * bernoulliNumbers[x] * pow(angle, (2 * x) - 1));

        tanval +=  pow(-1, x - 1) * (numerator / factorial);
    }

    return (sign * tanval);
}

double Tan(double angle)
{
    return (Sin(angle) / Cos(angle));
}

double Cot(double angle)
{
    return (1 / Tan(angle));
}

double Cosec(double angle)
{
    return (1 / Sin(angle));
}

double Sec(double angle)
{
    return (1 / Cos(angle));
}


#endif
