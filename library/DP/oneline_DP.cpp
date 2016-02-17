/*
  1行覚えるDP
  
  n x m のマスがあり, 各マスは白または黒に塗られている. 1 x 2 のブロックを重なりを生じないように
  敷き詰め、すべての白のマスを覆い,黒のマスを一切覆わないような方法の総数を求め, M で割った余りを答える.
  
  1 <= n <= 15
  1 <= m <= 15
  2 <= M <= 10^9
*/

#include <iostream>

using namespace std;

#define MAX_N 15
#define MAX_M 15

int n, m, M;
int dp[2][1<<MAX_M];
bool color[MAX_N][MAX_M]; // false: 白マス, true: 黒マス

void solve()
{
    int *crt = dp[0], *next = dp[1];
    crt[0] = 1;
    for (int i = n-1; i >= 0; i--) {
        for (int j = m-1; j >= 0; j--) {
            for (int used = 0; used < (1<<m); used++) {
                if ((used >> j & 1) || color[i][j]) {
                    // (i, j) にはブロックを置く必要がない
                    next[used] = crt[used & ~(1<<j)];
                } else {
                    // 2通りの向きを試す
                    int res = 0;
                    // 横向き
                    if (j+1 < m && !(used >> (j+1) & 1) && !color[i][j+1]) {
                        res += crt[used | 1 << (j+1)];
                    }
                    // 縦向き
                    if (i+1 < n && !color[i+1][j]) {
                        res += crt[used | 1<<j];
                    }
                    next[used] = res % M;
                }
            }
            swap(crt,next);
        }
    }
    cout << crt[0] << endl;
}
