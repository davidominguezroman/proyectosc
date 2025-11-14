/* problem 3.5 */

#include <stdio.h>

int main(void)
{
    long int secinyear = 3.156e7;
    int years;

    printf("How old are you in years? ");
    scanf("%d", &years);
    printf("You are %ld seconds old.\n", years * secinyear);

    return 0;
}