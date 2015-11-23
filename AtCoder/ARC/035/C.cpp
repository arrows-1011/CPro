#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_V 410
#define INF 1e9
typedef long long ll;
 
int main(){
    ll V,E,a,b,c,K;
    ll res = 0LL;
    ll d[MAX_V][MAX_V];
    cin >> V >> E;
    for(int i = 0 ; i < V ; i++){
	for(int j = 0 ; j < V ; j++){
	    d[i][j] = INF;
	}
	d[i][i] = 0;
    }
    for(int i = 0 ; i < E ; i++){
	cin >> a >> b >> c; a--; b--;
	d[a][b] = d[b][a] = c;
    }
    for(int k = 0 ; k < V ; k++){
	for(int i = 0 ; i < V ; i++){
	    for(int j = 0 ; j < V ; j++){
		d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
	    }
	}
    }
    cin >> K;
    while(K--){
	cin >> a >> b >> c; a--; b--;
	res = 0LL;
	if(d[a][b] > c){
	    d[a][b] = d[b][a] = c;
	    for(int i = 0 ; i < V ; i++){
		for(int j = 0 ; j < V ; j++){
		    d[i][j] = min(d[i][j],d[i][a]+d[a][b]+d[b][j]);
		    d[i][j] = min(d[i][j],d[i][b]+d[b][a]+d[a][j]);
		    res += d[i][j];
		}
	    }
	    cout << res/2 << endl;
	}else{
	    for(int i = 0 ; i < V ; i++){
		for(int j = 0 ; j < V ; j++){
		    res += d[i][j];
		}
	    }
	    cout << res/2 << endl;
	}
    }
    return 0;
}
