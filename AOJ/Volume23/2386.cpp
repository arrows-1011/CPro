#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ll N, G[100][100];
    cin >> N;
    for(int i = 0 ; i < N ; i++){
	for(int j = 0 ; j < N ; j++){
	    cin >> G[i][j];
	}
    }
    ll ans = 0;
    for(int i = 0 ; i < N ; i++){
	for(int j = 0 ; j < i ; j++){
	    ans += min(G[i][j],G[j][i]);
	}
    }
    cout << ans << endl; 
    return 0;
}
