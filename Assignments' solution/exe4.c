#include<stdio.h>
#include<string.h>
#define MAX 3
#pragma warning(disable:4996)

float dotProduct(float* vector1, float* vector2, int size);
void readVector(const char* prompt, float* vector, int size);
void printVector(const char* prompt, float* vector, int size);
int main()
{
	float vec1[MAX], vec2[MAX];
	//Read user elements input for vector 1 and 2
	readVector("Please input three elements of vector V1:\n", vec1, MAX);
	readVector("Please input three elements of vector V2:\n", vec2, MAX);

	//Print vector 1 and vector 2
	printVector("\nYou have inserted vector V1=", vec1, MAX);
	printVector("You have inserted vector V2=", vec2, MAX);

	//Compute the dot product of two vectors:
	float result = dotProduct(vec1, vec2, MAX);
	printf("Dot product of two vectors: %.2f\n", result);
}

//Function to compute the dot product of two vectors
float dotProduct(float* vector1, float* vector2, int size)
{
	float product = 0;
	for (int i = 0; i < size; i++)
	{
		product = product + vector1[i] * vector2[i];
	}
	return product;
}

//Function to read input elements
void readVector(const char* prompt, float* vector, int size)
{
	printf(prompt);
	for (int i = 0; i < size; i++)
	{
		printf("Insert element %d: ", i + 1);
		scanf("%f", &vector[i]);
	}
}

//Function to print vector
void printVector(const char* prompt, float* vector, int size)
{
	printf(prompt);
	int i = 0;
	if (i < size)
	{
		printf("(%.1f , %.1f , %.1f)\n", vector[i], vector[i + 1], vector[size - 1]);
	}
}