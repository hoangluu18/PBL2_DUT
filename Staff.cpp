#include "staff.h"

staff::staff()
{
    this->staffId = "";
    this->staffName = "";


}

staff::~staff()
{

}

staff::staff(string id, string name)
{
    this->staffId = id;
    this->staffName = name;
 
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



//set
void staff::setId(string id)
{
    this->staffId = id;
}

void staff::setName(string name)
{
    this->staffName = name;
}



//operator
bool staff::operator==(const staff& s)
{
    return this->staffId == s.staffId;
}

ostream& operator<<(ostream& os, const staff& s)
{
    os << s.staffId << " " << s.staffName << " "  << endl;
    return os;
}

istream& operator>>(istream& is, staff& s)
{
    cout<<"\nStaff Id: ";
    is>>s.staffId;
    cout<<"\nStaff Name: ";
    is.ignore();
    getline(is,s.staffName);
    

    return is;
}

const staff& staff::operator = (const staff &s)
{
    this->staffId = s.staffId;
    this->staffName = s.staffName;
 
    return *this;
}