#include <bits/stdc++.h>

using namespace std;

#define MAX_N 10010
#define MAX_D 101
typedef long long ll;

const ll MOD = 1000000007LL;

string N;
int D;
ll dp[MAX_N][MAX_D][2];

ll dfs(int idx, int d, bool lt)
{
    if (idx == (int)N.size()) {
        return (d == 0);
    }

    ll &res = dp[idx][d][lt];
    if (res != -1) return res;
    
    res = 0;
    int num = N[idx] - '0';
    for (int i = 0; i < 10; i++) {
        if (lt || i <= num) {
            res += dfs(idx + 1, (d + i) % D, lt || i < num) % MOD;
        }
    }
    return res % MOD;
}

int main()
{
    cin >> D >> N;
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 0, 0) - 1 << endl;    
    return 0;
}
