#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int X,sum = 0;
    cin >> X;
    while(X > 0){
	sum += X%10;
	X /= 10;
    }
    cout << sum << endl;
    return 0;
}
