#include "movieManagement.h"

movieManagement::movieManagement() 
{
    
}

movieManagement::~movieManagement() 
{

}



void movieManagement::addMovie(movie newMovie)
{    
    this->insert(newMovie);
}


bool movieManagement::removeMovie(string id)
{    
    movie* m  = this->search(id);
    if(m == NULL){
        cout<<"not found\n";
        return false;
    }
   
    this->remove(*m);
     return true;
    

}



bool movieManagement::editMovie(string id)
{  
    movie* m = this->search(id);
    if(m == NULL){
        cout<<"not found\n";
        return false;
    }
    
    this->edit(*m);
    return true;
}



void movieManagement::printListMovies()
{  
    this->print();
}

// // đang phát triển
// void movieManagement::printListMovies()
// {
//     cout<<setw(5)<<"id"<<setw(30)<<"title"<<setw(20)<<"genre"<<setw(10)<<"lenght"<<setw(10)<<"age"<<setw(10)<<"year"<<endl;
//     //this->print();
//     for(int i = 0; i < this->getSize(); i++)
//     {
//        // cout<<setw(5)<<this->get(i).getId()<<setw(30)<<this->get(i).getTitle()<<setw(20)<<this->get(i).getGenre()<<setw(10)<<this->get(i).getLenght()<<setw(10)<<this->get(i).getAge()<<setw(10)<<this->get(i).getYear()<<endl;
//     }
// }

void movieManagement::readFile() 
{
    ifstream file;

    file.open("Movie_information.txt");

    if(!file.is_open())
    {
        cout<<"can not open file, check again\n";
    }
    //id,title,genre,lenght,age,year
    else
    {
       string line;
       movie token;
       int pos;

     try{  
        while (getline(file,line))
       {
          pos = line.find(';');

          token.setId(line.substr(0,pos));

          line.erase(0,pos+1);

          pos = line.find(';');

          token.setTitle(line.substr(0,pos));

          line.erase(0,pos+1);
         
            pos = line.find(';');

            token.setGenre(line.substr(0,pos));

            line.erase(0,pos+1);

            pos = line.find(';');

            token.setLenght(stoi(line.substr(0,pos)));

            line.erase(0,pos+1);

            pos = line.find(';');

            token.setAge(line.substr(0,pos));
            
            line.erase(0,pos+1);
            
            token.setYear(stoi(line));
            
            this->addMovie(token);
       }
     
     }
        catch(const std::exception& e)
        {
            cout<<"error: "<<e.what()<<endl;
            cout<<"check again file\n";

        }
       
    }
    file.close();
} 


void movieManagement::writeFile()
{
   ofstream file;
   file.open("Movie_information.txt");
   if(!file.is_open())
   {
       cout<<"can not open file, check again\n";
   }
   else
   {
      node<movie>* current = this->head;
      while(current != NULL)
      {
        file<<current->data.getId()<<";"<<current->data.getTitle()<<";"<<current->data.getGenre()<<";"<<current->data.getLenght()<<";"<<current->data.getAge()<<";"<<current->data.getYear()<<endl;
        
        current = current->next;
      }
      

      file.close();
   
   }

}

