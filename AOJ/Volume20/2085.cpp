#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 1010
#define INF 1e9
 
struct Intersection{
    int x,y;
};
 
struct State{
    int dist,v,dir,c;
    State(int dist,int v,int dir,int c) :
	dist(dist),v(v),dir(dir),c(c) {}
    bool operator < (const State &s)const{
	if(dist != s.dist){
	    return dist > s.dist;
	}else{
	    return c > s.c;
	}
    }
};
 
int M,N;
string src,dst;
vector<int> G[MAX];
Intersection n[MAX];
map<string,int> num;
 
int nextdir(int xs,int ys,int xt,int yt,int dir){
    if(dir == 0){
	if(xs < xt) return -1;
	if(ys > yt) return -1;
	if(xs > xt) return 3;
	return 0;
    }else if(dir == 1){
	if(ys > yt) return -1;
	if(xs > xt) return -1;
	if(ys < yt) return 0;
	return 1;
    }else if(dir == 2){
	if(xs > xt) return -1;
	if(ys < yt) return -1;
	if(xs < xt) return 1;
	return 2;
    }else{
	if(ys < yt) return -1;
	if(xs < xt) return -1;
	if(ys > yt) return 2;
	return 3;
    }
}
 
int getDist(int x1,int y1,int x2,int y2){
    return max(abs(x2-x1),abs(y2-y1));
}
 
void solve(){
    priority_queue<State> Q;
    int dist[MAX][4];
    fill(dist[0],dist[0]+MAX*4,INF);
    for(int i = 0 ; i < 4 ; i++){
	Q.push(State(0,num[src],i,1));
	dist[num[src]][i] = 0;
    }
    while(!Q.empty()){
	State s = Q.top(); Q.pop();
	int v = s.v,dir = s.dir;
	if(dist[v][dir] < s.dist) continue;
	if(v == num[dst]){
	    cout << s.c << endl;
	    return;
	} 
	Intersection ni = n[v];
	for(int i = 0 ; i < (int)G[v].size() ; i++){
	    Intersection u = n[G[v][i]];
	    int ndir = nextdir(ni.x,ni.y,u.x,u.y,dir);
	    if(ndir == -1) continue;
	    int ndist = s.dist + getDist(ni.x,ni.y,u.x,u.y);
	    if(ndist < dist[G[v][i]][ndir]){
		dist[G[v][i]][ndir] = ndist;
		Q.push(State(ndist,G[v][i],ndir,s.c+1));
	    }
	}
    }
    cout << "impossible" << endl;
}
 
int main(){
    string name,a,b;
    int x,y;
    while(cin >> M >> N, M){
	num.clear();
	for(int i = 0 ; i < MAX ; i++){
	    G[i].clear();
	}
	for(int i = 0 ; i < M ; i++){
	    cin >> name >> x >> y;
	    n[i+1] = (Intersection){x,y};
	    num[name] = i+1;
	}
	for(int i = 0 ; i < N ; i++){
	    cin >> a >> b;
	    G[num[a]].push_back(num[b]);
	    G[num[b]].push_back(num[a]);
	}
	cin >> src >> dst;
	solve();
    }
    return 0;
}
