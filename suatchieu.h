#include "list.h"

class suatchieu {
    private:
    string id;
    string stt;
    string time;
    string date;
    string seat_infor;

    public:
    suatchieu(string = "", string ="", string = "", string = "", string ="");
    ~suatchieu();
    
    string getId();
    string getstt();
    string gettime();
    string getdate();
    string getseat();

    void setid(string);
    void setstt(string);
    void settime(string);
    void setdate(string);
    void setseat(string);

    bool operator==(const suatchieu &m);
    friend ostream& operator<<(ostream& os, const suatchieu& m);
    friend istream& operator>>(istream& is, suatchieu& m);
    const suatchieu& operator = (const suatchieu &m);

};