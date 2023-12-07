#include "staffManager.h"

staffManager::staffManager()
{
   
}

staffManager::~staffManager()
{

}

void staffManager::addStaff(staff s)
{   
    this->insert(s);// insert vào list
    
}

bool staffManager::removeStaff(string id)
{
   staff* s = this->search(id);
   if(s == NULL)
   {
     cout<<"\n Not found , check again: ";
     return false;
   }
    staff temp = *s;
   this->remove(*s);
   accManagement acc;
   acc.removeAccount(temp);

   return true;
}

bool staffManager::changePassword(string id)
{
    staff* s = this->search(id);
    if(s == NULL)
    {
        cout<<"\n Not found , check again: ";
        return false;
    }
    
    accManagement acc;
    acc.changePassword(*s);

    return true;
}

bool staffManager::checkPrimarykey(string id)
{
    staff* s = this->search(id);
    if(s == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}


string staffManager::getStaffId(string nameStaff)
{
    this->readFile();
    node<staff>* temp = this->head;
    while(temp != NULL)
    {
        if(temp->data.getName() == nameStaff)
        {
            return temp->data.getId();
        }
        temp = temp->next;
    }
    return "";// không tìm thấy
}

string staffManager::getStaffName(string id)
{
    node<staff>* temp = this->head;
    while(temp != NULL)
    {
        if(temp->data.getId()== id)
        {
            return temp->data.getName();
        }
        temp = temp->next;
    }
    return "";// không tìm thấy
}


void staffManager::readFile()
{
    ifstream file;
    file.open("staff.txt");
    if(!file.is_open())
    {
        cout<<"can not open file, check again\n";
        system("pause");
    }
    else
    {
        string line;
        staff token;
        int pos;

        try
        {
            while(getline(file,line))
            {
                pos = line.find(';');
                token.setId(line.substr(0,pos));
                line.erase(0,pos+1);
                pos = line.find(';');
                token.setName(line.substr(0,pos));
                line.erase(0,pos+1);
                

                this->addStaff(token);

            }
        }
        catch(const std::exception& e)
        {
            cout<<"error: "<<e.what()<<endl;
            cout<<"check again file\n";
            system("pause");
        }
        
    }
    file.close();
}


void staffManager::writeFile()
{
   ofstream file;
   file.open("staff.txt");
   if(!file.is_open())
   {
       cout<<"can not open file, check again\n";
       system("pause");
   }
   else
   {
       node<staff>* temp = this->head;
       while(temp != NULL)
       {
           file<<temp->data.getId()<<";"<<temp->data.getName()<<";"<<endl;
           temp = temp->next;
       }
   }
   file.close();
}



//menu 

void staffManager::showStaff()
{   
    node<staff>* current = this->head;
    int widthTable = this->size;
    int count = 0; 
    string table[widthTable][3];

    while(current != NULL)
    {   
       
        table[count][0] = current->data.getId();
        table[count][1] = current->data.getName();
        
        count++;
        current = current->next;
    }

    int width[3] = {0};
    // Duyệt qua mảng 2 chiều để tính độ rộng của mỗi cột
    for (int i = 0; i < widthTable; i++) {
        for (int j = 0; j < 2; j++) {
            if (table[i][j].length() > width[j]) {
                width[j] = table[i][j].length();
            }
        }
    }
      // In ra dòng ngăn cách trên cùng của khung
      cout << "\t\t\t+";
      for (int j = 0; j < 2; j++) {
      cout << setw(width[j] + 2) << setfill('-') << "-"; 
      cout << "+";
    }
    cout<<endl;
     // In ra tiêu đề của bảng
    cout << "\t\t\t|";
    cout << setw(width[0] + 2) << setfill(' ') << left << "ID" << "|";
    cout << setw(width[1] + 2) << setfill(' ') << left << "TEN NHAN VIEN" << "|";
    cout << endl;

    // In ra nội dung của bảng
    for (int i = 0; i < widthTable; i++) {
        cout << "\t\t\t|";
        for (int j = 0; j < 2; j++) {
            cout << setw(width[j] + 2) << setfill(' ') << left << table[i][j] << "|";
        }
        cout << endl;
    }

  // In ra dòng ngăn cách dưới cùng của khung
    cout << "\t\t\t+";
    for (int j = 0; j < 2; j++) {
    cout << setw(width[j] + 2) << setfill('-') << "-"; 
    // In ra dấu "+"
    cout << "+";
    }
    cout << endl;


}



//start menu

void staffManager::start()
{   
    system("cls");
    
    this->readFile();
    char tt;
    
do{
     
    this->showStaff();
    cout << endl;

    cout << "\t\t\t";
    for (int j = 0; j <= 1; j++)
    {
        cout << char(218);
        for (int i = 0; i < 21; i++)
            cout << char(196);
        cout << char(191) << "     ";
    }
    cout << endl;
    cout << "\t\t\t";
    cout << char(179) << " 1 " << char(179) << "    ADD STAFF    " << char(179);
    cout << "     " << char(179) << " 2 " << char(179) << "   REMOVE STAFF  " << char(179) << endl;

    cout << "\t\t\t";
    for (int j = 0; j <= 1; j++)
    {
        cout << char(192);
        for (int i = 0; i < 21; i++)
            cout << char(196);
        cout << char(217) << "     ";
    }
    cout << endl;
    cout << "\t\t\t";
    for (int j = 0; j <= 1; j++)
    {
        cout << char(218);
        for (int i = 0; i < 21; i++)
            cout << char(196);
        cout << char(191) << "     ";
    }
    cout << endl;
    cout << "\t\t\t";
    cout << char(179) << " 3 " << char(179) << " CHANGE PASSWORD " << char(179);
    cout << "     " << char(179) << " 4 " << char(179) << "       BACK      " << char(179) << endl;

    cout << "\t\t\t";
    for (int j = 0; j <= 1; j++)
    {
        cout << char(192);
        for (int i = 0; i < 21; i++)
            cout << char(196);
        cout << char(217) << "     ";
    }
    cout << endl;
    
   
    tt = getche();
    

    switch(tt)
    {   
        case '1':
        { 
            staff s;
            cin>>s;
            this->addStaff(s);
            accManagement acc;
            acc.addAccount(s);// insert mật khẩu
            this->writeFile();
            break;
        }
        case '2':
        {   
            string id;
            cout<<"\n\t\t\tID need remove: ";
            cin>>id;
            while(this->removeStaff(id) != true)
            {   
                cout<<"\n\t\t\tID: ";
                cin>>id;
                continue;
            }
            this->writeFile();
            break;
        }
        case '3':
        {  
            string id;
            cout<<"\n\t\t\tID: ";
            cin>>id;
            while(this->changePassword(id) != true)
            {   
                cout<<"\t\t\tID: ";
                cin>>id;
                continue;
            }
            break;
        }
        case '4':
        {   
            return;
        }
        default:cout<<"\a";
    }
 system("cls");
    
}
while(tt != 4);
}


