#include <iostream>
using namespace std;
class movie
{
   protected: //id,title,genre,lenght,age,year
    int id;
    string title;
    string genre;
    string summary; // phát triển thành file riêng 
    int lenght;
    string age;
    int year;

    public:
    movie();
    movie(int idMovie, string title, string genre, string summary, int lenght, string age, int year);
    ~movie();
   
    //get
    int getId();
    string getTitle();
    string getGenre();
    string getSummary();
    int getLenght();
    string getAge();
    int getYear();
    

    //set
    void setId(int idMovie);
    void setTitle(string title);
    void setGenre(string genre);
    void setSummary(string summary);
    void setLenght(int lenght);
    void setAge(string age);
    void setYear(int year);

    

    //operator 
    bool operator==(const movie &m);
    friend ostream& operator<<(ostream& os, const movie& m);
    friend istream& operator>>(istream& is, movie& m);
    const movie& operator = (const movie &m);
    
    //other
   




};