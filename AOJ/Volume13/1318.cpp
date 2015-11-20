#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 6001
#define INF 1e9
 
struct State{
    int dist,v,cap;
    State(int dist,int v,int cap) 
	: dist(dist),v(v),cap(cap) {}
 
    bool operator > (const State &s)const{
	return dist > s.dist;
    }
};
 
struct Edge{
    int to,dist;
    Edge(int to,int dist) : to(to),dist(dist) {}
};
 
int N,M,cap,src,dst,idx;
set<int> LPG;
vector<Edge> G[MAX];
 
void init(){
    idx = 1;
    LPG.clear();
    for(int i = 0 ; i < MAX ; i++){
	G[i].clear();
    }
}
 
int dijkstra(){
    vector<vector<int> > dist(idx);
    cap *= 10;
  
    for(int i = 0 ; i < idx ; i++){
	dist[i].resize(cap+1);
	for(int j = 0 ; j <= cap ; j++){
	    dist[i][j] = INF;
	}
    }
 
    dist[src][cap] = 0;
 
    priority_queue<State,vector<State>,greater<State> > Q;
    Q.push(State(0,src,cap));
 
    while(!Q.empty()){
	State s = Q.top(); Q.pop();
	int v = s.v,c = s.cap;
     
	if(dist[v][c] < s.dist) continue;
     
	if(v == dst){
	    return dist[v][c];
	}
 
	for(int i = 0 ; i < (int)G[v].size() ; i++){
	    Edge e = G[v][i];
	    int nc = (LPG.find(v) != LPG.end()) ? cap : c;
	    if(e.dist <= nc){
		nc -= e.dist;
		if(dist[v][c] + e.dist < dist[e.to][nc]){
		    dist[e.to][nc] = dist[v][c] + e.dist;
		    Q.push(State(dist[e.to][nc],e.to,nc));
		}                           
	    }
	}
    }
    return -1;
}
 
int main(){
    int d;
    string a,b;
   
    while(cin >> N >> M >> cap, N){
	init();
	map<string,int> mp; 
	cin >> a; mp[a] = src = idx++; 
	cin >> a; mp[a] = dst = idx++; 
	for(int i = 0 ; i < N ; i++){
	    cin >> a >> b >> d;
	    if(mp.find(a) == mp.end()){
		mp[a] = idx++;
	    }
	    if(mp.find(b) == mp.end()){
		mp[b] = idx++;
	    }
	    G[mp[a]].push_back(Edge(mp[b],d));
	    G[mp[b]].push_back(Edge(mp[a],d));
	}
	for(int i = 0 ; i < M ; i++){
	    cin >> a;
	    LPG.insert(mp[a]);
	}
	cout << dijkstra() << endl;
    }
    return 0;
}
