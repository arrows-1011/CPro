#include <bits/stdc++.h>
 
using namespace std;
 
int C, D, W, X;
int E[16][31], F[16][31];
int memo[31][51][6];
const int dx[] = {-1, 1};
 
int solve(int d, int w, int x)
{
    if (d == D) return 0;
 
    int &res = memo[d][w][x];
    if (res != -1) return res;
   
    res = solve(d+1, w, x);
 
    for (int i = 0; i < C; i++) {
        if (E[i][d] == 0) continue;
        if (w + F[i][d] <= W) {
            res = max(res, solve(d+1, w + F[i][d], x) + E[i][d]);      
        }    
        if (x + 1 > X) continue;
        for (int j = 0; j < 2; j++) {
            int nx = i, cost = 0, f = 0;
            while (1) {
                if (nx < 0 || nx >= C || E[nx][d] == 0) break;
                f += F[nx][d];
                cost += E[nx][d];
                if (w + f <= W) {
                    res = max(res, solve(d+1, w + f, x+1) + cost);
                }
                nx += dx[j];
            }
        }   
    }
    return res;
}
 
int main()
{
    while (cin >> C >> D >> W >> X, C) {
        for (int i = 0; i < C; i++) {
            for (int j = 0; j < D; j++) {
                cin >> E[i][j];
            }
        }
 
        for (int i = 0; i < C; i++) {
            for (int j = 0; j < D; j++) {
                cin >> F[i][j];
            }
        }
 
        memset(memo, -1, sizeof(memo));
     
        int res = solve(0, 0, 0);
        cout << res << endl;
    }
    return 0;
}
