#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll n, res = 1145141919LL;
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        ll j = n / i;
        res = min(res, abs(i - j) + n - i * j);
    }
    cout << res << endl;
    return 0;
}

