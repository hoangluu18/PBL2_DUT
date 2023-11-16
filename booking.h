#pragma once

#include "suatchieu.h"
#include <iostream>
#include <string>
#include <fstream>
#include "accManagement.h"
#include "ticket.h"
#include "list.h"

#include "movieManagement.h"
class Booking {
    public:
    void Datve(string nameStaff);
    string Chonghe(string);
    string getmoviename(string);
    string getmovietime(string);
  
};
