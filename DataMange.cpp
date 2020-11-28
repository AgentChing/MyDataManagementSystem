#include<iostream>
#include<cstring>
#include<algorithm>
#include<fstream>
using namespace std;
int menu();
typedef struct Character
{
	string name;
	string actor;

}Character;
typedef struct Cast {
	string name;
	string voiced;
}Cast;
typedef struct Object
{
	string oname;
	string genre[10]; int genrecount;
    Character character; int charcount;
	Cast cast; int castcount;
	int rating;
	int year_of_realse;
	string discription;
}Object;




void create_new_database(Object *arr , int *count)
{
    ofstream fout;
	fout.open("My_data_base.txt",ios::app);
    int i= *count;
    cout<<"Enter the movie name  :"<<endl;
    cin.get();
    getline(cin,arr[i].oname);
    fout<<arr[i].oname<<"|";
	cout<<"Enter the genre's of the movie  :"<<endl;
	string s;
	int j=0;
	getline(cin,s);
	fout<<s<<"|";
	char * s11= strtok((char*)s.c_str()," ");
	j++;
	while(s11)
    {
        s11=strtok(NULL," ");
        j+=1;
    }
     arr[i].genrecount=j;

    cout<<"Enter the Ratings on a scale of 10  :"<<endl;
    cin>>arr[i].rating;
    fout<<arr[i].rating<<"|";
    cout<<"Enter all the character name separated by a comma  :"<<endl;
    cin.get();
    cin.get();
    getline(cin,arr[i].character.name);
    cout<<"Enter all the character actor separated by a comma  :"<<endl;
    cin.get();
    getline(cin,arr[i].character.actor);

    fout<<arr[i].character.name<<"|"<<arr[i].character.actor<<"|";
    cout<<"Enter all the cast name separated by a comma  :"<<endl;
    getline(cin,arr[i].cast.name);
    cout<<"Enter all the cast voiced actor separated by a comma  :"<<endl;
    getline(cin,arr[i].cast.voiced);
    fout<<arr[i].cast.name<<"|"<<arr[i].cast.voiced<<"|";
    cout<<"Enter the year of release  :"<<endl;
    cin>>arr[i].year_of_realse;
    fout<<arr[i].year_of_realse<<"|";
    cout<<"Enter the description  :"<<endl;
    cin.get();
    getline(cin,arr[i].discription);
    fout<<arr[i].discription;
    fout<<endl;

    *count = ++i;
    fout.close();
};

int main()
{

	int choice;
	Object arr[1000];
	int c=0;

	do
	{
		choice = menu();
		if(choice == 1)
		{
		create_new_database(arr,&c);

		}
		if(choice == 2)
        {   ifstream fin;
            string movies[10000];
            int mov=0;
            fin.open("My_data_base.txt");
            string snew;
            while(fin)
            {
                getline(fin,snew);
                if(snew=="")
                    break;
                char * nnew = strtok((char*)snew.c_str(), "|");
                movies[mov++] = string(nnew);
                }
            sort(movies,movies+mov);
            for(int mov1=0;mov1< mov; mov1++)
                cout<<movies[mov1]<<endl;
            fin.close();
            cout<<"----------------------------------------------------------------------------------------------"<<endl;

        }
        if(choice == 3)
        {

            int key=9;
            string data[]={"Name of the movie: ","The genre's of the movie: ","Rating: ","All the character names: ","All the character actors: ","All the cast names: ","All the cast voiced: ","Release Date :","Description: "};
            string sname;
            cout<<"Enter the name of the movie you want to search for  :";
            cin.get();
            getline(cin,sname);
            //cout<<sname<<endl;
            ifstream fin;

            int c=0;
            fin.open("My_data_base.txt");
            string snew;
            while(fin)
            {
                getline(fin,snew);
                if(snew=="")
                {  c=1;
                   break;
                }

                char * nnew = strtok((char*)snew.c_str(), "|");

                if(nnew == sname)
                {   cout<<data[9-key]<<nnew<<endl;
                    key--;
                    while(key>0)
                    {
                        nnew= strtok(NULL, "|");
                        cout<<data[9-key]<<nnew<<endl;
                        key--;
                    }


                   break;
                }
                }

            fin.close();

           if(c==1)
            cout<<"The movie you're looking for is currently unavailable"<<endl;

            cout<<"----------------------------------------------------------------------------------------------"<<endl;




        }
	} while (choice != 0);
}



int menu()
{
	int choice;

	cout<<"\n---------------MENU-----------------"<<endl;
	 cout<<"\nTo ADD New Item enter:   1"<<endl;
	 cout<<"\nTo to view all the movies 2"<<endl;
	cout<<"\nTo SEARCH an Movie's info enter: 3"<<endl;
	cout<<"\nTo DELETE an Item enter: 4"<<endl;
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
