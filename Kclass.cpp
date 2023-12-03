#include "Kclass.h"

void intro()
{
    system("cls");
	cout << "\t\t" << char(218);
    for(int i=0; i<70; i++){
        cout << char(196);
    }
    cout << char(191) << endl;

    cout << "\t\t" << char(179) << " " ;
    cout << char(218);
    for(int i=0; i<66; i++){
        cout << char(196);
    }
    cout << char(191) << " " << char(179) << endl << "\t\t" << char(179) << " " << char(179) << "\t\t";
    cout << "DA NANG UNIVERSITY OF SCIENCE AND TECHNOLOGY";
    cout << "         " << char(179) << " " << char(179) << endl;
    cout << "\t\t" << char(179) << " " << char(179) << "\t\t     ";
    cout << "FACULTY OF INFORMATION TECHNOLOGY";
    cout << "               " << char(179) << " " << char(179) << endl;
    cout << "\t\t" << char(179) << " " << char(179);
    for(int i=0; i<33; i++) cout << "  ";
    cout << char(179) << " " << char(179) << endl;
    cout << "\t\t" << char(179) << " " << char(179) << "\t\t     ";
    cout << "  PBL2: DU AN CO SO LAP TRINH";
    cout << "                   " << char(179) << " " << char(179) << endl;

    cout << "\t\t" << char(179) << " " << char(179) << "\t\t ";
    cout << "DE TAI: Quan ly dat ve xem phim tai rap phim";
    cout << "        " << char(179) << " " << char(179) << endl;

    cout << "\t\t" << char(179) << " " << char(179);
    for(int i=0; i<33; i++) cout << "  ";
    cout << char(179) << " " << char(179) << endl;

    cout << "\t\t" << char(179) << " " << char(179) << "\t\t ";
    cout << "  Sinh vien thuc hien:  Do Long Nghia";
    cout << "               " << char(179) << " " << char(179) << endl;
    cout << "\t\t" << char(179) << " " << char(179) << "\t\t ";
    cout << "                        Luu Viet Hoang";
    cout << "              " << char(179) << " " << char(179) << endl;
    cout << "\t\t" << char(179) << " " << char(179) << "\t\t ";
    cout << "                        Tran Ngoc Minh Hoang";
    cout << "        " << char(179) << " " << char(179) << endl;
    cout << "\t\t" << char(179) << " " << char(179) << "\t\t ";
    cout << "            Lop:  22T_NHAT2         ";
    cout << "                " << char(179) << " " << char(179) << endl;

    cout << "\t\t" << char(179) <<  " " << char(192);
    for(int i=0; i<66; i++) cout << char(196);
    cout << char(217) << " " << char(179) << endl;
    cout << "\t\t" << char(192);
    for(int i=0; i<70; i++) cout << char(196);
    cout << char(217);
	getch();
}

void intro_manager()
{    
	system("cls");
	cout <<"\t\t\t"<<"|===========================|" << endl;
	cout <<"\t\t\t"<<"|     	MANAGEMENT          |"<< endl;
	cout <<"\t\t\t"<<"|  1. Movie Management      |" << endl;
	cout <<"\t\t\t"<<"|  2. Staff Managemnt       |" << endl;
	cout <<"\t\t\t"<<"|  3. Revenue Statistics    |" << endl;
	cout <<"\t\t\t"<<"|  4. Exit                  |" << endl;
	cout <<"\t\t\t"<<"|===========================|" << endl;
    cout<<"\t\t\tChoose: ";

}

void intro_staff()
{
	system("cls");
	cout <<"\t\t\t"<<"|===========================|" << endl;
	cout <<"\t\t\t"<<"|     	STAFF               |"<< endl;
	cout <<"\t\t\t"<<"|  1. Booking               |" << endl;
	cout <<"\t\t\t"<<"|  2. Exit                  |" << endl;
	cout <<"\t\t\t"<<"|===========================|" << endl;
	cout <<"\t\t\tChoose: ";

}

void run()
{   

	do
	{ 
	  bool check ,out_the_loop = false;// điều kiện thoát vòng lặp
	  string nameStaff = "";
	  intro();
	  accManagement acc;
	  acc.checkLogin(check, nameStaff);// check = true gọi đến quản lí , false gọi đến nhân viên đặt vé
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
					Revenue revenue;
					revenue.total_inDay();
					break;
				}
				case '4':
				{   
					out_the_loop = true;
					break;
				}

				default: cout<<"\a";

			} 
		}

	  }

	  else 
	{	while(out_the_loop == false)
		{
       		char tt; 
			intro_staff();

			tt = getche();
       		switch (tt)
			{

				case '1':
				{
					Booking booking;
					booking.Datve(nameStaff);
					break;
				}

				case '2':
				{   
					out_the_loop = true;
					break;
				}

				default: cout<<"\a";

			} 
		}

	  }


	} while (1);

}


