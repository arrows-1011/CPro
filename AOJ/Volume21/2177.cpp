#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll get_num(ll p, ll idx)
{
    vector<int> v;
    while (p > 0) {
        v.push_back(p%10);
        p /= 10;
    }
    reverse(v.begin(), v.end());
    return v[idx];
}

ll get_digit(ll p)
{
    ll res = 0;
    while (p > 0) {
        p /= 10;
        res++;
    }
    return res;
}

int main()
{
    ll dig[11] = {0};
    for (int i = 1; i < 11; i++) {
        dig[i] = (ll)(i)*(9*pow(10, i-1));
        dig[i] += dig[i-1];
    }

    ll N, K;
    while (cin >> N >> K, N) {
        ll j = -1;
        for (int i = 0; i < 11; i++) {
            if (N <= dig[i]) {
                j = i;
                break;
            }
        }
        ll n = (N - (dig[j-1] + 1));
        ll p = pow(10, j-1) + n/j;        
        ll idx = n % j;        
        for (int i = 0; i < K; i++) {
            cout << get_num(p, idx);
            idx++;
            if (idx == get_digit(p)) {
                idx = 0;
                p++;   
            }
        }
        cout << endl;
    }
    return 0;
}
