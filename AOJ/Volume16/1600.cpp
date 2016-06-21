#include <bits/stdc++.h>

using namespace std;

#define INF (1<<29)

int main()
{
    int m, nmin, nmax;
    while (cin >> m >> nmin >> nmax, m) {
        vector<int> P(m);
        for (int i = 0; i < m; i++) {
            cin >> P[i];
        } 
        int gap = P[nmin-1] - P[nmin], res = nmin;
        for (int i = nmin; i < nmax; i++) {
            if (gap < P[i] - P[i+1]) {
                gap = P[i] - P[i+1];
                res = i + 1;
            } else if (gap == P[i] - P[i+1]) {
                res = i + 1;
            }
        }
        cout << res << endl;
    }
    return 0;
}
