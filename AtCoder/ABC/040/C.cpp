#include <bits/stdc++.h>

using namespace std;

#define INF (1e9)

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<int> dp(N+1, INF);
    dp[0] = 0;
    for (int i = 0; i < N-1; i++) {
        for (int j = 1; j <= 2; j++) {
            if (i + j >= N) continue;
            dp[i+j] = min(dp[i+j], dp[i] + abs(a[i] - a[i+j]));
        }
    }

    cout << dp[N-1] << endl;    
    return 0;
}
