#include <bits/stdc++.h>

using namespace std;

#define MAX 200
#define INF 1000002
typedef pair<int, int> pii;

int H, W, N;
int X1[MAX], X2[MAX], Y1[MAX], Y2[MAX];
bool fld[MAX*6][MAX*6];

int compress(int *x1, int *x2)
{
    vector<int> xs;
    for (int i = 0; i < N; i++) {
        for (int d = -1; d <= 1; d++) {
            int tx1 = x1[i] + d, tx2 = x2[i] + d;
            xs.push_back(tx1);
            xs.push_back(tx2);
        }
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    for (int i = 0; i < N; i++) {
        x1[i] = find(xs.begin(), xs.end(), x1[i]) - xs.begin();
        x2[i] = find(xs.begin(), xs.end(), x2[i]) - xs.begin();
    }
    return xs.size();
}

int solve()
{
    W = compress(X1, X2);
    H = compress(Y1, Y2);
    
    memset(fld, 0, sizeof(fld));
    for (int i = 0; i < N; i++) {
        for (int y = Y1[i]; y <= Y2[i]; y++) {
            for (int x = X1[i]; x <= X2[i]; x++) {
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
            res++;

            queue<pii> Q;
            Q.push(pii(x, y));
            while (!Q.empty()) {
                pii p = Q.front(); Q.pop();
                int sx = p.first, sy = p.second;

                for (int i = 0; i < 4; i++) {
                    int tx = sx + dx[i], ty = sy + dy[i];
                    if (tx < 0 || W <= tx || ty < 0 || H <= ty || fld[ty][tx]) {
                        continue;
                    }

                    Q.push(pii(tx, ty));
                    fld[ty][tx] = 1;
                }

            }
        }

    }
    return res;
}

int main()
{
    while (cin >> N, N) {
        H = W = INF;
        int x[2], y[2];
        for (int i = 0; i < N; i++) {
            cin >> x[0] >> y[0] >> x[1] >> y[1];
            for (int j = 0; j < 2; j++) {
                x[j] = x[j] * 2 + 1;
                y[j] = y[j] * 2 + 1;
            }
            int dj[] = {1, 0, 0, -1}, dk[] = {0, -1, 1, 0};
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    int l = j * 2 + k, m = i * 4 + l;
                    int nj = j + dj[l];
                    int nk = k + dk[l];
                    X1[m] = x[j];  Y1[m] = y[k];
                    X2[m] = x[nj]; Y2[m] = y[nk];
                    if (X1[m] > X2[m]) swap(X1[m], X2[m]);
                    if (Y1[m] > Y2[m]) swap(Y1[m], Y2[m]);
                }
            }                        
        }
        N *= 4;
        cout << solve() << endl;
    }
    return 0;
}
