

#include<iostream>
#include<cstring>
#include<algorithm>
#include<fstream>
#include<vector>
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

void genre(string * genrelist,int j,string movie_name)
{

    cout<<"the name:"<<movie_name<<endl;
    ifstream fin;
    fin.open("genre.txt");

    ofstream fout;
    fout.open("temp.txt");
    string l;
    int c;
    while(fin)
    {
        c=0;
        getline(fin,l);
        string str=l;
        if(l== "")
        {
            cout<<"i'm here!"<<endl;
            break;
        }

        char * genre = strtok((char*)str.c_str(),",");

        for(int i=0;i<j;i++)
        {   cout<<genrelist[i]<<endl;
            if(genrelist[i] == genre)
            {
                l=l+ movie_name +",";
              ///  cout<<"inside if"<<l<<endl;
                fout<<l<<endl;
                c=1;
            }
        }
        if(c==0)
            fout<<l<<endl;



    }

    fin.close();
    fout.close();

    remove("genre.txt");

    rename("temp.txt","genre.txt");





}


void create_new_database(Object *arr , int *count)
{ string genrelist[100];
    ofstream fout;
    ofstream fout1;
    ofstream fout2;
    string movie_name;
    fout2.open("Cast.txt",ios::app);
    fout1.open("Character.txt",ios::app);
	fout.open("My_data_base.txt",ios::app);
    int i= *count;
    cin.get();
    cout<<"Enter the movie name  :"<<endl;

    getline(cin,arr[i].oname);
    movie_name=arr[i].oname;
    fout<<arr[i].oname<<"|";
	cout<<"Enter the genre's of the movie separated by comma from (adventure,drama,thriller, comedy, action, romance, horror ,fiction ,mystery ,animation,Paranoid)"<<endl;
	string s;
	int j=0;

	getline(cin,s);

	fout<<s<<"|";
	///genre(genrelist,j,arr[i].oname);
	char *idk= strtok((char*)s.c_str(),",");
	genrelist[j++]= string(idk);


    while(idk)
    {
        idk= strtok(NULL,",");
        if(idk == NULL)
            break;
        genrelist[j++]=idk;

        }

    arr[i].genrecount=j;

    cout<<"Enter the Ratings on a scale of 10  :"<<endl;
    cin>>arr[i].rating;
    while(arr[i].rating >10)
    {
        cout<<"Please enter less than 10! "<<endl;
        cin>>arr[i].rating;
    }

    fout<<arr[i].rating<<"|";
    cout<<"Enter all the character name separated by a comma  :"<<endl;
    //cin.get();
    cin.get();
    getline(cin,arr[i].character.name);
    fout<<arr[i].character.name<<"|";
    char *nnew= strtok((char*)(arr[i].character.name).c_str(),",");
    fout1<<nnew<<","<<arr[i].oname<<","<<endl;
    while(nnew)
    {
        nnew= strtok(NULL,",");
        fout1<<nnew<<","<<arr[i].oname<<","<<endl;
    }
    cout<<"Enter all the character actor separated by a comma  :"<<endl;
    //cin.get();
    getline(cin,arr[i].character.actor);

    fout<<arr[i].character.actor<<"|";
    cout<<"Enter all the cast name separated by a comma  :"<<endl;
    getline(cin,arr[i].cast.name);
    char *nnew1= strtok((char*)(arr[i].cast.name).c_str(),",");
    fout2<<nnew1<<","<<arr[i].oname<<","<<endl;
    while(nnew1)
    {
        nnew1= strtok(NULL,",");
        fout2<<nnew1<<","<<arr[i].oname<<","<<endl;
    }
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
    genre(genrelist,j,movie_name);
    fout.close();
    fout1.close();
    fout2.close();

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

            int key;
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
            {   key=9;
                getline(fin,snew);
                if(snew=="")
                {
                   continue;
                }

                char * nnew = strtok((char*)snew.c_str(), "|");

                if(nnew == sname)
                {   cout<<data[9-key]<<nnew<<endl;
                    key--;
                    c=1;
                    while(key>0)
                    {
                        nnew= strtok(NULL, "|");
                        cout<<data[9-key]<<nnew<<endl;
                        key--;
                    }


                   continue;
                }


                    cout<<"-------------------------------------------"<<endl;
                }

            fin.close();

           if(c!=1)
            cout<<"The movie you're looking for is currently unavailable,check the spelling once!!"<<endl;

            cout<<"----------------------------------------------------------------------------------------------"<<endl;




        }
        if(choice == 4)
        {
        ifstream fin1;
        string movies[10000];
            int mov=0;
        fin1.open("Character.txt");
        string schar;
        string line1;
        cout<<"Enter the character name :";
        cin.get();
        getline(cin,schar);
        while(fin1)
       {
            getline(fin1,line1);
            if(line1=="")
                break;
            char * nnew= strtok((char*)line1.c_str(),",");

            if(nnew == schar)
            {
                   nnew= strtok(NULL,",");
                  // cout<<nnew<<endl;

                    movies[mov++] = string(nnew);
              }


            }
            sort(movies,movies+mov);
            if(mov==0)
            {
                cout<<"No movie available"<<endl;
            }
            else{
                 cout<<"The movies are :"<<endl;
            for(int mov1=0;mov1< mov; mov1++)
                cout<<movies[mov1]<<endl;
            }


        fin1.close();
             cout<<"---------------------------------------------------------------------------------------------------------------------"<<endl;
        }
        if(choice == 5)
        {
            ifstream fin1;
        string movies[10000];
            int mov=0;
        fin1.open("Cast.txt");
        string schar;
        string line1;
        cout<<"Enter the cast name :";
        cin.get();
        getline(cin,schar);
        while(fin1)
       {
            getline(fin1,line1);
            if(line1=="")
                break;
            char * nnew= strtok((char*)line1.c_str(),",");

            if(nnew == schar)
            {
                   nnew= strtok(NULL,",");
                  // cout<<nnew<<endl;

                    movies[mov++] = string(nnew);
              }


            }
            sort(movies,movies+mov);
            if(mov==0)
            {
                cout<<"No movie available"<<endl;
            }
            else{
                 cout<<"The movies are :"<<endl;
            for(int mov1=0;mov1< mov; mov1++)
                cout<<movies[mov1]<<endl;
            }


        fin1.close();
             cout<<"---------------------------------------------------------------------------------------------------------------------"<<endl;
        }
        if(choice==6)
        {
             ifstream fin;
             string movies[1000];
                    int mov=0;
             fin.open("genre.txt");
             string s,l;
             cout<<"enter the genre :"<<endl;
             cin>>s;
             while(fin)
             {
                 getline(fin,l);
                 char *genre = strtok((char*)l.c_str(),",");
                 if(s==genre){
                    while(genre != "")
                    {
                       genre = strtok(NULL,",");
                       if(genre == NULL)
                        break;
                       movies[mov++] = genre;
                    }
                    break;
                 }



             }
             if(mov == 0)
                cout<<"No movies found in this particular genre"<<endl;
             else{
                    sort(movies,movies + mov);
                for(int m=0;m<mov;m++)
                    cout<<movies[m]<<endl;
             }


             fin.close();
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
	cout<<"\nTo SEARCH all the Movies by character names: 4"<<endl;
	cout<<"\nTo SEARCH all the Movies by cast names: 5"<<endl;
	cout<<"\nTo SEARCH all the Movies by genre 6"<<endl;
	cout<<"\nTo DELETE an Item enter: 7"<<endl;
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
