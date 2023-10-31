#pragma once

#include "list.h"
#include <iostream>
#include "movie.h"
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>


using namespace std;


class movieManagement :protected list<movie> 
{   
    
    public:

    movieManagement();
    ~movieManagement();

    void startManager();
    void startStaff();
    void addMovie(movie m);
    bool removeMovie(string);
    bool editMovie(string);
    void printListMovies();
    void printMovie(string);
    void readFile();
    void writeFile();
    bool checkPrimarykey(string);
};