#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cstring>

using namespace std;

constexpr int MAX_V = 2525;
constexpr int INF = (1 << 29);

struct edge {
    int to, cap, rev;
    edge(int to, int cap, int rev) :
        to{to}, cap{cap}, rev{rev} {}
};

vector<edge> G[MAX_V];
int level[MAX_V], iter[MAX_V];

void add_edge(int from, int to, int cap)
{
    G[from].emplace_back(to, cap, G[to].size());
    G[to].emplace_back(from, 0, G[from].size() - 1);
}

void bfs(int s)
{
    memset(level, -1, sizeof(level));
    queue<int> Q;
    level[s] = 0;
    Q.push(s);
    while (!Q.empty()) {
	int v = Q.front(); Q.pop();
	for (int i = 0; i < (int)G[v].size(); i++) {
	    edge& e = G[v][i];
	    if (e.cap > 0 && level[e.to] < 0) {
		level[e.to] = level[v] + 1;
		Q.push(e.to);
	    }
	}
    }
}

int dfs(int v, int t, int f)
{
    if (v == t) return f;
    for (int& i = iter[v]; i < (int)G[v].size(); i++) {
	edge& e = G[v][i];
	if (e.cap > 0 && level[v] < level[e.to]) {
	    int d = dfs(e.to, t, min(f, e.cap));
	    if (d > 0) {
		e.cap -= d;
		G[e.to][e.rev].cap += d;
		return d;
	    }
	}
    }
    return 0;
}

int max_flow(int s, int t)
{
    int flow = 0;
    for (;;) {
	bfs(s);
	if (level[t] < 0) return flow;
	memset(iter, 0, sizeof(iter));
	int f;
	while ((f = dfs(s, t, INF)) > 0) {
	    flow += f;
	}
    }
}

int main()
{
    int N, n = 0;
    cin >> N;
    map<pair<int, int>, int> mp;
    vector<int> a(N), b(N), c(N), d(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        if (mp.count(make_pair(a[i], b[i])) == 0) {
            mp[make_pair(a[i], b[i])] = n++;
        }
        if (mp.count(make_pair(c[i], d[i])) == 0) {
            mp[make_pair(c[i], d[i])] = n++;
        }
    }
    
    int S = n + N + 1, T = S + 1;
    for (int i = 0; i < N; i++) {
        add_edge(S, i, 1);
        add_edge(i, N + mp[make_pair(a[i], b[i])], 1);
        add_edge(i, N + mp[make_pair(c[i], d[i])], 1);
    }

    for (int i = 0; i < n; i++) {
        add_edge(i + N, T, 1);
    }
    
    cout << (max_flow(S, T) == N ? "YES" : "NO") << endl;
    return 0;
}
