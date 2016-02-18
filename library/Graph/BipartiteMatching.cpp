#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_V 1010
#define INF 1e9

struct edge {
    int to, cap, rev;
    edge(int to, int cap, int rev) :
        to(to), cap(cap), rev(rev) {}
};
 
int V, E;
vector<edge> G[MAX_V];
int level[MAX_V], iter[MAX_V];
 
void add_edge(int from, int to, int cap){
    G[from].push_back(edge(to, cap, G[to].size()));
    G[to].push_back(edge(from, 0, G[from].size()-1));
}
 
void bfs(int s)
{
    memset(level, -1, sizeof(level));
    queue<int> Q;
    level[s] = 0;
    Q.push(s);
    while (!Q.empty()) {
	int v = Q.front(); Q.pop();
	for (int i = 0; i < (int)G[v].size(); i++) {
	    edge &e = G[v][i];
	    if (e.cap > 0 && level[e.to] < 0) {
		level[e.to] = level[v] + 1;
		Q.push(e.to);
	    }
	}
    }
}
 
int dfs(int v, int t, int f)
{
    if (v == t) return f;
    for (int &i = iter[v]; i < (int)G[v].size(); i++) {
	edge &e = G[v][i];
	if (e.cap > 0 && level[v] < level[e.to]) {
	    int d = dfs(e.to, t, min(f,e.cap));
	    if (d > 0) {
		e.cap -= d;
		G[e.to][e.rev].cap += d;
		return d;
	    }
	}
    }
    return 0;
}
 
int max_flow(int s, int t)
{
    int flow = 0;
    for (;;) {
	bfs(s);
	if (level[t] < 0) return flow;
	memset(iter, 0, sizeof(iter));
	int f;
	while ((f = dfs(s, t, INF)) > 0) {
	    flow += f;
	}
    }
}

int main(){
    int s = 0, t = 1;
    cout << max_flow(s,t) << endl;
    return 0;
}
