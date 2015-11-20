#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ll N,M,s,t,e;
    cin >> N >> M;
    vector<ll> S,T,E,c(N);
    while(cin >> s >> t >> e, s){
	S.push_back(s-1);
	T.push_back(t-1);
	E.push_back(e);
    }
    ll L;
    cin >> L;
    for(int i = 0 ; i < L ; i++){
	ll b[M];
	for(int j = 0 ; j < N ; j++){
	    c[j] = 0;
	}
	for(int j = 0 ; j < M ; j++){
	    cin >> b[j];
	}
	for(int j = 0 ; j < (int)S.size() ; j++){
	    c[S[j]] += b[T[j]]*E[j];
	}
	for(int j = 0 ; j < N ; j++){
	    if(j > 0){ cout << " "; }
	    cout << c[j];
	}
	cout << endl;
    }
    return 0;
}
