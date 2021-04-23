#include <stdio.h>
#include <string.h>

int main (void)
{
    char FirstName[10];
    char LastName[10];
    
    printf("Enter your first name: ");
    scanf("%s", FirstName);

    printf(" Your name is %s\n", FirstName);

    printf("Enter your last name: ");
    scanf("%s", LastName);

    printf(" Your name is %s\n", LastName);
    return 0;

}