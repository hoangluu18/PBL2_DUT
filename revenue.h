#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include "Staff.h"
using namespace std;


struct EmployeeRevenue
{
    staff Staff;
    long totalRevenue;
};

class Revenue : public staff
{
private:
    staff* employees; //nhan vien
    int employeesCount;// so nhan vien

    EmployeeRevenue* temporaryRevenues;//doanh thu tam thoi
    int temporaryRevenuesCount;//tong doanh thu tam

public:
    Revenue();
    ~Revenue();

    void total_inDay();

private:
    void processEmployee(const string &employeeName, const string &employeeId);
    void processRevenue(const string &employeeName, const string &employeeId, long revenue);
    void printTotalRevenues();
    string getCurrentDateTime();
};
