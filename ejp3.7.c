/* problem 3.7 */

#include <stdio.h>

int main(void)
{
    float inchtocm = 2.54;
    float inches;

    printf("Enter a length in inches: ");
    scanf("%f", &inches);
    printf("%.3f inches is equal to %.3f cm.\n", inches, inches * inchtocm);

    return 0;

}