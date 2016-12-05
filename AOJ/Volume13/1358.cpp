#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

constexpr int MAX_N = 50;
constexpr int MAX_C = 100;
constexpr int INF = (1 << 29);

vector<int> G[MAX_N], G2[MAX_N][3];
bool visited[MAX_N][MAX_C];

bool dfs(int curr, int goal, int rem)
{
    if (visited[curr][rem]) return 0;
    visited[curr][rem] = 1;
    
    if (rem == 0) {
        return (curr == goal);
    }    
    for (auto& next : G[curr]) {
        if (dfs(next, goal, rem - 1)) {
            return 1;
        }
    }
    return 0;
}

void solve(int N)
{    
    vector<int> d(N, INF);
    d[N - 1] = 0;

    bool update = 1;
    while (update) {
        update = 0;

        for (int i = 0; i < N; i++) {
            int cost = 0;
            for (int j = 0; j < 3; j++) {
                int mc = INF;
                for (auto& u : G2[i][j]) {
                    mc = min(mc, d[u]);
                }
                cost = max(cost, mc + 1);                
            }

            if (cost < d[i]) {
                d[i] = cost;
                update = 1;
            } 
        }            
    }
    
    if (d[0] == INF) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << d[0] << endl;
    }
}

int main()
{
    int N, M, a[3];
    cin >> N >> M >> a[0] >> a[1] >> a[2];
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v; u--; v--;
        G[u].emplace_back(v);
    }
    
    for (int i = 0; i < 3; i++) {
        for (int from = 0; from < N; from++) {
            for (int to = 0; to < N; to++) {
                if (from == to) continue;
                memset(visited, 0, sizeof(visited));
                if (dfs(from, to, a[i])) {
                    G2[from][i].emplace_back(to);
                }
            }
        }
    }       
    solve(N);
    return 0;
}
