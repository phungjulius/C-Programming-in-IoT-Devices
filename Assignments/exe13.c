#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#define MAX 50
#define LENGTH 100
//define Item as a type name
typedef struct Item Item;
struct Item
{
	char name[MAX];
	float price;
	int count;
};

int main()
{
	Item itemArray[LENGTH];
	int totalCount = 0;
	int lineCount = 0;
	char input[MAX]={'\0'};
	char line[LENGTH]={'\0'};
	char name[MAX]={'\0'};
	int itemCount;
	float price;
	FILE* readFile;

	printf("Please enter text file's name following by \'.txt\': ");
	do
	{	//Prompt user for correct input format
		scanf("%s", input);
		if (strstr(input, ".txt") == NULL)
		{
			printf("Please enter the correct format following by \'.txt\' : ");
		}
		else
			break;
	} while (1);

	printf("Your inserted text file name is: %s\n", input);

	readFile = fopen(input, "r");
	if (readFile == NULL)
	{
		printf("Unable to open file %s\n", input);
		return -1;
	}
	else
	{
		printf("Reading items information from file %s to an array.\n", input);
		// Program reads from file to array until the end of the file OR upto 100 total items in the store are reached
		while (!feof(readFile) && totalCount < LENGTH)
		{
			if (fgets(line, LENGTH, readFile) != NULL)
			{
				if (sscanf(line, " %f;%[^;];%d", &price, name, &itemCount) == 3)
				{
					if (itemCount > (LENGTH - totalCount))
					{
						break;
					}
					else
					{
						itemArray[lineCount].price = price;
						strcpy(itemArray[lineCount].name, name);
						itemArray[lineCount].count = itemCount;
						totalCount = totalCount + itemCount;
					}
				}
				lineCount++;
			}
			else
				return -1;
		}
	}
	fclose(readFile);
	printf("\n\n");
	for (int i = 0; i < lineCount; i++)
	{
		printf("Price: %8.2f      Item: %-25s      Count: %-15d\n", itemArray[i].price, itemArray[i].name, itemArray[i].count);
	}
	printf("\nDone Reading items information from file %s to an array.\n\n", input);
	printf("Total lines read from file %s: %d\n", input, lineCount);
	printf("Total items in store read from file %s: %d\n", input, totalCount);
	return 0;
}