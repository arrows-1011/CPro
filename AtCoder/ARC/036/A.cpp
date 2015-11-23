#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int N,K,t[100010];
    cin >> N >> K;
    for(int i = 0 ; i < N ; i++){
	cin >> t[i];
    }
    bool found = false;
    for(int i = 2 ; i < N ; i++){
	if(t[i-2]+t[i-1]+t[i] < K){
	    found = true;
	    cout << i+1 << endl;
	    break;
	}
    }
    if(!found){
	cout << -1 << endl;
    }
    return 0;
}
