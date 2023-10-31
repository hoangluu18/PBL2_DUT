#include "accManagement.h" 
#include "movieManagement.h"

void accManagement::checkLogin()
{   
    
    char tt;
    string choose;
    do
	{

    system("cls");   
	cout<<"\t\t\t" << " ===============================" << endl;
	cout<<"\t\t\t" << " |                             |" << endl;
	cout<<"\t\t\t" << " |         Login as            |" << endl;
	cout<<"\t\t\t" << " |         1) Manager          |" << endl;
	cout<<"\t\t\t" << " |         2) Staff            |" << endl;
	cout<<"\t\t\t" << " |         3) Exit             |" << endl;
	cout<<"\t\t\t" << " |                             |" << endl;
	cout<<"\t\t\t" << " ===============================" << endl;
    
	tt  = getche();
	movieManagement movie;
	switch (tt)
	{
		case '1':
		{   system("cls");
            string username, password;
			string choose = "loginManager.txt";
            this->setChoose(choose);
            this->ReadFile();
            cout<<"\t\t\t" << " ===============================" << endl;
			cout<<"\t\t\t" << "                              " << endl;
			cout<<"\t\t\t" << "         - Login -             " << endl;
			cout<<"\t\t\t" << "        Username: ", cin >> username;
			cout<<"\t\t\t" << "        Password: ", cin >> password;
			cout<<"\t\t\t" << "                              " << endl;
			cout<<"\t\t\t" << "                              " << endl;
			cout<<"\t\t\t" << " ===============================" << endl;
			while(this->search(username,password) == false)
			{   system("cls");
                cout<<"\t\t\tWrong username or password, retype"<<endl;
                cout<<"\t\t\t" << "        Username: ", cin >> username;
			    cout<<"\t\t\t" << "        Password: ", cin >> password;
                continue;
			}
			movie.startManager();
           return;
		}

		case '2':
		{   system("cls");
			string username, password;
			string choose = "loginStaff.txt";
            this->setChoose(choose);
            this->ReadFile();
            cout<<"\t\t\t" << " ===============================" << endl;
			cout<<"\t\t\t" << "                              " << endl;
			cout<<"\t\t\t" << "         - Login -             " << endl;
			cout<<"\t\t\t" << "        Username: ", cin >> username;
			cout<<"\t\t\t" << "        Password: ", cin >> password;
			cout<<"\t\t\t" << "                              " << endl;
			cout<<"\t\t\t" << "                              " << endl;
			cout<<"\t\t\t" << " ===============================" << endl;
			while(this->search(username,password) == false)
			{   system("cls");
                cout<<"\t\t\t!!! Wrong username or password, retype !!!"<<endl;
                cout<<"\t\t\t" << "        Username: ", cin >> username;
			    cout<<"t\t\t" <<  "        Password: ", cin >> password;
                continue;
			}
			movie.startStaff();
           return;
		}

        case '3':
        {
           return;
        }
        
        default: cout<<"\a";
	  
	}
    	
	} while (tt != '3');
   
}