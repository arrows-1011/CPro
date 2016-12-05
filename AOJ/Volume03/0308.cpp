#include <iostream>

using namespace std;

constexpr int MAX = 200;
constexpr int INF = (1 << 29);

int main()
{
    int N, u, v, d[MAX][MAX];
    string s;

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            d[i][j] = (i != j) * INF;
        }
    }
    
    cin >> N;    
    for (int i = 0; i < N; i++) {
        cin >> u >> s >> v;
        u--; v--; v += MAX / 2;
        if (s == "lock") swap(u, v);
        d[u][v] = -1;
    }

    for (int k = 0; k < MAX; k++) {
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    
    bool res = 0;
    for (int i = 0; i < MAX; i++) {
        if (d[i][i] < 0) {
            res = 1;
            break;
        }
    }
    cout << res << endl;    
    return 0;
}
