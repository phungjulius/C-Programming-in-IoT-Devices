#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define READ "numbers.txt"
#define WRITE "print.txt"

int main()
{
	FILE* readFile;
	FILE* writeFile;
	int numberArray[MAX];
	int count = 0;
	int value = 0;
	float sum = 0;
	float average;

	readFile = fopen(READ, "r");
	writeFile = fopen(WRITE, "w");

	//Check if the files are able to open
	if (readFile == NULL)
	{
		printf("Unable to open %s\n", READ);
		return 1;
	}
	else if (writeFile == NULL)
	{
		printf("Unable to open %s\n", WRITE);
		return 1;
	}
	else
	{
		printf("Reading numbers from %s file \n", READ);
		//Read numbers from file to array until file 'ALMOST' ends (NOT read the terminating element) OR 100 numbers have been read.
		while (fscanf(readFile, "%d", &numberArray[count]) != EOF && count < MAX)
		{
			count++;
		}
		printf("Done reading numbers from %s file to array\n", READ);
	}
	//Print numbers from the number array, total sum and average to the screen
	for (int i = 0; i < count; i++)
	{
		printf("Element[%d] is %d\n", i, numberArray[i]);
		sum = sum + numberArray[i];
	}
	printf("Total numbers count is: %d\n", count);
	printf("Sum is: %.2f\n", sum);
	average = sum / count; //Calculate average of read numbers
	printf("Average is %.2f\n", average);
	
	//Write counts, average and printing numbers to file print.txt line by line
	fprintf(writeFile, "Total numbers read from file %s is %d. Average is %.2f. Start printing number line by line:\n", READ, count, average); 
	for (int i = 0; i < count; i++)
	{
		fprintf(writeFile, "%d\n", numberArray[i]);
	}
	printf("Succesfully write numbers to %s file\n", WRITE);
	fclose(readFile);
	fclose(writeFile);
}