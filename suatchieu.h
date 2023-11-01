#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#pragma once
using namespace std;


class Suatchieu {
    private:
    string Stt;
    string maphim;
    string TimeBegin;
    int price;

    public:
    Suatchieu(string = "",string = "", string = "", int = 0);
    ~Suatchieu();

    void setTimeBegin();
    void setprice();
    void setstt();
    static bool Checkmaphim(const string&, const string& );
    static void themsuatchieu();
    static void insuatchieucuaphim();
    static void insuatchieucuaphimcochuoidauvao(string = "");
    static string** inseat();
    static void inthongtinsuatchieu(string);
}; 