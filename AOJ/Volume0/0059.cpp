#include <iostream>

using namespace std;
 
int main(){
    double x1,y1,x2,y2,x3,y3,x4,y4;
     
    while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4){
        if(x4 < x1 || x2 < x3 || y2 < y3 || y4 < y1) cout << "NO" << endl;
        else cout << "YES" << endl;        
    }
    return 0;
}
