/*
  subTの頂点を全て含むようなグラフのエッジのコストの和の最小値を出す
  |V| = n, |T| = t としたとき，
  時間計算量 O(n 3^t + n^2 2^t + n^3)．
  空間計算量 O(n 2^t)．
 */

#include <bits/stdc++.h>

using namespace std;

#define INF (1<<29)
typedef vector<int> Vec;
typedef vector<Vec> Graph;

int minimum_steiner_tree(Graph &d, Vec &subT)
{
    int N = d.size(), T = subT.size();
    if (T <= 1) return T;
    
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    
    int dp[1<<T][N];
    for (int i = 0; i < (1<<T); i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = INF;
        }
    }

    for (int i = 0; i < T; i++) {
        for (int j = 0; j < N; j++) {
            dp[1<<i][j] = d[subT[i]][j];
        }
    }

    for (int i = 1; i < (1<<T); i++) {
        if (!(i & (i - 1))) continue;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < i; k++) {
                if ((i | k) == i) {
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j]);
                }
            }
        }
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + d[j][k]);
            }
        }
    }
    int res = INF;
    for (int i = 0; i < (1<<T); i++) {
        for (int j = 0; j < N; j++) {
            res = min(res, dp[i][j] + dp[((1<<T)-1)-i][j]);
        }
    }
    return res;
}

int get_dist(int y1, int x1, int y2, int x2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

int main()
{
    int H, W, x;
    while (cin >> H >> W, H) {
        Vec subT;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> x;  
                if (x == 1) {
                    subT.push_back(i * W + j);
                }
            }
        }

        Graph G(H*W, Vec(H*W));
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                for (int k = 0; k < H; k++) {
                    for (int l = 0; l < W; l++) {
                        G[i*W+j][k*W+l] = get_dist(i, j, k, l);
                    }
                }
            }
        }
        cout << H*W - minimum_steiner_tree(G, subT) << endl;
    }
    return 0;
}
