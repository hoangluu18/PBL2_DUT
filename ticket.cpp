#include "ticket.h"
#include <ctime>
#include <iomanip>

string getCurrentDateTime() {
    std::time_t now = std::time(0);
    std::tm *localTime = std::localtime(&now);

    std::ostringstream oss;
    oss << std::put_time(localTime, "%d/%m/%y %H:%M");
    return oss.str();
}

ticket::ticket(string id, string customer, string movie, string theatre, string seat, int price, string movietime, string staff){
    this->TicketId = id;
    this->CustomerName = customer;
    this->MovieName = movie;
    this->TheatreCode = theatre;
    this->Seat = seat;
    this->Price = price;
    this->BuyTime = getCurrentDateTime();
    this->MovieTime = movietime;
    this->NameStaff = staff;
}

void ticket::show(){
    cout << MovieName << endl;
    cout << "START: " << MovieTime << endl;
    cout << Price << "VND" << setw(5) << "SEAT: " << Seat << "THEATRE: " << TheatreCode << endl;
    cout << "CUSTOMER: " << CustomerName << endl;
    cout << "STAFF: " << NameStaff << endl;
    cout << BuyTime << endl;
    cout << TicketId << endl;
}



