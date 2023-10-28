#include <iostream>
using namespace std;

class Staff {
    private:

    string StaffName;
    string StaffId;
    int Revenue;

    public:
    Staff(string = "", string = "", int = 0);
    ~Staff();

    string getName();
    string getId();
    int getRevenue();
    
};
