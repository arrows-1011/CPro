#include <bits/stdc++.h>

using namespace std;

#define MAX 110
#define INF (1<<29)
typedef pair<int, int> pii;

struct Edge {
    int to, cost;
    Edge (int to, int cost) : to(to), cost(cost) {}
};

int main()
{
    int N, M, P;
    while (cin >> N >> M >> P, N) {
        int d[MAX][MAX];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                d[i][j] = INF;
            }
            d[i][i] = 0;
        }
        
        vector<Edge> G[MAX];
        
        int a, b, c;
        for (int i = 0; i < M; i++) {
            cin >> a >> b >> c;
            d[a][b] = d[b][a] = c;
            G[a].push_back(Edge(b, c));
            G[b].push_back(Edge(a, c));
        }

        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }

        priority_queue<pii> Q;
        Q.push(pii(d[0][N-1], N-1));
        
        vector<bool> visited(MAX, 0);
        visited[N-1] = 1;

        vector<double> cnt(MAX, 0);
        cnt[N-1] = 1;
        
        while (!Q.empty()) {
            pii p = Q.top(); Q.pop();
            int v = p.second;
            for (int i = 0; i < (int)G[v].size(); i++) {
                Edge &e = G[v][i];
                if (d[0][e.to] + e.cost == d[0][v]) {
                    cnt[e.to] += cnt[v];
                    if (!visited[e.to]) {
                        visited[e.to] = 1;
                        Q.push(pii(d[0][e.to], e.to));
                    }
                }
            }
        }

        priority_queue<pii, vector<pii>, greater<pii>> Q2;
        Q2.push(pii(0, 0));

        vector<bool> visited2(MAX, 0);
        visited2[0] = 1;

        double dp[MAX] = {};
        dp[0] = 1;
        
        while (!Q2.empty()) {
            pii p = Q2.top(); Q2.pop();
            int v = p.second;
            for (int i = 0; i < (int)G[v].size(); i++) {
                Edge &e = G[v][i];
                if (visited[e.to] && d[0][v] + e.cost == d[0][e.to]) {
                    dp[e.to] += dp[v] * cnt[e.to] / cnt[v];                    
                    if (!visited2[e.to]) {
                        visited2[e.to] = 1;
                        Q2.push(pii(d[0][e.to], e.to));
                    }
                }
            }
        }

        int child;
        for (int i = 0; i < P; i++) {
            cin >> child;
            printf("%.10f\n", dp[child]);            
        }
        cout << endl;
    }
    return 0;
}
