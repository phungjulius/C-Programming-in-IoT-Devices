#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#define LENGTH 30
#pragma warning(disable : 4996)

uint16_t crc16(const uint8_t* data_p, unsigned int length);

int main()
{
    FILE* fr;
    uint8_t* data = NULL;

    char fileName[LENGTH];
    do
    {
        printf("Please enter a binary's file following by\'.bin\' OR \'.dat\'. Enter \''stop\' to exit the progam: ");
        scanf("%s",&fileName);
        fr = fopen(fileName, "rb");
        if (strcmp(fileName, "stop") == 0 || strcmp(fileName, "STOP") == 0)
        {
            printf("Stop the program.");
            break;
        }
        else
        {
            if (fr == NULL)
            {
                printf("Error! Unable to open the file");
                return -1;
            }
            else
            {
                //Check size of the binary file
                fseek(fr, 0, SEEK_END);
                int size = ftell(fr);
                fseek(fr,0,SEEK_SET);
                printf("Size of the file : %1d\n", size);
                printf("Size of unit8_t : %d\n",sizeof(uint8_t));
                
                //Allocate memory for data in binary file
                data = malloc(size * sizeof(uint8_t));
                fread(data, sizeof(uint8_t), size, fr);
                
				//crc16(data, sizeof(data));              
                printf("Number of byte read : %d\n", size*(sizeof(uint8_t)));
                printf("16-bit CRC : %.4X\n\n", crc16(data, size));
                fclose(fr);
                free(data);
                
            }            
        }
    } while (1);
}

uint16_t crc16(const uint8_t* data_p, unsigned int length)
{
    uint8_t x;
    uint16_t crc = 0xFFFF;
    while (length--)
    {
        x = crc >> 8 ^ *data_p++;
        x ^= x >> 4;
        crc = (crc << 8) ^ ((uint16_t)(x << 12)) ^ ((uint16_t)(x << 5)) ^ ((uint16_t)x);
    }
    return crc;
}

