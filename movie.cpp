#include "movie.h"

movie::movie()
{
    this->id = "";
    this->title = "";
    this->genre = "";
    this->lenght = 0;
    this->age = "";
    this->year = 0;
}

movie::~movie()
{

}

movie::movie(string idMovie, string title, string genre, int lenght, string age, int year)
{
    this->id = idMovie;
    this->title = title;
    this->genre = genre;
    this->lenght = lenght;
    this->age = age;
    this->year = year;
}

//operator

bool movie::operator==(const movie &m)
{
    return this->id == m.id;
}

ostream& operator<<(ostream& os, const movie& m)
{
    os<<"idMovie: "<<m.id<<" title: "<<m.title<<" genre: "<<m.genre<<" lenght: "<<m.lenght<<" age: "<<m.age<<" year: "<<m.year<<"\n";
    return os;
}

istream& operator>>(istream& is, movie& m)
{
    cout<<"idMovie: ";
    is>>m.id;
    is.ignore();

    cout<<"title: ";
    getline(is,m.title);

    cout<<"genre: ";
    is>>m.genre;

    cout<<"lenght: ";
    is>>m.lenght;

    cout<<"Age: ";
    is>>m.age;

    cout<<"year: ";
    is>>m.year;

    return is;
}

const movie& movie::operator = (const movie &m)
{
    this->id = m.id;
    this->title = m.title;
    this->genre = m.genre;
    this->lenght = m.lenght;
    this->age = m.age;
    this->year = m.year;
    return *this;
}


//get
string movie::getId()
{
    return this->id;
}

string movie::getTitle()
{
    return this->title;
}

string movie::getGenre()
{
    return this->genre;
}


int movie::getLenght()
{
    return this->lenght;
}

string movie::getAge()
{
    return this->age;
}

int movie::getYear()
{
    return this->year;
}



//set
void movie::setId(string idMovie)
{
    this->id = idMovie;
}
void movie::setTitle(string title)
{
    this->title = title;
}
void movie::setGenre(string genre)
{
    this->genre = genre;
}
void movie::setLenght(int lenght)
{
    this->lenght = lenght;
}
void movie::setAge(string age)
{
    this->age = age;
}
void movie::setYear(int year)
{
    this->year = year;
}



