#include "booking.h"
char S[9][9];
string Booking::Chonghe(){
    if(S[0][0] != ' ') {
        S[0][0] = ' '; 
    int index = 0;
    for(int i = 1; i < 9 ; i++) {
        S[i][0] = 'A' + index;
        index++;
    }
    for(int i = 1; i < 9; i++) {
        S[0][i] = '0' + i;
    }
    for(int i = 1; i < 9; i++) {
        for(int j = 1; j < 9; j++) {
            S[i][j] = '0';
        }
    }
    }
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++) {
            cout << S[i][j] << "   ";
        }
        cout << endl << endl;
    }
    cout << "Chon ghe ban mong muon: " << endl;
    string token;
    
    bool book = false;
    while(book == false) {
        cin >> token;
        char hangghe = token[0];
        int hang = hangghe - 64;
        char soghe = token[1];
        int ghe = soghe - '0';
        if(S[hang][ghe] == '0') {
            S[hang][ghe] = 'X';
            cout << "Ban da dat thanh cong ghe " << token << endl;
            break;
        } else {
            cout << "Hang ghe nay da co nguoi dat. Xin vui long chon hang ghe khac: ";
        }
    }
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++) {
            cout << S[i][j] << "   ";
        }
        cout << endl << endl;
        }

    return token;// => A1
 }


string Booking::getmoviename(string maphim){ // hàm lấy tên phim để bỏ vào ticket
    ifstream inFile("Movie_information.txt");
    if(!inFile) {
        cout <<"Khong tim thay file";
    } 
    string line;
    string tenphim;
    while(getline(inFile, line)) {
        if(line.find(maphim) == 0) {
            istringstream ss(line);
            
            getline(getline(ss, tenphim, ';'), tenphim, ';');
        }
    }
    inFile.close();

    return tenphim;
}

string Booking::getmovietime(string find ){ // hàm lấy thời gian bắt đầu chiếu phim để bỏ vào ticket
    ifstream inFile("suatchieu.txt");
    if(!inFile) {
        cout <<"Khong tim thay file";
    } 
    string line;
    string movietime;
     size_t pos;
    while(getline(inFile, line)) {
        if(line.find(find) == 0) {
        pos = line.find_last_of(';'); // Tìm vị trí của dấu ';' cuối cùng

        if (pos != string::npos && pos + 1 < line.length()) {
            movietime = line.substr(pos + 1);
            
        } else {
            cout << "Không tìm thấy dấu ';' cuối cùng trong dòng." << endl;
        }
    }
        // if(line.find(find) == 0)
        // size_t lastpos = line.find_last_of(';');
        // if(lastpos != string::npos && lastpos + 1 < line.length()) {
        //     movietime = line.substr (lastpos + 1);
        //     break;
        // }
    }
    return movietime;
}


void Booking::Datve(string NameStaff){
    system("cls");
    movieManagement m;
    m.readFile();
    m.printListMovies();
    string customer;
    cout <<"Ten cua ban: ";
    cin.ignore();
    getline(cin,customer);
    cout << "Put in movie ID: ";
    string maphim;
    cin >> maphim;
    while(m.checkPrimarykey(maphim) == true) {
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
    


    cout << "Ban muon dat bao nhieu ve: ";
    int count;
    cin >> count;
    ticket s[count];   

    for(int i = 0; i < count; i++) { // bước chọn chỗ ngồi
    string seat = h.Chonghe();
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
    for(int i = 0; i < count; i++) {
        s[i].show();
    }
    cout << "Tong so tien ban can tra la " << 55000 * count << " Y/n" << endl;
    char temp;
    cin >> temp;
    if (temp == 'y' || temp == 'Y') {
        cout << "Ban da thanh toan thanh cong. Chuc ban xem phim vui ve!" << endl;
        for(int i = 0; i < count; i++) {
            s[i].SaveToFile();
        }
    }
     system("cls");

    cout<<"\t\t\tTHANK YOU FOR CHOSE OUR SERVICE!\n";
    getch();
}


