#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define FILENAME "numbers.txt"

int readNumber(const char* prompt);

int main()
{
	FILE* myFile;
	int array[MAX];
	int number;
	int count = 0;

	myFile = fopen(FILENAME,"w");
	if (myFile == NULL)
	{
		printf("Unable to open %s\n", FILENAME);
		return 1;
	}
	//Program will stop asking input once 20 numbers have read OR once user enters negative number
	for (int i = 0; i < MAX; i++)
	{
		number = readNumber("Please enter an integer.[Enter a negative integer to STOP]: ");
		if (number < 0)
		{
			printf("Program is stopped.\n");
			break;
		}
		else
		{
			array[i] = number;
			printf("Adding number %d into array[%d]\n", number, i);
			fprintf(myFile, "%.2d ", number);
			count++;
		}
	}
	printf("There are %d numbers have been added !\n", count);
	printf("Done writing input numbers into file %s\n\n", FILENAME);
	fclose(myFile);
}

// Function to ask input number from user
int readNumber(const char* prompt)
{
	int number = 0;
	char input[MAX];
	printf("%s", prompt);
	fgets(input, MAX, stdin);
	sscanf(input, "%d", &number);
	return number;
}