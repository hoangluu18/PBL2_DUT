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
void display_select_login(){
	system("cls");
    cout << endl
         << endl;
    cout << "\t\t\t";
    for (int i = 0; i < 60; i++)
        cout << char(219);
    cout << endl
         << "\t\t\t" << char(219);
    cout << "                                                          ";
    cout << char(219);
    cout << endl
         << "\t\t\t" << char(219);
    cout << "\t\t  ";
    cout << "SELECT LOGIN PERMISSIOSN";
    cout << "\t\t   " << char(219) << endl;
    cout << "\t\t\t" << char(219);
    cout << "                                                          ";
    cout << char(219);
    cout << "\t\t\t" << char(219);
    cout << endl
         << "\t\t\t";
    for (int i = 0; i < 60; i++)
        cout << char(219);
    cout << endl
         << endl
         << "\t\t\t";
    for (int k = 0; k < 3; k++)
    {
        cout << char(218);
        for (int i = 0; i < 16; i++)
            cout << char(196);
        cout << char(191) << "   ";
    }
    cout << endl << "\t\t\t"; 
    cout << char(179) << " 1 " << char(179) << "   MANAGER  " << char(179);
    cout << "   " << char(179) << " 2 " << char(179) << "    STAFF   " << char(179);
    cout << "   " << char(179) << " 3 " << char(179) << "     EXIT   " << char(179);
    cout << endl << "\t\t\t";
    for(int k=0; k<3;k++){
        cout << char(192);
        for (int i = 0; i < 16; i++)
            cout << char(196);
        cout << char(217) << "   ";
    }
    cout << endl << endl << "\t\t\t";
    for(int i=0;i<60; i++) cout<< char(219);
}
//check login
void accManagement::checkLogin(bool& check, string& nameStaff)
{   
    
    char tt;
    string choose;
	bool checkExit = false ;// chuyển về trạng thái đăng nhập nếu không nhớ mk
    do
	{ 
	display_select_login();
    
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

			while(this->search(username,password) == false) //sk xử lí nếu nhập sai mk
			{   
				system("cls");
                cout<<"\t\t\tWrong username or password"<<endl;
				cout<<"\t\t\t1.Retype"<<endl;
				cout<<"\t\t\t2.Back menu"<<endl;
				cout<<"\t\t\tChoose: ";

				char choose;
				choose = getche();

				if(choose == '1')
				{
				system("cls");
                cout<<"\t\t\t" << "Username: ", cin >> username;
			    cout<<"\t\t\t" << "Password: ", cin >> password;
				}

				else if(choose == '2')
				{   
					checkExit = true;
					break;
				}
				
                continue; // nếu nhập char khác 1 và 2 thì tiếp tục vòng lặp
			}
			if(checkExit == true)// nếu muốn trở về menu chính
			{   
				checkExit = false; 
				break; //tiếp tục vòng lặp do while
			}
           return; //nhập đúng trả về main tiếp tục gọi hàm tiếp theo
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

			while(this->search(username,password) == false)//tương tự case 1
			{   
				system("cls");
                cout<<"\t\t\tWrong username or password"<<endl;
				cout<<"\t\t\t1.Retype"<<endl;
				cout<<"\t\t\t2.Back Menu"<<endl;
				cout<<"\t\t\tChoose: ";
				char choose;
				choose = getche();
				if(choose == '1')
				{
                cout<<"\t\t\t" << "Username: ", cin >> username;
			    cout<<"t\t\t" <<  "Password: ", cin >> password;
				}
				else if(choose == '2')
				{
					checkExit = true;
					break;
				}
                continue;
			}
			if(checkExit == true)
			{   
				checkExit = false;
				break;
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
	cout<<"\t\t\tPassword: ";
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




