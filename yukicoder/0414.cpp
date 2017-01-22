#include <iostream>
#include <set>

using namespace std;

using ll = long long;

set<ll> prime_factor(ll n)
{
    set<ll> res;
    for (ll i = 2; i * i <= n; i++) {
	while (n % i == 0) {
	    res.insert(i);
	    n /= i;
	}
    }
    if (n != 1) res.insert(n);
    return res;
}

int main()
{
    ll N;
    cin >> N;
    
    auto pf = prime_factor(N);
    bool found = 0;
    for (auto& p : pf) {
        if (N % p == 0 && p != N) {
            found = 1;
            cout << p << " " << N / p << endl;
            break;
        }
    }
    if (!found) cout << 1 << " " << N << endl;
    return 0;
}
