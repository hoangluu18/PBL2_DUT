#include "movieManagement.h"


int main() {
    // đang nháp

    movieManagement m;
    movie m1;
    cin>>m1;
    m.addMovie(m1);
    m.printListMovies();

    movie m2;
    cin>>m2;
    m.addMovie(m2);
    
    int a = 5;
   if( m.removeMovie(a))
    {
    cout<<"deleted\n";
    }  
    else cout<<"not found\n";

   
    m.printListMovies();
   

    list<movie> l;
    l.insert(m1);
    cout<<l.getSize();

   // m.getSize();
    
   
//  list<movie> l;
//     movie m1;
//     cin>>m1;
//     l.insert(m1);
//     l.print();
//     movie m2;
//     cin>>m2;
//     l.insert(m2);
//     l.print();
//      cout<<"abc";
//     movie*  m3;
//     m3 = l.search(2);
//     l.insert(*m3);
//     l.print();
//     l.remove(*(l.search(2)));
//     cout<<l.getSize();


   
    

    
   
     cout<<m.getSize();
    
   
    return 0;
    
}



