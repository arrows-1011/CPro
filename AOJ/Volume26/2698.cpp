#include <bits/stdc++.h>

using namespace std;

#define MAX 21
typedef vector<int> Vec;
typedef vector<Vec> Mat;

int H, W;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int memo[MAX][MAX][MAX][MAX];

int grundy(int x1, int y1, int x2, int y2, Mat &f)
{
    if (x1 > x2 || y1 > y2) {
        return 0;
    }

    if (memo[y1][x1][y2][x2] != -1) {
        return memo[y1][x1][y2][x2];
    }
        
    unordered_set<int> st;
    for (int i = y1; i <= y2; i++) {
        for (int j = x1; j <= x2; j++) {
            if (f[i][j] == 0) {
                st.insert(grundy(x1, y1, j-1, i-1, f) ^
                          grundy(j+1, y1, x2, i-1, f) ^
                          grundy(x1, i+1, j-1, y2, f) ^
                          grundy(j+1, i+1, x2, y2, f));
            }
        }
    }   
    
    int res = 0;
    while (st.count(res)) res++;
    return (memo[y1][x1][y2][x2] = res);
}

int main()
{    
    cin >> H >> W;
    Mat f(H);
    for (int i = 0; i < H; i++) {
        f[i].resize(W);
        for (int j = 0; j < W; j++) {
            char ch;
            cin >> ch;
            f[i][j] = (ch == 'X');
        }
    }
    memset(memo, -1, sizeof(memo));
    cout << (grundy(0, 0, W-1, H-1, f) != 0 ? "First" : "Second") << endl;
    return 0;
}
