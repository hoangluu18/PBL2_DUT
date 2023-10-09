#include "movieManagement.h"


int main() {
    // đang nháp
    movieManagement m;
    //  int id;
    // string title;
    // string genre;
    // string summary; // cái này đang thấy hơi căng
    // int lenght;
    // string age;
    // int year;
    // cout<<"size: "<<m.getSize()<<endl;
   
    // movie m1(1,"The Avengers","Action","",143,"PG-13",2012);
    // movie m2(2,"The Avengers: Age of Ultron","Action","",141,"PG-13",2015);
    // movie m3(3,"The Avengers: Infinity War","Action","",149,"PG-13",2018);
    // movie m4(4,"The Avengers: Endgame","Action","",181,"PG-13",2019);

    // m.addMovie(m1);
    // m.addMovie(m2);
    // m.addMovie(m3);
    // m.addMovie(m4);
    // cout<<"size: "<<m.getSize()<<endl;
    // m.removeMovie(3);
    // cout<<"size: "<<m.getSize()<<endl;
    // m.printListMovies();
    // m.editMovie(2);
    // m.printListMovies();


    m.readFile();
    cout<<m.getSize()<<endl;

    m.printListMovies();
    return 0;

}