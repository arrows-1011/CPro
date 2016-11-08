#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

constexpr int MAX_V = 10000;
using pii = pair<int, int>;

struct edge{
    int to, cost;
    edge(int to, int cost) : to{to}, cost{cost} {}
};

int V;
bool used[MAX_V];
vector<edge> G[MAX_V];

/*
  O(E log V)
  複数ケースがある場合vectorの初期化に注意
*/
int prim()
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(pii(0, 0));
    memset(used, false, sizeof(used));
    int res = 0;
  
    while (!pq.empty()) {
	pii p = pq.top(); pq.pop();
	int v = p.second;
	if (used[v]) continue;
	used[v] = true;
	res += p.first;
	for (int i = 0; i < (int)G[v].size(); i++) {
	    edge e = G[v][i];
	    pq.push(pii(e.cost, e.to));
	}
    }
    return res;
}

int main()
{
    int E,s,t,w;
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
	cin >> s >> t >> w;
	G[s].emplace_back(t, w);
	G[t].emplace_back(s, w);
    }
    cout << prim() << endl;
    return 0;
}
