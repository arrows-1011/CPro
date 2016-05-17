#include <bits/stdc++.h>

using namespace std;

#define MAX 100000
#define MOD 1000000007
typedef long long ll;

vector<int> G[MAX];
ll dp[MAX][2];

// color -> white is 0, black is 1
ll dfs(int v, int prev, int color)
{
    if (color != -1 &&
        dp[v][color] != -1) return dp[v][color];

    ll w = 1, b = (color <= 0);
    for (int i = 0; i < (int)G[v].size(); i++) {
        int to = G[v][i];
        if (to == prev) continue;
        w = (w * dfs(to, v, 0)) % MOD;
        b = (b * dfs(to, v, 1)) % MOD;
    }
    return (dp[v][color] = (w + b) % MOD);
}

int main()
{
    int N, a, b;
    cin >> N;
    for (int i = 0; i < N-1; i++) {
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, -1, -1) << endl;
    return 0;
}
