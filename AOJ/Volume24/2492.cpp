#include <bits/stdc++.h>
  
using namespace std;
  
#define MAX 110
#define INF 1e9
typedef pair<int,int> pii;
  
bool a[MAX];
int N,G[MAX];
  
int dijkstra(){
    int res = INF;
    int dist[MAX];
    fill(dist,dist+MAX,INF);
    dist[0] = 0;
    priority_queue<pii,vector<pii>,greater<pii> > Q;
    Q.push(pii(0,0));
    while(!Q.empty()){
	pii now = Q.top(); Q.pop();
	int v = now.second;
	if(dist[v] < now.first) continue;
	if(v == N-1){
	    if(a[N-1]){
		res = min(res,dist[N-1]);
	    }else{
		res = min(res,dist[N-1]+1);
	    }
	    continue;
	}
	if(a[v]){
	    if(dist[v] < dist[v+1]){
		dist[v+1] = dist[v];
		Q.push(pii(dist[v+1],v+1));
	    }
	}else{
	    if(dist[v] + 1 < dist[v+1]){
		dist[v+1] = dist[v] + 1;
		Q.push(pii(dist[v+1],v+1));
	    }
	    if(dist[v] < dist[G[v]]){
		dist[G[v]] = dist[v];
		Q.push(pii(dist[G[v]],G[v]));
	    }
	}
    }
    return res;
}
  
int main(){
    string in,s[MAX];
    cin >> N;
    for(int i = 0 ; i < N ; i++){
	cin >> in;
	if(in == "goto"){
	    a[i] = false;
	    cin >> in;
	    s[i] = in;
	}else{
	    a[i] = true;
	    s[i] = in;
	}
	s[i].resize(s[i].size()-1);
    }
  
    for(int i = 0 ; i < N ; i++){
	for(int j = 0 ; j < N ; j++){
	    if(i == j) continue;
	    if(s[i] == s[j]){
		if(!a[i] && a[j]){
		    G[i] = j;
		}else if(a[i] && !a[j]){
		    G[j] = i;
		}
	    }
	}
    }
    cout << dijkstra() << endl;
    return 0;
}
