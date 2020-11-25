
#include<iostream>
#include<cstring>

using namespace std;
int menu();
typedef struct Object
{
	char oname[70];
	string genre[10]; int genrecount;
	struct Character *character; int charcount;
	struct Cast *cast; int castcount;
	int rating;
	int year_of_realse;
	string discription;
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
void create_new_database(Object *arr , int *count)

{
    int i= *count;
    cout<<"Enter the movie name:"<<endl;
    cin>>arr[i].oname;
	cout<<"Enter the genre of the movie and enter 0 once finished!"<<endl;
	string s="1";
	int j=0;
	while(s !="0")
    {

        cin>>s;
        if(s=="0")
            break;
        arr[i].genre[j++]=s;
        j++;

    }
    arr[i].genrecount=j;

    cout<<"Enter the Ratings on a scale of 10"<<endl;
    cin>>arr[i].rating;
    cout<<"Enter the year of release"<<endl;
    cin>>arr[i].year_of_realse;
    cout<<"Enter the description"<<endl;
    cin>>arr[i].discription;


    *count = ++i;

};

int main()
{
	//openfile();
	int choice;
	Object arr[1000];
	int c=0;

	do
	{
		choice = menu();
		if(choice == 1)
		{
		create_new_database(arr,&c);
    cout<<c<<endl;
		}
	} while (choice != 0);
}



int menu()
{
	int choice;

	cout<<"\n---------------MENU-----------------"<<endl;
	 cout<<"\nTo ADD New Item enter:   1"<<endl;
	cout<<"\nTo SEARCH an Item enter: 2"<<endl;
	cout<<"\nTo DELETE an Item enter: 3"<<endl;
	 cout<<"\nTo Exit : Enter  0\n"<<endl;
	cout<<"\n|\n Your response : "<<endl;
	cin>>choice;
	switch (choice)
	{
	case 1:  choice = 1; break; ///cout<<"ADD";
	case 2:  choice = 2; break;///cout<<"Search";
	case 3:  choice = 3; break;///cout<<"Delete";
	case 0:  choice = 0; break;///cout<<"Terminate";
	}
	return choice;

}



// void openfile()
// {
// 	FILE *f;
// 	char name1[50], name2[50];
// 	f = fopen("C:\\Users\\HP\\Desktop\\animedatabase.txt", "r");
// 	while (fscanf(f, "%s%*c%s\n", &name1, &name2) != EOF) {
// 		printf("\n%s", name1);
// 		printf("\n%s", name2);
// 	}
// 	fclose(f);

// }
