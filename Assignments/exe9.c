#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
#define MAX 15

//define Student as a type name
typedef struct Student Student;
int studentInCity(Student* studentArray, char* city, int size);
struct Student
{
    char name[20];
    int number;
    char address[30];
    char city[20];
    float credit;
};

int main() {
    int studentCount = 0;
    char input[MAX];
    char city[MAX];
    Student studentArray[MAX] = {
        {"Andy",202201,"Happy Village no.2","HongKong",100.5},
        {"Matt",202203,"Happy City no.20","Tokyo",124.5},
        {"Kenny",202202,"Wall Street 12","L.A",122.5},
        {"Max",202211,"Wall Street 03","L.A",129.5},
        {"Mikael",202205,"Diamond road no.2","Seoul",120},
        {"Julius",202206,"Victoria Bay no.18","HongKong",125.5},
        {"Mike",202208,"High Mountain no.2","Zurich",101.5},
        {"Joe",202209,"Roman road no.9","Rome",125.5},
        {"Jasmine",202210,"Join Road no.5","Berlin",120.5},
        {"Kate",202204,"Happy World no.9","Tokyo",123.5},
        {"Jolie",202207,"Big Towel no.4","ShangHai",150.5},
        {" ",0," "," ",0}
    };
    do
    {
        printf("Enter city name / Enter \'stop\' or \'STOP\' to exit: ");
        fgets(city, MAX, stdin);
        sscanf(city, "%s", &input);
        if (strncmp(city, "stop\n", 5) == 0 || strncmp(city, "STOP\n", 5) == 0)
        {
            printf("Stopping the program!");
            break;
        }
        else
        {
            printf("City input is: %s", city);
            //Call function to print number of student and student informtion of a given city
            studentCount = studentInCity(studentArray, input, MAX);
            if (studentCount == 0)
            {
                printf("Number of students live in this city: %d\n", studentCount);
                printf("No student live in this city. Please enter another city.\n");
            }
            else
                printf("Number of students live in this city: %d\n", studentCount);

        }
    } 
    while (1);
}
// Function to print number of students and all student information of a given city
int studentInCity(Student* studentArray, char* city, int size)
{
    int count = 0;
    printf("| %-20s | %20s | %-20s | %-20s | %20s |\n", "Student name", "Student number", "Address", "City", "Total credits");
    for (int i = 0; i < size; i++)
    {
        if (strncmp(studentArray[i].city, city, size) == 0 && studentArray[i].number != 0)
        {
            printf("| %-20s | %20d | %-20s | %-20s | %20.2f |\n", studentArray[i].name, studentArray[i].number, studentArray[i].address, studentArray[i].city, studentArray[i].credit);
            count++;
        }
    }
    return count;
}


