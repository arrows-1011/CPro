#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<ll, ll> prime_factor(ll n)
{
    map<ll, ll> res;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            res[i]++;
            n /= i;
        }
    }
    if (n != 1) res[n]++;
    return res;
}

int main()
{
    ll L;
    while (cin >> L, L) {
        map<ll, ll> p = prime_factor(L);
        ll res = 1;
        for (auto &x: p) {
            ll n = x.second + 1;
            res *= (n * n - (n - 1) * (n - 1));
        }
        cout << (res + 1) / 2 << endl;
    }
    return 0;
}
