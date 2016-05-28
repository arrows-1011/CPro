#include <bits/stdc++.h>

using namespace std;

double get_x(double r1, double r2)
{
    return sqrt(pow(r1 + r2, 2) - pow(r1 - r2, 2));
}

int main()
{
    int N;
    cin >> N;
    vector<double> R(N), x(N);
    for (int i = 0; i < N; i++) {
        cin >> R[i];      
    }
    double res = 0;
    for (int i = 0; i < N; i++) {
        double nx = R[i];
        for (int j = 0; j < i; j++) {
            nx = max(nx, x[j] + get_x(R[i], R[j]));
        }
        x[i] = nx;
        res = max(res, x[i] + R[i]);
    }
    printf("%.10f\n", res);
    return 0;
}
