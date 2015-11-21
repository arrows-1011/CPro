/*
  DAGの各辺 (u,v) について,u が v よりも先に位置するように並べることを,
  トポロジカルソートという.

  この辺の説明は,蟻本の(P89~P90)
  
  以下の制約が必要となる.
  グラフGがDAGである.
  グラフGに多重辺がない.
  グラフGに自己ループがない.
  
  O(V+E)
 */

#include <bits/stdc++.h>

using namespace std;

#define MAX_V 10010
typedef vector<int> Vec;

int V,E;
Vec G[MAX_V];

bool visit(int v,Vec &order,Vec &color){
    color[v] = 1;
    for(int i = 0 ; i < (int)G[v].size() ; i++){
        int to = G[v][i];
        if(color[to] == 2) continue;
        if(color[to] == 1) return false;
        if(!visit(to,order,color)) return false;
    }
    order.push_back(v);
    color[v] = 2;
    return true;
}

bool topologicalSort(Vec &order){
    Vec color(V,0);
    for(int i = 0 ; i < V ; i++){
        if(color[i] == 0 && !visit(i,order,color)){
            return false;
        }
    }
    reverse(order.begin(),order.end());
    return true;
}

int main(){
    int s,t;
    cin >> V >> E;
    for(int i = 0 ; i < E ; i++){
        cin >> s >> t;
        G[s].push_back(t);
    }
    Vec order;
    if(topologicalSort(order)){
        for(int i = 0 ; i < V ; i++){
            cout << order[i] << endl;
        }
    }
    return 0;
}
