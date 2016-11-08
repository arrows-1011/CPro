/*
  V回以上のupdateがあれば負の閉路が存在する。
*/

#include <iostream>

using namespace std;

constexpr int MAX_V = 1000;
constexpr int MAX_E = 2000;
constexpr int INF = (1 << 29);

struct edge {
    int from, to, cost;
};

int V, E, d[MAX_V];
edge es[MAX_E];

bool find_negative_loop(int s)
{
    int cnt = 0;
    for (int i = 0; i < V; i++) {
	d[i] = INF;
    }
    d[s] = 0;
    while (true) {
	bool update = false;
	cnt++;
	for (int i = 0; i < E; i++) {
	    edge e = es[i];
	    if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
		d[e.to] = d[e.from] + e.cost;
		if (cnt == V) {
                    return true;
                }
		update = true;
	    }
	}
	if (!update) {
            break;
        }
    }
    return false;
}

int main()
{
    int r;
    cin >> V >> E >> r;
    for (int i = 0; i < E; i++) {
	cin >> es[i].from >> es[i].to >> es[i].cost;
    }
    if (find_negative_loop(r)) {
	cout << "NEGATIVE CYCLE" << endl;
    } else {
	for (int i = 0; i < V; i++) {
	    if (d[i] == INF) {
		cout << "INF" << endl;
	    } else {
		cout << d[i] << endl;
	    }
	}
    }
    return 0;
}
