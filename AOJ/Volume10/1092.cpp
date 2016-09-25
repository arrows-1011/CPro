#include <bits/stdc++.h>

using namespace std;

#define MAX 334
typedef pair<int, int> pii;

int main()
{
    int s, d, m;
    while (cin >> s >> d >> m) {
        vector<pii> v[s];
        for (int i = 0; i < s; i++) {
            int k, w, p;
            cin >> k;
            for (int j = 0; j < k; j++) {
                cin >> w >> p;
                v[i].push_back(pii(w, p));
            }
        }

        int dp[MAX], f;
        memset(dp, -1, sizeof(dp));
        dp[m] = 0;
        for (int i = 0; i < d; i++) {
            cin >> f;
            for (int j = 0; j < (int)v[f].size(); j++) {
                for (int k = 0; k <= m; k++) {
                    if (dp[k] == -1) continue;
                    int nm = k - v[f][j].second;
                    if (nm >= 0) {
                        dp[nm] = max(dp[nm], dp[k] + v[f][j].first);
                    }
                }
            }   
        }
        
        int idx = m;
        for (int i = m-1; i >= 0; i--) {
            if (dp[i] > dp[idx]) {
                idx = i;
            }
        }
        cout << dp[idx] << " " << m - idx << endl;
    }
    return 0;
}
