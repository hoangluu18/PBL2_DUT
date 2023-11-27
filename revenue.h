#pragma once

#include <iostream>
#include <fstream>
#include <vector>
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
    vector<Employee> employees;
    vector<EmployeeRevenue> temporaryRevenues;

public:
    void total_inDay();
    
private:
    void processEmployee(const string &employeeName, const string &employeeId);
    void processRevenue(const string &employeeName, const string &employeeId, long revenue);
    void printTotalRevenues();
    string getCurrentDateTime();
};
