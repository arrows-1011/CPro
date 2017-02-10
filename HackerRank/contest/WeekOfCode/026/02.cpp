#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

vector<ll> divisor(ll n)
{
    vector<ll> res;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.emplace_back(i);
            if (i != n / i) res.emplace_back(n / i);
        }
    }
    return res;
}

ll digit_sum(ll x)
{
    ll sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main()
{
    ll N;
    cin >> N;
    
    auto d = divisor(N);
    sort(d.begin(), d.end());
    
    ll res = 0, mv = -1;
    for (const auto& v : d) {
        int ds = digit_sum(v);
        if (ds > res) {
            res = ds;
            mv = v;
        }
    }
    cout << mv << endl;
    return 0;
}
