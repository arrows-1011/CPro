#include <iostream>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

constexpr int MAX = 514;
constexpr int UNVISITED = (1 << 25);

struct Edge {
    int to, cost;
    Edge() {}
    Edge(int to, int cost) :
        to{to}, cost{cost} {}
};

vector<Edge> G[MAX];
int dist[MAX];

bool dfs(int v, int p, int d)
{
    if (dist[v] != UNVISITED) {
        return (dist[v] != d);
    }
    
    dist[v] = d;
    for (const auto& g : G[v]) {
        if (g.to == p) continue;
        if (dfs(g.to, v, d + g.cost)) {
            return true;
        }
    }
    return false;
}

bool run()
{
    int N;
    cin >> N;
    if (N == 0) {
        return false;
    }

    for (int i = 0; i < MAX; i++) {
        G[i].clear();
    }
    
    int n = 0;
    map<string, int> s2i;
    
    string t, u, v;
    for (int i = 0; i < N; i++) {
        cin >> u >> u;

        if (s2i.count(u) == 0) {
            s2i[u] = n++;
        }
        
        cin >> t >> t >> v;
        t = t.substr(3);

        if (s2i.count(v) == 0) {
            s2i[v] = n++;
        }
        
        int num = stoi(t);        
        G[s2i[v]].emplace_back(s2i[u], -num);
        G[s2i[u]].emplace_back(s2i[v], num);
    }
   
    bool ok = 1;
    for (int i = 0; i < n; i++) {
        fill(dist, dist + MAX, UNVISITED);
        if (dfs(i, -1, 0)) {
            ok = 0;
            break;
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
    return true;
}

int main()
{
    while (run())
        ;
    return 0;
}
