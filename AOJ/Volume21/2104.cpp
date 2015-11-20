#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 100010
 
int main(){
    int Tc,N,K,x[MAX],a[MAX];
    cin >> Tc;
    while(Tc--){
	cin >> N >> K;
	for(int i = 0 ; i < N ; i++){
	    cin >> x[i];
	}
	for(int i = 1 ; i < N ; i++){
	    a[i-1] = x[i]-x[i-1];
	}
	sort(a,a+N-1);
	int res = 0;
	for(int i = 0 ; i < N-K ; i++){
	    res += a[i];
	}
	cout << res << endl;
    }
    return 0;
}
