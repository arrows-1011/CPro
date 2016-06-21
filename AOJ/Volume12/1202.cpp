#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, tc = 1;
    while (cin >> N, N) {
        vector<double> X1(N), Y1(N), X2(N), Y2(N);
        vector<double> xs, ys;
        for (int i = 0; i < N; i++) {
            double x, y, r;
            cin >> x >> y >> r;
            X1[i] = x - r; Y1[i] = y - r;
            X2[i] = x + r; Y2[i] = y + r;
            xs.push_back(X1[i]); xs.push_back(X2[i]);
            ys.push_back(Y1[i]); ys.push_back(Y2[i]);
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());
        
        double res = 0;
        for (int i = 0; i < (int)xs.size()-1; i++) {
            for (int j = 0; j < (int)ys.size()-1; j++) {
                int cnt = 0;
                for (int k = 0; k < N; k++) {
                    if (X1[k] <= xs[i] && xs[i+1] <= X2[k] &&
                        Y1[k] <= ys[j] && ys[j+1] <= Y2[k]) {
                        cnt++;
                    }
                }
                if (cnt > 0) {
                    res += (xs[i+1] - xs[i]) * (ys[j+1] - ys[j]);
                }
            }
        } 
        printf("%d %.2f\n", tc++, res);
    }        
    return 0;
}
