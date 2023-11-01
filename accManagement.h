#pragma once
//create by luu viet hoang
#include<iostream>
#include "hash.h"
#include <conio.h>
using namespace std;
class accManagement : public Hash
{
private:
    string userName;

public:
    
    void checkLogin();
    //get , set
    string getUserName(); // lấy tên nhân viên cho phần booking
    void setUserName(string);

};

