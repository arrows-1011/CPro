#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const ll MOD = ((1e9) + 7);
 
int dp[2][5050];
 
int main()
{
    int N, L;
    scanf("%d %d", &N, &L);
    vector<int> x(N), a(N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &x[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
 
    fill(dp[0], dp[0] + L, 1);    
    for (int i = 0; i < N; i++) {
        int curr = i & 1, next = !curr;
        for (int j = x[i]; j < L; j += a[i]) {
            if (j > 0) {
                dp[next][j] += dp[curr][j-1];
            } else {
                dp[next][j] = dp[curr][j];
            }
            dp[next][j] %= MOD;
            if (a[i] == 0) break;
        }
         
        for (int j = x[i]; j < L; j++) {
            dp[next][j+1] += dp[next][j];
            dp[next][j+1] %= MOD;
        }
        fill(dp[curr], dp[curr] + L, 0);
    }
    printf("%d\n", dp[N&1][L-1]);
    return 0;
}
