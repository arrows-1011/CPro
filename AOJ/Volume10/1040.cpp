#include <bits/stdc++.h>

using namespace std;

#define INF (1<<29)
typedef vector<int> Vec;
typedef vector<Vec> Graph;

int minimum_steiner_tree(Graph &d, Vec &heart)
{
    int N = d.size(), T = heart.size();
    if (T <= 1) return T;   
    
    int dp[1<<T][N];
    for (int i = 0; i < (1<<T); i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = INF;
        }
    }

    for (int i = 0; i < T; i++) {
        for (int j = 0; j < N; j++) {
            dp[1<<i][j] = d[heart[i]][j];
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
    return res + 1;
}

int get_dist(int y1, int x1, int y2, int x2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

int main()
{
    int H, W, x;
    while (cin >> H >> W, H) {
        Vec heart;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> x;  
                if (x == 1) {
                    heart.push_back(i * W + j);
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
        cout << H*W - minimum_steiner_tree(G, heart) << endl;
    }
    return 0;
}
