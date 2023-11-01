#pragma once
//create by luu viet hoang
#include<iostream>
#include "hash.h"
#include <conio.h>
#include "staff.h"
using namespace std;
class accManagement : public Hash
{
private:
    string userName;
   // string password;
public:
    //get , set
    string getUserName(); // lấy tên nhân viên cho phần booking
    void setUserName(string);
    // string getPassword();
    // void setPassword(string);
    //other
    void checkLogin(bool& check); // true = manager, false = staff
    void addAccount(staff s);
    void removeAccount(staff s);
    void changePassword(staff s);
    

};

