#include <bits/stdc++.h>

using namespace std;

#define INF (1LL<<55)
typedef long long ll;

bool c(ll x, int N, vector<ll> &H, vector<ll> &S)
{
    vector<ll> t(N);
    for (int i = 0; i < N; i++) {
        t[i] = (x - H[i]) / S[i];
    }
    sort(t.begin(), t.end());
    for (int i = 0; i < N; i++) {
        if (i > t[i]) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int N;
    cin >> N;
    vector<ll> H(N), S(N);
    ll l = 0, r = INF;
    for (int i = 0; i < N; i++) {
        cin >> H[i] >> S[i];
        l = max(l, H[i]);
    }
    
    while (r - l > 0) {
        ll mid = (l + r) / 2;
        if (c(mid, N, H, S)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << endl;
    return 0;
}
