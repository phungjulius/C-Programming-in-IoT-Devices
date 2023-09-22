#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define PASSLENGTH 32
#define MAX 20
#pragma warning(disable:4996)

//Program generates password that containing random printable characters and reserved given word

void passGenerate(char* arr, int size, const char* word);

int main()
{
	char word[MAX]={'\0'};
	int number = 0;
	char* array;
	array = malloc(sizeof(char) * PASSLENGTH);
	if (array == NULL)
	{
		printf("Error in allocating dynamic memory.");
		return -1;
	}
	do
	{
		printf("Please enter a word: ");
		scanf("%s", word);

		//Program will stop once user enters stop
		if (strcmp(word, "stop") == 0)
		{
			printf("Stop program!");
			break;
		}
		size_t wordLeng = strlen(word);
		do
		{
			printf("Please enter a number range from %zu to 30: ", wordLeng + 2);
			scanf("%d", &number);
			if (number <= 30 && number >= wordLeng + 2)
				break;
		} while (1);
		
		//Call function to generate password
		passGenerate(array, number, word);

		//Print password
		printf("Password generated: ");
		for (int i = 0; i < number; i++)
		{
			printf("%c", array[i]);
		}
		printf("\n");
	} while (1);
	free(array);
}

//Function to generate password containing printable characters and a reserved given word in a random position
void passGenerate(char* arr, int size, const char* word)
{
	int ranValue = 0;
	int ranPosition = 0;
	for (int i = 0; i < size; i++)
	{
		//Create random printable characters for the password ranging from 33-126 in ASCII table
		ranValue = (rand() % 940) % 94 + 33;
		arr[i] = ranValue;
	}

	//Create enough random positions for given word so it is contained in password
	size_t r = size - strlen(word);
	ranPosition = rand() % r;

	//Copy a given word into password in reversed order.
	size_t n = strlen(word) - 1;
	for (int i = n; i >= 0; i--)
	{
		arr[ranPosition] = word[i];
		ranPosition++;
	}
}

