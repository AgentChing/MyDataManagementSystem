#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int menu();
FILE * openfile();
void addObject();
void initiate_Olist();
int countcommas(char*);

typedef struct Olist {
	struct Object *object;
	int olist_count;
}Olist;

typedef struct Object
{

	char oname[70];
	char genre[10][15]; int genrecount;
	/*struct Character*/char character[50][50]; int charcount;
	/*struct Cast*/char cast[50[50]; int castcount;
	float rating;
	int year_of_realse;
	char discription[200];
}Object;

/*typedef struct Character
{
	char name[30];
	char actor[30];

}Character;

typedef struct Cast {
	char name[30];
	char voiced[30];
}Cast;*/

void stringpejadoo(struct Olist * O,char* c, int type,int listnum)
{
    switch(type)
    {
    case 1:{
        int j=0,i=0k=0;
        while(c[i]!='\0')
        {
            if(c[i]=='|')
            {
                j+=1;
                k=0;
            }
            O.object[listnum].genre[j][k] = c[i];
            i+=1;
            j+=1;
        }
    break;
    }
    case 2:{
    int j=0,i=0k=0;
        while(c[i]!='\0')
        {
            if(c[i]=='|')
            {
                j+=1;
                k=0;
            }
            O.object[listnum].character[j][k] = c[i];
            i+=1;
            j+=1;
        }
    break;}
    case 3:int j=0,i=0k=0;
        while(c[i]!='\0')
        {
            if(c[i]=='|')
            {
                j+=1;
                k=0;
            }
            O.object[listnum].cast[j][k] = c[i];
            i+=1;
            j+=1;
        }
    break;
    }
}
struct Olist* readfile()
{
 FILE *f;
 f = fopen("C:\\Users\\HP\\Desktop\\animedatabase.txt", "r");
 struct Olist olist;
 char temp[1000];
 olist.olist_count=0;
 olist.object = (struct Object *) malloc(sizeof(struct Object)*1000);
     while(fgets(olist.object[olist.olist_count].oname,70*sizeof(char),f) != EOF)
        {
            fscanf(f,"%d%*c%f",&olist.object[olist.olist_count].year_of_realse,&olist.object[olist.olist_count].rating);
            fscanf(f,"%d%*c%s",&olist.object[olist.olist_count].genrecount,temp);
            stringpejadoo(olist,temp,1,olist.olist_count);
            fscanf(f,"%d%*c%s",&olist.object[olist.olist_count].charcount,temp);
            stringpejadoo(olist,temp,2,olist.olist_count);
            fscanf(f,"%d%*c%s",&olist.object[olist.olist_count].castcount,temp);
            stringpejadoo(olist,temp,3,olist.olist_count);
            fgets(olist.object[olist.olist_count].discription,200*sizeof(char),f);
            olist.olist_count+=1;
        }

return &olist;

}

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
	printf("\nTo SEE all Items enter : 4");
	printf("\nTo Exit : Enter  0\n");
	printf("\n|\n Your response : "); scanf("%d", &choice);
	switch (choice)
	{
	case 1: printf("ADD"); addObject(f); choice = 1; break;
	case 2: printf("Search"); choice = 2; break;
	case 3: printf("Delete"); choice = 3; break;
	case 4: {
            struct Olist *O;
            O = readfile();
            for(int i=0;i<2;i++)
            {
                printf("%s\n",O.object[i].oname);
            }
	}
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
    fprintf(f,"%d%*c%f", O.year_of_realse, O.rating);
    fprintf(f,"%d%*c%s", O.genrecount, genre);
    fprintf(f,"%d%*c%s",O.charcount, characters);


	fclose(f);
}











/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void checkfile(FILE *);
int menu(FILE *);
void additem(FILE *);



typedef struct Object
{
    char name[50];
    int episodecount;
    int status;
    int releaseyear;
    float rating;
    int genrecount;
    char genre[40][50];
    int charcount;
    char characters[20][30];
    char actors[20][30];

}Object;

void main()
{
    FILE *f;
    checkfile(f);
    int p;
    do{
        p = menu(f);
    }while(p!=0);
}

void getstring(char str[])
{
    fflush(stdin);
    gets(str);
    int a=strlen(str);
    for(int i=0;i<a;i++)
    {
        if(str[i]==' ')
            str[i]='_';
    }
}

void checkfile(FILE *f)
{
    if((f = fopen("C:\\Users\\HP\\Desktop\\animedatabase.txt","r")) == NULL)
    {
        printf("-ERROR : FILE NOT FOUND---------\nCreate new file?(y/n)");
        char b;
        t1:
        scanf("%c",&b);
        if(b =='Y'||b=='y')
        {
            f = fopen("C:\\Users\\HP\\Desktop\\animedatabase.txt","w");
            fclose(f);
            printf("-DATABASE CREATED...");
            return;
        }
        else if(b=='n'||b=='N')
        {
          printf("\n Terminating Program...");
          exit(1);
        }
        else
        {
            printf("\nEnter A Valid Input---");
            goto t1;
        }
    }
    else{
        printf("-DATABASE RETRIVED...");
        fclose(f);
        return;
    }
}

int menu(FILE *f)
{
    int choice;
    printf("\n---------------MENU-----------------");
	printf("\nTo ADD New Item enter:   1");
	printf("\nTo SEARCH an Item enter: 2");
	printf("\nTo DELETE an Item enter: 3");
	printf("\nTo SEE all Items enter : 4");
	printf("\nTo Exit : Enter  0\n");
	printf("\n|\n Your response : "); scanf("%d", &choice);
	switch(choice)
	{
	    case 0:break;
        case 1:{additem(f);break;}
        case 2:{printf("\nSEARCH");break;}
	}

	return choice;
}

void additem(FILE *f)
{
    f = fopen("C:\\Users\\HP\\Desktop\\animedatabase.txt","a");
    struct Object O;
    printf("\nEnter name                         :  ");
    getstring(O.name);
    printf("\nEnter Number Of Episodes           :  ");
    scanf("%d",&O.episodecount);
    printf("\nEnter Status                       :  ");
    printf("\n\t|1: watched\n\t|2: to watch\n\t|3: watching\n\t|---------------response: ");
    scanf("%d",&O.status);
    printf("\nEnter year of Release (ddmmyyyy)   :  ");
    scanf("%d",&O.releaseyear);
    printf("\nrating out of 10                     :  ");
    scanf("%f",&O.rating);
    O.genrecount =0,O.charcount =0;
    char addmore;
    printf("\nGENRE--");
    do{
        printf("\n|Enter Genre                              :  ");
        getstring(O.genre[O.genrecount]);
        O.genrecount+=1;
        printf("enter y to add more, anything else to stop :");
        scanf("%c",&addmore);
    }while(addmore == 'y'||addmore =='Y');
    printf("\nCHARACTERS--");
    do{
        printf("\nEnter Character Name           :  ");
        getstring(O.characters[O.charcount]);
        printf("\n--Enter Actor's Name       :  ");
        getstring(O.actors[O.charcount]);
        O.charcount+=1;
        printf("enter y to add more, anything else to stop :");
        scanf("%c",&addmore);
    }while(addmore == 'y'||addmore =='Y');

    fprintf(f,"\n%s %d %d %d %f %d ",O.name,O.episodecount,O.status,O.releaseyear,O.rating,O.genrecount);
    for(int i=0;i<O.genrecount;i++)
    {
        fprintf(f,"%s ",O.genre[i]);
    }
    fprintf(f,"%d ",O.charcount);
    for(int i=0;i<O.charcount;i++)
    {
        fprintf(f,"%s ",O.characters[i]);
        fprintf(f,"%s ",O.actors[i]);
    }
    fclose(f);
}

*/
