// HW#11a Chee Tey
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define PROMPT "Enter the input channel (2 to 10) (Type zero or a character to exit):\n"
#define PROMPT1 "Data point choices: 2048, 4096, and 8192 (Type zero or a character to exit)\n"
double dRand(void);
int Setup(int* pnChan, int* pnPt);
int CollectData(int nChan, int nPt, double Data[][nPt]);
int valid(int i, int* pnPt);

int main (void)
{
    printf("#Hw#11a Chee Tey\n");

    int pnChan, pnPt;
    srand((unsigned int) time (0));

    while(!Setup(&pnChan, &pnPt)) // While the user gives good input
    {   
        // Allocate memory for a 2D array
        void* pData = malloc(sizeof(double) * (pnChan) * (pnPt));
        if (!pData) // If the pointer is NULL
        {
            printf("Please request fewer channels or data points\n");
        }
        else
        {
            CollectData(pnChan, pnPt, pData); // Fill in the 2D arary with data
            printf("Number of channels : %d\nNumber of data points : %d\nSize (in bytes) of memory allocated: %lu\n", pnChan, pnPt, sizeof(double)*pnChan*pnPt);
            printf("Address of the memory allocated memory block: %p\n\n", pData);
        }
        free(pData); // Free up the memory used
    }
    printf("Program exited!\n");
    return 0;
}

double dRand(void) // return a random double value 
{
    return (rand() * (10.0/RAND_MAX));
}

int Setup(int* pnChan, int* pnPt)
{
    int val = 0;
    
    printf(PROMPT); // Prompts the user for 'channel'

    // If the user gives good input
    if(scanf("%d", pnChan) && *pnChan != 0 && (*pnChan >=2 && *pnChan <=10))
    {
        printf(PROMPT1); // Prompts the user for 'data points'
        
        // Execute only if user gives bad input
        if((!scanf("%d", pnPt) || *pnPt == 0) || ((*pnPt != 2048 && *pnPt != 4096 && *pnPt != 8192) && !valid(*pnPt, pnPt)))
        {
            val--;
            while(getchar() != '\n'); // Clears the buffer
        }
    }
    else
    {
        val--;
        while(getchar() != '\n'); // Clear the buffer
    }

    return val;
}

// Fills in the 2D array with data
int CollectData(int nChan, int nPt, double Data[][nPt])
{
    int i, j, val;
    for (i = 0, val = 0; i < nChan; i++)
    {
        for (j = 0; j < nPt; j++)
        {
            Data[i][j] = dRand(); // Fill in the i-th item in the 2D array with a random value
        }
    }
    return val;
}

// A function to round the user's input 
int valid(int i, int* pnPt)
{
    int val = 0;

    if (i >= 2000 && i <= 9000) // If the input is within the range
    {
        val++;
        if (i >= 2000 && i <= 3500) *pnPt = 2048;
        else if (i >3500 && i <= 6000) *pnPt = 4096;
        else *pnPt = 8192;
    }
    return val;
}

// #Hw#11a Chee Tey
// Enter the input channel (2 to 10) (Type zero or a character to exit):
// 2
// Data point choices: 2048, 4096, and 8192 (Type zero or a character to exit)
// 2048
// Number of channels : 2
// Number of data points : 2048
// Size (in bytes) of memory allocated: 32768
// Address of the memory allocated memory block: 0x7faa8f008200

// Enter the input channel (2 to 10) (Type zero or a character to exit):
// 5
// Data point choices: 2048, 4096, and 8192 (Type zero or a character to exit)
// 8192
// Number of channels : 5
// Number of data points : 8192
// Size (in bytes) of memory allocated: 327680
// Address of the memory allocated memory block: 0x108588000

// Enter the input channel (2 to 10) (Type zero or a character to exit):
// 6
// Data point choices: 2048, 4096, and 8192 (Type zero or a character to exit)
// 8500
// Number of channels : 6
// Number of data points : 8192
// Size (in bytes) of memory allocated: 393216
// Address of the memory allocated memory block: 0x1085d9000

// Enter the input channel (2 to 10) (Type zero or a character to exit):
// 7
// Data point choices: 2048, 4096, and 8192 (Type zero or a character to exit)
// 0
// Program exited!

