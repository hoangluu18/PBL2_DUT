#include "suatchieu.h"
class Booking {
    public:
    static void Datve(){
        system("cls");
    string filemovie = "Movie_information.txt";
    cout << "Nhap ma phim ban muon chon: ";
    string maphim;
    cin >> maphim;
    if(Suatchieu::Checkmaphim(filemovie, maphim) == true) {
       system("cls");
       cout << "Xin moi chon suat chieu: " << endl;
       Suatchieu::insuatchieucuaphimcochuoidauvao(maphim);
       Suatchieu::inthongtinsuatchieu(maphim);
    }
    }
};