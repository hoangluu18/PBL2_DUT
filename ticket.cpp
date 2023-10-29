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






void ticket::readTicket(ifstream& inFile, const string& targetId){
    ticket ticket;
        std::string line;

        while (std::getline(inFile, line)) {
            std::string id, customer, movie, TheatreCode, seat, buytime, movietime, staffname;
            int price;

            std::size_t pos = 0;
            std::string token;
            int count = 0;
            while ((pos = line.find(";")) != string::npos) {
                token = line.substr(0, pos);
                line.erase(0, pos + 1);
                switch (count) {
                    case 0:
                        id = token;
                        break;
                    case 1:
                        customer = token;
                        break;
                    case 2:
                        movie = token;
                        break;
                    case 3:
                        TheatreCode = token;
                        break;
                    case 4:
                        seat = token;
                        break;
                    case 5:
                        price = std::stoi(token);
                        break;
                    case 6:
                        buytime = token;
                        break;
                    case 7:
                        movietime = token;
                        break;
                    case 8:
                        staffname = token;
                        break;
                }
                count++;
            }

            if (id == targetId) {
                ticket.TicketId = id;
                ticket.CustomerName = customer;
                ticket.MovieName = movie;
                ticket.TheatreCode = TheatreCode;
                ticket.Seat = seat;
                ticket.Price = price;
                ticket.BuyTime = buytime;
                ticket.MovieTime = movietime;
                ticket.NameStaff = staffname;
                ticket.show();
                inFile.close();
                return;
            } 
        }
        cout << "Khong tim thay id cua hoa don";
} 

        