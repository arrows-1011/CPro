#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int N,K,P;
    cin >> N;
    while(N--){
	cin >> K >> P;
	K %= P;
	cout << (K == 0 ? P : K) << endl;
    }
    return 0;
}
