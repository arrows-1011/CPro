#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 1010
 
struct Edge{
    int to,cost;
    Edge(){}
    Edge(int to,int cost) :
        to(to),cost(cost) {}
};
 
vector<Edge> G[MAX_N];
vector<int> C;
 
int solve(int v){
    int res = 0;
    for(int i = 0 ; i < (int)G[v].size() ; i++){
        Edge e = G[v][i];
        if(C[e.to-1] > 0){
            res += e.cost;
        }else{
            res += min(e.cost,solve(e.to));
        }
    }
    return res;
}
 
int main(){
    int N,u,v,p;
    cin >> N; C.resize(N-1);
    for(int i = 0 ; i < N-1 ; i++){
        cin >> C[i];
    }
    for(int i = 0 ; i < N-1 ; i++){
        cin >> u >> v >> p;
        G[u].push_back(Edge(v,p));
    }
    cout << solve(0) << endl;
    return 0;
}
