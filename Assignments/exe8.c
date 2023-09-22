
#include <stdio.h>
#include <string.h>
#define MAX 256

void reverseCiphor(char* str, int size);
int main()
{
    char str[MAX];
    printf("This program is to reverse a giving string in reverse order\n");
    printf("Please input a string: ");
    fgets(str, MAX, stdin);
    printf("Your input string: %s", str);
    //Call function to reverse letters in user's input in reverse Alphabet order
    reverseCiphor(str, MAX);
    printf("First encryption : %s", str);
    //Call reverse function again, and this time should bring the input back to original
    reverseCiphor(str, MAX);
    printf("Second encyption/ Decryption: %s", str);
}

// Function to reverse letters in a string in reverse Alphabet order
void reverseCiphor(char* str, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = 'A' - str[i] + 'Z';
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = 'a' - str[i] + 'z';
        }
    }
}