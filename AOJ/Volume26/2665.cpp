#include <bits/stdc++.h>

using namespace std;

#define MAX 5050
typedef long long ll;
const ll MOD = ((1e9) + 7);

int dp[MAX][MAX];

int main()
{
    int N, L;
    cin >> N >> L;
    vector<int> x(N), a(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i]; 
    }
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < L; i++) {
        dp[0][i] = 1;
    }

    for (int i = 0; i < N; i++) {        
        for (int j = x[i]; j < L; j += a[i]) {
            if (j > 0) {
                dp[i+1][j] += dp[i][j-1];
            } else {
                dp[i+1][j] = dp[i][j];
            }
            dp[i+1][j] %= MOD;
            if (a[i] == 0) break;
        }
        
        for (int j = x[i]; j < L; j++) {
            dp[i+1][j+1] += dp[i+1][j];
            dp[i+1][j+1] %= MOD;
        }      
    }
    
    cout << dp[N][L-1] << endl;
    return 0;
}
