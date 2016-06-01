#include <bits/stdc++.h>

using namespace std;

#define MAX_N 16
#define MAX_M 16

int M, N;
double P[MAX_M][MAX_N];
double dp[MAX_N][1<<MAX_M];

double solve(int n, int m)
{   
    double &res = dp[n][m];
    
    if (res != -1) {
        return res;
    }
    res = 0;

    for (int i = 0; i < M; i++) {
        if (!(m >> i & 1)) continue;
        double p = 1.0, q = 0.0;
        for (int j = n; j < N; j++) { 
            q += p * (1 - P[i][j]) * solve(j, m & ~(1<<i));
            p *= P[i][j];
        }
        q += p;
        res = max(res, q);
    }    
    return res;
}

int main()
{
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> P[i][j];
        }
    }
    fill(dp[0], dp[MAX_N], -1);
    printf("%.10f\n", solve(0, (1<<M)-1));
    return 0;
}
