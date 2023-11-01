#pragma once
//create by : luu viet hoang
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
    //orther function 
    string getUserName();
    void setUserName(string);

};

