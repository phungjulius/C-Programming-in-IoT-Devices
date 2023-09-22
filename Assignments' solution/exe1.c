#include <stdio.h>
#pragma warning(disable:4996)

int main() {
    int inputCount;
    float userInput, total, average;
    inputCount = 0;
    total = 0;
    printf("This program calculates the average of your input numbers.\n");
    printf("Enter '0' to print out the average number.\n\n");
    do
    {
        printf("Please enter a number: ");
        scanf("%f", &userInput);

        if (userInput > 0)
        {
            inputCount++;
            total = total + userInput;
        }
        else if (userInput < 0)
        {
            printf("Please enter only a positive number!\n");
        }
        else if (userInput = 0)
        {
            break;
        }
    } while (userInput > 0 || userInput < 0);

    //Calculate average of input numbers and print out the result
    average = total / inputCount;
    printf("\nThe average of positive numbers you have entered: %.2f\n", average);
}