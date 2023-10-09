#include "list.h"
#include <iostream>
#include "movie.h"
#include <fstream>
#include <string>
#include <iomanip>


using namespace std;


class movieManagement :public list<movie> 
{   
    // private:
    // list<movie> list_movies;
    public:

    movieManagement();
    ~movieManagement();

    void addMovie(movie m);
    void removeMovie(int);
    void editMovie(int);
    void printListMovies();
    void readFile();
    void writeFile();




   const movieManagement& operator = (const movieManagement &m);




};