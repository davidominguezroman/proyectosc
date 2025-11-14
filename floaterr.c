/* floaterr.c -- demonstrates round-of error */

#include <stdio.h>

int main(void)
{
    float a, b, c, d;

    b = 2.0e20 + 1.0;
    a = b - 2.0e20;
    c = 2.0e4 + 1.0;
    d = c - 2.0e4;
    printf("%f \n", a);
    printf("%f \n", d);

    return 0;
}