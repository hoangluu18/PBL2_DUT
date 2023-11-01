#include "list.h"
#include "movie.h"
#include <fstream>
#include <string>
//create by : tran ngoc minh hoang
class ticket {
    private:
    string TicketId;// id
    string CustomerName; // tênh khách hangf
    string MovieName;// tên phim
    string TheatreCode;// mã rạp
    string Seat;//ghế ngồi
    int Price;// giá
    string BuyTime; // thời gian mua 
    string MovieTime; //==> movie.length
    string NameStaff;// tên nhân viên
    public:

    string getTicketId();
    string getCustomerName();
    string getMovieName();
    string getTheatreCode();
    string getSeat();
    int getPrice();
    string getBuyTime();
    string getMovieTime();
    string getNameStaff();
    void setBuyTime(string);


    ~ticket(); // buytime lấy theo thời gian thực
    ticket(string = "", string = "", string = "", string ="", string = "", string ="", string ="", int = 0);
    void show();
    void SaveToFile();
    static void readTicket(std::ifstream& , const std::string& ); 
};