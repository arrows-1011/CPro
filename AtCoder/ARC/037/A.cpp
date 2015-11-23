#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int N,a,sum = 0;
    cin >> N;
    while(N--){
	cin >> a;
	if(a >= 80) continue;
	sum += 80-a;
    }
    cout << sum << endl;
    return 0;
}
