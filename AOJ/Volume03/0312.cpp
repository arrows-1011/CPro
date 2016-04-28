#include <bits/stdc++.h>

using namespace std;

#define INF LLONG_MAX
typedef long long ll;

int M, N;
vector<ll> tw, tt;
vector<ll> c, b;

void init()
{
    tw.resize(M+2); tt.resize(M+2);
    tw[0] = tt[0] = 0;
    tw[M+1] = tt[M+1] = INF;
    c.resize(N); b.resize(N);
}

int solve()
{
    int dp[1<<15];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    
    for (int i = 0; i < (1<<N); i++) {
        if (dp[i] == -1) continue;        
        for (int j = 0; j < N; j++) {
            if (i >> j & 1) continue;                        
            int ni = i | (1<<j);
            int p1 = upper_bound(tw.begin() + dp[i], tw.end(), c[j] + tw[dp[i]]) - (tw.begin()) - 1;
            int p2 = upper_bound(tt.begin() + dp[i], tt.end(), b[j] + tt[dp[i]]) - (tt.begin()) - 1;
            dp[ni] = max(dp[ni], min(p1, p2));
        }
    }

    return dp[(1<<N)-1];
}

int main()
{    
    cin >> M >> N;
    init();
    for (int i = 1; i <= M; i++) {
        cin >> tw[i] >> tt[i];
        tw[i] += tw[i-1];
        tt[i] += tt[i-1];
    }    
    for (int i = 0; i < N; i++) {
        cin >> c[i] >> b[i];
    }
    cout << solve() << endl;
    return 0;
}
