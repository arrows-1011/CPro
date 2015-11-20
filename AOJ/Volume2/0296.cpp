#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int v[6];
    const int c[6] = {1,5,10,50,100,500};
    for(int i = 0 ; i < 6 ; i++){
	cin >> v[i];
    }
    int sum = 0;
    for(int i = 0 ; i < 6 ; i++){
	sum += v[i]*c[i];
    }
    cout << (sum >= 1000) << endl;
    return 0;
}
