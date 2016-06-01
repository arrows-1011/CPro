#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX_N = (1<<18)-1;

vector<ll> x, dat[MAX_N];

void init(int k, int l, int r)
{
    if (r - l == 1) {
        dat[k].push_back(x[l]);
    } else {
        int lch = k * 2 + 1, rch = k * 2 + 2;
        init(lch, l, (l + r) / 2);
        init(rch, (l + r) / 2, r);
        dat[k].resize(r - l);

        merge(dat[lch].begin(), dat[lch].end(),
              dat[rch].begin(), dat[rch].end(),
              dat[k].begin());
    }
}

int query(int i, int j, ll x, int k, int l, int r)
{
    if (j <= l || r <= i) {
        return 0;
    } else if (i <= l && r <= j) {
        return upper_bound(dat[k].begin(), dat[k].end(), x) - dat[k].begin();
    } else {
        int lc = query(i, j, x, k * 2 + 1, l, (l + r) / 2);
        int rc = query(i, j, x, k * 2 + 2, (l + r) / 2, r);
        return lc + rc;
    }
}

int main()
{
    ll D, Q, l, r, e;
    scanf("%lld", &D);
    x.resize(D);
    for (int i = 0; i < D; i++) {
        scanf("%lld", &x[i]);
    }    
    
    init(0, 0, D);
    
    scanf("%lld", &Q);
    while (Q--) {
        scanf("%lld %lld %lld", &l, &r, &e);
        l--; r--;
        ll a = min(x[l], x[r]) - e, b = max(x[l], x[r]) + e;        
        printf("%lld\n", query(l, r+1, a-1, 0, 0, D) +
                         (r - l + 1) - query(l, r+1, b, 0, 0, D));
    }
    return 0;
}

