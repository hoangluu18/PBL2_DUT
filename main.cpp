//#include "movieManagement.h"
#include <iostream>
#include <string>
//#include "movie.h"
#include "accManagement.h"
#include <conio.h>
#include "movieManagement.h"
using namespace std;

bool check ;
void intro()
{
    system("cls");
    cout <<"\t\t\t"<< " ===============================" << endl;
	cout <<"\t\t\t"<< " |                             |" << endl;
	cout <<"\t\t\t"<< " |                             |" << endl;
	cout <<"\t\t\t"<< " |         Welcome to          |" << endl;
	cout <<"\t\t\t"<< " |           CINEMA            |" << endl;
	cout <<"\t\t\t"<< " |                             |" << endl;
	cout <<"\t\t\t"<< " |                             |" << endl;
	cout <<"\t\t\t"<< " ===============================" << endl;
    cout<<"\t\t\t"<<"Press any key to login..."<<endl;
	getch();
}

void choice()
{

}

void login()
{ 
    accManagement acc;
	acc.checkLogin();
}

void movieManager()
{
	movieManagement movie;
	movie.start();
}

void run()
{   
	intro();
	login();
	movieManager();
}
int main()
{    
   run();
   cout<<"\nhello";
}






