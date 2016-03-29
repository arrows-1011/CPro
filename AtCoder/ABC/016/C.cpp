#include <bits/stdc++.h>

using namespace std;

#define MAX 15
#define INF (1<<29)

int main()
{
    int N, M, a, b;
    int d[MAX][MAX];
    fill(d[0], d[MAX], INF);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        a--; b--;
        d[a][b] = d[b][a] = 1;
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (i == j) {
                continue;
            }
            if (d[i][j] == 2) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
