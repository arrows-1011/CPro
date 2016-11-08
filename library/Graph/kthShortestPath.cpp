#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int INF = (1 << 29);

struct Edge {
    int from, to, cost;
    Edge() {}
    Edge(int from, int to, int cost) :
        from{from}, to{to}, cost{cost} {}

    bool operator < (const Edge& e) const {
        return cost > e.cost;
    }
};

using Edges = vector<Edge>;
using Graph = vector<Edges>;

int k_shortestPath(const Graph &G, int s, int t, int k) {
    const int n = G.size();

    Graph h(n); // make reverse graph
    for (int i = 0; i < n; i++) {
        for (auto& e : G[i]) {
            h[e.to].emplace_back(e.to, e.from, e.cost);
        }
    }
    
    vector<int> d(n, INF); d[t] = 0;    // make potential
    vector<int> p(n, -1);               // using backward dijkstra
    priority_queue<Edge> pq; pq.push(Edge(t, t, 0));
    while (!pq.empty()) {
	Edge e = pq.top(); pq.pop();
	if (p[e.to] >= 0) continue;
	p[e.to] = e.from;
        for (auto& f : h[e.to]) {
            if (e.cost + f.cost < d[f.to]) {
                d[f.to] = e.cost + f.cost;
                pq.push(Edge(f.from, f.to, e.cost + f.cost));                
            }
        }
    }
    int l = 0; // forward dijkstra-like method
    priority_queue<Edge> pq2; pq2.push(Edge(-1, s, 0));
    while (!pq2.empty()) {
	Edge e = pq2.top(); pq2.pop();
	if (e.to == t && ++l == k) return e.cost + d[s];
	for (auto& f : G[e.to]) {
	    pq2.push(Edge(f.from, f.to, e.cost + f.cost - d[f.from] + d[f.to]));            
        }
    }
    return -1; // not found
}
