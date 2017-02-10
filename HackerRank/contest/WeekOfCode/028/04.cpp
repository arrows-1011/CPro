#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

using ll = long long;
constexpr ll MAX = 110000;

class Union_Find {
  public:
    ll par[MAX], rank[MAX], sz[MAX], gnum;
    
    Union_Find(ll N) {
        gnum = N;
        for (ll i = 0; i < N; i++) {
            par[i] = i;
            rank[i] = 0;
            sz[i] = 1;
        }
    }

    ll find(ll x)
    {
        if (par[x] == x) {
            return x;
        }
        return par[x] = find(par[x]);
    }

    void unite(ll x, ll y)
    {
        x = find(x);
        y = find(y);
        if (x == y) return;
        
        if (rank[x] < rank[y]) {
            par[x] = y;
            sz[y] += sz[x];
        } else {
            par[y] = x;
            sz[x] += sz[y];
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
        gnum--;
    }

    bool same(ll x, ll y)
    {
        return (find(x) == find(y));
    }

    ll size(ll x)
    {
        return sz[find(x)];
    }
};

int main()
{
    ll Q;
    vector<ll> p(MAX + 1), q(MAX + 1);
    for (ll i = 1; i <= MAX; i++) {
        q[i] = p[i] = i * (i + 1);        
        q[i] += q[i - 1];
    }    
    
    cin >> Q;
    while (Q--) {
        ll N, M;
        cin >> N >> M;
        Union_Find uf(N);
        for (ll i = 0; i < M; i++) {
            ll a, b;
            cin >> a >> b; a--; b--;
            uf.unite(a, b);
        }
        
        ll res = 0, sum = 0, m = 0;
        vector<pair<ll, ll>> s;
        set<ll> used;
        for (ll i = 0; i < N; i++) {
            ll par = uf.find(i);
            if (used.count(par) == 0) {
                used.insert(par);
                res += q[uf.size(i) - 1];                
                sum += p[uf.size(i) - 1];
                m += uf.size(i) - 1;
                s.emplace_back(p[uf.size(i) - 1], uf.size(i) - 1);
            }
        }

        sort(s.rbegin(), s.rend());
        res += (M - m) * sum;
        for (ll i = 1; i < (ll)s.size(); i++) {
            s[i].first += s[i - 1].first;
            res += s[i - 1].first * s[i].second;
        }
        cout << res << endl;
    }        
    return 0;
}
