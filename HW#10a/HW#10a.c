// HW#10a Chee Tey 
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 41
#define PROMPT "Enter a line of text:\n"
#define PROMPT1 "Enter a character to search:\n"
#define PROMPT2 "\nPress any key to continue or press enter to quit:\n"

int CharIsAt(char* pStr, char ch, int loc[], int mLoc);
int valid(void);

int main (void)
{
    char array[SIZE], input, ch;
    int loc[SIZE], answer;
    int flag;
    char* pArray = array;

    printf("HW#10a Chee Tey\n");
    
    // Run the loop at least once
    do
    {
        flag = 0;

        printf(PROMPT); // Prompts the user for a string

        fgets(array, SIZE, stdin); // Reads in the string 

        // Replaces the '\n' in array to be a null character
        while(*pArray)
        {
            if(*pArray == '\n')
            {
                *pArray = '\0';
                flag++;
            }
            pArray++;
        }

        // Clear the buffer if needed
        if (!flag)
        {
            while (getchar() != '\n');
        }
        
        printf(PROMPT1); // Prompts the user for a character

        ch = getchar(); // Reads in a character

        while (getchar() != '\n'); // Clears the buffer if needed

        printf("\nThe string entered is: %s\n", array);

        printf("The character being searched for is: '%c'\n", ch);

        // Saves the number of times the character has been found in answer
        answer = CharIsAt(array, ch, loc, SIZE); 

        printf("'%c' is found in location: ", ch);

        // Print the location the character is found relative to the first character in the string
        for (int j = 0; j < answer; j++)
        {
            printf("%d ", loc[j]);
        }
        printf("\n");

        printf("There are %d '%c' in the array.\n", answer, ch);

        printf(PROMPT2); // Asks the user if the want to exit or continue
    }
    while (valid());

    return 0;

}

int valid(void)
{
    char c;
    int val;
    c = getchar();

    // If a blank line is entered
    if(c =='\n' )
    {
        val = 0;
    }
    
    else
    {
        val = 1;
        while (getchar() != '\n');
    }
    
    return val;
}
int CharIsAt(char* pStr, char ch, int loc[], int mLoc)
{
    int counter; // Counter for the number of times 'ch' is found
    char* initialptr = pStr;

    for (counter = 0; *pStr != '\0'; pStr++)
    {
        if (*pStr == ch && counter < mloc) // if the pointed character is the same as 'ch'
        {
            loc[counter++] = pStr - initialptr;
        }
    }    
    
    return counter;
}

// HW#10a Chee Tey
// Enter a line of text:
// I love Minnesota
// Enter a character to search:
// o

// The string entered is: I love Minnesota
// The character being searched for is: 'o'
// 'o' is found in location: 3 13 
// There are 2 'o' in the array.

// Press any key to continue or press enter to quit:
// a
// Enter a line of text:
// Florida and Texas
// Enter a character to search:
// a

// The string entered is: Florida and Texas
// The character being searched for is: 'a'
// 'a' is found in location: 6 8 15 
// There are 3 'a' in the array.

// Press any key to continue or press enter to quit:






