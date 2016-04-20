#include <bits/stdc++.h>

using namespace std;

#define MAX 45
#define PI acos(-1)
#define INF (1<<29)
typedef pair<double, double> P;

int N, M;
double memo[MAX][MAX][MAX];
vector<double> x, y;

double area(int a, int b, int c)
{
    vector<P> p(3);
    p[0] = P(x[a], y[a]);
    p[1] = P(x[b], y[b]);
    p[2] = P(x[c], y[c]);   
    
    double res = 0;
    for (int i = 1; i < 4; i++) {
	res += (p[i%3].first - p[i-1].first) * (p[i%3].second + p[i-1].second);
    }
    res /= 2.0;
    return abs(res);
}

double get_max_area(int L, int R, int m)
{
    if (m == M) {
        return 0;
    }    
    double &res = memo[L][R][m];
    if (res != -1) {
        return res;
    }
    for (int i = R+1; i < N; i++) {
        res = max(res, get_max_area(L, i, m+1) + area(L, R, i));
    }
    return res;
}

int main()
{
    double p;
    while (cin >> N >> M, N) {
        x.clear(); y.clear();
        x.resize(N); y.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> p;
            p *= (2.0 * PI);
            x[i] = cos(p); y[i] = sin(p);
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    memo[i][j][k] = -1;
                }
            }
        }

        double mx = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                for (int k = j+1; k < N; k++) {
                    mx = max(mx, get_max_area(i, k, 3) + area(i, j, k));
                }
            }
        }
        printf("%.6f\n", mx);
    }
    return 0;
}
