#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 256
#pragma warning(disable:4996)

void replace(char* str, int size);
int main()
{
    char str[MAX];
    printf("This program converts first letter of every word in a string to upper case!\n\n");
    do
    {
        printf("Enter a string: ");
        fgets(str, MAX, stdin);
        if (strncmp(str, "stop\n", 5) == 0 || strncmp(str, "STOP\n", 5) == 0)
        {
            break;
        }
        //Replace whitespaces in a string with underscores
        replace(str, MAX);
        printf("Result: %s\n", str);
    } 
	while (1);
    printf("Stopping the programme.");
}

//Function to replace whitespaces of a string with underscore
void replace(char* str, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (i == 0)
            str[i] = toupper(str[i]);
        if (str[i] == ' ')
            str[i + 1] = toupper(str[i + 1]);
    }
}