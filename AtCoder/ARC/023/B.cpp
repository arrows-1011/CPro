#include <bits/stdc++.h>

using namespace std;

int main()
{
    int H, W, D;
    cin >> H >> W >> D;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }
    
    int res = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if ((i + j) % 2 != D % 2 || (i + j > D)) {
                continue;
            }
            res = max(res, A[i][j]);
        }
    }
    cout << res << endl;
    return 0;
}
