#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 100000
#define INF (1<<29)
 
vector<int> G[MAX];
 
vector<int> bfs(int N)
{
    vector<int> d(N, INF);
    d[0] = 0;
     
    queue<int> Q;
    Q.push(0);
 
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        for (int i = 0; i < (int)G[v].size(); i++) {
            int to = G[v][i];
            if (d[v] + 1 < d[to]) {
                d[to] = d[v] + 1;
                Q.push(to);
            } 
        }
    }
    return d;
}

set<int> st, edges[MAX], edges2[MAX];

void erase(int v)
{
    for (auto &e: edges2[v]) {
        if (e != 0 && edges[e].count(v) > 0) {
            edges[e].erase(v);
            if (edges[e].size() == 0) {
                st.insert(e);
                erase(e);
            }
        }
    }
}

int main()
{
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> a(M), b(M);
    for (int i = 0; i < M; i++) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
 
    auto d = bfs(N);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (int)G[i].size(); j++) {
            int to = G[i][j];
            if (d[i] + 1 == d[to]) {
                edges[to].insert(i);
                edges2[i].insert(to);
            }
        }
    }
    
    int R;
    for (int i = 0; i < Q; i++) {
        cin >> R;
        R--;        
        int s = a[R], t = b[R];
        if (s != 0) {
            if (d[s] == d[t] + 1 && edges[s].count(t) > 0) {
                edges[s].erase(t);
            }
            if (st.count(s) == 0 && edges[s].size() == 0) {
                st.insert(s);
                erase(s);
            }   
        }
        if (t != 0) {                  
            if (d[t] == d[s] + 1 && edges[t].count(s) > 0) {
                edges[t].erase(s);
            }

            if (st.count(t) == 0 && edges[t].size() == 0) {
                st.insert(t);
                erase(t);
            }     
        }              
        cout << st.size() << endl;;
    }    
    return 0;
}
