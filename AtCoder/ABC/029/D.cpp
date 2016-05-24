#include <bits/stdc++.h>

using namespace std;

#define MAX_D 10
typedef long long ll;

ll dp[MAX_D][2][12];
vector<int> num;

ll dfs(int idx, bool lt, ll one)
{
    if (idx == (int)num.size()) {
        return one;
    }
    ll &res = dp[idx][lt][one];
    if (res != -1) return res;
    
    res = 0;
    for (int i = 0; i < 10; i++) {
        if (lt || i <= num[idx]) {
            res += dfs(idx + 1, lt || i < num[idx], one + (i == 1));
        }        
    }
    return res;
}

int main()
{
    int N;
    cin >> N;
    while (N > 0) {
        num.push_back(N % 10);
        N /= 10;
    }
    memset(dp, -1, sizeof(dp));
    reverse(num.begin(), num.end());
    cout << dfs(0, 0, 0) << endl;
    return 0;
}
