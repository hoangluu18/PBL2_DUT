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

//check login
void accManagement::checkLogin(bool& check, string& nameStaff)
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
			check = true; // true == manager
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
			check = false; // false == staff
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
			nameStaff = username;
           return;
		}

        case '3':
        {   
			system("cls");
			cout<<"\n\n\n\t\t\t" << " ====================SEE YOU AGAIN====================" << endl;
           	exit(0);// điều kiện duy nhất kết thúc chương trình
        }
        
        default: cout<<"\a";
	  
	}
    	
	} while (tt != '3');
   
}

//add account

void accManagement::addAccount(staff new_staff)
{   
	string choose = "loginStaff.txt";
	this->setChoose(choose); // chọn file cần mở
	this->ReadFile();
	string password;
	cout<<"Password: ";
	cin>>password;
	this->insert(new_staff.getName(),password);
	this->WriteFile();

}

void accManagement::removeAccount(staff delStaff)
{
	string choose = "loginStaff.txt";
	this->setChoose(choose); // chọn file cần mở
	this->ReadFile();
	string password_current;
	cout<<"Password : ";
    cin>>password_current;
	while(this->search(delStaff.getName(),password_current) == false) // nhập mật khẩu hiện tại để xóa tài khoản
	{   
		cout<<"\t\t\tWrong password, retype"<<endl;
		cout<<"\t\t\t" << "        Password: ", cin >> password_current;
		continue;
	}
	this->removeKey(delStaff.getName(),password_current);
	this->WriteFile();

	
}

void accManagement::changePassword(staff s)
{
    string choose = "loginStaff.txt";
	this->setChoose(choose); // chọn file cần mở
	this->ReadFile();

	string password_current;
	cout<<"Current password: ";
	cin>>password_current;
	while(this->search(s.getName(),password_current) == false) // nhập mật khẩu hiện tại để xóa tài khoản
	{   
		cout<<"\t\t\tWrong password, retype"<<endl;
		cout<<"\t\t\t" << "        Password: ", cin >> password_current;
		continue;
	}

	this->removeKey(s.getName(),password_current);// xóa mật khẩu cũ

	string new_pass;
	cout<<"New password: ";
	cin>>new_pass;
	
	this->insert(s.getName(),new_pass);
	this->WriteFile();
}




