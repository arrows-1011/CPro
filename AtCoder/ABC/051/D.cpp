#include <iostream>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    
    constexpr int INF = (1 << 29);
    
    int d[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            d[i][j] = INF * (i != j);
        }
    }
    
    int a[M], b[M], c[M];
    for (int i = 0; i < M; i++) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;
        d[a[i]][b[i]] = d[b[i]][a[i]] = c[i];
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < M; i++) {
        if (d[a[i]][b[i]] != c[i]) ++cnt;
    }
    cout << cnt << endl;
    
    return 0;
}
