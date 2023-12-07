#include "revenue.h"

Revenue::Revenue()
{
    employees = nullptr;
    employeesCount = 0;

    temporaryRevenues = nullptr;
    temporaryRevenuesCount = 0;
}

Revenue::~Revenue()
{
    delete[] employees;
    delete[] temporaryRevenues;
}

void Revenue::total_inDay()
{
    ifstream inputFile("ticket.txt");

    if (!inputFile.is_open())
    {
        cerr << "Error!" << endl;
        return;
    }

    string line;
    while (getline(inputFile, line))
    {
        size_t pos = line.find(';', 0);
        pos = line.find(';', pos + 1);
        pos = line.find(';', pos + 1);
        pos = line.find(';', pos + 1);
        line.erase(0, pos + 1);
        pos = line.find(';', 0);

        string RV = line.substr(0, pos);
        line.erase(0, pos + 1);
        string day = line.substr(0, 8);
        pos = line.find(';', 0);
        line.erase(0, pos + 1);
        pos = line.find(';', 0);
        line.erase(0, pos + 1);
        pos = line.find(';', 0);
        string name = line.substr(0, pos);
        line.erase(0, pos + 1);
        string idx = line.substr(0, pos);
        pos = 0;

        if (getCurrentDateTime() == day)
        {
            processEmployee(name, idx);
            processRevenue(name, idx, stol(RV));
        }
    }
    printTotalRevenues();

    inputFile.close();
}

void Revenue::processEmployee(const string &employeeName, const string &employeeId)
{
    bool employeeExist = false;
    for (int i = 0; i < employeesCount; ++i)
    {
        if (employees[i].getId() == employeeId)
        {
            employeeExist = true;
            break;
        }
    }

    if (!employeeExist)
    {
        // Add a new employee
        staff* newEmployees = new staff[employeesCount + 1];
        copy(employees, employees + employeesCount, newEmployees);
        newEmployees[employeesCount] = {employeeId, employeeName};

        delete[] employees;
        employees = newEmployees;
        ++employeesCount;
    }
}

void Revenue::processRevenue(const string &employeeName, const string &employeeId, long revenue)
{
    bool revenueExist = false;
    for (int i = 0; i < temporaryRevenuesCount; ++i)
    {
        if (temporaryRevenues[i].Staff.getId() == employeeId)
        {
            revenueExist = true;
            temporaryRevenues[i].totalRevenue += revenue;
            break;
        }
    }

    if (!revenueExist)
    {
        // Add a new revenue entry
        
        EmployeeRevenue* newRevenues = new EmployeeRevenue[temporaryRevenuesCount + 1];
        copy(temporaryRevenues, temporaryRevenues + temporaryRevenuesCount, newRevenues);
        //newRevenues[temporaryRevenuesCount] = {employeeId, employeeName, revenue};
        newRevenues[temporaryRevenuesCount].Staff.setId(employeeId);
        newRevenues[temporaryRevenuesCount].Staff.setName(employeeName);
        newRevenues[temporaryRevenuesCount].totalRevenue = revenue;

        delete[] temporaryRevenues;
        temporaryRevenues = newRevenues;
        ++temporaryRevenuesCount;
    }
}

void Revenue::printTotalRevenues()
{
    system("cls");
    for (int i = 0; i < temporaryRevenuesCount; ++i)
    {
        cout << "ID: " << temporaryRevenues[i].Staff.getId() << ", Name: " << temporaryRevenues[i].Staff.getName() << ", Total Revenue: " << temporaryRevenues[i].totalRevenue << endl;
    }
    system("pause");
}

string Revenue::getCurrentDateTime()
{
    time_t now = time(0);
    tm *localTime = localtime(&now);

    ostringstream oss;
    oss << put_time(localTime, "%d/%m/%y");
    return oss.str();
}
