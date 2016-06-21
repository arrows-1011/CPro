#include <bits/stdc++.h>

using namespace std;

#define MAX 100000
#define MAX_LOG_V 25
const int INF = (1e9);
typedef pair<int, int> pii;

struct Edge {
    int to, cost;
    Edge (int to, int cost) :
        to(to), cost(cost) {}
};

vector<Edge> G[MAX];
vector<int> G2[MAX];

vector<int> dijkstra(int N, vector<int> &F)
{
    vector<int> d(N, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (auto &f: F) {
        d[f] = 0;
        pq.push(pii(0, f));
    }

    while (!pq.empty()) {
        pii p = pq.top(); pq.pop();
        int v = p.second;
        
        for (int i = 0; i < (int)G[v].size(); i++) {
            Edge &e = G[v][i];
            if (d[v] + e.cost < d[e.to]) {
                d[e.to] = d[v] + e.cost;
                pq.push(pii(d[e.to], e.to));
            }
        }
    }
    return d;
}

void update_cost(int N, vector<int> &d)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (int)G[i].size(); j++) {
            int k = G[i][j].to;
            G[i][j].cost = min(d[i], d[k]);
        }
    }
}

int par[MAX], rnk[MAX];

void init(int N)
{
    for (int i = 0; i < N; i++) {
        par[i] = i;
        rnk[i] = 0;
    }
}

int find(int x)
{
    if (par[x] == x) {
        return x;
    }
    return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x == y) return;
    if (rnk[x] < rnk[y]) {
        par[x] = par[y];
    } else {
        par[y] = par[x];
        if (rnk[x] == rnk[y]) {
            rnk[x]++;
        }
    }
}

bool same(int x, int y)
{
    return (find(x) == find(y));
}

struct edge {
    int u, v, cost;
    
    edge (int u, int v, int cost) :
        u(u), v(v), cost(cost) {}
    
    bool operator < (const edge &e) const {
        return cost > e.cost;
    }
};

vector<edge> es;

void kruskal(int N)
{
    sort(es.begin(), es.end());
    init(N);
    for (int i = 0; i < (int)es.size(); i++) {
        edge &e = es[i];
        if (!same(e.u, e.v)) {
            unite(e.u, e.v);
            G2[e.u].emplace_back(e.v);
            G2[e.v].emplace_back(e.u);
        }
    }
}

int root;
int parent[MAX_LOG_V][MAX];
int min_cost[MAX_LOG_V][MAX];
int depth[MAX];

void dfs(int v, int p, int d, vector<int> &dist)
{
    parent[0][v] = p;
    min_cost[0][v] = min(dist[v], (p >= 0 ? dist[p] : INF));    
    depth[v] = d;
    for (int i = 0; i < (int)G2[v].size(); i++) {
        if (G2[v][i] != p) {
            dfs(G2[v][i], v, d + 1, dist);
        }
    }
}

void lca_init(int V, vector<int> &d)
{
    root = 0;
    dfs(root, -1, 0, d);
    for (int k = 0; k + 1 < MAX_LOG_V; k++) {
        for (int v = 0; v < V; v++) {
            if (parent[k][v] < 0) {
                parent[k+1][v] = -1;
                min_cost[k+1][v] = min_cost[k][v];
            } else {
                parent[k+1][v] = parent[k][parent[k][v]];
                min_cost[k+1][v] = min(min_cost[k][v],
                                       min_cost[k][parent[k][v]]);
            }
        }
    }
}

int lca(int u, int v, vector<int> &d)
{
    int res = min(d[u], d[v]);
    if (depth[u] > depth[v]) swap(u, v);
    for (int k = 0; k < MAX_LOG_V; k++) {
        if ((depth[v] - depth[u]) >> k & 1) {
            res = min(res, min_cost[k][v]);
            v = parent[k][v];            
        }
    }

    if (u == v) return res;

    for (int k = MAX_LOG_V - 1; k >= 0; k--) {
        if (parent[k][u] != parent[k][v]) {
            res = min(res, min(min_cost[k][u], min_cost[k][v]));
            u = parent[k][u];
            v = parent[k][v];
        }
    }
    return min(res, d[parent[0][u]]);
}

int main()
{
    int N, M, K, Q;
    cin >> N >> M >> K >> Q;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c; a--; b--;
        G[a].emplace_back(b, c);
        G[b].emplace_back(a, c);
    }
    
    vector<int> F(K);
    for (int i = 0; i < K; i++) {
        cin >> F[i]; F[i]--;        
    }

    auto d = dijkstra(N, F);

    update_cost(N, d);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (int)G[i].size(); j++) {
            int from = i, to = G[i][j].to, cost = G[i][j].cost;
            es.emplace_back(from, to, cost);
        }
    }
    
    kruskal(N);       
    lca_init(N, d);
    
    while (Q--) {
        int s, t;
        cin >> s >> t; s--; t--;
        cout << lca(s, t, d) << endl;
    }    
    return 0;
}
