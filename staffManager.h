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
#include "accManagement.h"
using namespace std;

class staffManager : protected list<staff>
{
private:
   
public:
    staffManager();
    ~staffManager();

    void start(); // start menu
    void addStaff(staff s);// thêm nhân viên và mật khẩu nhân viên
    bool removeStaff(string id);// xóa nhân viên và mật khẩu nhân viên
    bool changePassword(string id);// thay đổi mật khẩu nhân viên
    void readFile();
    void writeFile();
    bool checkPrimarykey(string id);
    void showStaff();
};


//#endif