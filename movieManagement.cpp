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
        cout<<"\nnot found , check again : ";
        return false;
    }
   
    this->remove(*m);
     return true;
    

}



bool movieManagement::editMovie(string id)
{  
    movie* m = this->search(id);
    if(m == NULL){
        cout<<"\nnot found check again : \n";
        return false;
    }
    
    this->edit(*m);
    return true;
}


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

void movieManagement::printListMovies()
{   
    node<movie>* current = this->head;
    int widthTable = this->size;
    int count = 0; 
    string table[widthTable][6];

    while(current != NULL)
    {   
       
        table[count][0] = current->data.getId();
        table[count][1] = current->data.getTitle();
        table[count][2] = current->data.getGenre();
        table[count][3] = to_string(current->data.getLenght());
        table[count][4] = current->data.getAge();
        table[count][5] = to_string(current->data.getYear());
        count++;
        current = current->next;
    }

    int width[6] = {0};
    // Duyệt qua mảng 2 chiều để tính độ rộng của mỗi cột
    for (int i = 0; i < widthTable; i++) {
        for (int j = 0; j < 6; j++) {
            if (table[i][j].length() > width[j]) {
                width[j] = table[i][j].length();
            }
        }
    }
      // In ra dòng ngăn cách trên cùng của khung
      cout << "\t\t\t+";
      for (int j = 0; j < 6; j++) {
      cout << setw(width[j] + 2) << setfill('-') << "-"; 
      cout << "+";
    }
    cout<<endl;
     // In ra tiêu đề của bảng
    cout << "\t\t\t|";
    cout << setw(width[0] + 2) << setfill(' ') << left << "MA" << "|";
    cout << setw(width[1] + 2) << setfill(' ') << left << "TEN PHIM" << "|";
    cout << setw(width[2] + 2) << setfill(' ') << left << "THE LOAI" << "|";
    cout << setw(width[3] + 2) << setfill(' ') << left << "DODAI" << "|";
    cout << setw(width[4] + 2) << setfill(' ') << left << "DO TUOI" << "|";
    cout << setw(width[5] + 2) << setfill(' ') << left << "NAM" << "|";
    cout << endl;

    // In ra nội dung của bảng
    for (int i = 0; i < widthTable; i++) {
        cout << "\t\t\t|";
        for (int j = 0; j < 6; j++) {
            cout << setw(width[j] + 2) << setfill(' ') << left << table[i][j] << "|";
        }
        cout << endl;
    }

  // In ra dòng ngăn cách dưới cùng của khung
    cout << "\t\t\t+";
    for (int j = 0; j < 6; j++) {
    cout << setw(width[j] + 2) << setfill('-') << "-"; 
    // In ra dấu "+"
    cout << "+";
    }
    cout << endl;


}


void movieManagement::start()
{   
    system("cls");
    this->readFile();
    char tt;
    
do{
     
    this->printListMovies();
    cout<<"\t\t\t1. add movie\n";
    cout<<"\t\t\t2. remove movie\n";
    cout<<"\t\t\t3. edit movie\n";
    cout<<"\t\t\t4. list movie\n";
    cout<<"\t\t\t5. exit\n";
    cout<<"\t\t\tchoose: ";
    
    tt = getche();
    

    switch(tt)
    {   
        case '1':
        { 
            movie new_movie;
            cout<<endl;
            cin>>new_movie;
            this->addMovie(new_movie);
            this->writeFile();
            break;
        }
        case '2':
        {   string id;
            cout<<"\nmovie id : ";
            cin>>id;
            while(this->removeMovie(id) != true)
            {    
                cin>>id;
                continue;
            }
            this->writeFile();
            break;
        }
        case '3':
        {
            string id;
            cout<<"\nmovie id : ";
            cin>>id;
            while(this->editMovie(id) != true)
            {
                cin>>id;
                continue;
            }
            this->writeFile();
            break;
        }
        case '4':
        {   cout<<"\n";
            system("cls");
            this->printListMovies();
            cout<<"\t\t\tpress any key to continue";
            getch();
            break;
        }
        case '5':
        {
           return;
        }
        default:cout<<"\a";
    }
 system("cls");
    
}
while(tt != 5);
}
