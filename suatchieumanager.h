#pragma once
#include "suatchieu.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include <sstream>
using namespace std;

class suatchieumanager : protected list<suatchieu> {
    public:
    suatchieumanager();
    ~suatchieumanager();

    string getmovieid(string, string); 
    string getmovietime(string, string);
    string getmoviedate(string, string);

    string getmoviename(string);

    void setmovieseat(string, string, string);
    void addsuatchieu(suatchieu);  
    void readFile();
    void writeFile();
    void checkId(string);
    string readseat(string, string);
    void resetseat();
    void print_Pre_seat(string);
    string pickseat();

    void createNewSuatchieu(string id);
};