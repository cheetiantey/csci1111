#include <stdio.h>
#include <stdlib.h>

int x = 100;

int main(void)
{
    printf("Hello world!\n");
    int* number0;
    *number0 =  5;

    int* number1;
    number1 = number0;

    int number2 = 6;
    number1 = &number2;

    printf("%i\n", *number0);
    printf("Seoond %i\n", *number1);
    printf("Third %i\n", number2);
    printf("%i\n", x);
    
    return 0;

}