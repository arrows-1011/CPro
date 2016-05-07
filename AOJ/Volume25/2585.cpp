#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100
#define MAX_H 25
#define INF (1<<29)

struct Edge {
    int to, c, h, r;
    Edge (int to, int c, int h, int r) :
        to(to), c(c), h(h), r(r) {}
};

struct State {
    int c, v, h;
    State (int c, int v, int h) :
        c(c), v(v), h(h) {}

    bool operator < (const State &s) const {
        return c > s.c;
    }
};

int main()
{
    int N, M, H, K, S, T, P;
    while (cin >> N >> M >> H >> K, N) {
        vector<Edge> G[MAX_N];
        for (int i = 0; i < M; i++) {
            int a, b, c, h, r;
            cin >> a >> b >> c >> h >> r;
            a--; b--; r--;
            G[a].push_back(Edge(b, c, h, r));
            G[b].push_back(Edge(a, c, h, r));
        }
        cin >> S >> T >> P; S--; T--;
        vector<int> d(P), bit(P);
        for (int i = 0; i < P; i++) {
            int l, k;
            cin >> l >> d[i];
            for (int j = 0; j < l; j++) {
                cin >> k; k--;
                bit[i] |= (1<<k);
            }            
        }

        int dp[1<<8];
        fill(dp, dp + (1<<8), INF);
        dp[0] = 0;
        for (int i = 0; i < (1<<K); i++) {
            if (dp[i] == INF) continue;              
            for (int j = 0; j < P; j++) {
                int ni = (i | bit[j]);
                dp[ni] = min(dp[ni], dp[i] + d[j]);
            }
        }
       
        int res = INF;
        for (int i = 0; i < (1<<K); i++) {
            int d[MAX_N][MAX_H];
            for (int j = 0; j < N; j++) {
                for (int k = 0; k <= H; k++) {
                    d[j][k] = INF;
                }
            }

            d[S][H] = 0;
            
            priority_queue<State> Q;
            Q.push(State(0, S, H));
            
            while (!Q.empty()) {
                State s = Q.top(); Q.pop();
                int v = s.v, h = s.h;
                int cost = s.c;
                
                if (v == T) {
                    res = min(res, cost + dp[i]);
                    break;
                }

                for (int j = 0; j < (int)G[v].size(); j++) {
                    Edge &e = G[v][j];
                    int nh = h - e.h;
                    if (nh < 0) continue;
                    
                    int ncost = cost;
                    if (!(i >> e.r & 1)) {
                        ncost += e.c;
                    } 
                    if (ncost < d[e.to][nh]) {
                        d[e.to][nh] = ncost;
                        Q.push(State(ncost, e.to, nh));
                    }
                }
            }            
        }
        cout << (res == INF ? -1 : res) << endl;
    }
    return 0;
}
