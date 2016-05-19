#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[2][7];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 7; j++) {
            cin >> a[i][j];
        }
    }
    
    int res = 0;
    for (int i = 0; i < (1<<7); i++) {
        int gold = 0;
        for (int j = 0; j < 7; j++) {
            int b = (i >> j & 1);
            gold += a[b][j];
        }
        res = max(res, gold);
    }
    cout << res << endl;
    return 0;
}
