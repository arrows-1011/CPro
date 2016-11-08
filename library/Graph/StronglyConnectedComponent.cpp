#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

constexpr int MAX_V = 1000;

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
    used[v] = true;
    for (int i = 0; i < (int)G[v].size(); i++) {
	if (!used[G[v][i]]) {
            dfs(G[v][i]);
        }
    }
    vs.emplace_back(v);
}

void rdfs(int v, int k)
{
    used[v] = true;
    cmp[v] = k;
    for (int i = 0; i < (int)rG[v].size(); i++) {
	if (!used[rG[v][i]]) {
            rdfs(rG[v][i], k);
        }
    }
}

int scc()
{
    memset(used, false, sizeof(used));
    vs.clear();
    for (int v = 0; v < V; v++) {
	if (!used[v]) {
            dfs(v);
        }
    }
    memset(used, false, sizeof(used));
    int k = 0;
    for (int i = vs.size() - 1; i >= 0; i--) {
	if (!used[vs[i]]) {
            rdfs(vs[i], k++);
        }
    }
    return k;
}
