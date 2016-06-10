#include <bits/stdc++.h>

using namespace std;

#define MAX_N 20
#define INF (1<<29)

int main()
{
    int N, M;
    while (cin >> N) {
        cin >> M;
        int d[MAX_N][MAX_N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                d[i][j] = INF;
            }
            d[i][i] = 0;
        }
        int a, b, c1, c2;
        for (int i = 0; i < M; i++) {
            scanf("%d,%d,%d,%d", &a, &b, &c1, &c2);
            a--; b--;
            d[a][b] = c1;
            d[b][a] = c2;
        }
        scanf("%d,%d,%d,%d", &a, &b, &c1, &c2);
        a--; b--;

        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }

        cout << c1 - c2 - d[a][b] - d[b][a] << endl;
    }           
    return 0;
}
