#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100
#define MAX_C 100001
#define INF (1<<29)
typedef pair<int, int> pii;

int m[MAX_N];
pii dp[2][MAX_C];

void set_m(vector<int> &p)
{
    for (int i = 0; i < (int)p.size(); i++) {    
        m[i] = ((p[i] - 1) / 1000 + 1) * 1000;
    }
}

void update(pii &a, pii &b)
{
    if (a.first < b.first) {
        a = b;
    } else if (a.first == b.first) {
        if (a.second > b.second) {
            a = b;
        }
    }
}

int main()
{
    int N;
    while (cin >> N, N) {
        vector<int> p(N);
        for (int i = 0; i < N; i++) {
            cin >> p[i];
        }
        
        set_m(p);
        
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < MAX_C; j++) {
                dp[i][j] = pii(-1, INF);
            }
        }
        
        dp[0][0] = pii(0, 0);
        for (int i = 0; i < N; i++) {
            int curr = (i & 1), next = !(i & 1);
            for (int j = 0; j < MAX_C; j++) {
                if (dp[curr][j].first == -1) continue;
                
                update(dp[next][j], dp[curr][j]);
                
                {
                    int pay = m[i];
                    int change = pay - p[i];                    

                    int _500 = (change / 500);
                    int nc = j + change - _500 * 500;                    
                    
                    pii ncost = pii(dp[curr][j].first + _500,
                                    dp[curr][j].second + p[i]);                    
                    
                    update(dp[next][nc], ncost);
                }
                
                {
                    int pp = p[i] % 1000;
                    if (pp > 500 || pp == 0) {
                        if (abs(pp - 500) <= j) {
                            int pay = m[i] + abs(pp - 500);
                            int change = pay - p[i];
                            int _500 = (change / 500);
                            int nc = j - abs(pp - 500) + change - _500 * 500;
                            
                            pii ncost = pii(dp[curr][j].first + _500,
                                            dp[curr][j].second + p[i]);                    
                    
                            update(dp[next][nc], ncost);
                        }
                    } 
                }
            }
            
            for (int j = 0; j < MAX_C; j++) {
                dp[curr][j] = pii(-1, INF);
            }
        }
        
        pii res = pii(-1, INF);
        for (int i = 0; i < MAX_C; i++) {
            update(res, dp[N&1][i]);            
        }
        cout << res.first << " " << res.second << endl;
    }
    return 0;
}
