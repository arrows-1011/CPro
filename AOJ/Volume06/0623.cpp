#include <bits/stdc++.h>

using namespace std;

#define MAX 100000
#define INF (1LL<<55)
typedef long long ll;
typedef pair<ll, ll> pll;

int main()
{
    ll N, M, K, S, P, Q;
    cin >> N >> M >> K >> S >> P >> Q;
    
    vector<ll> z(N, INF);
    queue<int> q;
    for (int i = 0; i < K; i++) {
        ll c;
        cin >> c; c--;
        z[c] = 0;
        q.push(c);
    }
    
    vector<int> G[MAX];
    for (int i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    
    while (!q.empty()) {
        int v = q.front(); q.pop();
        if (z[v] == S) continue;

        for (int i = 0; i < (int)G[v].size(); i++) {
            int to = G[v][i];
            if (z[v] + 1 < z[to]) {
                z[to] = z[v] + 1;
                q.push(to);
            }
        }
    }

    vector<ll> dist(N, INF);
    dist[0] = 0;
    
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push(pll(0, 0));

    while (!pq.empty()) {
        pll p = pq.top(); pq.pop();
        ll c = p.first, v = p.second;

        if (v == N-1) {
            cout << c << endl;
            break;
        }
        
        for (int i = 0; i < (int)G[v].size(); i++) {
            int to = G[v][i];
            if (z[to] == 0) continue;
            
            ll ncost = c;
            if (to != N-1) ncost += (z[to] == INF ? P : Q);
            if (ncost < dist[to]) {
                dist[to] = ncost;
                pq.push(pll(dist[to], to));
            }
        }
    }    
    return 0;
}
