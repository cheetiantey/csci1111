// HW#12a Chee Tey
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define PROMPT "Please enter number of channels [2-10]. (0 to quit)\n"
#define PROMPT1 "Data point choices: 2048, 4096, and 8192 (Type zero or a character to exit)\n"
#define FILESIZE 20
double dRand(void);
int Setup(int* pnChan, int* pnPt);
int CollectData(int nChan, int nPt, double Data[][nPt]);
int WriteBinary(int nChan, int nPt, double Data[][nPt], const char * pfname);
int ReadBinary(int nChan, int nPt, double Data[][nPt], const char * pfname);
int AvgData(int nChan, int nPt, double Data[][nPt], double Avg[]);
int Results(int nChan, double Avg[]);
int exist(char* pfname, const int filesize);

int main (void)
{
    printf("#Hw#12a Chee Tey\n");
    int pnChan, pnPt;
    long memSize;
    void* pData;
    void* newPData;
    char filename[FILESIZE] = "data.txt";
    srand((unsigned int) time (0));

    while(!Setup(&pnChan, &pnPt)) // While the user gives good input
    {   
        // Allocate memory for a 2D array
        memSize = sizeof(double) * (pnChan) * (pnPt);
        pData = malloc(memSize);
        double Avg[pnPt];

        if (!pData) // If the pointer is NULL
        {
            printf("Please request fewer channels or data points\n");
        }
        else
        {
            CollectData(pnChan, pnPt, pData); // Fill in the 2D arary with data
            if(!exist(filename, FILESIZE))
            {
                WriteBinary(pnChan, pnPt, pData, filename);
                newPData = malloc(memSize);
                if (newPData)
                {
                    ReadBinary(pnChan, pnPt, newPData, filename);
                    AvgData(pnChan, pnPt, newPData, Avg);
                    free(newPData);
                }
                else
                {
                    ReadBinary(pnChan, pnPt, pData, filename);
                    AvgData(pnChan, pnPt, pData, Avg);
                }
                Results(pnChan, Avg);
                free(pData); // Free up the memory used
            }
        }
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
    char ch;
    *pnPt = 0;
    do
    {
        printf(PROMPT);
        while (scanf("%d",pnChan)==0)
        {
			while(getchar()!='\n');
			puts("Invalid input, please enter number of channels [2-10]. (0 to quit)");
		}
    } while ((*pnChan!=0) && (*pnChan < 2 && *pnChan >10)); // While the user keys in invalid response

    while(getchar()!='\n');

    if (*pnChan>1) 
    {
        do 
        {
			printf(PROMPT1);
			ch=getchar();
			while(getchar()!='\n');
			switch (ch) {
				case '2': 	*pnPt = 2048;
							break;
				case '4':	*pnPt = 4096;
						   	break;
				case '8':	*pnPt = 8192; // Do not need a break here.
				case 'q':	break; // Skip default and exit do while
				default: puts("Invalid selection.");
			}
		} while (*pnPt==0 && ch!='q');
    }
    
    return ((*pnChan>1) && (*pnPt>0)) ? 0: -1;
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

int exist(char* pfname, const int filesize)
{
    int val = 0, flag = 0;
    char response, *ptr;
    FILE* fp = fopen(pfname, "rb");

    // Execute only if the file is opened successfully
    if(fp)
    {
        fclose(fp); // Close the file
        val--; 
        printf("%s already exists! Do you want to overwrite it?[N/y] or New File[F]: ", pfname);
        response = getchar(); // Get a char from the user
        while (getchar()!='\n'); // Clear the buffer
        if ((toupper(response)=='Y')) val++; // The user would like to overwrite the existing file

        // If the user indicated that they want a new file
        else if ((toupper(response)=='F')) 
        {
            // A while loop to get a desired filename from the user to store the data
            do
            {
                puts("Enter yout desired file name");
                if (flag++) puts("(The entered filename already exists)");
                fgets(pfname, filesize, stdin);
                for (ptr=pfname; (*ptr!='\0') && (*ptr!='\n'); ptr++);
                if (*ptr=='\0') while (getchar()!='\n');
                else (*ptr = '\0');
            } while ((fp=fopen(pfname, "rb")));
            val++;
        }
    }
    return val;
}
int WriteBinary(int nChan, int nPt, double Data[][nPt], const char* pfname)
{
    int returnval;
    FILE* fp = fopen(pfname, "wb"); 

    if (fp) // Execute only if fp is not NULL
    {
        returnval = fwrite(&nChan, sizeof(int), 1, fp); // Write the number of channels to the file
        if (returnval != 1)  printf("Error in fwrite()\n");

        returnval = fwrite(&nPt, sizeof(int), 1, fp); // Write the number of points to the file
        if (returnval != 1)  printf("Error in fwrite()\n");

        returnval = fwrite(Data, sizeof(double)*nChan*nPt, 1, fp); 
        if (returnval != 1)  printf("Error in fwrite()\n");
        
        fclose(fp); // Close the file
    }
    return 0;
}

int ReadBinary(int nChan, int nPt, double Data[][nPt], const char * pfname)
{
    int val = -1, channel = 0, points, returnval;
    FILE* fp = fopen(pfname, "rb");

    returnval = fread(&channel, sizeof(int), 1, fp);
    if (returnval != 1)  printf("Error in fread()\n");
    returnval = fread(&points, sizeof(int), 1, fp);
    if (returnval != 1)  printf("Error in fread()\n");
    
    // Execture only if the number of channels and points match from the file match the ones in the system
    if ((nChan == channel) && (nPt == points))
    {
        val++; // Increment val
        returnval = fread(Data, sizeof(double)*nChan*nPt, 1, fp);  // Get the data point and save it into the array
        if (returnval != 1)  printf("Error in fread()\n");
    }
    fclose(fp); // Close the file
    return val;
}
int AvgData(int nChan, int nPt, double Data[][nPt], double Avg[])
{
    int i, j, val = 0;
    double sum;

    for (i = 0; i < nChan; i++, sum = 0)
    {
        for (j = 0, sum = 0; j < nPt; j++)
        {
            sum+=Data[i][j]; // Sum up the data points in a channel
        }
        Avg[i] = sum/nPt; // Calculate the average of the data points in a channel
    }
    return val;
}

int Results(int nChan, double Avg[])
{
    int i, val = 0;
    printf("\n");

    // Print out the average of data points in each channel
    for (i = 0; i < nChan; i++) printf("Average of Channel %d is %lf\n", i+1, Avg[i]);
    return val;
}

// #Hw#12a Chee Tey
// Please enter number of channels [2-10]. (0 to quit)
// 2
// Data point choices: 2048, 4096, and 8192 (Type zero or a character to exit)
// 4096
// data.txt already exists! Do you want to overwrite it?[N/y] or New File[F]: y

// Average of Channel 1 is 5.060364
// Average of Channel 2 is 4.940029
// Please enter number of channels [2-10]. (0 to quit)
// 5
// Data point choices: 2048, 4096, and 8192 (Type zero or a character to exit)
// 8
// data.txt already exists! Do you want to overwrite it?[N/y] or New File[F]: F
// Enter yout desired file name
// newfile.txt

// Average of Channel 1 is 5.008050
// Average of Channel 2 is 4.945370
// Average of Channel 3 is 5.008895
// Average of Channel 4 is 5.062060
// Average of Channel 5 is 5.008896
// Please enter number of channels [2-10]. (0 to quit)
// 2
// Data point choices: 2048, 4096, and 8192 (Type zero or a character to exit)
// 4000
// newfile.txt already exists! Do you want to overwrite it?[N/y] or New File[F]: n
// Please enter number of channels [2-10]. (0 to quit)
// 0
// Program exited!

