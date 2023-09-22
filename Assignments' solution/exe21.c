#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define NAMELENGTH 30
#pragma warning(disable:4996)

char* readFile(char* fileName);

int main()
{
	char fileName[NAMELENGTH]={'\0'};
	char* str;
	char c;
	int letterCounts[26] = { 0 };
	int wordCount = 0;
	size_t length = 0;
	double percent;
	
	//Prompt user to enter correc file name.
	do
	{
		printf("Please enter a text file's name following by \'.txt\': ");
		scanf("%s", fileName);
		if (strstr(fileName, ".txt") != NULL )
			break;
		else
			printf("Please enter a correct file format. For example: students.txt\n");
	} while (1);
	
	//Call function to read file data into array
	str = readFile(fileName);
	if (str == NULL)
	{
		printf("Error! Unable to read the file.\n");
		return -1;
	}
	
	length = strlen(str);

	//Counting first letter of every word in "str" array and assign them into "letterCounts" array 
	//The indexes of numbers in "letterCounts" array are corresponding to Alphabet order
	for (int i = 0; i < (length-1); i++)
	{
		if (i == 0 && str[i] != ' ')
		{
			c = tolower(str[i]);
			if (c >= 'a' && c <= 'z')
			{
				letterCounts[c - 'a']++;
				wordCount++;
			}
		}	
		if (i > 0 && str[i - 1] == ' ')
		{
			c = tolower(str[i]);
			if (c >= 'a' && c <= 'z')
			{
				letterCounts[c - 'a']++;
				wordCount++;
			}
		}
	}
	free(str);

	printf("There are %d words that have letter as the first character in this file\n\n", wordCount);

	//Print top 5 most frequent letters
	printf("Table of 5 letters that frequently as the first characters in file <%s>\n", fileName);
	printf("%-10s%-10s%-10s\n", "Letter", "Count", "Frequency");
	for (int i = 0; i < 5; i++)
	{
		int max = 0;
		for (int k = 0; k < 26; k++)
		{
			if (letterCounts[k] > letterCounts[max])
				max = k;
		}
		if (letterCounts[max] != 0)
		{
			percent = ((double)letterCounts[max] / wordCount * 100);
			printf("%-10c%-10d%-10.2f\n", 'a' + max, letterCounts[max], percent);
			letterCounts[max] = 0;
		}
		else
			break;
	}
}

//Function to read file and store file data to array
char* readFile(char* fileName)
{
	FILE* rFile;
	char c;
	int i = 0;

	//open the file in text mode
	rFile = fopen(fileName, "r");
	if (rFile == NULL)
	{	
		printf("Error! File does not exist or unable to open the file.");
		return NULL;
	}
	printf("-----Reading data from file %s-----\n", fileName);

	fseek(rFile, 0, SEEK_END);
	int size = ftell(rFile);
	fseek(rFile, 0, SEEK_SET);

	//Allocate dynamically memory to array to store file data
	char* str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
	{
		printf("Error in allocating dynamic memory.");
		return NULL;
	}
	while (!feof(rFile) && (c = fgetc(rFile)) != EOF)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	fclose(rFile);
	return str;
}

