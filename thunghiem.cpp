#include "suatchieumanager.h"
#include "movieManagement.h"
#include "ticket.h"
// char S[9][9];
// //hàm tạo bảng chỗ ngồi
// void createtable() {
//     S[0][0] = ' ';
//     int index = 0;
//     for (int i = 1; i < 9; i++)
//     {
//         S[i][0] = 'A' + index;
//         index++;
//     }
//     for (int i = 1; i < 9; i++)
//     {
//         S[0][i] = '0' + i;
//     }
//     for (int i = 1; i < 9; i++)
//     {
//         for (int j = 1; j < 9; j++)
//             {
//                 S[i][j] = '0';
//             }
//         }
// }

int main() {
    system("cls");
    movieManagement movie;
    movie.readFile();
    movie.printListMovies();
    string customer;
    cout << "Customer Name: ";
    cin.ignore();
    getline(cin, customer);
    suatchieumanager manager;
    manager.readFile();
    
    string id;
    cout << "Put in movie ID: ";
    cin >> id;

    while(movie.checkPrimarykey(id) == true) {
        cout << "Movie not found. Try Again! :";
        cin >> id;
    }
    system("cls");

    manager.checkId(id);

    string stt;
    cout << "Nhap stt ma ban muon: ";
    cin >> stt;
    string m = manager.readseat(id, stt);
    // manager.print_Pre_seat(m);
    cout << "Nhap so luong ve ban muon mua: ";
    int count;
    cin >> count;
    system("cls");
    ticket s[count];
    string seat;
    for(int i = 0; i < count; i++) {
            manager.print_Pre_seat(m);
            if(i > 0) cout << "Booked successed! " << seat << endl;
            seat = manager.pickseat();
            m = m + ";" + seat;
            s[i].setId(to_string(i));
            s[i].setCustomer("Hoang");
            s[i].setMovieName(manager.getmoviename(id));
            s[i].setMovieTime(manager.getmovietime(id, stt));
            s[i].setSeat(seat);
            s[i].setPrice(55000);
            s[i].setBuyTime();
            s[i].setNameStaff("HUY");
            system("cls");
    }
    system("cls");
    manager.setmovieseat(id, stt, m);
    for(int i = 0; i < count; i++){
        s[i].show();
        cout << endl;
    }

    cout << "The total amount you need to pay is " << 55000 * count << "VND.    Y/N" << endl;
    char temp;
    cin >> temp;

    if(temp == 'y' || temp == 'Y') {
        system("cls");
        cout << "\t\t\t Paid successed!. Thank you for chose our service!" << endl;
        for(int i = 0; i < count; i++){
            s[i].SaveToFile();
        }
        manager.writeFile();
    } else if (temp == 'n' || temp == 'N') {
        cout << "You have cancelled the payment." << endl;
    }
    // cout << "Press any key to continue!";
    // cin.get();
}