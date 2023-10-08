#include "movieManagement.h"

movieManagement::movieManagement()
{
    this->list_movies = list<movie>();
}

movieManagement::~movieManagement()
{
    

}

void movieManagement::addMovie(movie newMovie)
{    
    this->list_movies.insert(newMovie);
  

}


bool movieManagement::removeMovie(int id)
{    
    movie m (id,"","","",0,0);
    int count = this->getSize();
   this->remove(m);
   if(this->getSize() != count ){
    return true;
   }

   return false;
    
    
   
}



void movieManagement::editMovie(int id)
{  
     movie m (id,"","","",0,0);// tạo movie tạm thời trùng id với movie cần tìm
    if(this->search(m) == nullptr){
        cout<<"not found\n";
    }
    else{
        this->edit(m);
    }
}



void movieManagement::printListMovies()
{
    this->list_movies.print();
}








