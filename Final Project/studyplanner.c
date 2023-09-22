/*Author : Julius Phung*/
/*Final project for C Programming course*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 80
#define DATE 5
#define TIME 8
#define DATABASE "database.bin"
#pragma warning(disable:4996)

typedef struct Course Course;
struct Course
{
	char name[MAX];
	char room[MAX];
};

int readDate();
int readNumber(const char* prompt);
void readTime(int* begin, int* end);
int clearData(char* fileName, Course table[TIME][DATE]);
int addClass(char* fileName, Course table[TIME][DATE]);
int printTable(char* fileName, Course table[TIME][DATE]);
int removeClass(char* fileName, Course table[TIME][DATE]);

int main()
{
	Course timeTable[TIME][DATE] = { '\0' };

	int option = 0;
	char userInput[MAX] = { '\0' };

	printf("-----STUDY PLANNER-----\n");
	do
	{
		printf("1. Empty the database.\n2. Add class.\n3. Remove class.\n4. Print weekly schedule.\n5. Quit.\n");
		option = readNumber("Please select a number according to options above: ");
		printf("\n");
		switch (option)
		{
		case 1: //Empty database
			printf("OPTION 1 : CLEAN DATABASE\n");
			//Call clearDatabase function
			if (clearData(DATABASE, timeTable) != 0)
				//exit if error
				exit(1);
			break;
		case 2: //Add class
			printf("OPTION 2 : ADD CLASS\n");
			//Call addClass function
			if (addClass(DATABASE, timeTable) != 0)
				exit(1);
			break;
		case 3: //Remove class
			printf("OPTION 3 : REMOVE CLASS\n");
			//Call removeClass function
			if (removeClass(DATABASE, timeTable) != 0)
				exit(1);
			break;
		case 4: //Print timetable			
			printf("OPTION 4 : PRINT WEEKLY STUDY PLAN\n");
			if (printTable(DATABASE, timeTable) != 0)
				exit(1);
			printf("\n");
			break;
		case 5: //Quit
			printf("OPTION 5 : QUIT THE PROGRAMME\n");
			exit(0);
		default:
			printf("Please select a number range from 1-5 only!\n\n");
		}
	} while (1);
}

//Function to prompt user for number input
int readNumber(const char* prompt)
{
	int number = 0;
	char input[MAX] = { '\0' };
	do
	{
		printf("%s", prompt);
		fgets(input, MAX, stdin);
		if (sscanf(input, "%d", &number) == 1)
			break;
		else
			printf("Input accepts number only! Try again! \n");
	} while (1);
	return number;
}

//Function to read user's input of course's date
int readDate()
{
	int number = 0;
	char input[MAX] = { '\0' };
	printf("[MONDAY	TUESDAY	WESDNESDAY THURSDAY FRIDAY]\n");
	printf("[%d %6d %7d %10d %8d     ]\n", 0, 1, 2, 3, 4);
	number = readNumber("Enter a number corresponding to the date of the class: ");
	return number;
}

//Function to read user's input about course's starting and ending time
void readTime(int* num1, int* num2)
{
	int begin = 0, end = 0;
	char input[MAX] = { '\0' };

	printf("[09:00 10:00 11:00 12:00 13:00 14:00 15:00 16:00 17:00]\n");
	printf("[%d %5d %5d %5d %5d %5d %5d %5d %5d    ]\n", 0, 1, 2, 3, 4, 5, 6, 7, 8);
	printf("Enter a number corresponding to the time above.\n");

	begin = readNumber("Start time: ");
	*num1 = begin;

	end = readNumber("End time: ");
	*num2 = end;
}

//Function to add classes into schedule
int addClass(char* fileName, Course table[TIME][DATE])
{
	int number = 0, date = 0, begin = 0, end = 0;
	char name[MAX] = { '\0' };
	char room[MAX] = { '\0' };
	char input[MAX] = { '\0' };

	FILE* wFile = fopen(fileName, "wb");
	if (wFile == NULL)
	{
		printf("Error! Can not open file for saving data!\n ");
		return -1;
	}
	number = readNumber("How many course(s) that you wish to add? ");
	for (int i = 0; i < number; i++)
	{
		printf("Enter a class name: ");
		fgets(name, MAX, stdin);
		name[strcspn(name, "\n")] = '\0';
		printf("Enter classroom: ");
		fgets(room, MAX, stdin);
		room[strcspn(room, "\n")] = '\0';

		do
		{
			date = readDate();
			if (date >= 0 && date <= 4)
				break;
			printf("Please enter a number from range 0-4 only!\n\n");
		} while (1);

		do
		{
			readTime(&begin, &end);
			if ((begin >= 0 && begin <= 8) && (end >= 0 && end <= 8))
				break;
			printf("Please enter a number per input from range 0-8 only!\n\n");
		} while (1);

		//Assign course name and room name into 2D array's indexes according to user's input of date and time.
		for (int k = begin; k < end; k++)
		{
			strcpy(table[k][date].room, room);
			strcpy(table[k][date].name, name);
		}
		printf("\n");
	}

	fwrite(table, sizeof(Course), TIME * DATE, wFile);
	printf("\n");
	printf("Done saving input data into database file! Please check the timetable again by option 4. \n\n");
	fclose(wFile);
	return 0;
}

//Function to read database from binary file and store into 2D array and print database to compiler.
int printTable(char* fileName, Course table[TIME][DATE])
{
	FILE* oFile = fopen(fileName, "rb");
	if (oFile == NULL)
	{
		printf("Error! Unable to open the file to read database!\n");
		return -1;
	}

	while (!feof(oFile))
	{
		fread(table, TIME * DATE, sizeof(Course), oFile);
	}
	printf("TIME | DATE\t%-20s\t%-20s\t%-20s\t%-20s\t%-20s\n\n", "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY");
	int h = 9;
	for (int m = 0; m < 8; m++)
	{
		for (int n = 0; n < 5; n++)
		{
			if (n == 0)
			{
				printf("%02d:00\t\t", h);
				h++;
			}
			if (table[m][n].name != NULL)
			{
				printf("%-20s\t", table[m][n].name);
			}
		}
		printf("\n");
		for (int q = 0; q < 5; q++)
		{
			if (q == 0)
			{
				printf("                ");
			}
			if (table[m][q].room != NULL)
			{
				printf("%-20s\t", table[m][q].room);
			}
		}
		printf("\n");
	}
	fclose(oFile);
	return 0;
}

//Function to clean database
int clearData(char* fileName, Course table[TIME][DATE])
{
	FILE* f = fopen(fileName, "wb+");
	if (f == NULL)
	{
		printf("Error! Unable to open file to delete database!\n");
		return -1;
	}
	else
	{
		//Empty 2D array
		memset(table, '\0', TIME * DATE * sizeof(Course));
		fclose(f);
		printf("Database file is cleaned. Please check the timetable again by option 4.\n\n");
		return 0;
	}
}

//Function to let user to remove specific database
int removeClass(char* fileName, Course table[TIME][DATE])
{
	int number = 0, date = 0, begin = 0, end = 0;
	char input[MAX] = { '\0' };

	//Call printTable function
	if (printTable(fileName, table) != 0)
	{
		printf("Error! Unable to loading database from file!\n");
		return -1;
	}
	printf("\n");
	number = readNumber("How many course(s) that you wish you delete? ");
	for (int i = 0; i < number; i++)
	{
		do
		{
			date = readDate();
			if (date >= 0 && date <= 4)
				break;
			printf("Please enter a number from range 0-4 only! \n");
		} while (1);
		printf("\n");

		do
		{
			readTime(&begin, &end);
			if ((begin >= 0 && begin <= 8) && (end >= 0 && end <= 8))
				break;
			printf("Please enter a number per input from range 0-8 only! \n");
		} while (1);
		printf("\n");

		for (int k = begin; k < end; k++)
		{
			if (table[k][date].name != NULL && table[k][date].room != NULL)
			{
				*table[k][date].name = '\0';
				*table[k][date].room = '\0';
			}
			else if (table[k][date].name == NULL && table[k][date].room == NULL)
				printf("There is no database to delete in your selected time and date!\n");
		}
	}
	FILE* wF = fopen(fileName, "wb+");
	if (wF == NULL)
	{
		printf("Error! Unable to open file to save new data to file!\n");
		return -1;
	}
	fwrite(table, sizeof(Course), TIME * DATE, wF);
	fclose(wF);
	printf("Remove progress is done! Please check the timetable again by option 4.\n\n");
	return 0;
}



