#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f(ll x)
{
    ll res = 0;
    while (x > 0) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

int main()
{
    ll N;
    cin >> N;
    vector<ll> res;
    for (ll i = 0; i < 500; i++) {
        ll x = N - i;
        if (N - x == f(x)) {
            res.push_back(x);
        }
    }
    N = res.size();
    cout << N << endl;
    for (int i = N-1; i >= 0; i--) {
        cout << res[i] << endl;
    }

    return 0;
}
