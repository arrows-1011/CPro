#include <bits/stdc++.h>

using namespace std;

#define INF (1<<29)
#define MAX_V 100010
#define MAX_LOG_V 110
typedef long long ll;

vector<int> G[MAX_V];
int root;
int deg[MAX_V];

int parent[MAX_LOG_V][MAX_V];  
int depth[MAX_V];

void dfs(int v, int p, int d)
{
    parent[0][v] = p;
    depth[v] = d;
    for (int i = 0; i < (int)G[v].size(); i++) { 
	if(G[v][i] != p) {
	    dfs(G[v][i], v, d+1);
	}
    }
}

void init(int V)
{
    root = 0;
    dfs(root, -1, 0);
    for (int k = 0; k + 1 < MAX_LOG_V; k++) {
	for (int v = 0; v < V; v++) {
	    if (parent[k][v] < 0) {
		parent[k+1][v] = -1;
	    } else {
		parent[k+1][v] = parent[k][parent[k][v]];
	    }
	}
    }
}

int lca(int u, int v)
{
    if(depth[u] > depth[v]){
	swap(u, v);
    }
    for (int k = 0; k < MAX_LOG_V; k++) {
	if ((depth[v] - depth[u]) >> k & 1) {
	    v = parent[k][v];
	}
    }
    if (u == v) {
        return u;
    }
    for (int k = MAX_LOG_V-1; k >= 0; k--) {
	if (parent[k][u] != parent[k][v]) {
	    u = parent[k][u];
	    v = parent[k][v];
	}
    }
    return parent[0][u];
}

int main()
{
    int n, p;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> p; --p;
        G[p].push_back(i+1);
    }
    
    queue<int> Q; Q.push(0);
    vector<ll> d(MAX_V, INF); d[0] = 0;
    vector<int> path; path.push_back(0);
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        for (int i = 0; i < (int)G[v].size(); i++) {
            int to = G[v][i];
            if (d[v] + 1 < d[to]) {
                d[to] = d[v] + 1;
                Q.push(to);
                path.push_back(to);
            }
        }
    }
    
    init(n);
   
    ll res = 0;
    for (int i = 1; i < n; i++) {
        int l = lca(path[i-1], path[i]);
        res += d[path[i-1]] + d[path[i]] - 2*d[l];
    }
    cout << res << endl;
    return 0;
}
