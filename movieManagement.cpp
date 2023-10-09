#include "movieManagement.h"

movieManagement::movieManagement() 
{
    
}

movieManagement::~movieManagement() 
{
cout<<"huy movieManagement\n";

}



void movieManagement::addMovie(movie newMovie)
{    
    this->insert(newMovie);
}


void movieManagement::removeMovie(int id)
{    
    movie* m  = this->search(id);
    if(m == NULL){
        cout<<"not found\n";
    }
    else{
        this->remove(*m);
    }


}



void movieManagement::editMovie(int id)
{  
    movie* m = this->search(id);
    if(m == NULL){
        cout<<"not found\n";
    }
    else{
        this->edit(*m);
    }
}



// void movieManagement::printListMovies()
// {  
//     this->print();
// }

// đang phát triển
void movieManagement::printListMovies()
{
    cout<<setw(5)<<"id"<<setw(30)<<"title"<<setw(20)<<"genre"<<setw(10)<<"lenght"<<setw(10)<<"age"<<setw(10)<<"year"<<endl;
    //this->print();
    for(int i = 0; i < this->getSize(); i++)
    {
       // cout<<setw(5)<<this->get(i).getId()<<setw(30)<<this->get(i).getTitle()<<setw(20)<<this->get(i).getGenre()<<setw(10)<<this->get(i).getLenght()<<setw(10)<<this->get(i).getAge()<<setw(10)<<this->get(i).getYear()<<endl;
    }
}


//    int id;
//     string title;
//     string genre;
//     string summary = " ";
//     int lenght;
//     int year;

void movieManagement::readFile() // chưa có đọc summary phát triển sau
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

          token.setId(stoi(line.substr(0,pos)));

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

          token.setSummary("");

         this->addMovie(token);
       }
     
     }
        catch(const std::exception& e)
        {
            cout<<"error: "<<e.what()<<endl;
            cout<<"check again file\n";

        }
       
    }
    
    


} 


