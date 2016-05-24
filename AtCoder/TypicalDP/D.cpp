#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

double dp[2][210][110][110];

vector<int> get_num(ll x)
{
    const ll y[] = {2, 3, 5};
    vector<int> v(3, 0);    
    for (int i = 0; i < 3; i++) {
        while (x % y[i] == 0) {
            x /= y[i];
            v[i]++;
        }
    }
    if (x != 1) throw 0;
    return v;
}

void solve(ll N, ll D)
{
    vector<int> d;
    try {
        d = get_num(D);    
    } catch(...) {
        printf("%.10f\n", 0.0);
        return;
    }
        
    vector<int> n[6];
    for (int i = 0; i < 6; i++) {        
        n[i] = get_num(i + 1);
    }

    dp[0][0][0][0] = 1;    
    for (int i = 0; i < N; i++) {
        int curr = i & 1, next = (i + 1) & 1;
        for (int j = 0; j <= 200; j++) {
            for (int k = 0; k <= 100; k++) {
                for (int l = 0; l <= 100; l++) {
                    if (dp[curr][j][k][l] == 0) continue;
                    for (int m = 0; m < 6; m++) {
                        int nj = j + n[m][0], nk = k + n[m][1], nl = l + n[m][2];
                        dp[next][nj][nk][nl] += dp[curr][j][k][l] / 6.0;
                    }
                }
            }
        }
        
        for (int j = 0; j <= 200; j++) {
            for (int k = 0; k <= 100; k++) {
                for (int l = 0; l <= 100; l++) {
                    dp[curr][j][k][l] = 0;
                }
            }
        }        
    }

    double res = 0;
    for (int i = d[0]; i <= 200; i++) {
        for (int j = d[1]; j <= 100; j++) {
            for (int k = d[2]; k <= 100; k++) {
                res += dp[N&1][i][j][k];
            }
        }
    }
    printf("%.10f\n", res);
}

int main()
{
    ll N, D;
    cin >> N >> D;
    solve(N, D);
    return 0;
}
