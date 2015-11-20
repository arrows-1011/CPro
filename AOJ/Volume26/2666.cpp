#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 110
#define INF 1e9
 
struct Edge{
    int to,f;
    Edge(int to,int f) : to(to),f(f) {}
};
 
struct State{
    int v,d,e;
    State(int v,int d,int e) : v(v),d(d),e(e) {}
};
 
int d[MAX][MAX][1<<4];
 
int main(){
    int N,M,E,S,T,R,a,b,c;
    vector<Edge> G[MAX];
    cin >> N >> M >> E >> S >> T >> R;
    for(int i = 0 ; i < M ; i++){
        cin >> a >> b;
        G[a].push_back(Edge(b,-1));
        G[b].push_back(Edge(a,-1));
    }
    int bit = 0;
    vector<int> event(N,-1);
    for(int i = 0 ; i < E ; i++){
        cin >> a >> b >> c;
        G[a].push_back(Edge(b,i));
        G[b].push_back(Edge(a,i));
        event[c] = i;
        if(c == S) bit |= 1<<i;
    }
    fill(d[0][0],d[0][0]+MAX*MAX*(1<<4),INF);
    d[S][0][bit] = 0;
    bool ok = false;
    queue<State> Q; Q.push(State(S,0,bit));
    while(!Q.empty()){
        State s = Q.front(); Q.pop();
        int v = s.v,day = s.d,ev = s.e;
        if(v == T){
            ok = true;
            cout << d[v][day][ev] << endl;
            break;
        }
        int ncost = d[v][day][ev] + 1;
        if(ncost < d[S][0][ev]){
            d[S][0][ev] = ncost;
            Q.push(State(S,0,ev));
        }
        for(int i = 0 ; i < (int)G[v].size() ; i++){
            Edge e = G[v][i];
            if(day + 1 > R) continue;
            int nev = ev | (event[e.to] >= 0 ? 1<<event[e.to] : 0);
            if(e.f == -1 || (ev >> e.f & 1)){
                if(ncost < d[e.to][day+1][nev]){
                    d[e.to][day+1][nev] = ncost;
                    Q.push(State(e.to,day+1,nev));
                }
            }
        }
    }
    if(!ok) cout << -1 << endl;
    return 0;
}
