// HW#7 Chee Tey
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PROMPT0 "Enter the operation of your choice:\na. add               s. subtract\nm. multiply          d. divide\nq. quit\n"
#define PROMPT1 "Enter the first number: "
#define PROMPT2 "Enter the second number: "

// Function prototypes
double add(double num1, double num2); 
double subtract(double num1, double num2);
double multiply(double num1,double num2);
double divide(double num1, double num2);

int main (void)
{
    // Buffer is for when user input is strings instead of doubles 
    char choice;
    int buffer;
    double num1, num2; 

    printf("HW#7 Chee Tey\n");
    printf(PROMPT0); // Prompt the user for the mathematical fuction  

    // Only run the while loop when scanf doesn't return 0 AND (choice is either 'a', 's', 'm', or 'd')
    while (scanf("%c", &choice) && (choice == 'a' || choice == 's' || choice == 'm' || choice == 'd'))
    {
        printf(PROMPT1); // Prompts the user for the first number
        
        // Only execute if the scanf return 0 (meaning a character or string is entered)
        while (!(scanf("%lf", &num1))) 
        {
            while ((buffer = getchar()) != '\n')
            {
                putchar(buffer);
            }
            printf(" is not a number\n"); 
            printf(PROMPT1); // Prompts the user again for the first number
        }
    
        printf(PROMPT2); // Prompts the user for the second number

        // Only execute if the scanf return 0 (meaning a character or string is entered)
        while (!(scanf("%lf", &num2)))
        {
            while ((buffer = getchar()) != '\n')
            {
                putchar(buffer);
            }
            printf(" is not a number\n");
            printf(PROMPT2); // Prompts the user again for the second number
        }

        if (choice == 'a') // If the mathematical function chosen is 'a'
        {
            printf("%lf + %lf = %lf\n\n", num1, num2, add(num1, num2)); // Calls the add fuction
        }
        else if (choice == 's') // If the mathematical function chosen is 's'
        {           
            printf("%lf - %lf = %lf\n\n", num1, num2, subtract(num1, num2)); // Calls the subtract function
        }
        
        else if (choice == 'm') // If the mathematical function chosen is 'm'
        {
            printf("%lf * %lf = %lf\n\n", num1, num2, multiply(num1, num2)); // Calls the multiply fuction
        }

        else if (choice =='d') // If the mathematical function chosen is 'd'
        {
            while (num2 == 0) // Execute only if num2 is 0 (because a number divide by 0 is undefined)
            {
                printf("Please enter a number other than 0: "); // Prompts for second number again
                
                // Only execute if the scanf return 0 (meaning a character or string is entered)
                while (!(scanf("%lf", &num2))) 
                {
                    while ((buffer = getchar()) != '\n') // Clears the buffer
                    {
                        putchar(buffer);
                    }
                    printf(" is not a number\n");
                    printf(PROMPT2); // Prompts the user for the second number 
                }
            }
            printf("%lf / %lf = %lf\n\n", num1, num2, divide(num1, num2)); // Calls the divide fuction
        }
        
        getchar(); // Clears the buffer
        printf(PROMPT0);
    }

    printf("Bye!\n"); 
}

double add(double num1, double num2) // Add function
{
    double answer = 0;
    answer = num1 + num2;
    return answer;
}
double subtract(double num1, double num2) // Subtract function
{
    double answer = 0;
    answer = num1 - num2;
    return answer;
}

double multiply(double num1, double num2) // multiply function
{
    int answer = 0;
    answer = num1 * num2;
    return answer;
}

double divide(double num1, double num2) // divide function
{
    double answer = 0;
    answer = num1 / num2;
    return answer;
}

// HW#7 Chee Tey
// Enter the operation of your choice:
// a. add               s. subtract
// m. multiply          d. divide
// q. quit
// a
// Enter the first number: 22.4
// Enter the second number: one
// one is not a number
// Enter the second number: 1
// 22.400000 + 1.000000 = 23.400000

// Enter the operation of your choice:
// a. add               s. subtract
// m. multiply          d. divide
// q. quit
// d
// Enter the first number: 18.4
// Enter the second number: 0
// Please enter a number other than 0: 0.2
// 18.400000 / 0.200000 = 92.000000

// Enter the operation of your choice:
// a. add               s. subtract
// m. multiply          d. divide
// q. quit
// q
// Bye!