/*
  O(V^2)
*/

#include <iostream>
#include <vector>

using namespace std;

#define INF 1e9
#define MAX_V 1000

int cost[MAX_V][MAX_V];  //cost[u][v]は辺e=(u,v)のコスト(存在しない場合はINF)
int d[MAX_V];            //頂点sからの最短距離
bool used[MAX_V];        //すでに使われたかのフラグ
int V;                   //頂点数
int prevv[MAX_V];         //最短路の直前の頂点

//始点sから各頂点への最短距離を求める
void dijkstra(int s)
{
    for (int i = 0; i < V; i++) {
	d[i] = INF;
	used[i] = false;
	prevv[i] = -1;
    }
    d[s] = 0;
  
    while (true) {
	int v = -1;
	for (int u = 0; u < V; u++) {
	    if (!used[u] && (v == -1 || d[u] < d[v])) {
		v = u;
	    }
	}
	if (v == -1) {
            break;
        }
	used[v] = true;
	for (int u = 0; u < V; u++) {
	    if (d[u] > d[v] + cost[v][u]) {
		d[u] = d[v] + cost[v][u];
		prevv[u] = v;
	    }
	}
    }
}

//頂点tへの最短路
vector<int> get_path(int t)
{
    vector<int> path;
    for (; t != -1 ; t = prevv[t]) {
	path.push_back(t);
    }
    reverse(path.begin(), path.end());
    return path;
}
