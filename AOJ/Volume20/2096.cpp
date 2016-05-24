#include <bits/stdc++.h>

using namespace std;

#define MAX_V 150
#define INF (1LL<<55)
typedef long long ll;

struct Edge {
    int to;
    ll cap, rev;
    Edge(int to, ll cap, ll rev) :
        to(to), cap(cap), rev(rev) {}
};

vector<Edge> G[MAX_V];
ll level[MAX_V], iter[MAX_V];

void add_edge(int from, int to, ll cap)
{
    G[from].push_back(Edge(to, cap, G[to].size()));
    G[to].push_back(Edge(from, 0, G[from].size()-1));
}

void bfs(ll s)
{
    memset(level, -1, sizeof(level));
    queue<ll> Q;
    level[s] = 0;
    Q.push(s);
    while (!Q.empty()) {
	ll v = Q.front(); Q.pop();
	for (int i = 0; i < (int)G[v].size(); i++) {
	    Edge &e = G[v][i];
	    if (e.cap > 0 && level[e.to] < 0) {
		level[e.to] = level[v] + 1;
		Q.push(e.to);
	    }
	}
    }
}

ll dfs(int v, int t, ll f)
{
    if (v == t) return f;
    for (ll &i = iter[v]; i < (int)G[v].size(); i++) {
	Edge &e = G[v][i];
	if (e.cap > 0 && level[v] < level[e.to]) {
	    ll d = dfs(e.to, t, min(f, e.cap));
	    if (d > 0) {
		e.cap -= d;
		G[e.to][e.rev].cap += d;
		return d;
	    }
	}
    }
    return 0;
}

ll max_flow(int s, int t)
{
    ll flow = 0;
    for (;;) {
	bfs(s);
	if (level[t] < 0) return flow;
	memset(iter, 0, sizeof(iter));
	ll f;
	while ((f = dfs(s, t, INF)) > 0) {
	    flow += f;
	}
    }
}

void init()
{
    for (int i = 0; i < MAX_V; i++) {
        G[i].clear();
    }
}

int main()
{
    ll N, W;
    string in;
    map<string, int> mp = {
        {"Monday",    0},
        {"Tuesday",   1},
        {"Wednesday", 2},
        {"Thursday",  3},
        {"Friday",    4},
        {"Saturday",  5},
        {"Sunday",    6}
    };
        
    while (cin >> N >> W, N) {
        init();
        
        ll t, c, sum = 0;
        int S = N + 7, T = S + 1;
        for (int i = 0; i < N; i++) {
            cin >> t >> c;
            sum += t;
            add_edge(S, i, t);
            for (int j = 0; j < c; j++) {
                cin >> in;
                add_edge(i, N + mp[in], INF);
            }
        }
        for (int i = 0; i < 7; i++) {
            add_edge(N + i, T, W);
        }
        cout << (max_flow(S, T) >= sum ? "Yes" : "No") << endl;
    }
    return 0;
}

