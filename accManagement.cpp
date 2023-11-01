#include "accManagement.h" 
//get, set
void accManagement::setUserName(string username)
{
	this->userName = username;
}

string accManagement::getUserName()
{
	return this->userName;
}
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
                cout<<"\t\t\tWrong username or password, retype"<<endl;
                cout<<"\t\t\t" << "        Username: ", cin >> username;
			    cout<<"t\t\t" <<  "        Password: ", cin >> password;
                continue;
			}
			this->setUserName(username);// lấy tên nhân viên cho phần booking
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






// system("cls");
//     char tt;
//     string choose;
// 	accManagement acc;
// 	
	

    //  this->setChoose(choose);
    // this->ReadFile();
    // string username, password;
    // system("cls");
    
    //         cout << " ===============================" << endl;
	// 		cout << "                              " << endl;
	// 		cout << "         - Login -             " << endl;
	// 		cout << "        Username: ", cin >> username;
	// 		cout << "        Password: ", cin >> password;
	// 		cout << "                              " << endl;
	// 		cout << "                              " << endl;
	// 		cout << " ===============================" << endl;
    // if(this->search(username, password))
    // {   
    //     return true;
    // }
    // else
    // {    cout<<"Wrong username or password, retype"<<endl;
    //      cout<<"Press any key to continue"<<endl;
    //      getch();
    //     return false;
    // }