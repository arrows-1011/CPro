#include <iostream>

using namespace std;
 
int main(){
    double x1,x2,y1,y2,x3,x4,y3,y4;
     
    while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4){
        double a = (x2-x1)*(x4-x3),b = (y2-y1)*(y4-y3);
        if((float)a+(float)b == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
