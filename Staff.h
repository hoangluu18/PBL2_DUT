#pragma once
#include <iostream>
using namespace std;

class staff {
    private:

    string staffId; // mã nhân viên
    string staffName;// tên nhân viên
    long  revenue; // doanh thu

    public:
    staff();
    ~staff();

    //get 
    string getName();
    string getId();
    long getRevenue();

    //set
    void setName(string);
    void setId(string);
    void setRevenue(long);
    //operator
    bool operator== (const staff&);
    friend ostream& operator<<(ostream& os, const staff& );
    friend istream& operator>>(istream& is, staff& );
    const staff& operator = (const staff &m);
    //other
    
};
