//#include "movieManagement.h"
#include <iostream>
#include <string>
#include "accManagement.h"
#include <conio.h>
#include "movieManagement.h"
#include "suatchieu.h"
#include "staffManager.h"
using namespace std;


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

void intro_manager()
{    
	system("cls");
	cout <<"\t\t\t"<<"|===========================|" << endl;
	cout <<"\t\t\t"<<"|     	MANAGEMENT          |"<< endl;
	cout <<"\t\t\t"<<"|  1. Movie Management      |" << endl;
	cout <<"\t\t\t"<<"|  2. Staff Managemnt       |" << endl;
	cout <<"\t\t\t"<<"|  3. Exit                  |" << endl;
	cout <<"\t\t\t"<<"|===========================|" << endl;
    cout<<"\t\t\tChoose: ";
     
}



void run()
{   
	 
	do
	{ 
	  bool check ,out_the_loop = false;// điều kiện thoát vòng lặp
	  intro();
	  accManagement acc;
	  acc.checkLogin(check);// check = true gọi đến quản lí , false gọi đến nhân viên đặt vé
      if(check == true)
	  { 
		
		while(out_the_loop == false)
		{
       		char tt; // lựa chọn 1 là quản lí phim, 2 là quản lí nhân viên
			intro_manager();

			tt = getche();
       		switch (tt)
			{
		   
				case '1':
				{
					movieManagement movie;
					movie.start();
					break;
				}

				case '2':
				{
					
				    staffManager staff;
					staff.start();
					break;
				}

				case '3':
				{   
					out_the_loop = true;
					break;
				}

				default: cout<<"\a";
			
			} 
		}
		
	  }

	  else
	  {
           // gọi đến hàm booking.start(); // đang phát triển


	  }

		
	} while (1);
	
}


int main()
{    
     
	run();
	// // // staff d;
	// // // cin>>d;

    // // // accManagement acc;
    // // // // acc.removeAccount(d);
	// // // acc.changePassword(d);
    // staffManager staff;
	
	// staff.start();
	
	return 0;
}





