#include <stdio.h>
#pragma warning(disable:4996)

int main() {

    float monthlySalaries[12];
    float total = 0;

    printf("This program is calculating your total annual salary.\n");
    printf("Please enter your monthly salary accodrdingly.\n\n");

    for (int i = 0; i < 12; i++)
    {
        printf("Enter salary of month [%2u] = ", i + 1);
        scanf("%f", &monthlySalaries[i]);
        total = total + monthlySalaries[i];
    }

    printf("\nReport of your monthly salaries and annual income:\n\n");

    for (int i = 0; i < 12; i++)
    {
        printf("Your salary of month [%2u] = %10.2f \n", i + 1, monthlySalaries[i]);
    }
    printf("Total %21c %10.2f\n", '=', total);
}