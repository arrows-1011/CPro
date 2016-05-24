#include <bits/stdc++.h>

using namespace std;

double c(double x) {
    x /= 1.5;
    return pow(2.0, x);
}

int main()
{
    double P;
    cin >> P;
    double l = 0, r = P;
    for (int i = 0; i < 150; i++) {
        double m1 = (l*2 + r) / 3;
        double m2 = (l + r*2) / 3;

        if (P/c(m1) + m1 < P/c(m2) + m2) {
            r = m2;
        } else {
            l = m1;
        }
    }    
    printf("%.10f\n", P/c(l) + l);
    return 0;
}
