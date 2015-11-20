#include <iostream>
#include <map>
#include <algorithm>
 
using namespace std;
 
const int MAX = 500;
const int INF = 1e9;
 
int main(){
    int n,m;
 
    while(cin >> n >> m, n | m){
	map<string,int> mp;
	int dist[MAX+1][MAX+1];
	string a,b,start,goal,via;
	int c,d;
 
	for(int i = 0 ; i <= n ; i++){
	    for(int j = 0 ; j <= n ; j++){
		dist[i][j] = INF;
	    }
	}
 
	cin >> start >> via >> goal;
 
	int s = 1;
	for(int i = 0 ; i < m ; i++){
	    cin >> a >> b >> c >> d;
 
	    if(!mp[a]){
		mp[a] = s++;
	    }
	    if(!mp[b]){ 
		mp[b] = s++;
	    }
 
	    dist[mp[a]][mp[b]] = dist[mp[b]][mp[a]] = c / 40 + d;
	}
   
	for(int k = 1 ; k <= n ; k++){
	    for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
		    dist[i][j] = min(dist[i][j] ,dist[i][k] + dist[k][j]);
		}
	    }
	}
	cout << dist[mp[start]][mp[via]] + dist[mp[via]][mp[goal]] << endl;
    }
    return 0;
}
