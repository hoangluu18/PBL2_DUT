#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Suatchieu
{
private:
    string maphim;
    string TimeBegin;
    int price;

public:
    Suatchieu(string = "", string = "", int = 0);
    ~Suatchieu();

    void setTimeBegin();
    void setprice();
    static void themsuatchieu();
    static void insuatchieucuaphim();
};