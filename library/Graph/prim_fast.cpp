#include <bits/stdc++.h>

using namespace std;

#define MAX_V 10000
#define INF 1e9
typedef pair<int,int> pii;

struct edge{
    int to,cost;
};

int V;
bool used[MAX_V];
vector<edge> G[MAX_V];

/*
  O(E log V)
  複数ケースがある場合vectorの初期化に注意
*/
int prim(){
    priority_queue<pii,vector<pii>,greater<pii> > Q;
    Q.push(pii(0,0));
    memset(used,false,sizeof(used));
    int res = 0;
  
    while(!Q.empty()){
	pii p = Q.top(); Q.pop();
	int v = p.second;
	if(used[v]) continue;
	used[v] = true;
	res += p.first;
	for(int i = 0 ; i < (int)G[v].size() ; i++){
	    edge e = G[v][i];
	    Q.push(pii(e.cost,e.to));
	}
    }
    return res;
}

int main(){
    int E,s,t,w;
    cin >> V >> E;
    for(int i = 0 ; i < E ; i++){
	cin >> s >> t >> w;
	G[s].push_back((edge){t,w});
	G[t].push_back((edge){s,w});
    }
    cout << prim() << endl;
    return 0;
}
