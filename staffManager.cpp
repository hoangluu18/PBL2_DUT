#include "staffManager.h"

staffManager::staffManager()
{
   
}

staffManager::~staffManager()
{

}

void staffManager::addStaff(staff s)
{
    this->insert(s);
}

bool staffManager::removeStaff(string id)
{
   staff* s = this->search(id);
   if(s == NULL)
   {
     cout<<"\n Not found , check again: ";
     return false;
   }

   this->remove(*s);
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


void staffManager::printListStaff()
{
   node<staff>* temp = this->head;
    while(temp != NULL)
    {
        cout<<"Id: "<<temp->data.getId()<<endl;
        cout<<"Name: "<<temp->data.getName()<<endl;
        cout<<"Revenue: "<<temp->data.getRevenue()<<endl;

        temp = temp->next;
    }

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
                token.setRevenue(stoi(line));

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
           file<<temp->data.getId()<<";"<<temp->data.getName()<<";"<<temp->data.getRevenue()<<endl;
           temp = temp->next;
       }
   }
   file.close();
}
