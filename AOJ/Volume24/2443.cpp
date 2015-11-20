#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 10
#define INF 1e9
typedef vector<int> Vec;
 
int N, res;
map<Vec,int> dist[2];
Vec v[2];
 
void bfs(int p){
    int t = !p;
    Vec next;
    queue<Vec> que; 
 
    dist[p][v[p]] = 0;
    que.push(v[p]);
 
    while(!que.empty()){
	Vec s = que.front(); que.pop();
 
	if(s == v[t]){
	    res = dist[p][s];
	    break;
	}
 
	if(dist[p][s] >= (N-1)/2){
	    break;
	}
 
	for(int i = 0 ; i < N-1 ; i++){
	    for(int j = i + 1 ; j < N ; j++){
		next = s;
		reverse(next.begin()+i, next.begin()+j+1);
 
		if(!dist[p].count(next)){
		    dist[p][next] = dist[p][s] + 1;
		    que.push(next);
		} 
	    }
	}
    }
}
 
int main(){
    cin >> N;
    v[0].resize(N);
    for(int i = 0 ; i < N ; i++){
	cin >> v[0][i];
	v[1].push_back(i+1);
    }
 
    res = 9;
    bfs(0); bfs(1);
    map<Vec,int>::iterator it, val;
   
    for(it = dist[0].begin() ; it != dist[0].end() ; ++it){
	val = dist[1].find(it->first);
	if(val != dist[1].end()){
	    res = min(res, it->second+val->second);
	}    
    }
    cout << res << endl;
 
    return 0;
}
