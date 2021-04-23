// HW #5 Chee Tey
#include <stdio.h>
#include <string.h>

int main(void) 
{
    const int range1 = 3;
    const int range2 = 8;

    printf("HW #5 Chee Tey\n");
    printf(" n          n!\n");
    
    // loops from range1 to range2
    for (int i = range1; i <= range2; i++)
    {
        printf("%2d    ", i);
        
        int factorial = 1; // Resets the value of factorial to 1

        // Calculates the value of n!
        for (int j = 1; j <= i; j++)
        {
            factorial *= j; // Calculates n! by multiplying by j
        }
        printf("%8d\n\n", factorial); // Prints out the value of n!
        
    }
    return 0;
}

// HW #5 Chee Tey
//  n          n!
//  3           6

//  4          24

//  5         120

//  6         720

//  7        5040

//  8       40320