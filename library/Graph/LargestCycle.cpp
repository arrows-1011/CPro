#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int MAX_V = 5000;

int V, E, res;
vector<int> G[MAX_V];
int num[MAX_V], visited[MAX_V];

void dfs(int v, int c)
{
    visited[v] = 0; num[v] = c;
    for (int i = 0; i < (int)G[v].size(); i++) {
	int to = G[v][i];
	if (visited[to] == -1) {
	    dfs(to, c + 1);
	} else if(visited[to] == 0) {
	    res = max(res, num[v] - num[to] + 1);
	}
    }
    visited[v] = 1;
}

int getLargestCycle()
{
    res = 0;
    memset(num, -1, sizeof(num));
    memset(visited, -1, sizeof(visited));
    for (int i = 0; i < V; i++) {
	if (visited[i] == -1) {
	    dfs(i, 1);
	}
    }
    return (res >= 3 ? res : 0);
}
