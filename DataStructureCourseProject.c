#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int menu();
void openfile();

typedef struct Object
{
	char oname[70];
	char genre[10][15]; int genrecount;
	struct Character *character; int charcount;
	struct Cast *cast; int castcount;
	int rating;
	char discription[200];
}Object;

typedef struct Character
{
	char name[30];
	char actor[30];

}Character;

typedef struct Cast {
	char name[30];
	char voiced[30];
}Cast;

void main()
{
	openfile();
	int choice;
	do
	{
		choice = menu();
	} while (choice != 0);
}



int menu()
{
	int choice;

	printf("\n---------------MENU-----------------");
	printf("\nTo ADD New Item enter:   1");
	printf("\nTo SEARCH an Item enter: 2");
	printf("\nTo DELETE an Item enter: 3");
	printf("\nTo Exit : Enter  0\n");
	printf("\n|\n Your response : "); scanf("%d", &choice);
	switch (choice)
	{
	case 1: printf("ADD"); choice = 1; break;
	case 2: printf("Search"); choice = 2; break;
	case 3: printf("Delete"); choice = 3; break;
	case 0:printf("Terminate"); choice = 0; break;
	}
	return choice;

}



void openfile()
{
	FILE *f;
	char name1[50], name2[50];
	f = fopen("C:\\Users\\HP\\Desktop\\animedatabase.txt", "r");
	while (fscanf(f, "%s%*c%s\n", &name1, &name2) != EOF) {
		printf("\n%s", name1);
		printf("\n%s", name2);
	}
	fclose(f);

}
