/*
  有向グラフの閉路判定
  O(V + E)
*/

#include <bits/stdc++.h>

using namespace std;

#define MAX_V 100

int V,E;
bool found;
vector<int> G[MAX_V];  //複数ケースがある場合、初期化に注意.
int visited[MAX_V];

void dfs(int v){
    visited[v] = 0;
    for(int i = 0 ; i < (int)G[v].size() ; i++){
	int to = G[v][i];
	if(visited[to] == -1){
	    dfs(to);
	}else if(visited[to] == 0){
	    found = true;
	    return;
	}
    }
    visited[v] = 1;
}

void solve(){
    found = false;
    memset(visited,-1,sizeof(visited));
    for(int i = 0 ; i < V ; i++){
	if(visited[i] == -1){
	    dfs(i);
	}
    }
    cout << found << endl;
}

int main(){
    int s,t;
    cin >> V >> E;
    for(int i = 0 ; i < E ; i++){
	cin >> s >> t;
	G[s].push_back(t);
    }
    solve();
    return 0;
}
