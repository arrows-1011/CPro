#include <bits/stdc++.h>

using namespace std;

#define MAX_D 20
#define MAX_F 20
typedef long long ll;

ll dp[MAX_D][2][MAX_F][2];

ll dfs(int idx, bool lt, int forbit, bool used, string &s)
{
    if (idx == (int)s.size()) {
        return forbit;
    }
    ll &res = dp[idx][lt][forbit][used];
    if (res != -1) return res;
    res = 0;
    int num = s[idx] - '0';    
    for (int i = 0; i < 10; i++) {
        if (lt || i <= num) {
            bool n = (i == 4 || i == 9);
            int nforbit = forbit + (!used && n);
            res += dfs(idx + 1, lt || i < num, nforbit, used || n, s);
        }
    }
    return res;
}

int main()
{
    ll A, B;
    cin >> A >> B; A--;
    string a = to_string(A), b = to_string(B);
    memset(dp, -1, sizeof(dp));
    ll va = dfs(0, 0, 0, 0, a);
    memset(dp, -1, sizeof(dp));
    ll vb = dfs(0, 0, 0, 0, b);
    cout << vb - va << endl;
    return 0;
}
