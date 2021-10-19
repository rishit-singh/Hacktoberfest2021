// Miscellenous math related functions, macros, and globals.

#ifndef MISC_H
#define MISC_H

#define PI 3.141592654
#define TWOPI 6.283185307

#define RADIANS(x) ((PI / 180) * x) // x degrees to radians.
#define DEGREES(x) ((180 / PI) * x) //x radians to degrees.

int Factorial(int); // Finds the factorial of the provided int.

int Factorial(int x)
{
    if (!x || x == 1)
        return x;

    return x * Factorial(x - 1);
}



#endif
