#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int N,sum = 0,maxi = 0;
    cin >> N;
    vector<int> d(N);
    for(int i = 0 ; i < N ; i++){
	cin >> d[i];
	sum += d[i];
    }
    for(int i = 0 ; i < N ; i++){
	maxi = max(maxi,2*d[i]-sum);
    }
    cout << sum << endl;
    cout << maxi << endl;
    return 0;
}
