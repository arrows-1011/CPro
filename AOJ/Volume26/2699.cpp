#include <bits/stdc++.h>

using namespace std;

#define INF (1<<29)

double dist(double x, double y)
{
    return sqrt(x * x + y * y);
}

int main()
{
    int D, E;
    while (cin >> D >> E, D) {
        double res = INF;
        for (int x = 0; x <= 100; x++) {
            for (int y = 0; y <= 100; y++) {
                if (x + y != D) continue;
                res = min(res, abs(dist(x, y) - E));
            }
        }
        printf("%.10f\n", res);
    }
    return 0;
}
