/*
  最小カット
 */

#include <bits/stdc++.h>

using namespace std;

#define MAX_V 555
#define INF 1e9

struct edge {
    int to, cap, rev;
    edge(int to, int cap, int rev) :
        to(to), cap(cap), rev(rev) {}
};

vector<edge> G[MAX_V];
int level[MAX_V], iter[MAX_V];

void add_edge(int from, int to, int cap)
{
    G[from].push_back(edge(to, cap, G[to].size()));
    G[to].push_back(edge(from, 0, G[from].size()-1));
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
	    edge &e = G[v][i];
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
    for (int &i = iter[v]; i < (int)G[v].size(); i++) {
	edge &e = G[v][i];
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

void init()
{
    for (int i = 0; i < MAX_V; i++) {
        G[i].clear();
    }
}

int main()
{
    int Tc, W, H;
    cin >> Tc;
    for (int t = 0; t < Tc; t++) {
        init();
        cin >> W >> H;
        vector<vector<int>> r(H, vector<int>(W));
        
        int sum = 0;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> r[i][j];
                sum += r[i][j];
            }
        }
        
        const int di[] = {-1, +0, +1, +0};
        const int dj[] = {+0, -1, +0, +1};
        
        int S = H * W, T = S + 1;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if ((i + j) % 2 == 0) {
                    add_edge(S, i * W + j, r[i][j]);
                    for (int k = 0; k < 4; k++) {
                        int ni = i + di[k];
                        int nj = j + dj[k];
                        if (0 <= ni && ni < H && 0 <= nj && nj < W) {
                            add_edge(i * W + j, ni * W + nj, INF);
                        }
                    }
                } else {
                    add_edge(i * W + j, T, r[i][j]);
                }
            }
        }
        cout << "Case " << t + 1 << ": " << sum - max_flow(S, T) << endl;
    }
    return 0;
}
