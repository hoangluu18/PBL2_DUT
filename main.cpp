//#include "movieManagement.h"
#include <iostream>
#include <string>
//#include "movie.h"
#include "accManagement.h"
#include <conio.h>
#include "movieManagement.h"
#include "suatchieu.h"
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
    cout<<"\t\t\t"<<"\nPress any key to login..."<<endl;
	getch();
}

void choice(){}
void login()
{ 
    accManagement acc;
	acc.checkLogin();
}


void run()
{   
	intro();
	login();
	// Suatchieu::themsuatchieu();
	// Suatchieu::insuatchieucuaphim();
}
int main()
{    
   run();
   cout<<"\nPye Pye !!!";
}






