#include <bits/stdc++.h>

using namespace std;

#define MAX_P 234567
typedef long long ll;
const ll MOD = ((1e9) + 7);

ll fact[MAX_P]; 

ll extgcd(ll a, ll b, ll &x, ll &y)
{
    ll d = a;
    if (b != 0) {
	d = extgcd(b, a%b, y, x);
	y -= (a / b) * x;
    } else {
	x = 1; y = 0;
    }
    return d;
}

ll mod_inverse(ll a, ll m)
{
    ll x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}

ll mod_fact(ll n, ll p, ll &e)
{
    e = 0;
    if (n == 0) return 1LL;
    ll res = mod_fact(n/p, p, e);
    e += n/p;
    if (n / p % 2 != 0) return res * (p - fact[n % p]) % p;
    return res * fact[n % p] % p;
}

ll mod_comb(ll n, ll k, ll p)
{
    if (n < 0 || k < 0 || n < k) return 0LL;
    ll e1, e2, e3;
    ll a1 = mod_fact(n, p, e1), a2 = mod_fact(k, p, e2), a3 = mod_fact(n-k, p, e3);
    if (e1 > e2 + e3) return 0LL;
    return a1 * mod_inverse(a2 * a3 % p,p) % p;
}

void make_table()
{
    fact[0] = 1;
    for (ll i = 1; i < MAX_P; i++) {
        fact[i] = fact[i-1] * i;
        fact[i] %= MOD;
    }
}

int main()
{
    make_table();
    
    ll H, W, A, B;
    cin >> H >> W >> A >> B;
    ll res = 0;
    for (int i = 0; i < H - A; i++) {
        res += mod_comb(i + B - 1, B - 1, MOD) *
               mod_comb((H - i) + (W - B) - 2, W - B - 1, MOD);
        res %= MOD;        
    }
    cout << res << endl;
    return 0;
}
