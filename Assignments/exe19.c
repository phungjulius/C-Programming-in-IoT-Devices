#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

#define MAX 20
#define LENGTH 100

//Program that allows user to remove bytes from a binary file in desire position

int main()
{
	FILE* rFile;
	FILE* wFile;
	char fileName[MAX]={'\0'};
	char* str;
	int count = 0, position = 0, removeBytes = 0;
	
	//Prompt user to enter the file name
	do
	{
		printf("Please enter a binary file's name following by \'.dat\' or \'.bin\': ");
		scanf("%s", fileName);
		if (strstr(fileName, ".bin") != NULL || strstr(fileName, ".dat") != NULL)
			break;
		else
			printf("Please enter a correct file format. For example students.bin or pricelist.dat\n");
	} while (1);

	//Open and read the file in binary mode and store it into string
	rFile = fopen(fileName, "rb");
	if (rFile == NULL)
	{
		printf("Error! File does not exist OR unable to open the file");
		return -1;
	}
	else
	{
		fseek(rFile, 0, SEEK_END);
		int bytes = ftell(rFile);
		fseek(rFile, 0, SEEK_SET);

		//Allocating dynamic memory to contain file data
		str = malloc(sizeof(int) * bytes);
		if (str == NULL)
		{
			printf("Error in allocating memory to contain file data");
			return -1;
		}

		while (!feof(rFile))
		{
			fread(&str, sizeof(char), 1, rFile);
			count++;
		}
	}
	fclose(rFile);

	printf("File \'%s\' has %d bytes\n", fileName, count);
	printf("Which position would you like to remote bytes from? ");
	scanf("%d", &position);

	//Set offset limit
	if (position > count || position <0 )
	{
		printf("The offset is not valid");
		return -1;
	}
	printf("Please enter the number of bytes you would like to remove: ");
	scanf("%d", &removeBytes);

	//open file to overwrite it
	wFile = fopen(fileName, "wb");
	if ((position + removeBytes) > count)
	{
		printf("Data past the end of the file");
		return -2;
	}
	else if((position+removeBytes)<count)
	{
		for (int i = 0; i < position - 1; i++)
		{
			fwrite(&str[i], sizeof(char), 1, wFile);
		}
			
		for (int i = position + removeBytes ; i < count; i++)
			fwrite(&str[i], sizeof(char), 1, wFile);
	}
	fclose(wFile);
	free(str);
}

