#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Employee
{
    string employeeId;
    string employeeName;
};

struct EmployeeRevenue
{
    string employeeId;
    string employeeName;
    long totalRevenue;
};

class Revenue
{
private:
    Employee* employees;
    int employeesCount;

    EmployeeRevenue* temporaryRevenues;
    int temporaryRevenuesCount;

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
