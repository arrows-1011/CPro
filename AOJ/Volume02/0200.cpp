#include <bits/stdc++.h>

using namespace std;

#define MAX 110
#define INF (1<<29)

int main()
{
    int M, N;
    while (cin >> M >> N, M) {
        int co[MAX][MAX];
        int ti[MAX][MAX];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                co[i][j] = ti[i][j] = INF;                
            }
            co[i][i] = ti[i][i] = 0;
        }
        int a, b, c, t;
        for (int i = 0; i < M; i++) {
            cin >> a >> b >> c >> t;
            a--; b--;
            
            co[a][b] = co[b][a] = c;
            ti[a][b] = ti[b][a] = t;            
        }

        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    co[i][j] = min(co[i][j], co[i][k] + co[k][j]);
                    ti[i][j] = min(ti[i][j], ti[i][k] + ti[k][j]);
                }
            }
        }

        int Q, r;
        cin >> Q;
        while (Q--) {
            cin >> a >> b >> r;
            a--; b--;
            if (r == 0) {
                cout << co[a][b] << endl;
            } else {
                cout << ti[a][b] << endl;
            }
        }
    }
    return 0;
}
