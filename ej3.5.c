/* ej3.5.c -- fixing the code of the exercise 5 in chapter 3 */

#include <stdio.h> //# missing

int main(void) // int and (void) missing
{
    long double g; //the first ; should be , and h is unused
    long double tax;
    double rate;

    g = 1e21; // needs a decimal part
    rate = 1;
    tax = rate * g; //rate is undefined

    printf("g = %Lf and tax = %Lf\n", g, tax);

    return 0; // missing
}