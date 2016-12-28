#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

ll solve(int N, int W, vector<int>& w)
{
    vector<int> sum(N + 1);
    sort(w.begin(), w.end());
    
    for (int i = 0; i < N; i++) {
        sum[i + 1] = sum[i] + w[i];
    }

    if (sum[N] <= W) {
        return 1;
    }
    
    ll res = 0;
    vector<ll> dp(W + 1);
    constexpr ll MOD = ((1e9) + 7);
    
    dp[0] = 1;
    for (int i = N - 1; i >= 0; i--) {
        for (int j = W - w[i]; j >= 0; j--) {
            dp[j + w[i]] += dp[j];
            dp[j + w[i]] %= MOD;
        }

        int wl = max(0, W - sum[i] - w[i] + 1);
        int wr = W - sum[i] - (i > 0 ? w[i - 1] : 0);
        for (int j = wl; j <= wr; j++) {
            res += dp[j];
            res %= MOD;
        }
    }
    return res;
}

int main()
{
    int N, W;
    cin >> N >> W;
    vector<int> w(N);
    for (int i = 0; i < N; i++) {
        cin >> w[i];
    }
    cout << solve(N, W, w) << endl;
    return 0;
}

