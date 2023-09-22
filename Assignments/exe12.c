#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#define MAX 20
#define PRICELIST "pricelist.txt"

//define Item as a type name
typedef struct Item Item;
struct Item
{
	char name[50];
	float price;
};

int main()
{
	float price;
	int count = 0;
	char priceInput[50];
	Item itemArray[MAX];
	FILE* priceList;
	
	//Check if able to access the file
	priceList = fopen(PRICELIST, "w");
	if (priceList == NULL)
	{
		printf("Unable to open %s\n", PRICELIST);
		return 1;
	}
	//Program will stop asking user's input once user enters 'stop' or 'STOP' OR max of array is reached
	printf("Please enter information of items.\n");
	for (int i = 0; i < MAX; i++)
	{
		//Prompt user for item
		printf("Enter name of item. [Input \'stop\' OR \'STOP\' to stop]: ");
		fgets(itemArray[i].name, 50, stdin);
		if (strncmp(itemArray[i].name, "stop\n", 5) == 0 || strncmp(itemArray[i].name, "STOP\n", 5) == 0)
		{
			break;
		}
		printf("Added item: %s", itemArray[i].name);

		//Prompt user for item's price
		printf("Enter price of item: ");
		fgets(priceInput, 50, stdin);
		sscanf(priceInput, "%f", &itemArray[i].price);
		printf("Added price: %.2f\n\n", itemArray[i].price);
		count++;
	}
	printf("Done adding items and prices into array!\n");
	printf("Total %d items are added into %s.\n", count, PRICELIST);

	//Write content of the array to the file
	fprintf(priceList, "List of items and prices.\n");
	for (int i = 0; i < count; i++)
	{
		fprintf(priceList, "%.2f ; %s", itemArray[i].price, itemArray[i].name);
	}
	printf("Done adding items and prices into %s\n", PRICELIST);
	return 0;
	fclose(priceList);
}

