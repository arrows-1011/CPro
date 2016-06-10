#include <bits/stdc++.h>

using namespace std;

#define MAX_H 10
#define MAX_W 10
#define MAX 13*12+10
#define F first
#define S second
typedef pair<int, int> pii;
typedef pair<pii, int> Ink;

int mat[MAX_H][MAX_W];
const int size[] = {5,9,13};

const int dx[3][13] = {
    {-1, 0, 0, 1, 0},
    {-1, -1, -1, 0, 0, 0, 1, 1, 1},
    {-2, -1, -1, -1, 0, 0, 0, 0, 0, 1, 1, 1, 2}
};

const int dy[3][13] = {
    {0, -1, 0, 0, 1},
    {-1, 0, 1, -1, 0, 1, -1, 0, 1},
    {0, -1, 0, 1, -2, -1, 0, 1, 2, -1, 0, 1, 0}
};

inline bool inField(int x, int y)
{
    return (0 <= x && x < MAX_W && 0 <= y && y < MAX_H);
}

inline bool check(int x, int y, int s)
{
    for (int i = 0; i < size[s]; i++) {
        int nx = x + dx[s][i];
        int ny = y + dy[s][i];
        if (!inField(nx, ny)) return 0;
        if (mat[ny][nx] == 0) return 0;
    }
    return 1;
}

inline void removeBlur(int x, int y, int s, bool plus)
{
    for (int i = 0; i < size[s]; i++) {
        int nx = x + dx[s][i];
        int ny = y + dy[s][i];
        mat[ny][nx] = mat[ny][nx] + (plus ? +1 : -1);
    }
}

vector<Ink> v;
bool ok[MAX];

void solve(int x, int y, int rem, int n)
{
    if (n == 0) {
        if (rem == 0) throw 0;
        return;
    }
    if (!ok[rem]) return;
    if (rem < n*5 || rem > n*13) return;
    for (; y < MAX_H-1; y++) {
        for (; x < MAX_W-1; x++) {
            if (mat[y][x] == 0) continue;
            for (int i = 2; i >= 0; i--) {
                if (check(x, y, i)) {
                    removeBlur(x, y, i, 0);
                    v.push_back(Ink(pii(x, y), i+1));
                    solve(x, y, rem-size[i], n-1);
                    removeBlur(x, y, i, 1);
                    v.pop_back();
                }
            }
        }
        x = 1;
    }
}

void init()
{
    memset(ok, 0, sizeof(ok));
    ok[0] = 1;
    for (int i = 0; i < MAX; i++) {
        if (!ok[i]) continue;
        for (int j = 0; j < 3; j++) {
            if (i+size[j] < MAX) {
                ok[i+size[j]] = 1;
            }
        }
    }
}

int main()
{
    int n, cnt = 0;
    init();
    cin >> n;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> mat[i][j];
            cnt += mat[i][j];
        }
    }
    try{
        solve(1, 1, cnt, n);
    }catch(...){}
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i].F.F << " " << v[i].F.S << " " << v[i].S << endl;
    }
    return 0;
}
