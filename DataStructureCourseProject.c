#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void checkfile(FILE *);
int menu(FILE *);
void additem(FILE *);
void readitems(FILE *,int);
int readmenu();
int searchmenu();
void searchitem(FILE*, int);


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

void printobject(struct Object O)
{
    printf("\n%s :-",O.name);printf("\n |");
    int day=O.releaseyear/1000000, month = (O.releaseyear%1000000)/10000, year = O.releaseyear%10000;
    printf("\n---Rating = %0.2f/10   | Year of Release = %d//%d//%d    | Episode Count = %d    | Status = ",O.rating,day,month,year,O.episodecount);
    switch(O.status)
    {
        case 1:{printf("To Watch");break;}
        case 2:{printf("Watched");break;}
        case 3:{printf("watching");break;}
    }
    printf("\n |");
    printf("\n--GENRE : ");
    for(int i=0;i<O.genrecount;i++)
        printf("%s, ",O.genre[i]);
    printf("\n |");
    printf("\n--CHARACTERS : ");
    for(int i=0;i<O.charcount;i++)
        printf("\n\tCharcter:    name : %s ::      actor : %s",O.characters[i],O.actors[i]);
        printf("\n");

}

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

void ungetstring(char str[],int mode)
{
    int a=strlen(str);
    switch(mode)
    {
        case 1:{
        for(int i=0;i<a;i++)
            {
                if(str[i]=='_')
                    str[i]=' ';
            }
        break;
    }
        case -1:{
        for(int i=0;i<a;i++)
            {
                if(str[i]==' ')
                    str[i]='_';
            }
        }
        break;
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
        case 2:{int z = searchmenu(); searchitem(f,z);break;}
        case 3:{printf("\nDELETE");break;}
        case 4:{int z = readmenu();readitems(f,z);break;}
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

void readitems(FILE *f,int mode)
{
    f = fopen("C:\\Users\\HP\\Desktop\\animedatabase.txt","r");
    struct Object O;
    printf("---------------------------------------------------------\n");
    int z=1;
    while(fscanf(f,"%s %d %d %d %f %d",O.name,&O.episodecount,&O.status,&O.releaseyear,&O.rating,&O.genrecount) != EOF)
    {
       for(int i=0;i<O.genrecount;i++)
        {
            fscanf(f,"%s",O.genre[i]);
        }
        fscanf(f,"%d",&O.charcount);
        for(int i=0;i<O.charcount;i++)
        {
            fscanf(f,"%s",O.characters[i]);
            fscanf(f,"%s",O.actors[i]);
        }
      switch(mode)
      {
          case 1:{
            printf("\n %d. %s",z,O.name);
            z+=1;break;
          }
          case 2:{
            printf("\n %d. %s\t\t%0.2f\t%d\t",z,O.name,O.rating,O.episodecount);
            switch(O.status)
            {
                case 1:{printf("To watch");break;}
                case 2:{printf("Watched");break;}
                case 3:{printf("Watching");break;}
            }
            z+=1;
            break;
          }
          case 3:{
              int year=O.releaseyear%10000,month=(O.releaseyear/10000)%100,day=O.releaseyear/1000000;
            printf("\n %d. %s\t\t\t\t%d|%d|%d\t%0.2f\t",z,O.name,day,month,year,O.rating);
            for(int i=0;i<O.genrecount;i++)
            {
                printf("%s, ",O.genre[i]);
            }
            z+=1;
            break;
          }
      }
    }

    printf("\n---------------------------------------------------------\n");
    fclose(f);
    }



int readmenu()
{
    int a;
    printf("\n----- 1. Only Titles\n----- 2.Titles,ratings,Episode count");
    printf(",Status\n----- 3.Title,release-year, rating, genre\n-------------------------------response: ");
    scanf("%d",&a);
    return a;
}

int searchmenu()
{
    int c;
    printf("\nSearch By : ");
    printf("\n--1. NAME");
    printf("\n--2. CHARACTER NAME");
    printf("\n--3. RATING");
    printf("\n--4. ACTOR NAME");
    printf("\n--5. GENRE");
    printf("\n--6. STATUS");
    printf("\n------------Your Response :_");
    scanf("%d",&c);
    return c;
}

void searchitem(FILE *f,int mode)
{
    f = fopen("C:\\Users\\HP\\Desktop\\animedatabase.txt","r");
    struct Object O;
    char str[50],c;
    int k;
    float rate;
    fflush(stdin);
    switch(mode)
    {
        case 1:{printf("\nEnter Name : ");
              getstring(str);break;}
        case 2:{printf("\nEnter Character Name : ");getstring(str);break;}
        case 3:{printf("\nEnter 'mode' Ratingvalue ( > 9 or = 8 or < 5 ) : ");
                scanf("%c %f",&c,&rate);break;}
        case 4:{printf("\nEnter Actor Name : ");getstring(str);break;}
        case 5:{printf("\nEnter Genre : ");getstring(str);break;}
        case 6:{printf("\nEnter status number-\n\t\t1. To Watch\n\t\t2. Watched\n\t\t3. Watching");
                printf("\n\t\t\tyour response:_");
                scanf("%d",&k);break;}
    }
    while(fscanf(f,"%s %d %d %d %f %d",O.name,&O.episodecount,&O.status,&O.releaseyear,&O.rating,&O.genrecount) != EOF)
    {
       for(int i=0;i<O.genrecount;i++)
        {
            fscanf(f,"%s",O.genre[i]);
        }
        fscanf(f,"%d",&O.charcount);
        for(int i=0;i<O.charcount;i++)
        {
            fscanf(f,"%s",O.characters[i]);
            fscanf(f,"%s",O.actors[i]);
        }
        int z=1;
      switch(mode)
      {
          case 1:{
            if(strcmp(O.name,str)==0)
                printobject(O);
                printf("\n");
            break;
          }
          case 2:{
            for(int i=0;i<O.charcount;i++)
            {
                if(strcmp(O.characters[i],str)==0)
                {printobject(O);
                printf("\n");
                break;}
            }
            break;
          }
          case 3:{
             tg3:
             if(c == '>')
             {
                 if(O.rating>rate)
                 {printobject(O);
                printf("\n");
                break;}
             }
             else if(c == '<')
             {
                 if(O.rating<rate)
                 {printobject(O);
                printf("\n");
                break;}

             }
             else if(c == '=')
             {
              if(O.rating==rate)
                 {printobject(O);
                printf("\n");
                break;}
             }
             else if(c == 'e')
             {
                 break;
             }
             else {
                printf("\nERROR: invalid input format\nvalid format :=\n");
                printf("\t\t > (your value)\n\t\t < (your value)\n\t\t = (your value)\n\t\t enter e to exit :  Your Response : ");
                scanf("%c %f",&c,&rate);
                goto tg3;fflush(stdin);
             }
          }
          case 4:{
              for(int i=0;i<O.charcount;i++)
            {
                if(strcmp(O.actors[i],str)==0)
                {printobject(O);
                printf("\n");
                break;}
            }
            break;
          }
          case 5:{
          if(strcmp(O.genre,str)==0)
                printobject(O);
                printf("\n");
            break;
          }
          case 6:{
          if(O.status==k)
                printobject(O);
                printf("\n");
            break;
          }

      }
      z+=1;
    }

    printf("\n---------------------------------------------------------\n");
    fclose(f);

}

