#include <bits/stdc++.h>

using namespace std;

#define MAX 3010
#define INF (1<<29)
typedef pair<int, int> pii;

struct Edge {
    int to, cost;
    Edge (int to, int cost) :
        to(to), cost(cost) {}
};

int N, M, K;
vector<Edge> G[MAX];
int d[MAX];

void dijkstra(int src)
{
    d[src] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(pii(0, src));

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
}

int main()
{
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        a--; b--;
        G[a].push_back(Edge(b, l));
        G[b].push_back(Edge(a, l));
    }

    fill(d, d + MAX, INF);
    
    int src;
    for (int i = 0; i < K; i++) {
        cin >> src; src--;
        dijkstra(src);
    }
    
    int res = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (int)G[i].size(); j++) {
            int k = G[i][j].to, c = G[i][j].cost;
            int maxi = max(d[i], d[k]), mini = min(d[i], d[k]);
            res = max(res, mini + (int)ceil((maxi + c - mini) * 0.5));
        }
    }
    cout << res << endl;
    return 0;
}
