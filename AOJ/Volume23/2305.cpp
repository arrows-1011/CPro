#include <bits/stdc++.h>

using namespace std;

#define MAX_N 21
#define MAX_M 150001
#define INF (1<<29)
typedef long long ll;

double dp[MAX_N][MAX_M];

int main()
{
    int N;
    cin >> N;
    vector<double> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    fill(dp[0], dp[MAX_N], INF);
    dp[0][1] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = MAX_M-1; j >= 0; j--) {
            if (dp[i][j] == INF) continue;
            for (int k = 1; k <= MAX_M; k++) {
                ll nv = (ll)j * k; 
                if (nv >= MAX_M) break;
                dp[i+1][nv] = min(dp[i+1][nv],
                                  max(dp[i][j], abs(v[i]-nv) / v[i]));
            }

        }
    }
    double res = INF;
    for (int i = 0; i < MAX_M; i++) {
        res = min(res, dp[N][i]);
    }
    printf("%.15f\n", res);
    return 0;
}
