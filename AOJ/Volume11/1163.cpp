#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 3000;
const int INF = 1e8;
#define gcd(a,b) __gcd(a,b)
 
struct edge{ 
    int to, cap, rev;
};
 
vector<edge> G[MAX];
bool used[MAX];
 
void add_edge(int from,int to,int cap){
    G[from].push_back((edge){to ,cap ,G[to].size()});
    G[to].push_back((edge){from ,0 ,G[from].size()-1});
}
 
int dfs(int v,int t,int f){
    if(v == t) return f;
    used[v] = true;
    for(int i = 0 ; i < G[v].size() ; i++){
	edge &e = G[v][i];
	if(!used[e.to] && e.cap > 0){
	    int d = dfs(e.to,t,min(f,e.cap));
	    if(d > 0){
		e.cap -= d;
		G[e.to][e.rev].cap += d;
		return d;
	    }
	}
    }
    return 0;
}
 
int max_flow(int s,int t){
    int flow = 0;
 
    for(;;){
	memset(used,false,sizeof(used));
	int f = dfs(s,t,INF);
	if(f == 0) return flow;
	flow += f;
    }
}
 
int main(){
    int m,n,b,r;
   
    while(cin >> m >> n , m + n){
	vector<int> B,R;
	int s = m+n,t = s+1;
	memset(G,0,sizeof(G));
	for(int i = 0 ; i < m ; i++){
	    cin >> b;
	    B.push_back(b);
	    add_edge(s,i,1);
	}
 
	for(int j = 0 ; j < n ; j++){
	    cin >> r;
	    R.push_back(r);
	    add_edge(m+j,t,1);
	}
  
	for(int i = 0 ; i < m ; i++){
	    for(int j = 0 ; j < n ; j++){
		if(gcd(B[i],R[j]) != 1){
		    add_edge(i,m+j,1);
		}
	    }
	}
	cout << max_flow(s,t) << endl;
    }
    return 0;
}
