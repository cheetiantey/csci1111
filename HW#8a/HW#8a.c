// HW#8a  Chee Tey
#include <stdio.h>
#define PROMPT "Enter %d integer values: "
#define SIZE 5

// Function prototype for sort()
void sort(int newArray[], int n);

// Swap the two numbers
void swap(int* first, int* second);

int main(void)
{
    int array[SIZE];
    printf("HW#8a Chee Tey\n");
    printf(PROMPT, SIZE); // Prompts the user for integers 

    // Read in and saves the number of integers the user has entered in an array
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("Initial array: "); 

    // Prints out the initial array of integers
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");

    sort(array, SIZE); // Calls the sort() function and passing in array and SIZE as arguments

    printf("Sorted array: ");
    
    // Prints out the sorted array of integers
    for (int k = 0; k < SIZE; k++)
    {
        printf("%d ", array[k]);
    }

    printf("\n");

    return 0;
    
}

// Function definition for sort()
void sort(int newArray[], int n)
{
    int temp, j;
    int n1 = n - 1;
    int n1i = n1 - i;
    
    for (int i = 0; i < n1; i++) 
    {
        for (j = 0; j < n1i; j++)
        {
            // Only executes if the current integer is larger than the following integer
            if (newArray[j] > newArray[j + 1])
            {
                swap(&newArray[j], &newArray[j + 1]);                       
            }
        }
    }
}

// Swap the two numbers
void swap(int* first, int* second)
{
    int temp;

    temp = *first;
    *first = *second;
    *second = temp;
}

// HW#8a Chee Tey
// Enter 5 integer values: 4 23 41 8 15
// Initial array: 4 23 41 8 15 
// Sorted array: 4 8 15 23 41 
