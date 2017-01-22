#include <iostream>

using namespace std;

using ll = long long;

ll mod_pow(ll x, ll n, ll mod)
{
    if (n == 0) return 1;
    ll res = mod_pow(x * x % mod, n / 2, mod);
    if (n & 1) res = res * x % mod;
    return res;
}

int main()
{
    ll x, N, res = 0;
    cin >> x >> N;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        res += mod_pow(x, a, 1000003);
        res %= 1000003;
    }
    cout << res << endl;
    return 0;
}
