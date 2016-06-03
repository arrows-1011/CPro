#include <bits/stdc++.h>

using namespace std;

#define MAX 2010
typedef long long ll;
const ll MOD = (1e9) + 7;

ll dp[MAX][MAX];

ll extgcd(ll a, ll b, ll &x, ll &y)
{
    ll d = a;
    if (b != 0) {
	d = extgcd(b, a % b, y, x);
	y -= (a / b) * x;
    } else {
	x = 1; y = 0;
    }
    return d;
}

ll mod_inverse(ll a, ll m)
{
    ll x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}

int main()
{
    ll N, D, X;
    while (cin >> N >> D >> X, N) {
        ll res = 0, comb = 1;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= min(N, D); i++) {                        
            comb *= (D - i + 1) % MOD;
            comb %= MOD;
            comb *= mod_inverse(i, MOD);
            comb %= MOD;

            ll sum[MAX] = {};
            for (int j = 0; j <= N; j++) {
                sum[j] += dp[i-1][j];                
                if (j > 0) sum[j] += sum[j-1];
                sum[j] %= MOD;
            }

            for (int j = 0; j <= N; j++) {
                if (j > 0) dp[i][j] = sum[j-1];
                if (j - X >= 0) {
                    dp[i][j] += (-sum[j-X] + MOD) % MOD;
                }
                dp[i][j] %= MOD;
            }                
            res += dp[i][N] * comb;
            res %= MOD;
        }
        cout << res << endl;
    }
    return 0;
}

