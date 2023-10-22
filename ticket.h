#include "list.h"
#include "movie.h"

class ticket {
    private:
    string TicketId;
    string CustomerName;
    string MovieName;
    string TheatreCode;
    string Seat;
    int Price;
    string BuyTime;
    string MovieTime;
    string NameStaff;
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


    ~ticket(); // buytime lấy theo thời gian thực
    ticket(string = "", string = "", string = "", string ="", string = "", int = 0, string ="", string ="");
    void show();
    
};