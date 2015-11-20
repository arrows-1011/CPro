#include <iostream>

using namespace std;
 
int main(){
    int b,r,g,c,s,t;
     
    while(cin >> b >> r >> g >> c >> s >> t ,b+r+g+c+s){
        int medal = 100;
        medal += 95*b+63*r+7*g+2*c+3*s-3*t;
        cout << medal << endl;
    }
    return 0;
}
