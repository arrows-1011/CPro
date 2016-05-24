#include <bits/stdc++.h>

using namespace std;

int main()
{
    int L, S, D;
    double X, Y;
    cin >> L >> X >> Y >> S >> D;
    double res = LLONG_MAX;
    res = min(res, (double)((D - S + L) % L) / (X + Y));
    if (Y > X) {
        res = min(res, (double)((S - D + L) % L) / (Y - X));
    }
    printf("%.10f\n", res);
    return 0;
}
