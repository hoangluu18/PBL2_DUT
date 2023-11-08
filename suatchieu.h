#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


class Suatchieu {
    private:
    string Stt;
    string maphim;
    string TimeBegin;
    

    public:
    Suatchieu(string = "",string = "", string = "");
    ~Suatchieu();

    void setTimeBegin();
    void setstt();
    static bool Checkmaphim(const string&, const string& );
    static void themsuatchieu();
    static void insuatchieucuaphim();
    void printMovieShow(string = "");
    static string** inseat();
    void inthongtinsuatchieu(string, string);
    static void printseat(string, string);
    static void readseat(string);
}; 