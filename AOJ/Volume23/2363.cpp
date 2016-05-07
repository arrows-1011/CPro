#include <bits/stdc++.h>

using namespace std;

#define EPS (1e-7)

double get_ex()
{
    int n, m;
    cin >> n >> m;
    double v, r, p = 1, e = 0;
    for (int i = 0; i < m; i++) {
        cin >> v >> r;
        e += v * r;
        p -= r;        
    }
    return e / (1 - p);
}

int main()
{
    int t;
    double max_ex = 0;
    cin >> t;
    while (t--) {
        max_ex = max(max_ex, get_ex());        
    }
    cout << (max_ex - get_ex() > EPS ? "YES" : "NO") << endl;    
    return 0;
}
