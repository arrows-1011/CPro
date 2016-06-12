#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = LLONG_MAX/4;

bool c(ll x, int idx, vector<ll> &B)
{    
    int N = B.size() / 2;
    int p1 = lower_bound(B.begin(), B.end(), x + B[idx]) - B.begin();
    if (p1 - idx > N) return 0;
    int p2 = lower_bound(B.begin(), B.end(), x + B[p1]) - B.begin();
    if (p2 - idx > N) return 0;
    int p3 = lower_bound(B.begin(), B.end(), x + B[p2]) - B.begin();    
    return (p3 - idx <= N) && (B[p3] - B[p2] >= x);
}

int main()
{
    int N;
    cin >> N;
    vector<ll> A(N), B(2*N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        B[i] = A[i] + (i > 0 ? B[i-1] : 0);
    }
    for (int i = 0; i < N; i++) {
        B[N+i] = B[N+i-1] + A[i];
    }
    ll res = 0;
    for (int i = 0; i < N; i++) {
        ll lb = 0, ub = INF;
        while (ub - lb > 1) {
            ll mid = (lb + ub) / 2;
            if (c(mid, i, B)) {
                lb = mid;
            } else {
                ub = mid;
            }
        }
        res = max(res, lb);
    }
    cout << res << endl;
    return 0;
}
