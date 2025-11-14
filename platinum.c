/* platinum.c -- your weight in platinum */

#include <stdio.h>

int main(void) 
{
    float weight; /*user weight         */
    float value; /* platinum equivalent */

    printf("Are you worth your weight in platinum?\n");
    printf("Let check it out. \n");
    printf("Please, enter your weight in pounds: ");

    /* Get input from the user */

    scanf("%f", &weight);

    /* Assume platinum is $1700 per pounce */
    /* 14.5833 converts pounds avd. to ounces troy */

    value = 1700.0 * weight * 14.5833;

    printf("Your weight in platinum is worth $%.2f. \n", value);
    printf("You are easily worth that! If platinum prices drop,\n");
    printf("eat more to maintain your value. :P\n");

    return 0;
}