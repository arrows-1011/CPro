#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main(){
    int p1,p2,p3,j1,j2,P;
   
    cin >> p1 >> p2 >> p3 >> j1 >> j2;
 
    if( p1 >= p2 && p2 >= p3 ) P = p3; 
    else if( p1 >= p3 && p3 >= p2 ) P = p2; 
    else if( p2 >= p1 && p1 >= p3 ) P = p3; 
    else if( p2 >= p3 && p3 >= p1 ) P = p1;
    else if( p3 >= p1 && p1 >= p2 ) P = p2;
    else if( p3 >= p2 && p2 >= p1 ) P = p1;
    
    int J = min(j1,j2);
    cout << P + J - 50 << endl;
    return 0;
}
