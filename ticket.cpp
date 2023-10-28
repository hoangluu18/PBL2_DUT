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

ticket::ticket(string id, string customer, string movie, string theatre, string seat,  string movietime, string staff, int price){
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

void ticket::setBuyTime(string Buy){
    this->BuyTime = Buy;    
}

void ticket::SaveToFile() {
        ofstream outFile("ticket.txt", ios::app);
        if (outFile.is_open()) {
            outFile << TicketId;
            outFile << ";" << CustomerName ;
            outFile << ";" << MovieName ;
            outFile << ";" << TheatreCode ;
            outFile << ";" << Seat ;
            outFile << ";" << Price ;
            outFile << ";" << BuyTime ;
            outFile << ";" << MovieTime ;
            outFile << ";" << NameStaff << endl;
            outFile.close();
            
    }
}


void ticket::readTicketById(string targetId) {
        ifstream inFile("ticket.txt");
        string line;
        while (getline(inFile, line)) {
            istringstream iss(line);
            string id;
            string customer;
            string movie;
            string Theatre;
            string seat;
            double price;
            string buytime;
            string movietime;
            string staffname;
            if (getline(iss, line, ';') >> id >> ws &&
                getline(iss, customer, ';') >> ws &&
                getline(iss, movie, ';') >> ws &&
                getline(iss, Theatre, ';') >> ws &&
                getline(iss, seat, ';') >> ws &&
                getline(iss, buytime, ';') >> ws &&
                getline(iss, movietime, ';') >> ws &&
                getline(iss, staffname, ';') >> ws &&
                (iss >> price)) {
                    if (id == targetId) {
                        ticket tic(id, customer, movie, Theatre, seat, movietime, staffname, price);
                        tic.setBuyTime(buytime);
                        cout << "Da doc";
                        tic.show();
                    }
                }
                else cout << "Sai2";
        }
}  

