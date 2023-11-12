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
    cout << "Chon ghe ban mong muon: " << endl;
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
            cout << "Ban da dat thanh cong ghe " << seat << endl;
            break;
        }
        else
        {
            cout << "Hang ghe nay da co nguoi dat. Xin vui long chon hang ghe khac: ";
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

void resetshowtime(string maphim) {
    ifstream inFile("suatchieu.txt");
    if (!inFile.is_open()) {
        cerr << "K tim thay file" << endl;
        return;
    }
    string line;
    string file;
    bool found = false;
    while(getline(inFile, line)) { // hàm này tìm dòng có thông tin ghế ngồi của suất chiếu cần tìm và xóa thông tin ghế ngồi (nếu suất chiếu đó đã chiếu xong rồi)
        if(found == false && line.find(maphim) != string::npos) {
            found = true;
            file += line + "\n";
        } else if (found == true){ // dòng thông tin ghế ngồi bị bỏ qua không ghi vào file (coi như là xóa)
            file += "\n";
            found = false;
        } else {
            file += line + "\n";
        }
    }
        
    inFile.close();
    ofstream outFile("suatchieu.txt");
    outFile << file;
    outFile.close();
}


bool CheckTime(const string& targetTime) {
    // Lấy thời gian hiện tại
    time_t currentTime;
    time(&currentTime);
    // Chuyển đổi thời gian hiện tại thành cấu trúc tm
    struct tm* timeinfo;
    timeinfo = localtime(&currentTime);
    int targetHour, targetMinute;
    // So sánh thời gian đích với thời gian hiện tại
    if (timeinfo->tm_hour > targetHour || (timeinfo->tm_hour == targetHour && timeinfo->tm_min >= targetMinute)) {
        return true; 
    } else {
        return false; 
    }
}





void Booking::Datve(string NameStaff)
{
    system("cls");
    movieManagement m;
    m.readFile();
    m.printListMovies();
    string customer;
    cout << "Ten cua ban: ";
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

    k.printMovieShow(maphim);

    cout << "Chon suat chieu ma ban muon: " << endl;
    string Sothutu;
    cin >> Sothutu;
    k.inthongtinsuatchieu(maphim, Sothutu); // In thông tin suất chiếu
    
    string find = maphim + ";" + Sothutu;
    string movietime = h.getmovietime(find); // hàm lấy giờ suất chiếu để bỏ vô ticket

    //FIXME:
    // if(CheckTime(movietime)) { // kiểm tra suất chiếu đã chiếu chưa, nếu rồi thì reset chỗ ngồi 
    //     resetshowtime(find);
    // }

    
    cout << "So Luong Ve can dat: ";
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
    cout << "Tong so tien ban can tra la " << 55000 * count << " Y/n" << endl;
    char temp;
    cin >> temp;
    if (temp == 'y' || temp == 'Y')
    {
        cout << "Ban da thanh toan thanh cong. Chuc ban xem phim vui ve!" << endl;
        for (int i = 0; i < count; i++)
        {
            s[i].SaveToFile();
        }
    }
    system("cls");

    cout << "\t\t\tTHANK YOU FOR CHOSE OUR SERVICE!\n";
    getch();
}
