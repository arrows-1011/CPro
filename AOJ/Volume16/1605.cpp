#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

constexpr int MAX = 252;

class Union_Find {
  public:
    int par[MAX], rank[MAX], gnum;
    
    Union_Find(int N) {
        for (int i = 0; i < N; i++) {
            par[i] = i;
            rank[i] = 0;
        }
        gnum = N;
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
        } else {
            par[y] = x;
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
};

struct edge {
    int u, v, cost, col;
    edge() {}
    edge(int u, int v, int cost, int col) :
        u{u}, v{v}, cost{cost}, col{col} {}

    bool operator < (const edge& e) const {        
        if (cost != e.cost) {
            return cost < e.cost;
        }
        return col > e.col;
    }
};

int N, M, K;

void add_cost(int x, vector<edge>& es)
{
    for (auto& e : es) {
        if (e.col == 0) {
            e.cost += x;
        }
    }
}

pair<int, int> kruskal(int x, vector<edge> es)
{
    add_cost(x, es);
    sort(es.begin(), es.end());    
    
    Union_Find uf(N);
    int res = 0, k = 0;    
    for (const auto& e : es) {
        if (!uf.same(e.u, e.v)) {
            uf.unite(e.u, e.v);     
            res += e.cost;
            k += (e.col == 0);
        }
    }
    return make_pair(res, k);
}

bool unconnected(const vector<edge>& es)
{
    Union_Find uf(N);
    for (const auto& e : es) {
        if (!uf.same(e.u, e.v)) {
            uf.unite(e.u, e.v);
        }
    }
    return (uf.gnum != 1);
}

void solve(const vector<edge>& es)
{
    constexpr int INF = 252521;    
    int l = -INF, r = INF;

    if (unconnected(es)) {
        cout << -1 << endl;
        return;
    }
    
    while (r - l > 1) {
        int mid = (l + r) / 2;            
        auto mst = kruskal(mid, es);

        if (mst.second < K) {
            r = mid;
        } else {
            l = mid;
        }
    }

    auto ll = kruskal(l, es);
    auto rr = kruskal(r, es);

    if (rr.second <= K && K <= ll.second) {
        cout << rr.first - r * K << endl;
    } else {
        cout << -1 << endl;
    }
}

int main()
{
    while (cin >> N >> M >> K, N) {
        vector<edge> es;
        for (int i = 0; i < M; i++) {
            int u, v, w;
            char l;
            cin >> u >> v >> w >> l;
            u--; v--;
            es.emplace_back(u, v, w, l - 'A');
        }
        solve(es);       
    }
    return 0;
}
