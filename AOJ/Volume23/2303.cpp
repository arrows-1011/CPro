#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100
#define MAX_M 50
#define INF (1<<29)

int main()
{
    int N, M;
    double L;
    cin >> N >> M >> L;
    vector<double> P(N), T(N), V(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i] >> T[i] >> V[i];
        P[i] /= 100;
    }
    double p[MAX_N][MAX_M+1][MAX_M+1];
    memset(p, 0, sizeof(p));

    for (int i = 0; i < N; i++) {
        p[i][0][0] = 1;
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < M; k++) {
                p[i][j+1][k]   += p[i][j][k] * (1 - P[i]);
                p[i][j+1][k+1] += p[i][j][k] * P[i];
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        double res = 0;
        for (int j = 0; j <= M; j++) {
            double r = 1;
            bool win = 1;
            for (int k = 0; k < N; k++) {
                if (i == k) {
                    continue;
                }
                double rr = 0;
                bool ok = 0;
                for (int l = M; l >= 0; l--) {
                    if (V[k]*L+V[k]*V[i]*T[i]*j <
                        V[i]*L+V[i]*V[k]*T[k]*l) {
                        ok = 1;
                        rr += p[k][M][l];
                    } else {
                        break;
                    }
                }
                if (!ok) {
                    win = 0;
                    break;
                }
                r *= rr;
            }
            res += (win ? r * p[i][M][j] : 0);
        }
        printf("%.8f\n", res);
    }
    return 0;
}
