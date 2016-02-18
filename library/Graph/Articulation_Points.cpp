/*
  無向グラフG = (V,E)の関節点を列挙する.
  
  連結グラフ G において,頂点 v と,v から出ている全ての辺を削除して得られる部分グラフが,非連結になるとき,
  頂点 v をグラフ G の関節点（Articulation Point）または切断点という.
  
  (G-vでGが非連結になるときのvを関節点)
  
  O(V + E)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_V 100010
#define INF 1e9
typedef vector<int> Vec;

Vec G[MAX_V], ap;
int V, E;
int ord[MAX_V], low[MAX_V];

void init()
{
    for (int i = 0; i < V; i++) {
        G[i].clear();
        ord[i] = -1; low[i] = INF;
    }
}

void dfs(int v, int prev, int &k)
{
    ord[v] = low[v] = k++;
    int cnt = 0;
    bool isAri = false;
    for (int i = 0; i < (int)G[v].size(); i++) {
        int to = G[v][i];
        if (to == prev) continue;
        if (ord[to] == -1) {
            cnt++;
            dfs(to, v, k);
            low[v] = min(low[v], low[to]);
            if (prev >= 0 && ord[v] <= low[to]) {
                isAri = true;
            }
        }
        low[v] = min(low[v], ord[to]);
    }
    if (prev == -1 && cnt >= 2) isAri = true;
    if (isAri) ap.push_back(v);
}

int main()
{
    int s, t;
    cin >> V >> E; init();
    for (int i = 0; i < E; i++) {
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    int k = 0;
    for (int i = 0; i < V; i++) {
        dfs(i, -1, k);
    }
    sort(ap.begin(), ap.end());
    for (int i = 0; i < (int)ap.size(); i++) {
        cout << ap[i] << endl;
    }
    return 0;
}
