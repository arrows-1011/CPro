/*
  複数テストケースの場合、vector<edge> G[MAX_V]の初期化
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

constexpr int MAX_V = 100;
constexpr int INF = (1 << 29);

struct edge {
    int to, cap, rev;
    edge(int to, int cap, int rev) :
        to{to}, cap{cap}, rev{rev} {}
};

vector<edge> G[MAX_V];
bool used[MAX_V];

void add_edge(int from, int to, int cap)
{
    G[from].emplace_back(to, cap, G[to].size());
    G[to].emplace_back(from, 0, G[from].size() - 1);
}

int dfs(int v, int t, int f)
{
    if (v == t) return f;
    used[v] = true;
    for (int i = 0; i < (int)G[v].size(); i++) {
	edge& e = G[v][i];
	if (!used[e.to] && e.cap > 0) {
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
	memset(used, false, sizeof(used));
	int f = dfs(s, t, INF);
	if (f == 0) return flow;
	flow += f;
    }
}
