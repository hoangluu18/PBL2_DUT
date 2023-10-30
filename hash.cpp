#include "hash.h"

Hash::Hash()
{   
    choose = "";
   for(int i = 0; i < capacity; i++)
   {
       for(int j = 0; j < capacity; j++) 
       {
           this->key[i][j] = false;
       }
   }
}

Hash::~Hash()
{
   
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
                this->key[index1][index2] = true;
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
          system("pause");
      }
}

int Hash::hashFunction(string value)
{
    int hash = 0;
    for(int i = 0; i < value.length(); i++)
    {
        hash += value[i];
    }
    return hash % capacity;
}

void Hash::insert(string name,string pass)
{    
      int hashName = 0;
      int hashPass = 0;

       hashName = hashFunction(name);
      hashPass = hashFunction(pass);
      this->key[hashName][hashPass] = true;
}

bool Hash::search(string name, string pass)
{ 
    int hashName = hashFunction(name);
    int hashPass = hashFunction(pass);
    if(this->key[hashName][hashPass] == true)
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
        for(int i = 0; i < capacity; i++)
        {
            for(int j = 0; j < capacity; j++)
            {
                if(this->key[i][j] == true)
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

    file.close();
}



