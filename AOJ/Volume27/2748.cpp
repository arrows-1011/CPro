#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_V = 110;

int V, cmp[MAX_V];
bool used[MAX_V];
vector<int> G[MAX_V], rG[MAX_V], vs;

void add_edge(int from, int to)
{
    G[from].emplace_back(to);
    rG[to].emplace_back(from);
}

void dfs(int v)
{
    used[v] = 1;
    for (int i = 0; i < (int)G[v].size(); i++) {
        if (!used[G[v][i]]) {
            dfs(G[v][i]);
        }
    }
    vs.emplace_back(v);
}

void rdfs(int v, int k)
{
    used[v] = 1;
    cmp[v] = k;
    for (int i = 0; i < (int)rG[v].size(); i++) {
        if (!used[rG[v][i]]) {            
            rdfs(rG[v][i], k);
        }
    }
}

int scc()
{
    memset(used, 0, sizeof(used));
    vs.clear();
    for (int v = 0; v < V; v++) {
        if (!used[v]) {
            dfs(v);
        }
    }
    memset(used, 0, sizeof(used));
    int k = 0;
    for (int i = vs.size() - 1; i >= 0; i--) {
        if (!used[vs[i]]) {
            rdfs(vs[i], k++);
        }
    }
    return k;
}

vector<int> g[MAX_V];

void init(int N)
{
    V = N;
    for (int i = 0; i < N; i++) {
        G[i].clear();
        rG[i].clear();
        g[i].clear();
    }
}

double solve(int N, const vector<double>& P)
{
    int n = scc();
    vector<double> p(n, 1);
    
    vector<int> out(n), in(n);
    for (int i = 0; i < N; i++) {
        for (const auto& to : G[i]) {
            if (cmp[i] != cmp[to]) {
                out[cmp[i]]++;
            }            
        }

        for (const auto& from : rG[i]) {
            if (cmp[i] != cmp[from]) {
                in[cmp[i]]++;
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        p[cmp[i]] *= P[i];
    }
    double res = 1;
    for (int i = 0; i < n; i++) {
        if (out[i] >= 0 && in[i] == 0) {
            res *= (1.0 - p[i]);
        }
    }
    return res;
}

int main()
{
    int N, m;
    while (cin >> N, N > 0) {
        init(N);
        vector<double> P(N);        
        for (int i = 0; i < N; i++) {
            cin >> P[i] >> m;
            for (int j = 0; j < m; j++) {
                int a;
                cin >> a; a--;
                add_edge(i, a);
            }
        }       
        printf("%.10f\n", solve(N, P));
    }    
    return 0;
}
