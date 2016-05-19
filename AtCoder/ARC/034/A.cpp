#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    double a, b, c, d, e, max_point = 0;
    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c >> d >> e;
        max_point = max(max_point, a + b + c + d + e * 110.0/900.0);
    }
    printf("%.10f\n", max_point);
    return 0;
}
