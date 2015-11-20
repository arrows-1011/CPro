#include <iostream>
#include <cstdio>

using namespace std;

#define MAX 1001
#define INF 9999999
 
int sta_c[MAX+1][MAX+1],sta_t[MAX+1][MAX+1],cc[MAX],tt[MAX];
int n,m,a,b,c,t,k,p,q,r,mc,mt,nc,nt;
bool visit_c[MAX],visit_t[MAX];
 
int dijkstra(int s,int g,int ct){
    fill(cc,cc+MAX,INF); fill(visit_c,visit_c+MAX,false);
    fill(tt,tt+MAX,INF); fill(visit_t,visit_t+MAX,false);
     
    tt[s] = cc[s] = 0;
    while(true){
        mt = mc = INF;
        for(int i = 1 ; i <= m ; i++){
            if(cc[i] < mc && !visit_c[i]){
                mc = cc[i];
                nc = i;
            }
            if(tt[i] < mt && !visit_t[i]){
                mt = tt[i];
                nt = i;
            }
        }
         
        if(mc == INF && !ct) break;
        if(mt == INF && ct) break;
         
        visit_c[nc] = visit_t[nt] = true;
         
        for(int j = 1 ; j <= m ; j++){
            if(sta_c[nc][j]+cc[nc] < cc[j] && sta_c[nc][j] != INF){
                cc[j] = sta_c[nc][j]+cc[nc];
            }
            if(sta_t[nt][j]+tt[nt] < tt[j] && sta_t[nt][j] != INF){
                tt[j] = sta_t[nt][j]+tt[nt];
            }
        }
    }
    if(ct) return tt[g];
    return cc[g];
}
 
int main(){
    while(cin >> n >> m , n+m){
        fill(sta_c[0],sta_c[MAX],INF);
        fill(sta_t[0],sta_t[MAX],INF);
        while(n--){
            cin >> a >> b >> c >> t;
             
            sta_t[a][b] = sta_t[b][a] = t;
            sta_c[a][b] = sta_c[b][a] = c;
        }
        cin >> k;
        while(k--){
            cin >> p >> q >> r;
            cout << dijkstra(p,q,r) << endl;
        }
    }
    return 0;
}
