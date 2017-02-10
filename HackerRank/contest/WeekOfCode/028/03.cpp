#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
constexpr ll MOD = ((1e9) + 7);

int c(char ch)
{
    return ch - '0';
}

void add(ll& l, ll r)
{
    l += r;
    l %= MOD;
}

int main()
{
    int N;
    string s;
    cin >> N >> s;
    vector<vector<ll>> dp(N + 1, vector<ll>(8));
    
    for (int i = 0; i < N; i++) {
        int v = c(s[i]);
        dp[i + 1][v % 8]++;
        for (int j = 0; j < 8; j++) {
            if (dp[i][j] > 0) {
                int nj = (j * 10 + v) % 8;
                add(dp[i + 1][j], dp[i][j]);
                add(dp[i + 1][nj], dp[i][j]);
            }
        }
    }
    cout << dp[N][0] % MOD << endl;
    return 0;
}
