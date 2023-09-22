#include<stdio.h>
#include<string.h>
#define MAX 256
#pragma warning(disable:4996)

void replace(char* str, int size);
int main()
{
    char str[MAX];
    printf("This program converts whitespaces in a string into underscores!\n\n");
    do
    {
        printf("Enter a string: ");
        fgets(str, MAX, stdin);
        if (strncmp(str, "stop", 4) == 0 || strncmp(str, "STOP", 4) == 0)
        {
            break;
        }
        //Replace whitespaces in a string with underscores
        replace(str, MAX);
        printf("Result: %s\n", str);
    } 
	while (1);
    printf("Thank you for using this program!");
}

//Function to replace whitespaces of a string with underscore
void replace(char* str, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (str[i] == ' ')
        {
            str[i] = '_';
        }
    }
}