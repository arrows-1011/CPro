/*
  非負の重みを持つ無向の木の各頂点の高さを求める.
  ただし、各頂点について、そこから最も遠い葉までの距離を
  その頂点を根とした木の高さという.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define INF 1e9
typedef vector<int> Vec;
typedef pair<int, int> pii;

struct Edge {
    int to, cost;
    Edge(int to, int cost) :
	to(to), cost(cost) {}
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

int N;
Graph G;

Vec dijkstra(int s)
{
    Vec dist(N, INF);
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > Q;
    Q.push(pii(0, s));
    while (!Q.empty()) {
	pii p = Q.top(); Q.pop();
	int v = p.second;
	if (dist[v] < p.first) {
	    continue;
	}
	for (int i = 0; i < (int)G[v].size(); i++) {
	    Edge &e = G[v][i];
	    if (dist[v] + e.cost < dist[e.to]) {
		dist[e.to] = dist[v] + e.cost;
		Q.push(pii(dist[e.to], e.to));
	    }
	}
    }
    return dist;
}

int getFarthestPoint(int v)
{
    Vec vec = dijkstra(v);
    int resv = -1, max = -1;
    for (int i = 0; i < N; i++) {
	if (max < vec[i]) {
	    max = vec[i];
	    resv = i;
	}
    }
    return resv;
}

Vec getTreeHeight()
{
    int v1 = getFarthestPoint(0);
    int v2 = getFarthestPoint(v1);
    Vec d1 = dijkstra(v1), d2 = dijkstra(v2);
    Vec res(N);
    for (int i = 0; i < N; i++) {
	res[i] = max(d1[i], d2[i]);
    }
    return res;
}

int main()
{
    int a, b, c;
    cin >> N;
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
	cin >> a >> b >> c;
	G[a].push_back(Edge(b, c));
	G[b].push_back(Edge(a, c));
    }
    Vec height = getTreeHeight();
    for (int i = 0; i < N; i++) {
	cout << height[i] << endl;
    }
    return 0;
}
