/*
  最小辺カバー
 */

#include <bits/stdc++.h>

using namespace std;

#define MAX_V 1010

int V;
vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];

void add_edge(int u, int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}

bool dfs(int v)
{
    used[v] = 1;
    for (int i = 0; i < (int)G[v].size(); i++) {
	int u = G[v][i], w = match[u];
	if (w < 0 || (!used[w] && dfs(w))) {
	    match[v] = u;
	    match[u] = v;
	    return 1;
	}
    }
    return 0;
}

int bipartite_matching()
{
    int res = 0;
    memset(match, -1, sizeof(match));
    for (int v = 0; v < V; v++) {
	if (match[v] < 0) {
	    memset(used, 0, sizeof(used));
	    if (dfs(v)) {
                res++;
            }
	}
    }
    return res;
}

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    V = N * N;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (a[i] >= a[j]) {
                add_edge(i, j + N);
            }
        }
    }

    cout << N - bipartite_matching() << endl;        
    return 0;
}
