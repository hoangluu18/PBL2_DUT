#pragma once

#include "list.h"
#include "movie.h"
#include "suatchieumanager.h"

using namespace std;


class movieManagement :protected list<movie> 
{   
    
    public:

    movieManagement();
    ~movieManagement();

    void start();
    void addMovie(const movie& m);
    bool removeMovie(string);
    bool editMovie(string& , string&);
    void printListMovies();
    void readFile();
    void writeFile();
    bool checkPrimarykey(const string&);
};

