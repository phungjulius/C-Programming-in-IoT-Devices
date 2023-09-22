#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#define LENGTH 256
#define HOUR 23
#define MIN 59

void wake_up_time(int c_hour, int c_min, int s_hour, int s_min, int* w_hour, int* w_min);
void read_number(const char* prompt, int* hour, int* min);
int main()
{
    int c_hour = 0, c_min = 0, s_hour = 0, s_min = 0, w_hour = 0, w_min = 0;
    do
    {
        read_number("Please enter current time (HH:MM) ", &c_hour, &c_min);
        if (c_hour <= HOUR && c_min <= MIN)
            break;
        printf("Please enter the correct 24 HOURS format as (HH:MM)!\n");
    } 
	while (1);
    do
    {
        read_number("How long do you want to sleep (HH:MM) ", &s_hour, &s_min);
        if (s_hour <= HOUR && s_min <= MIN)
            break;
        printf("Please enter the correct 24 HOURS format as (HH:MM)!\n");
    } 
	while (1);

    //Call function calculate wake up time
    wake_up_time(c_hour, c_min, s_hour, s_min, &w_hour, &w_min);
    printf("If you go to bed now you must wake up at %02d:%02d\n", w_hour, w_min);
}
// Function to calculate wake up time
void wake_up_time(int c_hour, int c_min, int s_hour, int s_min, int* w_hour, int* w_min)
{
    int min = c_min + s_min;
    int hour = c_hour + s_hour;
    if (min >= 60 && hour >= 24)
    {
        *w_min = min - 60;
        hour = hour - 24;
        hour++;
        *w_hour = hour;
    }
    else if (min >= 60 && hour < 24)
    {
        *w_min = min - 60;
        hour++;
        *w_hour = hour;
    }
    else if (min < 60 && hour >= 24)
    {
        hour = hour - 24;
        *w_hour = hour;
        *w_min = min;
    }
    else
    {
        *w_hour = hour;
        *w_min = min;
    }
}

//Function to read input hours and minutes in hh:mm format
void read_number(const char* prompt, int* hour, int* min)
{
    int h = 0, m = 0;
    char input[LENGTH];
    do
    {
        printf("%s", prompt);
        fgets(input, LENGTH, stdin);
        printf("Your input time %s", input);
        //Check if input is in correct format.If not, print error message and prompt user to input again until correct.
        if (input[2] == ':')
        {
            break;
        }
        else
        {
            printf("Please enter the correct format as (HH:MM)!\n");
        }
    } while (1);

    sscanf(input, "%d:%d", &h, &m);
    *hour = h;
    *min = m;
}
