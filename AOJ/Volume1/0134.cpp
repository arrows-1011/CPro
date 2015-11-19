#include <iostream>
#include <cmath>

using namespace std;
 
int main(){
    int n,c;
    long long ave = 0;
     
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> c;
        ave += c;
    }
    cout << (int)(ave/n) << endl;
    return 0;
}
