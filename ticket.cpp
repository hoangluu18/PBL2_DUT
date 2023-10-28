#include "ticket.h"
#include <ctime>
#include <iomanip>
#include <fstream>
#include <string>
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
ticket::~ticket(){

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



string ticket::getTicketId(){
    return this->TicketId;
}


string ticket::getCustomerName(){
    return this->CustomerName;
}

string ticket::getMovieName(){
    return this->MovieName;
}

string ticket::getTheatreCode() {
    return this->TheatreCode;
}

string ticket::getSeat(){
    return this->Seat;
}

int ticket::getPrice(){
    return this->Price;
}

string ticket::getBuyTime(){
    return this->BuyTime;
}

string ticket::getMovieTime(){
    return this->MovieTime;
}

string ticket::getNameStaff(){
    return this->NameStaff;
}

void ticket::SaveToFile() {
        std::ofstream file("ticket.txt");
        if (file.is_open()) {
            file << "ID: " << TicketId << endl;
            file << "Customer: " << CustomerName << endl;
            file << "Movie: " << MovieName << endl;
            file << "Theatre: " << TheatreCode << endl;
            file << "Seat: " << Seat << endl;
            file << "Price: " << Price << endl;
            file << "Buy Time: " << BuyTime << endl;
            file << "Movie Time: " << MovieTime << endl;
            file << "Staff: " << NameStaff << endl;
            file.close();
            
    }
}

