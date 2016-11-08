/*
  無向グラフG = (V,E)の橋を列挙する.
  
  連結なグラフについて,削除するとグラフが非連結になるような辺を,橋という.
  Gは連結で,多重辺,自己ループはない.
  
  O(V + E)
 */

#include <iostream>
#include <vector>

using namespace std;

constexpr int MAX_V = 100010;
constexpr int INF = (1 << 29);
using Vec = vector<int>;
using pii = pair<int, int>;

int low[MAX_V], ord[MAX_V];
int V, E;
Vec G[MAX_V];
vector<pii> bridge;

void dfs(int v, int prev, int& k)
{
    ord[v] = low[v] = k++;
    for (int i = 0; i < (int)G[v].size(); i++) {
        int to = G[v][i];
        if (to == prev) continue;
        if (ord[to] == -1) {
            dfs(to, v, k);
            low[v] = min(low[v], low[to]);
            if (ord[v] < low[to]) {
                int a = min(v, to),b = max(v, to);
                bridge.emplace_back(a, b);
            }
        }
        low[v] = min(low[v], ord[to]);
    }
}

void init()
{
    bridge.clear();
    for (int i = 0; i < V; i++) {
        G[i].clear();
        ord[i] = -1; low[i] = INF;
    }
}

int main()
{
    int s, t;
    cin >> V >> E; init();
    for (int i = 0; i < E; i++) {
        cin >> s >> t;
        G[s].emplace_back(t);
        G[t].emplace_back(s);
    }
    int k = 0;
    for (int i = 0; i < V; i++) {
        if (ord[i] == -1) {
            dfs(i, -1, k);
        }
    }
    sort(bridge.begin(), bridge.end());
    for (int i = 0; i < (int)bridge.size(); i++) {
        cout << bridge[i].first << " " << bridge[i].second << endl;
    }
    return 0;
}
