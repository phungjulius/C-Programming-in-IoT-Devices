#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LINESIZE 100
#pragma warning(disable:4996)

// This program requires first argument should be a string <filename.txt> and second one should be number. For example filename.txt 3
int main(int argc, char* argv[])
{
	int number = 0;
	int lineCount = 0;
	char line[LINESIZE];
	FILE* rFile;

	//Check if number of arguments are two. If not print error message
	if (argc != 3)
	{
		printf("Two arguments required ! \n");
		return -1;
	}
	else if (argc == 3)
	{
		//Check if the arguments are in correct format. If not print guidance message
		if((strstr(argv[1], ".txt") == NULL) || (sscanf(argv[2], "%d", &number) != 1) || number<0)
		{
			printf("Please enter the correct format, starting by file name and following by a positive number.\n");
			printf("For example: filename.txt 3\n ");
			return -1;
		}
		else
		{
			printf("Start reading file \'%s\'\n",argv[1]);
			rFile = fopen(argv[1], "r");
			//Prompt error message if can not open the file
			if (rFile == NULL)
			{
				printf("Error! Unable to open the file.");
				return -1;
			}
			else
			{
				int count = 0;
				//Print the file content starting with the number in command line argument
				printf("Content from line number %d of file \'%s\':\n\n", number, argv[1]);
				while (!feof(rFile))
				{
					if (fgets(line, LINESIZE, rFile) != NULL)
					{
						count++;
						if (count >= number)
						{
							printf("%s", line);
						}
						
					}
				}
				printf("\n");
				//Prompt an error message if file does not have that many line as in command line argument.
				if (count < number)
				{
					printf("-----file <%s> does not have %d lines-----\n\n", argv[1], number);
				}
				//Close file
				fclose(rFile);
			}
		}			
	}
	return 0;
}
