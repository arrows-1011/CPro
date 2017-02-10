#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

constexpr int MAX_N = 2525210;
using ll = long long;

int main()
{
    ll N, P;
    cin >> N >> P;
    
    ll a;
    vector<ll> cnt(MAX_N);
    for (int i = 0; i < N; i++) {
        cin >> a;
        ll num = ceil((double)a / P);
        ++cnt[num];
    }
    
    ll res = 0;
    for (ll i = 0; i < MAX_N - 1; i++) {
        if (cnt[i] > 0) {
            res += i;
            if (cnt[i] > 1) {
                cnt[i + 1] += cnt[i] - 1;
            }                
        }
    }
    cout << res << endl;
    return 0;
}
