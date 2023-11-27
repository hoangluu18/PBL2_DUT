#include "revenue.h"

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
    auto it = find_if(employees.begin(), employees.end(),
                      [&employeeId](const Employee &e) {
                          return e.employeeId == employeeId;
                      });

    if (it == employees.end())
    {
        employees.push_back({employeeId, employeeName});
    }
}

void Revenue::processRevenue(const string &employeeName, const string &employeeId, long revenue)
{
    auto it = find_if(temporaryRevenues.begin(), temporaryRevenues.end(),
                      [&employeeId](const EmployeeRevenue &er) {
                          return er.employeeId == employeeId;
                      });

    if (it != temporaryRevenues.end())
    {
        it->totalRevenue += revenue;
    }
    else
    {
        temporaryRevenues.push_back({employeeId, employeeName, revenue});
    }
}

void Revenue::printTotalRevenues()
{
    for (const auto &er : temporaryRevenues)
    {
        cout << "ID: " << er.employeeId << ", Name: " << er.employeeName << ", Total Revenue: " << er.totalRevenue << endl;
    }
}

string Revenue::getCurrentDateTime()
{
    time_t now = time(0);
    tm *localTime = localtime(&now);

    ostringstream oss;
    oss << put_time(localTime, "%d/%m/%y");
    return oss.str();
}
