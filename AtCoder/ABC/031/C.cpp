#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

pii get_point(vector<int> &T)
{
    pii p(0, 0);
    for (int i = 0; i < (int)T.size(); i++) {
        if (i % 2 == 0) {
            p.first += T[i];
        } else {
            p.second += T[i];
        }
    }
    return p;
}

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int res = -5000;
    for (int i = 0; i < N; i++) {
        int max_aoki = -5000;
        vector<int> t;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            vector<int> T;
            if (i < j) {
                for (int k = i; k <= j; k++) {
                    T.push_back(a[k]);
                }
            } else {
                for (int k = j; k <= i; k++) {
                    T.push_back(a[k]);
                }
            }
            int point = get_point(T).second;
            if (max_aoki < point) {
                max_aoki = point;
                t = T;
            }                
        }
        res = max(res, get_point(t).first);
    }
    cout << res << endl;
    return 0;
}
