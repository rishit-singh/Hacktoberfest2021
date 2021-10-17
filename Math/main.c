#include <stdio.h>
#include <stdlib.h>
#include "trigfuncs.h"

int main(int argc, char** argv)
{
    printf("%f\n", CalculateSin(atof(argv[1]), 5));

    return 0;
}
