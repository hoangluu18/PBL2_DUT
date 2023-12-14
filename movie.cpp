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

// operator

bool movie::operator==(const movie &m)
{
    return this->id == m.id;
}

ostream &operator<<(ostream &os, const movie &m)
{
    os << "idMovie: " << m.id << " title: " << m.title << " genre: " << m.genre << " lenght: " << m.lenght << " age: " << m.age << " year: " << m.year << "\n";
    return os;
}

istream &operator>>(istream &is, movie &m)
{
    cout << "MOVIE ID: ";
    is >> m.id;

    is.ignore();

    cout << "TITLE: ";
    getline(is, m.title);

    cout << "GENRE: ";
    is >> m.genre;

    while (true)
    {
        cout << "LENGTH: ";
        string input;
        cin >> input;

        istringstream stream(input);
        if (stream >> m.lenght && stream.eof())
        {
            m.lenght = stoi(input);
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer.\n";
        }
    }

    cout << "AGE: ";
    is >> m.age;

    while (true)
    {
        cout << "YEAR: ";
        string input;
        cin >> input;

        istringstream stream(input);
        if (stream >> m.year && stream.eof())
        {

            break;
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer.\n";
        }
    }

    return is;
}

const movie &movie::operator=(const movie &m)
{
    this->id = m.id;
    this->title = m.title;
    this->genre = m.genre;
    this->lenght = m.lenght;
    this->age = m.age;
    this->year = m.year;
    return *this;
}

// get
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

// set
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
