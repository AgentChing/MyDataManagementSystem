#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int menu();
FILE * openfile();
void addObject();
void initiate_Olist();
int countcommas(char*);


typedef struct Olist {
	struct Object *olist;
	int olist_count;
};

typedef struct Object
{

	char oname[70];
	char genre[10][15]; int genrecount;
	struct Character *character; int charcount;
	struct Cast *cast; int castcount;
	float rating;
	int year_of_realse;
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
	FILE *f;
	f = openfile();
	int choice;
	Object arr[1000];
	int count = 0;

	do
	{
		choice = menu(f);

	} while (choice != 0);
}



int menu(FILE *f)
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
	case 1: printf("ADD"); addObject(f); choice = 1; break;
	case 2: printf("Search"); choice = 2; break;
	case 3: printf("Delete"); choice = 3; break;
	case 0:printf("Terminate"); choice = 0; break;
	}
	fflush(stdin);
	return choice;

}



FILE * openfile()
{
	FILE *f; 	char name1[50], name2[50];
	f = fopen("C:\\Users\\HP\\Desktop\\animedatabase.txt", "r");
	if (NULL != f)
	{
		int size;
		fseek(f, 0, SEEK_END);
		size = ftell(f);
		if (0 == size)
		{
			printf("file is empty\n");
		}

		else
		{
			if (fscanf(f, "%s%*c%s\n", &name1, &name2) != EOF)
			{
				while (fscanf(f, "%s%*c%s\n", &name1, &name2) != EOF)
				{
					printf("\n%s", name1);
					printf("\n%s", name2);
				}
			}
		}
	}
	else
	{
		char fileyn;
		printf("\n\n## ERROR : FILE NOT FOUND \nCreate File? y/n  ");
	tag1:
		scanf("%c", &fileyn);
		if ((int)fileyn == (int)'y' || (int)fileyn == (int)'Y')
		{
			fclose(f);
			f = fopen("C:\\Users\\HP\\Desktop\\animedatabase.txt", "a");
			fclose(f);
			printf("\n--Add new Elements now?y/n  ");
		tag2:
			scanf("%c", &fileyn);
			if ((int)fileyn == (int)'y' || (int)fileyn == (int)'Y')
			{
				addObject(f);
			}
			else if ((int)fileyn == (int)'n' || (int)fileyn == (int)'N')
			{
				printf("\nFile not Created-----------------------");
			}
			else
			{
				printf("\nEnter Valid Input :(y/n) ");
				goto tag2;
			}
		}
		else if ((int)fileyn == (int)'n' || (int)fileyn == (int)'N')
		{
			printf("File Not Created");
		}
		else
		{
			printf("\nEnter Valid Input :(y/n) ");
			goto tag1;
		}
	}


	fclose(f);
	return f;

}

int countcommas(char *c)
{
	int i = 0, count = 0;
	while (c[i] != '\0')
	{
		if (c[i] == '|')
			count += 1;
		i += 1;
	}
	return count + 1;
}
void addObject(FILE *f)
{
	struct Object O;
	fflush(stdin);
	char genre[50], characters[500], cast[500], description[500];
	f = fopen("C:\\Users\\HP\\Desktop\\animedatabase.txt", "a");
	printf("\nAdd Item Contains:---------------------------------");
	printf("\n\n Enter Name                    :  ");
	gets(O.oname);
	fflush(stdin);
	printf("Enter year of release (ddmmyyyy)   :  ");
	scanf("%d", &O.year_of_realse);
	fflush(stdin);
	printf("Rating (out of 10)                 :  ");
	scanf("%f", &O.rating);
	fflush(stdin);
	printf("Enter Genres separated by '|'      :  ");
	scanf("%s", genre);
	fflush(stdin);
	O.genrecount = countcommas(genre);
	printf("Enter Characters separated by '|'  :  ");
	scanf("%s", characters);
	fflush(stdin);
	O.charcount = countcommas(characters);
	printf("Enter Cast separated by '|'        :  ");
	scanf("%s", cast);
	fflush(stdin);
	O.castcount = countcommas(cast);
	printf("Description                        :  ");
	gets(description);
	fprintf(f, "\n%s ,%d,%f,%d, %s ,%d, %s ,%d, %s , %s \n", O.oname, O.year_of_realse, O.rating, O.genrecount, genre, O.charcount, characters, O.castcount, cast, description);


	fclose(f);
}
