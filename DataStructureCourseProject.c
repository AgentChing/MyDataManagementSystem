#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void menu(int*);

void main()
{
	int *choice;
	do
	{
		menu(choice);
	} while (*choice != 0);

}

void menu(int *choice)
{
	int c;
	printf("\n---------------MENU-----------------");
	printf("\nTo ADD New Item enter:   1");
	printf("\nTo SEARCH an Item enter: 2");
	printf("\nTo DELETE an Item enter: 3");
	printf("\nTo Exit : Enter  0\n");
	printf("\n|\n Your responce : "); scanf("%d",&c);
	switch (c)
	{
	case 1: printf("ADD"); *choice = 1; break;
	case 2: printf("Search"); *choice = 2; break;
	case 3: printf("Delete");*choice = 3; break;
	case 0:printf("Terminate"); *choice = 0; break;
	}
	return;
}