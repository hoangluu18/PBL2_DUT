#include "suatchieu.h"




Suatchieu::Suatchieu(string MaMovie, string Begin, int price) {
    this->maphim = MaMovie;
    this->TimeBegin = Begin;
    this->price = price;
} 

Suatchieu::~Suatchieu(){

}

void Suatchieu::setTimeBegin(){
    cout << "Thoi gian bat dau: ";
    string begin;
    cin >> begin;
    this->TimeBegin = begin;
    cout << endl;
}

void Suatchieu::setprice() {
    cout << "Gia: ";
    int price;
    cin >> price;
    this->price = price;
    cout << endl;
}


bool Checkmaphim(const std::string& filename, const std::string& prefix) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Không thể mở tệp " << filename << endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        if (line.compare(0, prefix.size(), prefix) == 0) {
            file.close(); 
            return true;
        }
    }

    file.close(); 
    return false;
}


    void Insuatchieuvaotrongfile(string& filename, string& line) {
        // Đọc toàn bộ nội dung từ tệp vào một chuỗi.
        ifstream inFile(filename);
        string NoidungFile;
    if(inFile) {
        string line;
        while(getline(inFile, line)) {
            NoidungFile += line + "\n";
        }
        inFile.close();  // đọc hết nội dung file rồi đóng file để tránh các bản ghi sau ghi đè lên các bản ghi trước
        } else {
            inFile.close();
            cout << "Khong co tep thong tin!" << endl;
            return;
        }

        // kiểm tra phim đó đã có suất chiếu nào chưa

        string TimMaphim = line.substr(0, 3); // trích ra 3 kí tự đầu của chuối line  để kiểm tra 3 kí tự đầu tiên mỗi hàng
        size_t foundPosition = NoidungFile.find(TimMaphim);
        if (foundPosition != string::npos) {

            // nếu có rồi thì thêm suất chiếu mới vào ngay bên dưới các suất chiếu mới của phim đó trong file txt
            size_t nextLinePosition = NoidungFile.find("\n", foundPosition);
            if (nextLinePosition != string::npos) { // string::npos là 1 tín hiệu có nghĩa là không tìm thấy -> != string::npos tức là đã tìm thấy chuỗi cần tìm

                // Thêm hàng mới xuống phía dưới của hàng trùng đó.
                NoidungFile.insert(nextLinePosition, "\n" + line);
            }
        } else {
            // nếu chưa có suất chiếu nào thì thêm vào cuối file .txt
            NoidungFile += "\n" + line;
        }

        // Ghi lại toàn bộ nội dung của chuỗi vào tệp văn bản.
        ofstream outFile(filename);
        outFile << NoidungFile;
        outFile.close();
    }

void Suatchieu::insuatchieucuaphim(){
    ifstream inFile("suatchieu.txt"); // Thay "your_file.txt" bằng đường dẫn tới tệp của bạn
    if (!inFile) {
        cout << "Không thể mở tệp." << endl;
        return;
    }
    string line;
    string maphim;
    cout << "Nhap ma phim can tim suat chieu: ";
    cin >> maphim;
    while (getline(inFile, line)) {
        if (line.find(maphim) == 0) {
            cout << line << endl;
        }
    }
    inFile.close();
}

void Suatchieu::themsuatchieu(){
    string filephim = "Movie_information.txt"; // file thông tin các phim đã tồn tại
    string filesuatchieu = "suatchieu.txt"; // file thông tin các suất chiếu của các phim
    cout << "Nhap ma phim: "; // nhập mã phim cần thêm suất chiếu mới
    string maphim;
    cin >>maphim;
    Suatchieu New;
    if(Checkmaphim(filephim, maphim) == true) { // hàm kiểm tra phim muốn thêm suất chiếu có tồn tại trong danh sách movie_information hay không
        cout << "Vui long nhap thong tin suat chieu cua ma phim " << maphim << endl;
        New.setTimeBegin();
        New.setprice();
        string Thongtinsuatchieu = maphim + ";" + New.TimeBegin + ";" + to_string(New.price);
        Insuatchieuvaotrongfile(filesuatchieu, Thongtinsuatchieu); // thêm thông tin vô file suatchieu.txt
    } 
    else cout << "Chua co phim do trong danh sach phim"; // nếu phim chưa tồn tại trong file movie_information thì hiện ra thông báo
}