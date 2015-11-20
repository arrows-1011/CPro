#include <iostream>

using namespace std;
 
int main(){
    int a[5];
    double ave = 0.0;
 
    for(int i = 0 ; i < 5 ; i++){
	cin >> a[i];
	ave += (a[i] >= 40 ?  a[i] : 40);
    }
    cout << ave / 5 << endl;
    return 0;
}
