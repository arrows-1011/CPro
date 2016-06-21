#include <bits/stdc++.h>

using namespace std;

#define MAX 100000
#define INF (1e9)
typedef pair<int, int> pii;
typedef pair<int, pii> P;

struct edge {
    int u, v, c;
    
    edge () {}
    edge (int u, int v, int c) :
        u(u), v(v), c(c) {}

    bool operator < (const edge &e) const {
        return c > e.c;
    }
};

class Union_Find {
  public:
    int par[MAX], rank[MAX], size[MAX], gnum;
    
    Union_Find(int N) {
        gnum = N;
        for (int i = 0; i < N; i++) {
            par[i] = i;
            rank[i] = 0;
            size[i] = 1;
        }
    }

    int find(int x)
    {
        if (par[x] == x) {
            return x;
        }
        return par[x] = find(par[x]);
    }

    void unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y) return;
        
        if (rank[x] < rank[y]) {
            par[x] = y;
            size[y] += size[x];
        } else {
            par[y] = x;
            size[x] += size[y];
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
        gnum--;
    }

    bool same(int x, int y)
    {
        return (find(x) == find(y));
    }

    int get_size(int x)
    {
        return size[find(x)];
    }

    int groups()
    {
        return gnum;
    }
};

vector<edge> es;
vector<P> vec;
int Q, num[MAX];

void kruskal(int N)
{
    sort(es.begin(), es.end());
    Union_Find uf(N);         
    int idx = 0;
    for (int i = 0; i < (int)es.size(); i++) {
	edge e = es[i];
        while (idx < Q && vec[idx].first >= e.c) {
            int j = vec[idx].second.second;
            int v = vec[idx].second.first;
            num[j] = uf.get_size(v);
            idx++;
        }
	if (!uf.same(e.u, e.v)) {            
            uf.unite(e.u, e.v);          
        }
    }
    while (idx < Q) {
        int j = vec[idx].second.second;
        int v = vec[idx].second.first;
        num[j] = uf.get_size(v);
        idx++;
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, y;
        cin >> a >> b >> y;
        a--; b--;
        es.push_back(edge(a, b, y));        
    }   

    int v, w;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> v >> w; v--;        
        vec.push_back(P(w, pii(v, i)));
    }

    sort(vec.rbegin(), vec.rend());
    kruskal(N);
    for (int i = 0; i < Q; i++) {
        cout << num[i] << endl;
    }       
    return 0;
}
