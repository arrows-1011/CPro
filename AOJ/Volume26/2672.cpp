#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 1010
#define MAX 14
#define INF (1<<29)
typedef pair<int,int> pii;
 
struct Edge{
    int to,w;
    Edge(int to,int w) : to(to),w(w) {}
};
 
struct State{
    int d,v,S;
    State(int d,int v,int S) :
        d(d),v(v),S(S) {}
     
    bool operator < (const State &s)const{
        return d > s.d;
    }
};
 
int N,M,dist[MAX_N][MAX_N],d[MAX][1<<MAX];
vector<Edge> G[MAX_N],G2[MAX];
 
void dijkstra(int src){
    priority_queue<pii,vector<pii>,greater<pii> > Q;
    Q.push(pii(0,src));
    dist[src][src] = 0;
    while(!Q.empty()){
        pii p = Q.top(); Q.pop();
        int v = p.second;
        if(dist[src][v] < p.first) continue;
        for(int i = 0 ; i < (int)G[v].size() ; i++){
            Edge e = G[v][i];
            if(dist[src][v] + e.w < dist[src][e.to]){
                dist[src][e.to] = dist[src][v] + e.w;
                Q.push(pii(dist[src][e.to],e.to));
            }
        }
    }
}
 
int dijkstra2(int src,int n){
    priority_queue<State> Q;
    Q.push(State(0,src,1<<src));
    d[src][1<<src] = 0;
    while(!Q.empty()){
        State s = Q.top(); Q.pop();
        int v = s.v,S = s.S;
        if(d[v][S] < s.d) continue;
        if(S == (1<<n)-1) return d[v][S];
        for(int i = 0 ; i < (int)G2[v].size() ; i++){
            Edge e = G2[v][i];
            int nS = S;
            if(e.to & 1){
                nS |= 1<<e.to;
                if(d[v][S] + e.w < d[e.to][nS]){
                    d[e.to][nS] = d[v][S] + e.w;
                    Q.push(State(d[e.to][nS],e.to,nS));
                }
            }else{
                if(e.to != src){
                    if(S >> (e.to-1) & 1){
                        nS |= 1<<e.to;
                        if(d[v][S] + e.w < d[e.to][nS]){
                            d[e.to][nS] = d[v][S] + e.w;
                            Q.push(State(d[e.to][nS],e.to,nS));
                        }
                    }else{
                        if(d[v][S] + e.w < d[e.to][nS]){
                            d[e.to][nS] = d[v][S] + e.w;
                            Q.push(State(d[e.to][nS],e.to,nS));
                        }
                    }
                }else{
                    if(d[v][S] + e.w < d[e.to][nS]){
                        d[e.to][nS] = d[v][S] + e.w;
                        Q.push(State(d[e.to][nS],e.to,nS));
                    }
                }
            }
        }
    }
    return INF;
}
 
void init(){
    memset(d,1,sizeof(d));
    memset(dist,1,sizeof(dist));
    for(int i = 0 ; i < MAX_N ; i++){
        G[i].clear();
        if(i < MAX) G2[i].clear();
    }
}
 
int main(){
    int K,P,a,b,c,cnt = 0;
    cin >> N >> M >> K >> P; P--;
    init();
    for(int i = 0 ; i < M ; i++){
        cin >> a >> b >> c; a--; b--;
        G[a].push_back(Edge(b,c));
        G[b].push_back(Edge(a,c));
    }
    for(int i = 0 ; i < N ; i++){
        dijkstra(i);
    }
    vector<int> s(K),t(K);
    map<int,int> num;
    num[P] = cnt++;
    for(int i = 0 ; i < K ; i++){
        cin >> s[i] >> t[i];
        s[i]--; t[i]--;
        num[s[i]] = cnt++;
        num[t[i]] = cnt++;
    }
    map<int,int>::iterator it,it2;
    for(it = num.begin() ; it != num.end() ; ++it){
        for(it2 = num.begin() ; it2 != num.end() ; ++it2){
            int u = it->second,v = it2->second;
            int w = it->first,x = it2->first;
            if(w == x) continue;
            G2[u].push_back(Edge(v,dist[w][x]));
        }
    }
    int res = dijkstra2(0,cnt);
    if(res == INF){
        cout << "Cannot deliver" << endl;
    }else{
        cout << res << endl;
    }
    return 0;
}
