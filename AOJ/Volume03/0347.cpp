#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

constexpr double INF = (1 << 29);

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    double maxi = -INF;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            int C = a[i], D = a[j];
            int x[2];
            if (C - D < 0) {
                for (int k = 0, l = 0; k < N; k++) {
                    if (i != k && j != k) {
                        x[l] = a[k];
                        if (++l == 2) break;
                    }
                }
            } else {
                for (int k = N - 1, l = 0; k >= 0; k--) {
                    if (i != k && j != k) {
                        x[l] = a[k];
                        if (++l == 2) break;
                    }
                }
            }
                
            maxi = max(maxi, (double)(x[0] + x[1]) / (C - D));
        }
    }
    printf("%.10f\n", maxi);
    return 0;
}
