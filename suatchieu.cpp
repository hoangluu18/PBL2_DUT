#include "suatchieu.h"

suatchieu::suatchieu(string ma, string sothutu, string thoigian, string ngay, string seat) : id(ma), stt(sothutu), time(thoigian), date(ngay), seat_infor(seat){}

suatchieu::~suatchieu(){}

string suatchieu::getId(){
    return this->id;
}

string suatchieu::gettime(){
    return this->time;
}

string suatchieu::getdate(){
    return this->date;
}

string suatchieu::getstt(){
    return this->stt;
}

string suatchieu::getseat(){
    return this->seat_infor;
}

void suatchieu::setid(string i){
    this->id = i;
}

void suatchieu::setdate(string d){
    this->date = d;
}

void suatchieu::setstt(string s){
    this->stt = s;
}

void suatchieu::settime(string t){
    this->time = t;
}

void suatchieu::setseat(string s) {
    this->seat_infor = s;
}

const suatchieu& suatchieu::operator= (const suatchieu &s){
    this->id = s.id;
    this->date = s.date;
    this->seat_infor = s.seat_infor;
    this->stt = s.stt;
    this->time = s.time;
    return *this;
}

istream& operator>>(istream& i, suatchieu& s){
    cout << "ID: ";
    i >> s.id;
    i.ignore();
    cout << "STT: ";
    i >> s.stt;
    cout << "Time: ";
    i >> s.time;
    cout << "Date: ";
    i >> s.date;
    cout << "Seat: ";
    i >> s.seat_infor;

    return i;
}

bool suatchieu::operator==(const suatchieu& s){
    return (this->id == s.id);
}

ostream& operator<<(ostream& o, const suatchieu& s){
    o << "ID: " << s.id << " Stt: " << s.stt << " Time: " << s.time << " Date: " << s.date << endl;
    o << s.seat_infor;
    return o;
}
