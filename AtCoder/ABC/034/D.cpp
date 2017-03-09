#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<double> w(N), p(N);
    for (int i = 0; i < N; i++) {
        cin >> w[i] >> p[i];
    }

    auto c = [&](double x) -> bool {
        vector<double> v(N);
        for (int i = 0; i < N; i++) {
            v[i] = w[i] * p[i] - x * w[i];
        }

        sort(v.rbegin(), v.rend());
        double res = 0;
        for (int i = 0; i < K; i++) {
            res += v[i];
        }
        return res >= 0;
    };

    double l = 0, r = 252521;
    for (int i = 0; i < 50; i++) {
        double mid = (l + r) / 2;
        if (c(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    
    printf("%.15f\n", r);
    return 0;
}
