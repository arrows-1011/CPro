#include <bits/stdc++.h>
 
using namespace std;
 
#define INF (1<<29)
 
int N, M;
vector<int> s, d;
int dp[110][1<<15];
int cost[1<<15];
 
int calc(int S, int D)
{
    return abs(cost[S] - D);
}
 
int solve(int m, int S)
{
    if (m == M) return 0;
   
    int &res = dp[m][S];
    if (res != -1) return res;
   
    res = INF;
    res = min(res, solve(m + 1, S) + calc(S, d[m]));    
    for (int i = 0; i < N; i++) {
        if (S >> i & 1) continue;
        res = min(res, solve(m, S|(1<<i)));    
    }
    return res;
}
 
void calc_cost()
{
    for (int i = 0; i < (1<<N); i++) {
        cost[i] = 0;
        for (int j = 0; j < N; j++) {
            if (i >> j & 1) {
                cost[i] += s[j];
            }
        }
    }
}
 
int main()
{
    while (cin >> N >> M, (N | M)) {
        s.clear(); s.resize(N);
        d.clear(); d.resize(M);
 
        for (int i = 0; i < N; i++) {
            cin >> s[i];
        }
 
        for (int i = 0; i < M; i++) {
            cin >> d[i];
        }
 
        sort(d.begin(), d.end());
     
        calc_cost();
        memset(dp, -1, sizeof(dp));
        cout << solve(0, 0) << endl;
    }
    return 0;
}
