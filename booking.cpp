
#include "booking.h"
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


// in suất chiếu vừa đặt để lưu vào file suatchieu.txt
void printseat(string suatchieu, string seat){
    ifstream inFile("suatchieu.txt");
    if(!inFile){
        cerr<<"Error opening file";
        exit(-1);
    }
    string file;
    string line;
    if(inFile.is_open()) {
        while(getline(inFile, line)) {
            file += line + "\n";
            if(line.find(suatchieu) != string::npos){
                file += seat + ";" ;
                break;
        }
    }
    while(getline(inFile, line)) {
        file += line + '\n';
    }
    inFile.close();
}
    ofstream outFile("suatchieu.txt");
    if(outFile.is_open()) {
        outFile << file;
        outFile.close();
    } else cerr << "Khong tim thay file"; 
}



// hàm để kiểm tra các chỗ ngồi đã được đặt
void Suatchieu::readseat(string suatchieu){
    ifstream inFile("suatchieu.txt");
    if(!inFile){
        cerr<<"Error opening file";
        exit(-1);
    }
    string line;
    string target;
    bool istarget = false;
    while(getline(inFile, line)) {
        if(istarget == true) {
            istringstream linestream(line);
            string field;
            while(getline(linestream, field, ';')) {         
                char hangghe = field[0];
                int hang = hangghe - 64;
                char soghe = field[1];
                int ghe = soghe - '0';
                if (S[hang][ghe] == '0') {
                    S[hang][ghe] = 'X';
                }   
            }
            istarget = false;
        } else if (line.find(suatchieu) != string::npos) {
            istarget = true;
        }   
    }
    inFile.close();
}


string pickseat(string suatchieu) {
    cout << "Pick the seat you desire: " << endl;
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
            cout << "Booked successed! " << seat << endl;
            break;
        }
        else
        {
            cout << "Someone else had booked this seat. Please pick another seat!: ";
        }
    }
    printseat(suatchieu, seat);
    return seat;
}


// hàm đặt ghế
string Booking::Chonghe(string suatchieu)
{
    if (S[0][0] != ' ') {
        createtable();
    }
    Suatchieu::readseat(suatchieu);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
        {
            cout << S[i][j] << "   ";
        }
        cout << endl
             << endl;
    }
    return pickseat(suatchieu);

}

string Booking::getmoviename(string maphim)
{ // hàm lấy tên phim để bỏ vào ticket
    ifstream inFile("Movie_information.txt");
    if (!inFile)
    {
        cout << "Khong tim thay file";
    }
    string line;
    string tenphim;
    while (getline(inFile, line))
    {
        if (line.find(maphim) == 0)
        {
            istringstream ss(line);

            getline(getline(ss, tenphim, ';'), tenphim, ';');
        }
    }
    inFile.close();

    return tenphim;
}

string Booking::getmovietime(string find)
{ // hàm lấy thời gian bắt đầu chiếu phim để bỏ vào ticket
    ifstream inFile("suatchieu.txt");
    if (!inFile)
    {
        cout << "Khong tim thay file";
    }
    string line;
    string movietime;
    size_t pos;
    while (getline(inFile, line))
    {
        if (line.find(find) == 0)
        {
            pos = line.find_last_of(';'); // Tìm vị trí của dấu ';' cuối cùng

            if (pos != string::npos && pos + 1 < line.length())
            {
                movietime = line.substr(pos + 1);
            }
            else
            {
                cout << "Không tìm thấy dấu ';' cuối cùng trong dòng." << endl;
            }
        }
        
    }
    return movietime;
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


string getCurrentDate()
{
    time_t now = time(0);
    tm *localTime = localtime(&now);

    ostringstream oss;
    oss << put_time(localTime, "%d/%m");
    return oss.str();
}

void resetSeat(){
    ifstream inputFile("suatchieu.txt"); 
    string line;
    string file;
    istringstream plus;
    bool checkreset = false;
    while (getline(inputFile, line)) {
        if(checkreset == true) {
            file += "\n";
            // cout << "Trigger";
            checkreset = false;
            continue;
        } else if (line.find("MP") != string::npos){
            
            istringstream iss(line);
            string token;

            getline(iss, token, ';'); 
            string maphim = token;

            getline(iss, token, ';'); 
            string stt = token;

            getline(iss, token, ';');
            string time = token;

            getline(iss, token, ';');
            string date = token;
    
            if((CompareDate(date) == 1 && CheckTime(time) == false) || CompareDate(date) == 2) {
                file += line + "\n";
                // cout << "Cringe";
                continue;
            } else if (CompareDate(date)  == 1 && CheckTime(time) == true) {
                checkreset = true;
                // cout << "DCM";
                date = GetTomorrowDate();
                file += maphim + ";" + stt + ";" + time + ";" + date + "\n";
                continue;
            } else if (CompareDate(date) == 0 && CheckTime(time) == false) {
                checkreset = true;
                // cout << "何？";
                date = getCurrentDate();
                file += maphim + ";" + stt + ";" + time + ";" + date + "\n";
                continue;
            } else if (CompareDate(date) == 0 && CheckTime(time) == true) {
                checkreset = true;
                // cout << "HUH?";
                date = GetTomorrowDate();
                file += maphim + ";" + stt + ";" + time + ";" + date + "\n";
                continue;
            }
        } else {
            file += line + "\n";
        }
    }
    inputFile.close();
    
    ofstream outFile("suatchieu.txt");
    outFile << file;
    outFile.close();
}





void Booking::Datve(string NameStaff)
{
    system("cls");
    movieManagement m;
    m.readFile();
    m.printListMovies();
    string customer;
    cout << "Customer Name: ";
    cin.ignore();
    getline(cin, customer);
    cout << "Put in movie ID: ";
    string maphim;
    cin >> maphim;
    while (m.checkPrimarykey(maphim) == true)
    {
        cout << "Movie not found, try again!: ";
        cin >> maphim;
    }   
    system("cls");

    Booking h;
    Suatchieu k;
    string tenphim = h.getmoviename(maphim); // hàm lấy tên phim để bỏ vào ticket
    resetSeat(); // thao tác reset suất chiếu theo giờ
    k.printMovieShow(maphim);

    cout << "Pick the showtime you desire: " << endl;
    string Sothutu;
    cin >> Sothutu;
    k.inthongtinsuatchieu(maphim, Sothutu); // In thông tin suất chiếu
    
    string find = maphim + ";" + Sothutu;
    string movietime = h.getmovietime(find); // hàm lấy giờ suất chiếu để bỏ vô ticket    
    cout << "Ticket's quantity: ";
    int count;
    cin >> count;
    ticket s[count];

    for (int i = 0; i < count; i++)
    { // bước chọn chỗ ngồi
        string seat = h.Chonghe(find);
        s[i].setId(to_string(i));
        s[i].setCustomer(customer);
        s[i].setMovieName(tenphim);
        s[i].setMovieTime(movietime);
        s[i].setSeat(seat);
        s[i].setPrice(55000);
        s[i].setBuyTime();
        s[i].setNameStaff(NameStaff);
        system("cls");
    }

    system("cls");
    for (int i = 0; i < count; i++)
    {
        s[i].show();
        cout << endl;
    }
    cout << "The total amount you need to pay is " << 55000 * count << "VND.  Y/n" << endl;
    char temp;
    cin >> temp;
    
    if (temp == 'y' || temp == 'Y')
    {
        cout << "Paid successed!. Have a nice time!" << endl;
        for (int i = 0; i < count; i++)
        {
            s[i].SaveToFile();
        }
    } else if (temp == 'n' || temp == 'N') {
        cout << "You have cancelled the payment." << endl;
    }


    system("cls");

    cout << "\t\t\tTHANK YOU FOR CHOSE OUR SERVICE!\n";
    getch();
}
