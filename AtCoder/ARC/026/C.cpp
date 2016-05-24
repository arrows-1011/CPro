#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 210001
#define INF LLONG_MAX/4
typedef long long ll;
 
struct P {
    int l, r;
    ll c;
  
    P(){}
    P(int l, int r, ll c) : l(l), r(r), c(c) {}
 
    bool operator < (const P &p) const {
        if (l != p.l) {
            return l < p.l;
        } else if (r != p.r) {
            return r > p.r;
        } 
        return c < p.c;
    }
};
 
const int MAX_N = (1<<18);
 
ll n, dat[2*MAX_N-1];
 
void init(ll n_)
{
    n = 1;
    while (n < n_) n *= 2LL;
  
    for (int i = 0; i < 2*n-1; i++) {
        dat[i] = INF;
    }
}
 
void update(ll k, ll a)
{
    k += n - 1;
    dat[k] = a;
  
    while (k > 0) {
        k = (k - 1) / 2;
        dat[k] = min(dat[k*2+1], dat[k*2+2]);
    }
}
 
ll query(int a, int b, int k, int l, int r)
{
    if (r <= a || b <= l) return INF;
  
    if (a <= l && r <= b) return dat[k];
    else {
        ll vl = query(a, b, k*2+1, l, (l+r)/2);
        ll vr = query(a, b, k*2+2, (l+r)/2, r);
        return min(vl, vr);
    }
}
 
ll dp[MAX];
 
int main()
{
    int N, L;
    cin >> N >> L;
    vector<P> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].l >> v[i].r >> v[i].c;
    }
 
    init(L+1);
    sort(v.begin(), v.end());
 
    fill(dp, dp+MAX, INF);
  
    dp[0] = 0;
    update(0, 0);
    for (int i = 0; i < N; i++) {
        P p = v[i];
        ll cost = min(dp[p.r], query(p.l, p.r+1, 0, 0, n) + p.c);
        dp[p.r] = cost;
        update(p.r, cost);
    }
    ll res = INF;
    for (int i = MAX-1; i >= L; i--) {
        res = min(res, dp[i]);
    }
    cout << res << endl;
    return 0;
}
