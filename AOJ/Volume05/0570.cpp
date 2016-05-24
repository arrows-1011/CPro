#include <bits/stdc++.h>

using namespace std;

#define MAX_N 501
#define MAX_M 501
typedef long long ll;
const ll MOD = 10000LL;

int M;
ll dp[MAX_N][MAX_M][10][2][3];

ll dfs(int idx, int m, int d, bool lt, int up, string &s)
{
    if (idx == (int)s.size()) {
        return (m == 0);
    }
    ll &res = dp[idx][m][d][lt][up];
    if (res != -1) return res;
    
    res = 0;    
    int num = s[idx] - '0';
    for (int i = 0; i < 10; i++) {
        int nup = -1;
        if (lt || i <= num) {
            if (up == 0 && d < i) {
                nup = 1;
            } else if (up == 1 && d > i) {
                nup = 0;
            } else if (up == 2) {
                if (d == 0) {
                    nup = 2;
                } else if (d > i) {
                    nup = 0;
                } else if (d < i) {
                    nup = 1;
                }
            }
            if (nup != -1) {
                res += dfs(idx + 1, (10*m + i) % M, i, lt || (i < num), nup, s);
            }            
            res %= MOD;
        }            
    }
    return res;
}

void sub(string &A)
{
    for (int i = (int)A.size()-1; i >= 0; i--) {
        int num = (A[i] - '0'); num--;
        if (num == -1) {
            A[i] = '9';
        } else {
            A[i] = num + '0';
            return;
        }
    }
}

int main()
{
    string A, B;
    cin >> A >> B >> M;

    sub(A);    
    memset(dp, -1, sizeof(dp));
    ll va = dfs(0, 0, 0, 0, 2, A);
    
    memset(dp, -1, sizeof(dp));    
    ll vb = dfs(0, 0, 0, 0, 2, B);

    cout << (vb - va + MOD) % MOD << endl;
    return 0;
}
