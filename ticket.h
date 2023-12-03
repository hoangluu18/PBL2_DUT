#include "movie.h"
#include <fstream>
#include <string>
// create by : tran ngoc minh hoang
class ticket
{
private:
    string TicketId;     // id
    string CustomerName; // tênh khách hangf
    string MovieName;    // tên phim
    string Seat;         // ghế ngồi
    int Price;           // giá
    string BuyTime;      // thời gian mua
    string MovieTime;    // thời gian chiếu
    string NameStaff;    // tên nhân viên
    string Staff_id;

public:
    string getId();
    string getCustomerName();
    string getMovieName();
    string getMovieTime();
    string getSeat();
    int getPrice();
    string getBuyTime();
    string getNameStaff();
    string getStaff_id();

    void setId(string);
    void setCustomer(string);
    void setMovieName(string);
    void setMovieTime(string);
    void setSeat(string);
    void setPrice(int);
    void setBuyTime();
    void setNameStaff(string);
    void setStaff_id(string);

    ~ticket();
    ticket(string = "", string = "", string = "", string = "", string = "", string = "", string = "");
    void show();
    string removeHyphens(string);
    void SaveToFile();
    friend ostream &operator<<(ostream &, const ticket &);
    friend istream &operator>>(istream &, ticket &);
    bool operator==(const ticket &);
};