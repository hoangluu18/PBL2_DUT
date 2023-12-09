#pragma once
#include <iostream>
using namespace std;
class movie
{
   protected: 
    string id; // id
    string title; // tieu de
    string genre; // the loai
    int lenght; // thoi luong
    string age;// do tuoi
    int year;// nam san xuat

    public:
    movie();
    movie(string idMovie, string title, string genre,  int lenght, string age, int year);
    ~movie();
   
    //get
    string getId();
    string getTitle();
    string getGenre();
    int getLenght();
    string getAge();
    int getYear();
    

    //set
    void setId(string idMovie);
    void setTitle(string title);
    void setGenre(string genre);
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