#include <iostream>
#include <cstring>

using namespace std;

constexpr int MAX_H = 20;

int H, N;
char b[MAX_H][2][2], tb[3][MAX_H][2][2];
char c[3][2][2][2],  nc[2][2][2];

constexpr int di[] = {+0, +0, +0, +0, +0, +0, +0, +0, +0, +1, +1, +1, +1, +1, +1, +1, +1, +1};
constexpr int dj[] = {+0, -1, +0, +1, +0, -1, -1, +1, +1, +0, -1, +0, +1, +0, -1, -1, +1, +1};
constexpr int dk[] = {+0, +0, -1, +0, +1, -1, +1, -1, +1, +0, +0, -1, +0, +1, -1, +1, -1, +1};

bool in_field(int i, int j, int k)
{
    return (0 <= i && i < 2 && 0 <= j && j < 2 && 0 <= k && k < 2);
}

bool move(int x, int n)
{
    fill(nc[0][0], nc[2][0], '.');
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                int ni = i + di[x], nj = j + dj[x], nk = k + dk[x];
                if (c[n][i][j][k] == '#') {
                    if (!in_field(ni, nj, nk)) return 0;
                    nc[ni][nj][nk] = '#';
                } 
            }
        }
    }
    return 1;
}

int score()
{
    int p = -1;    
    for (int i = 0; i < H + 2 * N; i++) {
        bool ng = 0;
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {                    
                    ng |= (b[i + j][k][l] == '#' && nc[j][k][l] == '#');
                }
            }
        }

        if (ng) break;
        p = i;
    }
    int res = 0;
    bool rem[2] = {};
    for (int i = 0; i < 2; i++) {        
        int cnt = 0;
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                if (nc[i][j][k] == '#') {
                    b[p + i][j][k] = '#';
                }
                if (b[p + i][j][k] == '#') {
                    cnt++;
                }
            }
        }
        if (cnt == 4) {
            rem[i] = 1;
            res++;
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    b[p + i][j][k] = '.';
                }
            }
        }
    }

    if (rem[0] || rem[1]) {
        for (int i = p + rem[1]; i >= 0; i--) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    int v = 1 + (rem[0] && rem[1]);
                    b[i][j][k] = (i >= v ? b[i - v][j][k] : '.');
                }
            }
        }
    }
    return res;
}

int solve(int n)
{
    if (n == N) return 0;
    
    int res = 0;
    memcpy(tb[n], b, sizeof(b));
    for (int i = 0; i < 18; i++) {
        if (move(i, n)) {
            int s = score();
            res = max(res, solve(n + 1) + s);
        }
        memcpy(b, tb[n], sizeof(b));
    }
    return res;
}

int main()
{
    while (cin >> H >> N, H) {
        fill(b[0][0], b[MAX_H][0], '.');
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    cin >> b[H - i + 2 * N][j][k];
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    for (int l = 0; l < 2; l++) {
                        cin >> c[i][j ^ 1][k][l];
                    }
                }
            }
        }
        cout << solve(0) << endl;;
    }        
    return 0;
}
