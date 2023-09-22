#include <stdio.h>
#pragma warning(disable:4996)
#define MAX 100

float averageCalculate(int yourArray[], int arraySize);

int main() {

    int courseGrades[MAX] , sizeInput, timeInput = 1, gradeInput;
   
    //Check user's input if the number is out of bound of the array.
    do
    {
        printf("How many students are to be graded in the class? ");
        scanf("%d", &sizeInput);
        if (sizeInput < MAX)
            break;
        else
        printf("Number you have entered is out of bound. Please enter another smaller number! \n");
    } 
    while (sizeInput >= MAX);
    
    courseGrades[sizeInput]; 
    
    for (int i = 0; i < sizeInput; i++)
    {
        do
        {
            printf("Please enter a grade of student number 4500%d: ", i);
            scanf("%d", &gradeInput);
            if (gradeInput <= 5 && gradeInput >= 0)
            {
                printf("Saving grade of student number %d\n", i + 4500);
                courseGrades[i] = gradeInput;
            }
            else
            {
                printf("Please enter a grade from range 0-5 only!\n");
            }
        } while (gradeInput > 5 || gradeInput < 0);
    }
    printf("\nDone saving the student grades!\n\n");

    //Print out each student's grade
    for (int k = 0; k < sizeInput; k++)
        printf("The grade of student no %d is %d \n", +4500+k, courseGrades[k]);

    //Calculate the averageFunction 
    float average = averageCalculate(courseGrades, sizeInput);
    printf("\nThe average of the class is %.1f\n", average);
}
        
// Function to calculate the average value of the array.
float averageCalculate(int yourArray[], int arraySize)
{
    float sum = 0, average;
    for (int i = 0; i < arraySize; i++)
    {
        sum = sum + yourArray[i];
    }
    average = sum / arraySize;
    return average;
}