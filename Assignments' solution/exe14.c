#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define LENGTH 50
#define BFILE "students.dat"

//define a Student type
typedef struct Student Student;
struct Student
{
    char name[LENGTH];
    int number;
    char address[LENGTH];
    char city[LENGTH];
    float credit;
};
int addStudent(Student* s);
void writeFile(FILE* f, Student* s, int count);
void printArray(FILE* f, Student* s);
int main()
{
    int count = 0;
    Student studentArray[100];
    char str[LENGTH];
    FILE* rFile;
    rFile = fopen(BFILE, "rb");
    FILE* wFile;
    wFile = fopen(BFILE, "ab");

    printf("Would you like to \'ADD\' more students OR to \'PRINT\' existing student information list?\n");
    do
    {
        printf("Enter \'ADD\' to add students OR \'PRINT\' to print existing student information: ");
        fgets(str, LENGTH, stdin);
        //Add more students
        if (strncmp(str, "ADD\n", 4) == 0)
        {
            //Call function to add students information into array
            //Add students to array
            count = addStudent(studentArray);
            //Check if the input are successful added into array
            printf("You have just input the following students information into an array:\n");
            for (int i = 0; i < count; i++)
            {
                printf("%s %d\n %s %s %.2f\n", studentArray[i].name, studentArray[i].number, studentArray[i].address, studentArray[i].city, studentArray[i].credit);
            }

            //Start writing into binary file
            writeFile(wFile, studentArray, count);
            
            fclose(wFile);
            break;
        }
        //Print existing students information 
        else if (strncmp(str, "PRINT\n", 6) == 0)
        {
            printArray(rFile,studentArray);
           
            fclose(rFile);
            break;
        }

    } while (1);
    return 0;
}
//Function to add student information. It returns total students added.
int addStudent(Student* s)
{
    char number[LENGTH];
    char credit[LENGTH];
    int i = 0;

    do
    {
        printf("Enter name OR \'stop\' to stop adding information: ");
        fgets(s[i].name, LENGTH, stdin);
        //Stop the program once user inputs 'stop'
        if (strncmp(s[i].name, "stop\n", 5) == 0)
        {
            printf("Finished adding student!\n");
            break;
        }
        else
        {
            printf("Enter student number: ");
            fgets(number, LENGTH, stdin);
            sscanf(number, "%d", &s[i].number);

            printf("Enter student's address: ");
            fgets(s[i].address, LENGTH, stdin);

            printf("Enter student's city: ");
            fgets(s[i].city, LENGTH, stdin);

            printf("Enter student's total credit: ");
            fgets(credit, LENGTH, stdin);
            sscanf(credit, "%f", &s[i].credit);

            i++;
        }

    } while (1);
    return i;
}
//Function to write student information into binary file
void writeFile(FILE* f, Student* s, int count)
{
    if (f == NULL)
    {
        printf("Unable to write into file. Exiting the program.");
    }
    else
    {
        fwrite(&s, sizeof(Student)*count, 1, f);
        printf("Successful writing to %s .", BFILE);
    }
}
//Function to print student information 
void printArray(FILE* f, Student* s)
{
    int i = 0;
    printf("Printing all students information:\n\n");
    if (f == NULL)
    {
        printf("Unable to open the file");
    }
    else
        while (!feof(f) && (fread(&s[i], sizeof(Student), 1, f) == 1))
        {
            printf("%s %d %s %s %.2f", s[i].name, s[i].number, s[i].address, s[i].city, s[i].credit);
            i++;
        }
}