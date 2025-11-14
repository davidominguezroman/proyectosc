/* problem 3.6 */

#include <stdio.h>

int main(void) 
{
    long double moleculeg = 3.0e-23;
    int massquart;

    printf("Enter the ammount of water in quarts: ");
    scanf("%d", &massquart);
    printf("The number of molecules in %d quarts of water is %.2Le\n",
         massquart, (massquart * 950.0) / moleculeg);

    return 0;
}