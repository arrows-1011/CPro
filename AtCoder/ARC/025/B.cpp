#include <bits/stdc++.h>

using namespace std;

int main()
{
    int H, W, res = 0;
    cin >> H >> W;
    vector<vector<int>> C(H+1, vector<int>(W+1, 0));
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> C[i][j];
            if ((i + j) % 2 == 0) {
                C[i][j] = -C[i][j];
            }
            if (C[i][j] == 0) {
                res = 1;
            }
        }
    }

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {            
            C[i][j] += C[i-1][j];
        }
    }

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            C[i][j] += C[i][j-1];
        }
    }

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            for (int k = i; k <= H; k++) {
                for (int l = j; l <= W; l++) {
                    if (i == k && j == l) continue;
                    if (C[k][l] - C[i-1][l] - C[k][j-1] + C[i-1][j-1] == 0) {
                        res = max(res, (k - i + 1) * (l - j + 1));
                    }
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}
