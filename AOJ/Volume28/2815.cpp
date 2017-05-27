#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

constexpr int MAX_V = 1000;
constexpr int INF = (1 << 29);

struct edge {
    int to, cap, cost, rev;
    edge(int to, int cap, int cost, int rev) :
        to{to}, cap{cap}, cost{cost}, rev{rev} {}
};

int V;
vector<edge> G[MAX_V];
int dist[MAX_V], prevv[MAX_V], preve[MAX_V];

void add_edge(int from, int to, int cap, int cost)
{
    G[from].emplace_back(to, cap, cost, G[to].size());
    G[to].emplace_back(from, 0, -cost, G[from].size() - 1);
}

int min_cost_flow(int s, int t, int f)
{
    int res = 0;
    while (f > 0) {
        fill(dist, dist + V, INF);
        dist[s] = 0;
        bool update = true;
        while (update) {
            update = false;
            for (int v = 0; v < V; v++) {
                if (dist[v] == INF) continue;
                for (int i = 0; i < (int)G[v].size(); i++) {
                    edge& e = G[v][i];
                    if (e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
                        dist[e.to] = dist[v] + e.cost;
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        update = true;
                    }
                }
            }
        }
        if (dist[t] == INF) return -1;
        int d = f;
        for (int v = t; v != s; v = prevv[v]) {
            d = min(d, G[prevv[v]][preve[v]].cap);
        }
        f -= d;
        res += d * dist[t];
        for (int v = t; v != s; v = prevv[v]) {
            edge& e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return res;
}

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    
    int S = N + (M + 1) + 1, T = S + 1;
    V = T + 1;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        
        add_edge(S, i, 1, 0);
        add_edge(i, N, 1, -a);
    }
    

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int b;
            cin >> b;
            add_edge(j, N + i + 1, 1, -b);
        }
    }    
    
    for (int i = 0; i < M; i++) {
        int Ti;
        cin >> Ti;
        add_edge(N + i + 1, N + (M + 1), Ti, 0);
    }

    add_edge(N, T, INF, 0);
    add_edge(N + (M + 1), T, N - K, 0);

    cout << -min_cost_flow(S, T, N) << endl;    
    return 0;
}
