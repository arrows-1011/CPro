#include <bits/stdc++.h>

using namespace std;

#define MAX 1010
#define MAX_M 101

int dp[MAX_M][MAX];

int main()
{
    int LIMIT, N, M, X;
    string name;
    while (cin >> LIMIT >> N >> M >> X, LIMIT) {
        vector<int> c(N), s(N);
        for (int i = 0; i < N; i++) {
            cin >> name >> c[i] >> s[i];
        }
        int max_s[MAX];
        fill(max_s, max_s + MAX, -1);
        for (int i = 0; i < N; i++) {
            max_s[c[i]] = max(max_s[c[i]], s[i]);
            for (int j = i + 1; j < N; j++) {
                max_s[c[i] + c[j]] = max(max_s[c[i] + c[j]], s[i] + s[j]);
            }
        }
        for (int i = 0; i < LIMIT; i++) {
            max_s[i+1] = max(max_s[i+1], max_s[i]);
        }
        vector<int> sc(M), ss(M);
        for (int i = 0; i < M; i++) {
            cin >> name >> sc[i] >> ss[i];
        }
        for (int i = 0; i <= M; i++) {
            for (int j = 0; j <= LIMIT; j++) {
                dp[i][j] = -1;
            }
        }
        dp[0][0] = 0;
        for (int i = 0; i < M; i++) {
            for (int j = M-1; j >= 0; j--) {
                for (int k = LIMIT-sc[i]; k >= 0; k--) {
                    if (dp[j][k] == -1) continue;
                    int nk = k + sc[i];
                    if (nk <= LIMIT) {
                        dp[j+1][nk] = max(dp[j+1][nk], dp[j][k] + ss[i]);
                    }
                }
            }
        }
        
        int res = 0;
        for (int i = 0; i <= LIMIT; i++) {
            if (max_s[i] == -1) continue;
            for (int j = X; j <= M; j++) {
                if (dp[j][LIMIT-i] == -1) continue;
                res = max(res, max_s[i] + dp[j][LIMIT-i]);                   
            }
        }
        cout << res << endl;
    }
    return 0;
}
