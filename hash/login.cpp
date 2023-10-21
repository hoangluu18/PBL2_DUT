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
}