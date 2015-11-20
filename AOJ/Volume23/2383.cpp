#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 100000
#define MOD 1000000007
typedef long long ll;
 
int main(){
    int N,T,a[MAX_N];
    cin >> N >> T;
    for(int i = 0 ; i < N ; i++){
	cin >> a[i];
    }
    sort(a,a+N);
    ll res = 1;
    for(int i = 0 ; i < N ; i++){
	res *= upper_bound(a+i,a+N,a[i]+T)-(a+i);
	res %= MOD;
    }
    cout << res << endl;
    return 0;
}
