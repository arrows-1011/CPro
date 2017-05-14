#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 100000;
constexpr int INF = (1 << 29);

int N, M, w[MAX_N], point;
bool visited[MAX_N], used[MAX_N];
vector<int> G[MAX_N];

bool dfs(int curr, int prev)
{
    if (visited[curr]) return 1;
    visited[curr] = 1;
    
    bool reach = 0;
    for (int next : G[curr]) {
        if (next == prev) continue;                
        reach |= dfs(next, curr);
    }

    if (reach) {
        used[curr] = 1;
        point += w[curr];
    }
    return reach;
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d", &w[i]);
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    
    dfs(0, -1);
    
    using pii = pair<int, int>;
    priority_queue<pii> pq;
    pq.push(pii(0, 0));
    
    vector<int> d(N, -1);
    d[0] = 0;
    
    while (!pq.empty()) {
        pii p = pq.top(); pq.pop();
        int cost, curr;
        tie(cost, curr) = p;

        if (cost < d[curr]) continue;
        for (int next : G[curr]) {
            if (d[next] != -1) continue;
            
            d[next] = cost + (used[next] ? 0 : w[next]);
            pq.push(pii(d[next], next));
        }
    }
    
    point += *max_element(d.begin(), d.end());
    printf("%d\n", point + (!used[0] ? w[0] : 0));
    return 0;
}
