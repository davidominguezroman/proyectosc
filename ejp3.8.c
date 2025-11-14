/* problem 3.8 */

#include <stdio.h>

int main(void)
{
    int pinttocup = 2;
    int cuptoounces = 8;
    int ouncetotablespoons = 2;
    int tablespoonstoteaspoons = 3;

    float cups;

    printf("Enter a volume in cups: ");
    scanf("%f", &cups);
    printf("%.2f cups are equal to:\n", cups);
    printf("\t%.2f pints\n", cups / pinttocup);
    printf("\t%.2f ounces\n", cups * cuptoounces);
    printf("\t%.2f tablespoons\n", 
        cups * cuptoounces * ouncetotablespoons);  
    printf("\t%.2f teaspoons\n", 
        cups * cuptoounces * ouncetotablespoons * tablespoonstoteaspoons);
    return 0;

}