#include "hash.h"

Hash::Hash()
{   
    choose = "";
    hashValue[307][307] = {false};
}

Hash::~Hash()
{
    hashValue[307][307] = {false};
}
void Hash::setChoose(string name)
{
    this->choose = name;
}

string Hash::getChoose()
{
    return this->choose;
}

void Hash::ReadFile()
{
      ifstream file;
      file.open(getChoose());
      if(file.is_open())
      {
           string line;
           int pos;
         try{
           while(getline(file,line))
           {
               pos = line.find(';');
               int index1 = stoi(line.substr(0,pos));
                int index2 = stoi(line.substr(pos+1,line.length()));
                this->hashValue[index1][index2] = true;
               line.erase(0,line.length());

           }
         }
         catch(const exception& e)
        {
            cout<<"error: "<<e.what()<<endl;
            cout<<"check again file\n";

        }
      }

      else
      {
          cout<<"File not found check again"<<endl;
      }
}

int Hash::hashKey(string value)
{
    int hash = 0;
    for(int i = 0; i < value.length(); i++)
    {
        hash += value[i];
    }
    return hash % 307;
}

void Hash::insert(string name,string pass)
{    
      int hashName = 0;
      int hashPass = 0;

       hashName = hashKey(name);
      hashPass = hashKey(pass);
      this->hashValue[hashName][hashPass] = true;
}

bool Hash::search(string name, string pass)
{ 
    int hashName = hashKey(name);
    int hashPass = hashKey(pass);
    if(this->hashValue[hashName][hashPass] == true)
    {
        return true;
    }
    else
    {
        return false;
    }

}

void Hash::WriteFile()
{
    ofstream file;
    file.open(getChoose());
    if(file.is_open())
    {   
        for(int i = 0; i < 307; i++)
        {
            for(int j = 0; j < 307; j++)
            {
                if(this->hashValue[i][j] == true)
                {
                    file<<i<<";"<<j<<endl;
                }
            }
        }
    }
    else
    {
        cout<<"File not found check again"<<endl;
    }
}



