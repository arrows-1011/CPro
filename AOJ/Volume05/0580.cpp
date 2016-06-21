#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<ll> X1(N), Y1(N), Z1(N);
    vector<ll> X2(N), Y2(N), Z2(N);
    vector<ll> xs, ys, zs;
    for (int i = 0; i < N; i++) {
        cin >> X1[i] >> Y1[i] >> Z1[i];
        cin >> X2[i] >> Y2[i] >> Z2[i];
        xs.push_back(X1[i]); xs.push_back(X2[i]);
        ys.push_back(Y1[i]); ys.push_back(Y2[i]);
        zs.push_back(Z1[i]); zs.push_back(Z2[i]);
    }

    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    sort(zs.begin(), zs.end());
    zs.erase(unique(zs.begin(), zs.end()), zs.end());
    
    ll res = 0;
    for (int i = 0; i < (int)xs.size()-1; i++) {
        for (int j = 0; j < (int)ys.size()-1; j++) {
            for (int k = 0; k < (int)zs.size()-1; k++) {
                int cnt = 0;
                for (int l = 0; l < N; l++) {
                    if (X1[l] <= xs[i] && xs[i+1] <= X2[l] &&
                        Y1[l] <= ys[j] && ys[j+1] <= Y2[l] &&
                        Z1[l] <= zs[k] && zs[k+1] <= Z2[l]) {
                        cnt++;
                    }
                }
                if (cnt >= K) {
                    res += (xs[i+1] - xs[i]) * (ys[j+1] - ys[j]) * (zs[k+1] - zs[k]);
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}

