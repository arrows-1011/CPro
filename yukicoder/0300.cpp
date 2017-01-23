#include <iostream>
#include <map>

using namespace std;

using ll = long long;

map<ll, ll> prime_factor(ll n)
{
    map<ll, ll> res;
    for (ll i = 2; i * i <= n; i++) {
	while (n % i == 0) {
	    ++res[i];
	    n /= i;
	}
    }
    if (n != 1) res[n] = 1;
    return res;
}

int main()
{
    ll X;
    cin >> X;
    auto pf = prime_factor(X);
    ll res = 1;
    for (auto& p : pf) {
        if (p.second & 1) {
            res *= p.first;
        }
    }
    cout << res << endl;
    return 0;
}
