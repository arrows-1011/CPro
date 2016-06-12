#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    char c[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> c[i][j];            
        }
    }

    int res = (1<<29);
    for (int i = 1; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            int cost = 0;
            for (int k = 0; k < N; k++) {                
                for (int m = 0; m < M; m++) {
                    if (k < i) {
                        cost += (c[k][m] != 'W');
                    } else if (k < j) {
                        cost += (c[k][m] != 'B');
                    } else {
                        cost += (c[k][m] != 'R');
                    }
                }
            }
            res = min(res, cost);
        }
    }
    cout << res << endl;
    return 0;
}
