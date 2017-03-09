#include <bits/stdc++.h>

using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }

    constexpr int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    constexpr int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    vector<string> nS = S;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {            
            bool is_dot = 0;
            for (int k = 0; k < 8; k++) {
                int ni = i + di[k], nj = j + dj[k];
                if (ni < 0 || ni >= H || nj < 0 || nj >= W) {
                    continue;
                }
                if (S[ni][nj] == '.') {
                    is_dot = 1;
                    break;
                }
            }
            nS[i][j] = ((is_dot || S[i][j] == '.') ? '.' : '#');
        }
    }

    vector<string> bS = nS;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (nS[i][j] == '.') continue;
            bS[i][j] = '#';
            for (int k = 0; k < 8; k++) {
                int ni = i + di[k], nj = j + dj[k];
                if (ni < 0 || ni >= H || nj < 0 || nj >= W) {
                    continue;
                }
                bS[ni][nj] = '#';
            }
        }
    }
    if (S == bS) {
        cout << "possible" << endl;
        for (int i = 0; i < H; i++) {
            cout << nS[i] << endl;
        }
    } else {
        cout << "impossible" << endl;
    }
    return 0;
}
