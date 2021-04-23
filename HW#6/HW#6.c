// HW#6 Chee Tey
#include <stdio.h>
#include <limits.h>
#define PROMPT "Enter a number(or enter 'q' to quit): "
#define SIZE 10

unsigned long Factorial (unsigned int n);

int main (void)
{
    int number[SIZE], index;
    unsigned long maxFactorial;
    int k;
    
    printf("HW #6 Chee Tey\n");
    printf(PROMPT);

    // Take in the input 
    for (index = 0; index < SIZE && scanf("%d", &number[index]); index++);
    
    printf(" n            n!\n");

    for (int i = 0; i < index; i++)
    {
        printf("%2d     %10lu\n\n", number[i], Factorial(number[i])); // Prints out the value of n and n!
    }

    // Loops when k <= USHRT_MAX AND maxFactorial is smaller than USHRT_MAX
    for (k = 1, maxFactorial = 0; maxFactorial <= USHRT_MAX; k++)
    {
        maxFactorial = Factorial(k); // Calculates n!
    }
    maxFactorial = maxFactorial / --k; // Since maxFactorial is one factorial over, we divde maxFactorial by --k

    printf("The maximum value of an unsigned short is %d\n", USHRT_MAX);
    printf("The maximum value n that will produce the largest n! is %d\n",--k);
    printf("The largest n! that could be stored in an unsigned short is %lu\n", maxFactorial);
    return 0;
}

unsigned long Factorial (unsigned int n)
{
    unsigned long factorial = 1;

    for (int j = 1; j <= n; j++)
    {
        factorial *= j; // Calculates n! by multiplying by j
    }
    return factorial;
}

// HW #6 Chee Tey
// Enter a number(or enter 'q' to quit): 1 2 3 4 5 6 7 q
//  n            n!
//  1              1

//  2              2

//  3              6

//  4             24

//  5            120

//  6            720

//  7           5040

// The maximum value of an unsigned short is 65535
// The maximum value n that will produce the largest n! is 8
// The largest n! that could be stored in an unsigned short is 40320

