#include <bits/stdc++.h>

using namespace std;

#define MAX 1000
typedef pair<int, int> pii;

int W, H, N;
int X1[MAX], Y1[MAX], X2[MAX], Y2[MAX];
bool fld[MAX*6][MAX*6];

int compress(int *x1, int *x2, int w)
{
    vector<int> xs;
    for (int i = 0; i < N; i++) {
        for (int d = -1; d <= 1; d++) {
            int tx1 = x1[i] + d, tx2 = x2[i] + d;
            if (0 <= tx1 && tx1 < w) xs.push_back(tx1);
            if (0 <= tx2 && tx2 < w) xs.push_back(tx2);
        }
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    
    for (int i = 0; i < N; i++) {
        x1[i] = lower_bound(xs.begin(), xs.end(), x1[i]) - xs.begin();
        x2[i] = lower_bound(xs.begin(), xs.end(), x2[i]) - xs.begin();
    }
    return xs.size();
}

int solve()
{        
    W = compress(X1, X2, W);
    H = compress(Y1, Y2, H);

    memset(fld, 0, sizeof(fld));
    for (int i = 0; i < N; i++) {
        for (int y = Y1[i]; y < Y2[i]; y++) {
            for (int x = X1[i]; x < X2[i]; x++) {
                fld[y][x] = 1;
            }
        }
    }

    const int dx[] = {-1, 0, 1, 0};
    const int dy[] = {0, -1, 0, 1};
    int res = 0;
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            if (fld[y][x]) continue;
            res++; fld[y][x] = 1;
            queue<pii> Q; Q.push(pii(x, y));
            while (!Q.empty()) {
                pii p = Q.front(); Q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = p.first + dx[i];
                    int ny = p.second + dy[i];
                    if (0 <= nx && nx < W && 0 <= ny && ny < H &&
                        !fld[ny][nx]) {
                        fld[ny][nx] = 1;
                        Q.push(pii(nx, ny));
                    }
                }
            }            
        }
    }
    return res;
}

int main()
{
    while (cin >> W >> H >> N, W) {
        for (int i = 0; i < N; i++) {
            cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
        }
        cout << solve() << endl;
    }
    return 0;
}
