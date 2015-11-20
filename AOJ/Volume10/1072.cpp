#include <iostream>

using namespace std;
 
int main(){
    int r,c;
     
    while(cin >> r >> c , r+c){
        int seat_num = r*c;
        if(seat_num%2==0) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
