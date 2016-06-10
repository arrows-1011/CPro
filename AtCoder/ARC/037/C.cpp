#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<ll> a(N), b(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll lv = 1, rv = LLONG_MAX/2;
    while (rv - lv > 1) {
        ll mv = (lv + rv) / 2;
        ll sum = 0;
        for (int i = 0; i < N; i++) {
            int l = -1, r = N;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (a[i] * b[mid] < mv) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            sum += r;
        }
        if (sum < K) {
            lv = mv;
        } else {
            rv = mv;
        }        
    }
    cout << lv << endl;
    return 0;
}
