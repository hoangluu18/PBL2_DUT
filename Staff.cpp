#include "staff.h"

staff::staff()
{
    this->staffId = "";
    this->staffName = "";
    this->revenue = 0;

}

staff::~staff()
{

}

//get

string staff::getId()
{
    return this->staffId;
}

string staff::getName()
{
    return this->staffName;
}

long staff::getRevenue()
{
    return this->revenue;
}

//set
void staff::setId(string id)
{
    this->staffId = id;
}

void staff::setName(string name)
{
    this->staffName = name;
}

void staff::setRevenue(long revenue)
{
    this->revenue = revenue;
}

//operator
bool staff::operator==(const staff& s)
{
    return this->staffId == s.staffId;
}

ostream& operator<<(ostream& os, const staff& s)
{
    os << s.staffId << " " << s.staffName << " " << s.revenue << endl;
    return os;
}

istream& operator>>(istream& is, staff& s)
{
    cout<<"Staff Id: ";
    is>>s.staffId;
    cout<<"Staff Name: ";
    is.ignore();
    getline(is,s.staffName);
    

    return is;
}

const staff& staff::operator = (const staff &s)
{
    this->staffId = s.staffId;
    this->staffName = s.staffName;
    this->revenue = s.revenue;
    return *this;
}