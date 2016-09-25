#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll R, C, Q;
    while (cin >> R >> C >> Q, R) {
        vector<ll> a(Q), b(Q), order(Q);
        for (int i = 0; i < Q; i++) {
            cin >> a[i] >> b[i] >> order[i];
        }
        vector<bool> used_a(R, 0), used_b(C, 0);
        ll r = 0, c = 0, res = 0;
        for (int i = Q-1; i >= 0; i--) {
            if (a[i] == 0) { // 行
                if (!used_a[b[i]]) {
                    used_a[b[i]] = 1;
                    r++;
                    if (order[i] == 1) {
                        res += C - c;
                    }
                }
            } else {         // 列
                if (!used_b[b[i]]) {
                    used_b[b[i]] = 1;
                    c++;
                    if (order[i] == 1) {
                        res += R - r;
                    }
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
