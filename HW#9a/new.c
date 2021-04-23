// HW#9a Chee Tey
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NROW 3
#define NCOL 5

double dRand(void);
double dAvg(int col, double array2[]);
double dMax(int row, int col, double array3[][row]);

int main (void)
{
    double array[NROW][NCOL];
    double subtotal = 0;
    double average[NROW];
    int i, j;

    printf("HW#9a Chee Tey\n\n");

    srand((unsigned int) time(0));

    // Fill up the array with values
    for(i = 0; i < NROW; i++)
    {
        for(j = 0; j < NCOL; j++)
        {
            array[i][j] = dRand();
        }
    }

    printf("NROW                                                       Average\n");

    // Compute the average of each row in the array and print them  out
    for (i = 0; i < NROW; i++)
    {
        average[i] = dAvg(NCOL, array[i]);
        for (j = 0; j < NCOL; j++)
        {
            printf("%lf ", array[i][j]); // Print the value of each item
        }
        printf("              %lf\n", average[i]);
    }

    // Compute the average of all the values
    printf("\nAverage value of all results:\n");
    for (i = 0; i < NROW; i++)
    {
        subtotal += dAvg(NCOL, array[i]);
    }
    printf("%lf\n", subtotal/NROW);

    // Print out the largest value of all values
    printf("\nLargest double of all the values:\n%lf\n", dMax(NROW, NCOL, array));
    
    return 0;

}

// Returns a double value
double dRand(void) 
{
    return (rand() * 10.0 / RAND_MAX);
}

// Calculate the average of the values in a given array
double dAvg(int col, double array2[])
{
    double sum = 0;
    int i;

    for (i = 0; i < col; i++)
    {
        sum += array2[i];
    }
    
    return (sum/col);
}

// Find the Largest value in a given 2 dimensional array
double dMax(int row, int col, double array3[][col])
{
    double max = array3[0][0];
    int i, j;

    for (i = 0; i < row; i++) 
    {
        for (j = 0; j < col; j++)
        {   
            // Only executes if the current array item is larger than max
            if (array3[i][j] > max)
            {
                max = array3[i][j];
            }
        }
    }

    return max;
}


// HW#9a Chee Tey

// NROW                                                       Average
// 4.725009 3.221885 0.216343 6.069017 1.961277               3.238706
// 3.185554 9.609587 8.329829 9.432091 5.158998               7.143212
// 7.271169 6.538228 7.992515 0.195293 2.296777               4.858796

// Average value of all results:
// 5.080238

// Largest double of all the values:
// 9.609587