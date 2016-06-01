#include <bits/stdc++.h>

using namespace std;

#define MAX_V 514
#define INF (1<<29)

struct Edge {
    int to, cap, cost, rev;
    Edge(int to, int cap, int cost, int rev) :
        to(to), cap(cap), cost(cost), rev(rev) {}
};

int V;
vector<Edge> G[MAX_V];
int dist[MAX_V], prevv[MAX_V], preve[MAX_V];

void add_edge(int from, int to, int cap, int cost)
{
    G[from].push_back(Edge(to, cap, cost, G[to].size()));
    G[to].push_back(Edge(from, 0, -cost, G[from].size()-1));
}

int min_cost_flow(int s, int t, int f)
{
    int res = 0;
    while (f > 0) {
	fill(dist, dist + V, INF);
	dist[s] = 0;
	bool update = true;
	while (update) {
	    update = false;
	    for (int v = 0; v < V; v++) {
		if (dist[v] == INF) continue;
		for (int i = 0; i < (int)G[v].size(); i++) {
		    Edge &e = G[v][i];
		    if (e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
                        dist[e.to] = dist[v] + e.cost;
			prevv[e.to] = v;
			preve[e.to] = i;
			update = true;
		    }
		}
	    }
	}
	if (dist[t] == INF) return -1;
	int d = f;
	for (int v = t; v != s; v = prevv[v]) {
            d = min(d, G[prevv[v]][preve[v]].cap);
	}
        f -= d;
	res += d * dist[t];
	for (int v = t; v != s; v = prevv[v]) {
	    Edge &e = G[prevv[v]][preve[v]];            
	    e.cap -= d;
	    G[v][e.rev].cap += d;
        }
    }
    return res;
}

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> W(N, vector<int>(N)), E(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> W[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> E[i][j];
        }
    }
    
    int sum = 0;
    vector<vector<char>> F(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> F[i][j];
            if (F[i][j] == 'o') {
                sum += E[i][j];
            }
        }
    }

    int S = 2 * N, T = S + 1;
    V = T + 1;
    for (int i = 0; i < N; i++) {
        add_edge(S, i, 1, 0);
        add_edge(N+i, T, 1, 0);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (F[i][j] == 'o') {
                add_edge(i, j + N, 1, -E[i][j]);
            } else {
                add_edge(i, j + N, 1, W[i][j]);
            }
        }
    }
    
    cout << min_cost_flow(S, T, N) + sum << endl;
    vector<int> r, c, op;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (int)G[i].size(); j++) {
            int k = G[i][j].to - N;
            if (G[i][j].cap == 0 && F[i][k] == '.' && G[i][j].to < S) {
                r.push_back(i+1); c.push_back(k+1); op.push_back(0);
            }
            if (G[i][j].cap > 0 && F[i][k] == 'o' && G[i][j].to < S) {
                r.push_back(i+1); c.push_back(k+1); op.push_back(1);
            }
        }
    }

    cout << r.size() << endl;
    for (int i = 0; i < (int)r.size(); i++) {
        cout << r[i] << " " << c[i] << " ";
        cout << (op[i] == 0 ? "write" : "erase") << endl;
    }    
    return 0;
}
