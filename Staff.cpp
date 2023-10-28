#include "staff.h"

Staff::Staff(string Name, string Id, int reve) : StaffName(Name), StaffId(Id), Revenue(reve) {

}

Staff::~Staff(){

}

string Staff::getId(){
    return this->StaffId;
}

string Staff::getName(){
    return this->StaffName;
}

int Staff::getRevenue() {
    return this->Revenue;
}
