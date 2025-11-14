/* correcting silly program */

#include <stdio.h> // no include in original

int main(void) // void main(int)
{
    int legs; // cows, legs integer;
    _Bool valid = 0;
    //there was no space

    //printf("How many cow legs did you count?\n);
    printf("How many cow legs did you count? "); 
    scanf("%d", &legs); //scanf("%c", legs);
    while (!valid) {

        if (legs % 4 != 0) {
            printf("That is not a valid number of legs for cows. Try again.\n");
            printf("How many cow legs did you count? "); 
            scanf("%d", &legs); //scanf("%c", legs);
        } else {
            valid = 1;      
        }
    }
    //printf("That implies there are %f cows.\n", cows)
    printf("That implies there are %d cows.\n", legs / 4);
    return 0;
}