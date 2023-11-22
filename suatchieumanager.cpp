#include "suatchieumanager.h"

suatchieumanager::suatchieumanager(){}

suatchieumanager::~suatchieumanager(){}

void suatchieumanager::addsuatchieu(suatchieu s) {
    this->insert(s);
}

char S[9][9];
//hàm tạo bảng chỗ ngồi
void createtable() {
    S[0][0] = ' ';
    int index = 0;
    for (int i = 1; i < 9; i++)
    {
        S[i][0] = 'A' + index;
        index++;
    }
    for (int i = 1; i < 9; i++)
    {
        S[0][i] = '0' + i;
    }
    for (int i = 1; i < 9; i++)
    {
        for (int j = 1; j < 9; j++)
            {
                S[i][j] = '0';
            }
        }
}

void suatchieumanager::readFile(){
    ifstream inFile("suatchieu.txt");
    if(inFile.is_open() == false) {
        cerr << "File not found";
        return;
    }
    string line;
    suatchieu s;
    bool checkseat = false;
    while (getline(inFile, line)) {
        if(checkseat == true){

            s.setseat(line);
            this->addsuatchieu(s);
            checkseat = false;
            continue;

        }   else if(line.find("MP") != string::npos) {
            istringstream iss(line);
            string token;

            getline(iss, token, ';');
            s.setid(token);

            getline(iss, token, ';');
            s.setstt(token);

            getline(iss, token, ';');
            s.settime(token);

            getline(iss, token, ';');
            s.setdate(token);

            checkseat = true;
        }
    }
}

string suatchieumanager::getmoviedate(string id, string stt){
    node<suatchieu> * current = this->head;
    while(current != NULL){
        if(current->data.getId() == id && current->data.getstt() == stt) {
            return current->data.getdate();
        } else current = current->next;
    }
}
string suatchieumanager::getmovietime(string id, string stt){
    node<suatchieu> * current = this->head;
    while(current != NULL){
        if(current->data.getId() == id && current->data.getstt() == stt) {
            return current->data.gettime();
        } else current = current->next;
    }
}
string suatchieumanager::getmovieid(string id, string stt){
    node<suatchieu> * current = this->head;
    while(current != NULL){
        if(current->data.getId() == id && current->data.getstt() == stt) {
            // return current->data.getd();
        } else current = current->next;
    }
}

void suatchieumanager::setmovieseat(string id, string sothutu, string seat) {
    node<suatchieu>* current = this->head;
    while(current != NULL) {
        if (current->data.getId() == id && current->data.getstt() == sothutu) {
            current->data.setseat(seat);
            return;
        } else current = current->next;
    }   
}


string suatchieumanager::getmoviename(string id){
    ifstream inFile("Movie_information.txt");
    if (!inFile)
    {
        cout << "Khong tim thay file";
    }
    string line;
    string moviename;
    while (getline(inFile, line))
    {
        if (line.find(id) == 0)
        {
            istringstream ss(line);

            getline(getline(ss, moviename, ';'), moviename, ';');
        }
    }
    inFile.close();

    return moviename;
}


void suatchieumanager::writeFile(){
    ofstream outfile("clone.txt");
    node<suatchieu>* current = this->head;
    while(current != NULL) {
        outfile << current->data.getId() << ";" << current->data.getstt() << ";" << current->data.gettime() << ";" << current->data.getdate();
        outfile << "\n";
        outfile << current->data.getseat();
        outfile << "\n\n";
        current = current->next;
    }

    outfile.close();
}

void suatchieumanager::checkId(string id){
    node<suatchieu> * current = this->head;
    while(current != NULL) {
        if(current->data.getId() == id) {
            cout << current->data.getId() << ";" << current->data.getstt() << ";" << current->data.gettime() << ";" << current->data.getdate();
            cout << endl;
            current = current->next;
        } else current = current->next;
    }
    
}

string suatchieumanager::readseat(string id, string stt) {
    node<suatchieu> * current = this->head;
    while(current != NULL) {
        if (current->data.getId() == id && current->data.getstt() == stt) {       
            cout << current->data.getId() << ";" << current->data.getstt() << ";" << current->data.gettime() << ";" << current->data.getdate();
            cout << endl;
            return current->data.getseat();
        } else current = current->next;
    }
}

string getCurrentDate()
{
    time_t now = time(0);
    tm *localTime = localtime(&now);

    ostringstream oss;
    oss << put_time(localTime, "%d/%m");
    return oss.str();
}

string GetTomorrowDate() {
    // Lấy thời gian hiện tại
    time_t currentTime = time(nullptr);
    tm* localTime = localtime(&currentTime);
    localTime->tm_mday += 1;
    mktime(localTime);
    ostringstream oss;
    oss << setw(2) << setfill('0') << localTime->tm_mday << '/'
        << setw(2) << setfill('0') << localTime->tm_mon + 1;
    return oss.str();
}


bool CheckTime(const string& targetTime) {
    time_t currentTime;
    time(&currentTime);
    struct tm* timeinfo;
    timeinfo = localtime(&currentTime);
    int targetHour, targetMinute;
    sscanf(targetTime.c_str(), "%dH%d", &targetHour, &targetMinute);
    if (timeinfo->tm_hour > targetHour || (timeinfo->tm_hour == targetHour && timeinfo->tm_min >= targetMinute)) {
        return true; // Nếu thời gian hiện tại đã vượt qua thời gian target
    } else {
        return false; 
    }
}

int CompareDate(const string& dateString) {
    time_t currentTime = time(nullptr);
    tm* localTime = localtime(&currentTime);
    tm inputDate = {};
    istringstream iss(dateString);
    char delimiter;
    iss >> inputDate.tm_mday >> delimiter >> inputDate.tm_mon;
    inputDate.tm_mon -= 1;
    if (localTime->tm_mon > inputDate.tm_mon ||
        (localTime->tm_mon == inputDate.tm_mon && localTime->tm_mday > inputDate.tm_mday)) {
        return 0; // trước ngày hiện tại
    } else if (localTime->tm_mon == inputDate.tm_mon && localTime->tm_mday == inputDate.tm_mday) {
        return 1; // là ngày hiện tại
    } else {
        return 2; // sau ngày hiện tại
    }
}

void suatchieumanager::resetseat(){
    node<suatchieu>* current = this->head;
    while(current != NULL) {
        if((CompareDate(current->data.getdate()) == 1 && CheckTime(current->data.gettime()) == false) || CompareDate(current->data.getdate()) == 2){
            current = current->next;
        } else if(CompareDate(current->data.getdate()) == 1 && CheckTime(current->data.gettime()) == true) {
            current->data.setseat("");
            current->data.setdate(GetTomorrowDate());
            current= current->next;
        } else if(CompareDate(current->data.getdate()) == 0 && CheckTime(current->data.gettime()) == false) {
            current->data.setseat("");
            current->data.setdate(getCurrentDate());
            current = current->next;
        } else if(CompareDate(current->data.getdate()) == 0 && CheckTime(current->data.gettime()) == true) {
            current->data.setseat("");
            current->data.setdate(GetTomorrowDate());
            current = current->next;
        }
    }
}

void suatchieumanager::print_Pre_seat(string seat){
    createtable();
    istringstream ss(seat);
    string field;
    while(getline(ss, field, ';')) {
        char hangghe = field[0];
            int hang = hangghe - 64;
            char soghe = field[1];
            int ghe = soghe - '0';
            if (S[hang][ghe] == '0') {
                S[hang][ghe] = 'X';
        }   
    }
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++){
            cout << S[i][j] << "   ";
        }
        cout << endl << endl;
    }
}

string suatchieumanager::pickseat(){
    cout << "Pick the seat you desire: ";
    string seat;
    bool booking = false;
    while(booking == false) {
        cin >> seat;
        char hangghe = seat[0];
        int hang = hangghe - 64;
        char soghe = seat[1];
        int ghe = soghe - '0';
        if (S[hang][ghe] == '0')
        {
            S[hang][ghe] = 'X';
            
            break;
        }
        else
        {
            cout << "Someone else had booked this seat. Please pick another seat!: ";
        }
    }
    return seat;
}


