#include <iostream>
using namespace std;
class movie
{
   protected:
    int id;
    string title;
    string genre;
    string summary;
    int lenght;
    int year;

    public:
    movie();
    movie(int idMovie, string title, string genre, string summary, int lenght, int year);
    ~movie();
   
    //get, set
    int getId();
    

    //operator 
    bool operator==(const movie &m);
    friend ostream& operator<<(ostream& os, const movie& m);
    friend istream& operator>>(istream& is, movie& m);
    //other
   




};