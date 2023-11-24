#include "ticket.h"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <algorithm>
string getCurrentDateTime()
{
    time_t now = time(0);
    tm *localTime = localtime(&now);

    ostringstream oss;
    oss << put_time(localTime, "%d/%m/%y %H:%M");
    return oss.str();
}

ticket::ticket(string id, string customer, string movie, string seat, string movietime, string staff, string s_id)
{
    this->TicketId = id;
    this->CustomerName = customer;
    this->MovieName = movie;
    this->Seat = seat;
    this->Price = 55000;
    this->BuyTime = getCurrentDateTime();
    this->MovieTime = movietime;
    this->NameStaff = staff;
    this->Staff_id = s_id;
}
ticket::~ticket()
{
}
void ticket::show()
{
    
    cout << "o" << std::string(38, '=') << "o" << endl;
    std::cout << "\t  TicketId:   "  << TicketId << endl;
    std::cout << "  Movie:\t"  << MovieName << endl;
    std::cout << "  START:\t"  << MovieTime << endl;
    std::cout << "  Price:\t"  << Price << "VND " << endl;
    std::cout << "  CUSTOMER:    "  << CustomerName << endl;
    std::cout << "  STAFF:       "  << NameStaff << " " <<endl;
    std::cout << "  BUYTIME:     "  << BuyTime  << endl;
    cout << "o" << std::string(38, '=') << "o";
}

string ticket::removeHyphens(string str)
{
    // Xóa tất cả các ký tự '-' khỏi chuỗi
    str.erase(std::remove(str.begin(), str.end(), '-'), str.end());
    return str;
}
string ticket::getId()
{
    return this->TicketId;
}

string ticket::getCustomerName()
{
    return this->CustomerName;
}

string ticket::getMovieName()
{
    return this->MovieName;
}

string ticket::getSeat()
{
    return this->Seat;
}

int ticket::getPrice()
{
    return this->Price;
}

string ticket::getBuyTime()
{
    return this->BuyTime;
}

string ticket::getMovieTime()
{
    return this->MovieTime;
}

string ticket::getNameStaff()
{
    return this->NameStaff;
}
string ticket::getStaff_id(){
    return this->Staff_id;
}
void ticket::setId(string id)
{
    this->TicketId = id;
}

void ticket::setCustomer(string customer)
{
    this->CustomerName = customer;
}

void ticket::setMovieName(string movie)
{
    this->MovieName = movie;
}
void ticket::setMovieTime(string time)
{
    this->MovieTime = time;
}
void ticket::setSeat(string seat)
{
    this->Seat = seat;
}
void ticket::setPrice(int price)
{
    this->Price = price;
}

void ticket::setBuyTime()
{
    this->BuyTime = getCurrentDateTime();
}

void ticket::setNameStaff(string staff)
{
    this->NameStaff = staff;
}

void ticket::SaveToFile()
{
    ofstream outFile("ticket.txt", ios::app);
    if (outFile.is_open())
    {
        outFile << TicketId;
        outFile << ";" << CustomerName;
        outFile << ";" << MovieName;
        outFile << ";" << Seat;
        outFile << ";" << Price;
        outFile << ";" << BuyTime;
        outFile << ";" << MovieTime;
        outFile << ";" << NameStaff;
        outFile << ";" << Staff_id << endl;
        outFile.close();
    }
}

bool ticket::operator==(const ticket &t)
{
    if (this->TicketId == t.TicketId)
        return true;
    else
        return false;
}

ostream &operator<<(ostream &o, const ticket &t)
{
    o << t.TicketId;
    o << ";" << t.CustomerName;
    o << ";" << t.MovieName;
    o << ";" << t.Seat;
    o << ";" << t.Price;
    o << ";" << t.BuyTime;
    o << ";" << t.MovieTime;
    o << ";" << t.NameStaff << endl;
    return o;
}

