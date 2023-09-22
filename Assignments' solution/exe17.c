#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

//Program that takes file name and number as parameters. The first parameter should be string and second parameter should be integer.
int main(int argc, char* argv[])
{
	int maxByte = 0;
	FILE* rFile;
	FILE* wFile;
	char* buffer;
	int count = 0;
	char fileName[256];
	
	//Check if enough 2 arguments
	if (argc != 3)
	{
		printf("Two arguments required ! \n");
		return -1;
	}
	else if (argc == 3)
	{
		//Check if user input correct format
		if((strstr(argv[1], ".txt") == NULL) && (strstr(argv[1], ".dat") == NULL) && (strstr(argv[1], ".bin") == NULL) || (sscanf(argv[2], "%d", &maxByte) != 1) || maxByte<0)
		{
			printf("Please enter the correct format, starting by file name and following by a positive number.\n");
			printf("For example: filename.txt 3\n ");
			return -1;
		}
		else
		{			
			//Start doing something here
			printf("Start reading file \'%s\'\n", argv[1]);
			
			//Read file in binary mode
			rFile = fopen(argv[1], "rb");
			
			//Check size of input file
			fseek(rFile, 0, SEEK_END);
			int sizeFile = ftell(rFile);
			printf("Size of input file is: %d bytes\n", sizeFile);
			printf("Split file into multiple files with maximum %d bytes each file\n", maxByte);
			fseek(rFile, 0, SEEK_SET);

			//Check if input file is able to split from input bytes
			if (sizeFile < maxByte)
			{
				printf("Unable to split the file as input size is larger than file's size\n");
				return -1;
			}
			
			//Allocating memory for read file
			buffer = malloc(sizeof(char) * maxByte);

			//Prompt error message if can not open the file
			if (rFile == NULL)
			{
				printf("Error! Unable to open the file.");
				return -1;
			}				
			else
			{
				while (!feof(rFile))
				{
					sprintf(fileName, "%s.part%03d", argv[1], count+1);
					//Open a new file by new name
					wFile = fopen(fileName, "wb");
					if (wFile == NULL)
					{
						printf("Error in spliting file");
						return -1;
					}

					//Reading specific number of bytes from file
					int byteRead = fread(buffer, sizeof(char), maxByte, rFile);
					
					//Write into file from buffer
					fwrite(buffer, sizeof(char), byteRead, wFile);
					fclose(wFile);
					count++;					
				}					
			}
			//Close read file and free allocating memory
			fclose(rFile);
			free(buffer);
			printf("Done spliting %s file into %d files\n", argv[1], count);
		}
	}
	return 0;
}