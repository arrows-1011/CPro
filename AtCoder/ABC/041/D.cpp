#include <bits/stdc++.h>

using namespace std;

#define MAX 16
typedef long long ll;

int main()
{
    int N, M;
    cin >> N >> M;
    int x, y;
    vector<int> G[MAX];
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        x--; y--;
        G[y].push_back(x);
    }
    
    ll dp[1<<MAX] = {};
    dp[0] = 1;
    for (int i = 0; i < (1<<N); i++) {
        for (int j = 0; j < N; j++) {
            if (i >> j & 1) continue;
            bool ok = 1;
            for (int k = 0; k < (int)G[j].size(); k++) {
                if (!(i >> G[j][k] & 1)) {
                    ok = 0;
                    break;
                }
            }
            int ni = i | (1<<j);
            if (ok) dp[ni] += dp[i];
        }
    }
    cout << dp[(1<<N)-1] << endl;
    return 0;
}
