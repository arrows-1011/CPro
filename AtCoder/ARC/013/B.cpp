#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int G[N][3];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> G[i][j];
        }
        sort(G[i], G[i] + 3);
    }
    
    int res = 1;
    for (int i = 0; i < 3; i++) {
        int mx = 0;
        for (int j = 0; j < N; j++) {
            mx = max(mx, G[j][i]);
        }
        res *= mx;
    }
    cout << res << endl;
    return 0;
}
