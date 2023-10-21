#include "hash.h"  

int main()
{   
    cout<<"name ? , pass ?\n"; // test tạm thời nao build hẳn hỏi sau
    string name,pass;
    cin>>name>>pass;
    Hash hash;
    string chose = "loginStaff.txt";
    hash.setChoose(chose);
    hash.ReadFile();
    if(hash.search(name,pass))
    {
        cout<<"Login success"<<endl;
    }
    else
    {
        cout<<"Login fail"<<endl;
    }

    string name1 = "admin";
    string pass1 = "admin";
    
    if(hash.search(name1,pass1) == false)
    {
        hash.insert(name1,pass1);
    }

    hash.WriteFile();  // hàm này có vấn đề rồi
    
}