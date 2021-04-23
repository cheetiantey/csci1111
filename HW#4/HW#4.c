// HW #4 Chee Tey
#include <stdio.h>
#include <string.h>
#define PROMPT "Enter you height in inches followed by your first name(Enter 'q' to quit): "

int main(void) 
{
    char FirstName[30]; 
    int height, foot, inches;

    printf("HW #4 Chee Tey\n");
    printf(PROMPT);

    // Execute iff the user enter a valid input
    while (scanf("%d %s", &height, FirstName) == 2)
    {
        foot = height / 12;
        inches = height % 12;
        printf("%s's height is %d foot %d inches \n", FirstName, foot, inches);
        printf(PROMPT); // Prompts the user
        
    }
    return 0;
}

// HW #4 Chee Tey
// Enter you height in inches followed by your first name(Enter 'q' to quit): 72 Chee
// Chee's height is 6 foot 0 inches 
// Enter you height in inches followed by your first name(Enter 'q' to quit): q