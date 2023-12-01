#pragma once
// #ifndef MOVIE_MANAGEMENT_H
// #define MOVIE_MANAGEMENT_H
//create by luu viet hoang
#include "list.h"
#include <iostream>
#include "movie.h"
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>
#include "suatchieumanager.h"

using namespace std;


class movieManagement :protected list<movie> 
{   
    
    public:

    movieManagement();
    ~movieManagement();

    void start();
    void addMovie(movie m);
    bool removeMovie(string);
    bool editMovie(string);
    void printListMovies();
    void readFile();
    void writeFile();
    bool checkPrimarykey(string);
   
   //const movieManagement& operator = (const movieManagement &m);
};

//#endif