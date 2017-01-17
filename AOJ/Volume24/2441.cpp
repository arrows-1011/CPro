#include <iostream>

using namespace std;

using ll = long long;

ll sum(ll l, ll r, ll len)
{
    ll f = r / 3 - l / 3;
    ll b = r / 5 - l / 5;
    ll fb = r / 15 - l / 15;
    ll other = ((r - l) - (f + b - fb)) * len;
    return other + (f + b - 2 * fb) * 4 + fb * 8;
}

ll c(ll x)
{
    ll p = 1, len = 1;
    ll res = 0;
    while (p * 10 <= x) {
        res += sum(p - 1, p * 10 - 1, len);
        len++;
        p *= 10;
    }
    res += sum(p - 1, x - 1, len);
    return res;
}

int main()
{
    ll n;
    cin >> n;

    ll l = 0, r = n + 1;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (c(mid) < n) {
            l = mid;
        } else {
            r = mid;
        }
    }

    string s;
    for (ll i = l; i < l + 100; i++) {
        if (i % 15 == 0) {
            s += "FizzBuzz";
        } else if (i % 3 == 0) {
            s += "Fizz";
        } else if (i % 5 == 0) {
            s += "Buzz";
        } else {
            s += to_string(i);
        }
    }
    cout << s.substr(n - c(l) - 1, 20) << endl;
    return 0;
}
