#include "movie.h"

movie::movie()
{
    this->id = 0;
    this->title = "";
    this->genre = "";
    this->summary = "";
    this->lenght = 0;
    this->year = 0;
}

movie::~movie()
{

}

movie::movie(int idMovie, string title, string genre, string summary, int lenght, int year)
{
    this->id = idMovie;
    this->title = title;
    this->genre = genre;
    this->summary = summary;
    this->lenght = lenght;
    this->year = year;
}

bool movie::operator==(const movie &m)
{
    return this->id == m.id;
}

ostream& operator<<(ostream& os, const movie& m)
{
    os << m.id<< endl;
    os << m.title << endl;
    os << m.genre << endl;
    os << m.summary << endl;
    os << m.lenght << endl;
    os << m.year << endl;
    return os;
}

istream& operator>>(istream& is, movie& m)
{
    cout<<"idMovie: ";
    is>>m.id;
    cout<<"title: ";
    is>>m.title;
    cout<<"genre: ";
    is>>m.genre;
    cout<<"summary: ";
    is>>m.summary;
    cout<<"lenght: ";
    is>>m.lenght;
    cout<<"year: ";
    is>>m.year;

    return is;
}



