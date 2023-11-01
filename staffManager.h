#pragma once
// #ifndef STAFF_MANAGER_H
// #define STAFF_MANAGER_H
// create by : luu viet hoang
#include<iostream> 
#include "list.h"
#include <fstream>
#include <conio.h>
#include <string>
#include <iomanip>
#include "staff.h"

using namespace std;

class staffManager : protected list<staff>
{
private:
   
public:
    staffManager();
    ~staffManager();

    void start();
    void addStaff(staff s);
    bool removeStaff(string);
   // bool editStaff(string);
    void printListStaff();
    void readFile();
    void writeFile();
    bool checkPrimarykey(string);

};


//#endif