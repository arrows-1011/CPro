#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 500
#define INF (1<<29)
 
struct Edge {
    int to, cost, c;
    Edge (int to, int cost, int c) :
        to(to), cost(cost), c(c) {}
};
 
int main()
{
    int M, D, N, K;
    while (cin >> M >> N >> K >> D, M) {
        vector<Edge> G[MAX];
        vector<int> cake(M);
        for (int i = 0; i < M; i++) {
            cin >> cake[i];
        }
        int idx = 0, c;
        string a, b;
        map<string, int> mp;
        for (int i = 0; i < D; i++) {
            cin >> a >> b >> c;
            if (!mp.count(a)) mp[a] = idx++;
            if (!mp.count(b)) mp[b] = idx++;
            if (a[0] == 'C') {
                G[mp[b]].push_back(Edge(mp[a], c, a[1]-'1'));             
            } else {
                G[mp[b]].push_back(Edge(mp[a], c, -1));           
            }
            if (b[0] == 'C') {
                G[mp[a]].push_back(Edge(mp[b], c, b[1]-'1'));
            } else {
                G[mp[a]].push_back(Edge(mp[b], c, -1));           
            }
        }
        int s = mp["H"], t = mp["D"];
        int d[MAX][1<<6];
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < (1<<6); j++) {
                d[i][j] = INF;
            }
        }
        d[s][0] = 0;
        bool update = 1;
        while (update) {
            update = 0;
            for (int i = 0; i < (int)mp.size(); i++) {
                for (int j = 0; j < (int)G[i].size(); j++) {
                    Edge e = G[i][j];
                    for (int S = (1<<6)-1; S >= 0; S--) {
                        int ncost = d[i][S];
                        if (ncost == INF) continue;
                        
                        ncost += e.cost * K;
                        
                        if (e.c == -1) {
                            if (ncost < d[e.to][S]) { 
                                d[e.to][S] = ncost;
                                update = 1;
                            }
                        } else {
                            if (S >> e.c & 1) continue;
                            ncost -= cake[e.c];
                            if (ncost < d[e.to][S|(1<<e.c)]) {
                                d[e.to][S|(1<<e.c)] = ncost;
                                update = 1;
                            }
                        }
                    }
                }
            }
        }
        int res = INF;
        for (int i = 0; i < (1<<6); i++) {
            res = min(res, d[t][i]);
        }
        cout << res << endl;
    }
    return 0;
}
