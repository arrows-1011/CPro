#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100
#define MAX_C 20
#define MAX_R 10010
#define INF (1<<29)

struct State {
    int d, v;
    
    State(int d, int v) 
        : d(d), v(v) {}
    
    bool operator < (const State &s) const {
        return d > s.d;
    }
};

int N, M, C, mc[MAX_C];
vector<int> q[MAX_C];
int cost[MAX_C][MAX_R];
int dist[MAX_N][MAX_N][MAX_C];

int get_cost(int c, int d)
{
    int n = q[c].size();
    if (q[c][n-1] < d) {
        return cost[c][q[c][n-1]] + (d - q[c][n-1]) * mc[c];
    } else {
        return cost[c][d];
    }
}

int dijkstra(int src, int dst)
{
    int d[MAX_N];
    fill(d, d + MAX_N, INF);    
    d[src] = 0;
    
    priority_queue<State> Q;
    Q.push(State(0, src));
    
    while (!Q.empty()) {
        State s = Q.top(); Q.pop();
        int dd = s.d, v = s.v;
        if (v == dst) return dd;
        for (int i = 0; i < N; i++) {
            if (v == i) continue;
            for (int j = 0; j < C; j++) {
                if (dist[v][i][j] == INF) continue;
                int ncost = get_cost(j, dist[v][i][j]) + d[v];
                if (ncost < d[i]) {
                    d[i] = ncost;
                    Q.push(State(d[i], i));                    
                }
            }
        }
    }
    return -1;
}

void init()
{
    for (int i = 0; i < C; i++) {
        q[i].clear();
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < C; k++) {
                dist[i][j][k] = (i != j ? INF : 0);
            }
        }
    }

}

void warshall_floyd()
{
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int l = 0; l < C; l++) {
                    dist[i][j][l] = min(dist[i][j][l],
                                        dist[i][k][l] + dist[k][j][l]);
                }
            }
        }
    }
}

int main()
{
    int src, dst;
    while (cin >> N >> M >> C >> src >> dst, N) {
        init();
        src--; dst--;
        for (int i = 0; i < M; i++) {
            int a, b, c, d;
            cin >> a >> b >> d >> c;
            a--; b--; c--;
            dist[a][b][c] = min(dist[a][b][c], d);
            dist[b][a][c] = min(dist[b][a][c], d);
        }        

        warshall_floyd();
        vector<int> p(C);
        for (int i = 0; i < C; i++) {
            cin >> p[i];
        }       
        
        for (int i = 0; i < C; i++) {
            vector<int> r(p[i]);
            q[i].resize(p[i]+1, 0);
            for (int j = 1; j < p[i]; j++) {
                cin >> q[i][j];
            }            
            q[i][p[i]] = q[i][p[i]-1] + 1;
            
            for (int j = 0; j < p[i]; j++) {
                cin >> r[j];
                mc[i] = r[j];
            }
            
            cost[i][0] = 0;
            for (int j = 0; j < p[i]; j++) {
                for (int k = q[i][j]+1; k <= q[i][j+1]; k++) {
                    cost[i][k] = cost[i][k-1] + r[j];
                }
            }
        }
        cout << dijkstra(src, dst) << endl;
    }
    return 0;
}
