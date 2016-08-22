#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll calc(ll x)
{
    ll res = 1;
    for (ll i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            res *= i;
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x != 1) res *= x;
    return res;
}

int main()
{
    ll p, q;
    cin >> p >> q;
    p = q / __gcd(p, q);
    cout << calc(p) << endl;
    return 0;
}
