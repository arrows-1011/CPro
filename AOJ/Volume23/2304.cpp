#include <bits/stdc++.h>

using namespace std;

#define MAX_V 334
#define INF 1e9

struct Edge{
    int to,cap,rev;
    Edge(int to,int cap,int rev) :
        to(to),cap(cap),rev(rev) {}
};

vector<Edge> G[MAX_V];
int level[MAX_V],iter[MAX_V];

void add_edge(int from,int to,int cap){
    G[from].push_back(Edge(to,cap,G[to].size()));
    G[to].push_back(Edge(from,0,G[from].size()-1));
}

void bfs(int s){
    memset(level,-1,sizeof(level));
    queue<int> Q;
    level[s] = 0;
    Q.push(s);
    while(!Q.empty()){
        int v = Q.front(); Q.pop();
        for(int i = 0 ; i < (int)G[v].size() ; i++){
            Edge &e = G[v][i];
            if(e.cap > 0 && level[e.to] < 0){
                level[e.to] = level[v] + 1;
                Q.push(e.to);
            }
        }
    }
}

int dfs(int v,int t,int f){
    if(v == t) return f;
    for(int &i = iter[v] ; i < (int)G[v].size() ; i++){
        Edge &e = G[v][i];
        if(e.cap > 0 && level[v] < level[e.to]){
            int d = dfs(e.to,t,min(f,e.cap));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s,int t){
    int flow = 0;
    for(;;){
        bfs(s);
        if(level[t] < 0) return flow;
        memset(iter,0,sizeof(iter));
        int f;
        while((f = dfs(s,t,INF)) > 0){
            flow += f;
        }
    }
}

int main(){
    int N,M,S,T,a,b;
    int edge[MAX_V][MAX_V];
    memset(edge,-1,sizeof(edge));
    cin >> N >> M;
    for(int i = 0 ; i < M ; i++){
        cin >> a >> b;
        a--; b--;
        add_edge(a,b,1);
        add_edge(b,a,1);
        edge[b][a] = i;
    }
    cin >> S >> T; S--; T--;
    int res = max_flow(S,T);
    cout << res << endl;
    vector<int> v;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < (int)G[i].size() ; j++){
            int to = G[i][j].to;
            if(edge[i][to] == -1) continue;
            if(G[i][j].cap == 0){
                v.push_back(edge[i][to]);
            }
            edge[i][to] = -1;
        }
    }
    sort(v.begin(),v.end());
    int size = v.size();
    cout << size << endl;
    for(int i = 0 ; i < size ; i++){
        cout << v[i]+1 << endl;
    }
    return 0;
}
