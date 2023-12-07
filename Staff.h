#pragma once
#include <iostream>
using namespace std;
//create by luu viet hoang , tran ngoc minh hoang
class staff {
    private:

    string staffId; // mã nhân viên
    string staffName;// tên nhân viên
   

    public:
    staff();
    ~staff();
    staff(string id, string name);

    //get 
    string getName();
    string getId();


    //set
    void setName(string);
    void setId(string);

    //operator
    bool operator== (const staff&);
    friend ostream& operator<<(ostream& os, const staff& );
    friend istream& operator>>(istream& is, staff& );
    const staff& operator = (const staff &m);
    //other
    
};
