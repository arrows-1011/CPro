#include <bits/stdc++.h>

using namespace std;

#define MAX 20
#define MAX_V 500
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

bool inField(int y,int x,int H,int W){
    return (0 <= x && x < W && 0 <= y && y < H);
}

void init(){
    for(int i = 0 ; i < MAX_V ; i++){
        G[i].clear();
    }
}

int main(){
    int H,W,N;
    int r[MAX][MAX];
    cin >> N;
    for(int n = 0 ; n < N ; n++){
        int tcost = 0;
        init();
        cin >> W >> H;
        for(int i = 0 ; i < H ; i++){
            for(int j = 0 ; j < W ; j++){
                cin >> r[i][j];
                tcost += r[i][j];
            }
        }
        const int di[] = {0,-1,0,1};
        const int dj[] = {-1,0,1,0};
        int s = H*W,t = s+1;
        for(int i = 0 ; i < H ; i++){
            for(int j = 0 ; j < W ; j++){
                if((i+j)%2 == 0){
                    add_edge(s,i*W+j,r[i][j]);
                    for(int k = 0 ; k < 4 ; k++){
                        int ni = i + di[k];
                        int nj = j + dj[k];
                        if(inField(ni,nj,H,W)){
                            add_edge(i*W+j,ni*W+nj,INF);
                        }
                    }
                }else{
                    add_edge(i*W+j,t,r[i][j]);
                }
            }
        }
        cout << "Case " << n+1 << ": " << tcost - max_flow(s,t) << endl;
    }
    return 0;
}
