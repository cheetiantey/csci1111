// HW#8 Chee Tey
#include <stdio.h>
#define PROMPT "Enter a postitive integer value or 'q' to quit: "

int sum(int value);

int main (void)
{
    int value;
    printf("HW#8 Chee Tey\n");
    printf(PROMPT);

    while (scanf("%d", &value) && value > 0)
    {
        printf("Sum(%d) = %d\n", value, sum(value));
        printf(PROMPT);
    }  
      
    return 0;
}

int sum(int value)
{
    if (value == 1)
    {
        return 1;
    }
    else
    {
        return (value + sum(value-1));
    }
    
}