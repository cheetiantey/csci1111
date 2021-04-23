// HW #2 Chee Tey
#include <stdio.h> // Inludes the required library needed

int main(void)
{
    double cups, pints, ounces, tablespoons, teaspoons; // decalred all variables at once
    
    printf("/* HW #2 Chee Tey */\n");

    printf("Enter the number of cups to be converted: ");
    scanf("%lf", &cups); // Gets an input from the user 

    pints = cups / 2; // A pint is half a cup
    ounces = cups * 8; // An ounce is 8 cups
    tablespoons = ounces * 2; // A tablespoon is 2 ounces
    teaspoons = tablespoons * 3; // A teaspoon is 3 tablespoons

    printf("  %10.3lf cups\n", cups);
    printf("= %10.3lf pints\n", pints);
    printf("= %10.3lf ounces\n", ounces);
    printf("= %10.3lf tablespoons\n", tablespoons);
    printf("= %10.3lf teaspoons\n", teaspoons);

    return 0;
    
}

// /* HW #2 Chee Tey */
// Enter the number of cups to be converted: 3.2
//        3.200 cups
// =      1.600 pints
// =     25.600 ounces
// =     51.200 tablespoons
// =    153.600 teaspoons