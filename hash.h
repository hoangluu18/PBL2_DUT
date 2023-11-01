#pragma once
//create by : luu viet hoang
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const int capacity = 307;
class Hash
{
  private:
   
   bool key[capacity][capacity] ;  // true là tìm thấy false là không tìm thấy
   string choose; // staff or Manager 
    
  public:
   Hash();
   ~Hash();

   string getChoose();
   void setChoose(string name);
    
   int hashFunction(string);
   void ReadFile(); // lấy value từ file
   void WriteFile(); // ghi value vào file
   void insert(string  , string);
   bool search(string , string);
};
