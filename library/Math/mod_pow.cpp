#include <iostream>

using namespace std;

typedef long long ll;

ll mod_pow(ll x, ll n, ll mod)
{
    if (n == 0) return 1;
    ll res = mod_pow(x * x % mod, n / 2, mod);
    if (n & 1) res = res * x % mod;
    return res;
}
