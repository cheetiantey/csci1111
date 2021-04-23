//HW#13a Chee Tey
#include <stdio.h>
#define SIZE 5

struct detail
{
    char first[15], last[15]; // 15 bytes for first and last name
};

struct member
{
    int ssn; 
    struct detail name; // Nested structure
};

int main (void)
{
    printf("HW#13a Chee Tey\n");
    int i = 0; // Declaration of counter
    struct member members[SIZE] = {{.ssn = 205110887, .name.first = "Tom", .name.last = "Hanks"},
                                   {.ssn = 887223939, .name.first = "Elon", .name.last = "Musk"},
                                   {.ssn = 630771770, .name.first = "Bill", .name.last = "Gates"},
                                   {.ssn = 588400121, .name.first = "Larry", .name.last = "Ellison"},
                                   {.ssn = 228344590, .name.first = "Steve", .name.last = "Jobs"} }; 

    // Print out the data
    for (i = 0; i < SIZE; i++) printf("%d -- %s, %s\n", members[i].ssn, members[i].name.last, members[i].name.first);
    
    return 0; // Success
}

// HW#13a Chee Tey
// 205110887 -- Hanks, Tom
// 887223939 -- Musk, Elon
// 630771770 -- Gates, Bill
// 588400121 -- Ellison, Larry
// 228344590 -- Jobs, Steve

