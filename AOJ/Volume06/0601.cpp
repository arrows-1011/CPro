#include <bits/stdc++.h>

using namespace std;

#define MAX 100000
#define INF (1LL<<58)
typedef long long ll;

struct Edge {
    ll to, cost;
    Edge (ll to, ll cost) : to(to), cost(cost) {}
};

struct State {
    ll c, v, h;

    State (ll c, ll v, ll h) :
        c(c), v(v), h(h) {}

    bool operator < (const State &st) const {
        if (c != st.c) {
            return c > st.c; 
        } else {
            return h < st.h;
        }
    }       
};

int main()
{
    ll N, M, X;
    cin >> N >> M >> X;
    vector<ll> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    
    ll a, b, c;
    vector<Edge> G[MAX];
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c; a--; b--;
        G[a].push_back(Edge(b, c));
        G[b].push_back(Edge(a, c));
    }

    vector<ll> dist(N, INF);
    dist[0] = 0;
    
    priority_queue<State> Q;
    Q.push(State(0, 0, X));


    ll res = INF;    
    while (!Q.empty()) {
        State s = Q.top(); Q.pop();
        ll v = s.v, h = s.h;
        
        if (v == N-1) {
            res = min(res, s.c + (H[v] - h));
            continue;
        }

        for (int i = 0; i < (int)G[v].size(); i++) {
            Edge &e = G[v][i];
            ll nh = h - e.cost;

            if (nh < 0) {
                if (h - nh > H[v]) continue;
                if (s.c + e.cost - nh < dist[e.to]) {
                    dist[e.to] = s.c + e.cost - nh;
                    Q.push(State(dist[e.to], e.to, 0));
                }                
            } else {
                if (nh > H[e.to]) {
                    if (h - (nh - H[e.to]) < 0) continue;
                    if (s.c + (nh - H[e.to]) + e.cost < dist[e.to]) {
                        dist[e.to] = s.c + (nh - H[e.to]) + e.cost;
                        Q.push(State(dist[e.to], e.to, H[e.to]));
                    } 
                } else {                    
                    if (s.c + e.cost < dist[e.to]) {
                        dist[e.to] = s.c + e.cost;
                        Q.push(State(dist[e.to], e.to, nh));
                    }
                }
            }
        }
    }
    
    cout << (res != INF ? res : -1) << endl;
    return 0;
}
