#pragma once

#include "list.h"
#include <iostream>
#include "movie.h"
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <cmath>

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

   //const movieManagement& operator = (const movieManagement &m);
};