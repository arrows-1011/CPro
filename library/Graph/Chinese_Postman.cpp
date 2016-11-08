/*
  無向中国人郵便配達問題
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int INF = (1 << 29);

struct Edge {
    int src, dst, cost;
    
    Edge(int src, int dst, int cost) :
        src{src}, dst{dst}, cost{cost} {}
    
    bool operator < (const Edge& e) const
    {
        if (cost != e.cost) {
            return cost > e.cost;
        } else if(src != e.src) {
            return src < e.src;
        } else {
            return dst < e.dst;
        }
    }
};

using Edges = vector<Edge>;
using Graph = vector<Edges>;

int chinesePostman(const Graph& g)
{
    int sum = 0, size = g.size();
    vector<int> odds;
    for (int i = 0; i < size; i++) {
        for (auto x : g[i]) {
            sum += x.cost;
        }
        if (g[i].size() % 2) {
            odds.emplace_back(i);
        }
    }
    sum /= 2;
    int n = odds.size(), N = (1 << n);
    int d[n][n];
    for (int i = 0; i < n; i++) {
        int s = odds[i];
        vector<int> dist(size, INF), prev(size, -2);
        dist[s] = 0;
        priority_queue<Edge> Q;
        Q.push(Edge(-1, s, 0));
        while (!Q.empty()) {
            Edge e = Q.top(); Q.pop();
            if (prev[e.dst] != -2) continue;
            prev[e.dst] = e.src;
            for (auto x : g[e.dst]) {
                if (dist[x.dst] > e.cost + x.cost) {
                    dist[x.dst] = e.cost + x.cost;
                    Q.push(Edge(x.src, x.dst, dist[x.dst]));
                }
            }
        }
        for (int j = 0; j < n; j++) {
            d[i][j] = dist[odds[j]];
        }
    }
    vector<int> dp(N, INF);
    dp[0] = 0;
    for (int S = 0; S < N; S++) {
        for (int i = 0; i < n; i++) {
            if (S >> i & 1) continue;
            for (int j = i + 1; j < n; j++) {
                if (S >> j & 1) continue;
                dp[S | (1 << i)|(1 << j)] =
                    min(dp[S | (1 << i) | (1 << j)], dp[S] + d[i][j]);
            }
        }
    }
    return sum + dp[N - 1];
}

int main()
{
    int V, E, s, t, d;
    cin >> V >> E;
    Graph g(V);
    for (int i = 0; i < E; i++) {
        cin >> s >> t >> d;
        g[s].emplace_back(s, t, d);
        g[t].emplace_back(t, s, d);
    }
    cout << chinesePostman(g) << endl;
    return 0;
}
