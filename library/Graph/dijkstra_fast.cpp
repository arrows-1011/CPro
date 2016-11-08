/*
  O(E log V)
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int MAX_V = 100000;
constexpr int INF = (1 << 29);
using pii = pair<int, int>;

struct edge {
    int to, d;
};

int V,E;
int weight[MAX_V];
vector<edge> G[MAX_V];

void dijkstra(int s)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(pii(0, s));
    weight[s] = 0;
    while (!pq.empty()) {
	pii p = pq.top(); pq.pop();
	int v = p.second;
	if (weight[v] < p.first) continue;
	for (int i = 0; i < (int)G[v].size(); i++) {
	    edge &e = G[v][i];
	    if (weight[v] + e.d < weight[e.to]) {
		weight[e.to] = weight[v] + e.d;
		pq.push(pii(weight[e.to], e.to));
	    }
	}
    }
}

void init()
{
    for (int i = 0; i < MAX_V; i++) {
	G[i].clear();
	weight[i] = INF;
    }
}
