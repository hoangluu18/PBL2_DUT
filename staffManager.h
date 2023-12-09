#pragma once

#include "list.h"
#include <iomanip>
#include "staff.h"
#include "accManagement.h"
using namespace std;

class staffManager : protected list<staff>
{
private:
   
public:
    staffManager();
    ~staffManager();
   
    void start(); // start menu
    void addStaff(staff s);// thêm nhân viên và mật khẩu nhân viên
    bool removeStaff(string id);// xóa nhân viên và mật khẩu nhân viên
    bool changePassword(string id);// thay đổi mật khẩu nhân viên
    void readFile();
    void writeFile();
    bool checkPrimarykey(string id);
    void showStaff();
    string getStaffId(string nameStaff);// lấy id nhân viên từ tên
    string getStaffName(string id) ;// lấy tên nhân viên từ id
};
