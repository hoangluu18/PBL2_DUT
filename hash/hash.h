
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Hash
{
  private:
   bool hashValue[307][307] ; 
    string choose; // staff or Manager 
  public:
   Hash();
   ~Hash();

   string getChoose();
   void setChoose(string name);
    
   int hashKey(string);
   void ReadFile(); // lấy value từ file
   void WriteFile(); // ghi value vào file
   void insert(string  , string);
   bool search(string , string);
};
