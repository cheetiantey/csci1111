// HW #3 Chee Tey
#include <stdio.h>
#include <string.h> // Needed for strlen() function

int main (void)
{
    char FirstName[30]; // Char array of 30 for first name
    int FirstNameSize; 

    char LastName[30];
    int LastNameSize;
    
    printf("// HW #3 Chee Tey\n");

    printf("Enter your first name: "); // Prompts user for FN
    scanf("%s", FirstName); // Get the input from user 
    printf("Enter your Last name: "); // Prompts the user for LN
    scanf("%s", LastName); // Get the input from user

    printf("%s ", FirstName);
    printf("%s\n", LastName);

    // Calculates the length of the strings
    FirstNameSize = strlen(FirstName); 
    LastNameSize = strlen(LastName);

    // Prints the strlen() of the strings under the names
    printf("%*d", FirstNameSize, FirstNameSize);
    printf("%*d\n", LastNameSize + 1, LastNameSize);

    // Stores 1.0/3.0 in float and double
    float var0 = 1.0/3.0;
    double var1 = 1.0/3.0;

    // Print the results 
    printf("%.4f, %.8f, %.12f\n", var0, var0, var0);
    printf("%.4lf, %.8lf, %.12lf\n", var1, var1, var1);

    return 0;

}

// // HW #3 Chee Tey
// Enter your first name: Chee 
// Enter your Last name: Tey
// Chee Tey
//    4   3
// 0.3333, 0.33333334, 0.333333343267
// 0.3333, 0.33333333, 0.333333333333