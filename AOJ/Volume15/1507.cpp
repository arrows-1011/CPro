#include <bits/stdc++.h>

using namespace std;

#define MAX 252521

class Union_Find {
  public:
    int par[MAX], rnk[MAX], sz[MAX], gnum;
    
    Union_Find(int N) {
        gnum = N;
        for (int i = 0; i < N; i++) {
            par[i] = i;
            rnk[i] = 0;
            sz[i] = 1;
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
        
        if (rnk[x] < rnk[y]) {
            par[x] = y;
            sz[y] += sz[x];
        } else {
            par[y] = x;
            sz[x] += sz[y];
            if (rnk[x] == rnk[y]) {
                rnk[x]++;
            }
        }
        gnum--;
    }

    bool same(int x, int y)
    {
        return (find(x) == find(y));
    }

    int size(int x)
    {
        return sz[find(x)];
    }

    int groups()
    {
        return gnum;
    }
};

struct edge {
    int u, v, cost;    
};

bool comp(const edge& a, const edge& b)
{
    return a.cost < b.cost;
}

using ll = long long;

edge es[MAX];

ll solve(int N)
{
    Union_Find uf(N);
    sort(es, es + N - 1, comp);

    ll res = 0;
    for (int i = 0; i < N - 1; i++) {
        edge& e = es[i];
        if (!uf.same(e.u, e.v)) {
            res += (ll)uf.size(e.u) * uf.size(e.v) * e.cost;
            uf.unite(e.u, e.v);
        }
    }
    return res;
}

int main()
{
    int N, a, b, c;
    cin >> N;    
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b >> c;
        es[i] = {a, b, c};
    }
    cout << solve(N) << endl;
    return 0;
}
