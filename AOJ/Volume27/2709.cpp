#include <bits/stdc++.h>

using namespace std;

#define INF (1<<29)

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<int> D(M), dm(N, -1);
    for (int i = 0; i < M; i++) {
        cin >> D[i]; D[i]--;
        dm[D[i]] = 1<<i;
    }
    
    vector<vector<int>> v(N, vector<int>(K));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            cin >> v[i][j];
            v[i][j]--;
        }
    }
    
    int dp[1<<16];
    fill(dp, dp + (1<<16), INF);
    dp[(1<<M)-1] = 0;

    queue<int> Q;
    Q.push((1<<M)-1);

    while (!Q.empty()) {
        int S = Q.front(); Q.pop();
        if (dp[S] == INF) continue;
        for (int i = 0; i < K; i++) {
            int nS = 0;
            for (int j = 0; j < M; j++) {
                if (!(S >> j & 1)) continue;
                int nj = v[D[j]][i];
                if (dm[nj] >= 0) {
                    nS |= dm[nj];
                }                
            }
            if (dp[S] + 1 < dp[nS]) {
                dp[nS] = dp[S] + 1;
                Q.push(nS);
            }           
        }
    }
    cout << dp[0] << endl;
    return 0;
}
